from math import *
from pyx import *
from fractions import Fraction
import PyQt4
import sys
from PyQt4 import QtGui

class MainWindow(QtGui.QMainWindow):  
 def __init__(self):
  super(MainWindow, self).__init__()
  self.initUI()
 def initUI(self):      
  self.setGeometry(300, 300, 250, 150)
  self.setWindowTitle('Lissajiou')
  self.setWindowIcon(QtGui.QIcon('web.png'))
  self.xSlider = QtGui.QSlider('X')
  self.ySlider = QtGui.QSlider('Y')
  self.generateButton = QtGui.QButton('GENERUJ')
  self.show()

 def generate(self):
    a = input("Podaj wspolczynnik a:\n")
    b = input("Podaj wspolczynnik b:\n")
    c = 1
    g = graph.graphxyz(size=4,x2=None,y2=None)
    g.plot(graph.data.paramfunction("k", 0, 2*pi,
                                "x,y,z = cos("+str(a)+"*k), sin("+str(b)+"*k),cos("+str(c)+"*k)"))
    g.writePDFfile("lissajous.pdf")


def main():
 app = QtGui.QApplication(sys.argv)
 ex = MainWindow()
 sys.exit(app.exec_())

if __name__ == '__main__':
 main() 

