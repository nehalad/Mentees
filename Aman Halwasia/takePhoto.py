import picamera
def clickPhoto(OTP):
        filename=str(OTP)+".jpg"
        try:
                camera = picamera.PiCamera()
                camera.brightness = 70
                camera.contrast = 70
                camera.saturation = 0
                camera.awb_mode = 'incandescent'
                camera.capture(filename)
                print("Photo Saved: "+filename)    
                
        finally:
                camera.close()
        return filename

clickPhoto("12345")
