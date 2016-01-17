# -*- coding: cp1250 -*-
import PIL
from PIL import Image
import math
import random

divs = (input("Podaj liczbe podziałow:\n"))
image = Image.open("bartek.jpg")
imageSize = int(math.ceil(min(image.size)))
image = image.crop((0,0,imageSize,imageSize))
puzzleSize = int(math.ceil((imageSize/divs)))
resultImage = Image.new("RGB",(imageSize,imageSize),"white")

for rowNr in range(0,divs):
    for colNr in range(0,divs):
        box = (puzzleSize*colNr,
               puzzleSize*rowNr,
               puzzleSize*(colNr+1),
               puzzleSize*(rowNr+1))
        angle = random.choice([90,180,270])
        puzzle = image.crop(box).rotate(angle)
        #puzzle.save("puzzle/"+str(colNr)+"_"+str(rowNr)+".jpg")
        resultImage.paste(puzzle,box)
resultImage.save("puzzle.jpg")

