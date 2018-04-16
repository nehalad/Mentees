import cv2
import numpy as np
from PIL import Image
from pyzbar.pyzbar import decode
import picamera
import io
class Application():

    def detectQRImage(self):
        stream = io.BytesIO()
        with picamera.PiCamera() as camera:
            camera.start_preview()
            time.sleep(2)
            camera.capture(stream, format='jpeg')
            # "Rewind" the stream to the beginning so we can read its content
            stream.seek(0)         
            image = Image.open(stream)
            a=decode(image)
            print(a)
            
           

if __name__ == '__main__':
    app =Application()
    app.detectQRImage()
