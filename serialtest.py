import serial

arduino1 = serial.Serial('COM4', 9600)
arduino2 = serial.Serial('COM7', 9600)

while(True):
    x = 'o'
    x = x.encode('utf-8')
    arduino1.write(x)
    arduino2.write(x)
    print(x)
    x = 'x'
    x = x.encode('utf-8')
    arduino1.write(x)
    arduino2.write(x)
    print(x)
    