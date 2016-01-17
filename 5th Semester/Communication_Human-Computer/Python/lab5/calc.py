# -*- coding: utf-8 -*-
import sys
from PyQt4 import QtGui
from random import randint



class MainWindow(QtGui.QMainWindow):  
 def __init__(self):
  super(MainWindow, self).__init__()
  self.initUI()
  
 def initUI(self):
    self.setGeometry(800,400, 350, 250)
    self.setWindowTitle('Kalkulator')
    self.setWindowIcon(QtGui.QIcon('web.png'))
    self.menuBar().addMenu('Widok')
    self.menuBar().addMenu('Edycja')
    self.menuBar().addMenu('Pomoc')
    centralWidget = QtGui.QWidget()
    names=['',
           'MC', 'MR', 'MS', 'M+','M-',
           '<-', 'CE', 'C', '+/-', 'sqrt',
           '7','8', '9', '/','%',
           '4', '5', '6', '*','1/x',
           '1', '2', '3','-','=',
           '0','',',','+','']
    grid = QtGui.QGridLayout()
    j = 0
    pos = [(0,0),
           (1,0), (1,1), (1,2), (1,3),(1,4),
           (2,0), (2,1), (2,2), (2,3),(2,4),
           (3,0), (3,1), (3,2), (3,3),(3,4),
           (4,0), (4,1), (4,2), (4,3),(4,4),
           (5,0), (5,1), (5,2), (5,3),(5,4),
           (6,0), (6,1), (6,2), (6,3),(6,4)]
    
    for i in names:
     button = QtGui.QPushButton(i)
     if i=='':
        grid.addWidget(QtGui.QLCDNumber(),0,4)
     else:
        grid.addWidget(button, pos[j][0], pos[j][1])
     j = j + 1
    centralWidget.setLayout(grid)
    self.setCentralWidget(centralWidget)
    self.show()

def main():
 app = QtGui.QApplication(sys.argv)
 mw = MainWindow()
 sys.exit(app.exec_())

if __name__ == '__main__':
 main() 
