import PyQt4
import sys
from PyQt4 import QtGui
class WindowTitle(QtGui.QWidget):  
 def __init__(self,parent):
  super(WindowTitle, self).__init__(parent)
  self.initUI()

 def initUI(self):
  app = QtGui.QApplication(sys.argv)   
  self.setGeometry(300, 300, 250, 150)
  self.setWindowTitle('Title')
  self.setWindowIcon(QtGui.QIcon('web.png'))        
  self.show()
def main():
  app = QtGui.QApplication(sys.argv)
  wt = WindowTitle()
  sys.exit(app.exec_())

if __name__ == '__main__':
 main()
