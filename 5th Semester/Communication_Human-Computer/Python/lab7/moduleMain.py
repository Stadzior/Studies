# -*- coding: cp1250 -*-
import PyQt4
from PyQt4 import QtGui
import sys
import dialogWindowTitle
import dialogWindowColor
import dialogWindowIcon

class MainWindow(QtGui.QMainWindow):
 def __init__(self):
  super(MainWindow, self).__init__()
  self.initUI()

 def initUI(self):               
     label = QtGui.QLabel()
     label.setStyleSheet("QLabel { background-color: rgba(0,255,0); }")
     self.setCentralWidget(label)
     dialogWindowTitle = QtGui.QAction('Nazwa okna glownego', self)
     dialogWindowTitle.setStatusTip('window title')
     dialogWindowTitle.triggered.connect(self.showWindowTitle)
     dialogWindowColor = QtGui.QAction('Ustaw kolor tla', self)
     dialogWindowColor.setStatusTip('window color')
     dialogWindowColor.triggered.connect(self.showWindowColor)
     dialogWindowIcon = QtGui.QAction('Zmień ikone', self)
     dialogWindowIcon.setStatusTip('window icon')
     dialogWindowIcon.triggered.connect(self.showWindowIcon)
     menubar = self.menuBar()
     fileMenu = menubar.addMenu('Dialog')
     fileMenu.addAction(dialogWindowTitle)
     fileMenu.addAction(dialogWindowColor)
     fileMenu.addAction(dialogWindowIcon)
     self.setGeometry(300, 300, 350, 250)
     self.setWindowTitle('Main window')    
     self.show()
     
 def showWindowTitle(self):
     wt = dialogWindowTitle.WindowTitle(self)


 def showWindowColor(self):
     wc = dialogWindowColor.WindowColor()


 def showWindowIcon(self):
     wi = dialogWindowIcon.WindowIcon()  


def main():
  app = QtGui.QApplication(sys.argv)
  mw = MainWindow()
  sys.exit(app.exec_())

if __name__ == '__main__':
 main()




