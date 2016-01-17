from math import *
from pyx import *
from fractions import Fraction

a = input("Podaj wspolczynnik a:\n")
b = input("Podaj wspolczynnik b:\n")
c = input("Podaj wspolczynnik c:\n")
g = graph.graphxyz(size=4,x2=None,y2=None)
g.plot(graph.data.paramfunction("k", 0, 2*pi,
                                "x,y,z = cos("+str(a)+"*k), sin("+str(b)+"*k),cos("+str(c)+"*k)"))
g.writePDFfile("lissajous.pdf")
