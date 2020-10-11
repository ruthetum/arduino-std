import os
import tensorflow.keras
from PIL import Image, ImageOps
import numpy as np
from werkzeug.utils import secure_filename
import cv2
import serial

model = tensorflow.keras.models.load_model('./models/keras_model.h5')
arduino = serial.Serial('COM4', 9600)

# 마스크 착용 여부 분류
def classify(frame):
	prediction = model.predict(frame)
	if prediction[0][0] > 0.5:
		return "Mask"
	else:
		return "None"

cap = cv2.VideoCapture(0)
cap.set(3, 320)
cap.set(4, 240)

# 아두이노 시리얼 통신
def toArduino(result):
    if (result is "Mask"):
        x = 'o'
    else:
        x = 'x'
    x = x.encode('utf-8')
    arduino.write(x)

while(True):
    # 한 프레임씩 읽어오고
    # ret : 프레임 read 여부
    # frame : 읽은 프레임
    ret, frame = cap.read()

    # 좌우 전환
    frame = cv2.flip(frame,1)

    # 사이즈 조절
    size = (224, 224)
    frame = cv2.resize(frame, size, interpolation=cv2.INTER_AREA)

    # 이미지 정규화
    frame_normal = (frame.astype(np.float32) / 127.0) - 1
    # 이미지 차원 조정
    frame_reshape = frame_normal.reshape((1, 224, 224, 3))

    # 분류
    result = classify(frame_reshape)
    # 아두이노 시리얼 통신
    toArduino(result)
    # print(result)

    # 이미지 출력
    cv2.imshow('You wear a mask?', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()

