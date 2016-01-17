import cv2
import numpy as np
import random
import copy
import math
from PIL import ImageFilter
from PIL import Image
noiseLvl = input("Podaj poziom zaszumienia(1-50):\n")
if noiseLvl>50:
    noiseLvl = 50
elif noiseLvl<0:
    noiseLvl = 0
image = cv2.imread("bartek.jpg")
w,h = image.shape[:2]
m = w*h
noiseLvl = float(noiseLvl)/100

#Impulse noise
impulseNoise = copy.copy(image)
Xcoor = [random.randrange(w)]
Ycoor = [random.randrange(h)]
nPixs = int(math.ceil(m*noiseLvl))
for i in range(nPixs):
    Xcoor.append(random.randrange(w))
    Ycoor.append(random.randrange(h))
Coor = zip(Xcoor,Ycoor)

for x,y in Coor:
    impulseNoise[x][y] = [random.randint(0,255),
                              random.randint(0,255),
                              random.randint(0,255)]
cv2.imwrite("impulseNoise.jpg",impulseNoise)

#Median filter

#Gaussian noise
gaussNoise = (np.random.normal(image)-image)*noiseLvl*100
gaussNoise = image + gaussNoise
cv2.imwrite("gaussNoise.jpg",gaussNoise)

impulseImage = Image.open("impulseNoise.jpg")
gaussImage = Image.open("gaussNoise.jpg")

#Blur filter
impulseImage.filter(ImageFilter.BLUR).save("impulseNoiseBlurred.jpg")
gaussImage.filter(ImageFilter.BLUR).save("gaussNoiseBlurred.jpg")

#Median filter
impulseImage.filter(ImageFilter.MedianFilter).save("impulseNoiseMedian.jpg")
gaussImage.filter(ImageFilter.MedianFilter).save("gaussNoiseMedian.jpg")


