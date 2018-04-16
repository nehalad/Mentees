import cv2
import numpy as np
from PIL import Image
from pyzbar.pyzbar import decode
from picamera import PiCamera
import time
import io
class Application():

    def detectQRImage(self):
        stream = BytesIO()
        camera = PiCamera()
        camera.resolution = (1024, 768)
        camera.start_preview()
        while True:            
            #time.sleep(2)
            camera.capture(stream, format='jpeg',resize=(320, 240))
            # "Rewind" the stream to the beginning so we can read its content
            stream.seek(0)         
            image = Image.open(stream)
            a=decode(image)
            if(a):            
                print(a)
            
           

if __name__ == '__main__':
    app =Application()
    app.detectQRImage()
