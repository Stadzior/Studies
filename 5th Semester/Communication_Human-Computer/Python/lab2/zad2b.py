from pyx import *
from math import *
inputRange = input("Wprowadz liczbe splotow:\n")
c = canvas.canvas()
colours = [color.rgb.red,color.rgb.blue,color.rgb.green]
fCoor = [0,0,5,1,7,6,7,6]
s1Coor = [0,9,1,8.5,3.25,8,3.5,4.5]
s2Coor = [3.5,4.5,3.75,1,6,0,7,0]
tCoor = [0,6,1.5,9,5,10,7,9]
for i in range(0,int(inputRange)-1):
    first = path.curve(fCoor[0]+7*i,
                       fCoor[1],
                       fCoor[2]+7*i,
                       fCoor[3],
                       fCoor[4]+7*i,
                       fCoor[5],
                       fCoor[6]+7*i,
                       fCoor[7])
    second1 = path.curve(s1Coor[0]+7*i,
                       s1Coor[1],
                       s1Coor[2]+7*i,
                       s1Coor[3],
                       s1Coor[4]+7*i,
                       s1Coor[5],
                       s1Coor[6]+7*i,
                       s1Coor[7])
    second2 = path.curve(s2Coor[0]+7*i,
                       s2Coor[1],
                       s2Coor[2]+7*i,
                       s2Coor[3],
                       s2Coor[4]+7*i,
                       s2Coor[5],
                       s2Coor[6]+7*i,
                       s2Coor[7])
    third = path.curve(tCoor[0]+7*i,
                       tCoor[1],
                       tCoor[2]+7*i,
                       tCoor[3],
                       tCoor[4]+7*i,
                       tCoor[5],
                       tCoor[6]+7*i,
                       tCoor[7])
    c.stroke(first,[style.linewidth.THICK,colours[i%3]])
    c.stroke(second1,[style.linewidth.THICK,colours[(i+1)%3]])
    c.stroke(second2,[style.linewidth.THICK,colours[(i+1)%3]])
    c.stroke(third,[style.linewidth.THICK,colours[(i+2)%3]])

c.writePDFfile("warkocze.pdf")

