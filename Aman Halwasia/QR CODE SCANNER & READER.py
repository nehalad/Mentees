import cv2
import numpy as np
from PIL import Image
from pyzbar.pyzbar import decode
class Application():

    def detect_red_circle(self):
        cam = cv2.VideoCapture(0)
        while True:
            ret, frame = cam.read()
            impil=Image.fromarray(frame)
            a=decode(impil)
            print(a)
            
            if cv2.waitKey(10) & 0xFF == ord('q'):
                break

if __name__ == '__main__':
    app =Application()
    app.detect_red_circle()
