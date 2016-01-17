import PyQt4
import sys
from PyQt4 import QtGui
class WindowColor(QtGui.QWidget):  
 def __init__(self):
  super(WindowColor, self).__init__()
  self.initUI()

 def initUI(self):      
  self.setGeometry(300, 300, 250, 150)
  self.setWindowTitle('Color')
  self.setWindowIcon(QtGui.QIcon('web.png'))        
  self.show()

def main():
 app = QtGui.QApplication(sys.argv)
 ex = WindowColor()
 sys.exit(app.exec_())

if __name__ == '__main__':
 main() 
