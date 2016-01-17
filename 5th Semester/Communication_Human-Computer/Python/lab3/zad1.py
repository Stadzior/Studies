import cv2
import sys
import PIL
from PIL import Image

faceCascade = cv2.CascadeClassifier("haarscale_cascade_default.xml")
imageCV2 = cv2.imread("zdj.jpg")
imagePIL = Image.open("zdj.jpg")
faces = faceCascade.detectMultiScale(cv2.cvtColor(imageCV2, cv2.COLOR_BGR2GRAY))
i = 1
for (x, y, w, h) in faces:
    left = x
    top = y
    right = x+w
    bottom = y+h
    croppedImagePIL = imagePIL.crop((left, top, right, bottom)).resize((128,128))
    croppedImagePIL.save(str(i)+".jpg")
    i+=1
