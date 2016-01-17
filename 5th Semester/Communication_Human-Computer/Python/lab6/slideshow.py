# -*- coding: cp1250 -*-
import PyQt4
from PyQt4 import QtGui
import os,sys

class MainWindow(QtGui.QMainWindow):

 def __init__(self):
  super(MainWindow, self).__init__()
  self.initUI()
  self.image = QtGui.QLabel()
  self.listOfImages = []
  self.dirpath = ''
  self.currentImageIndex = 0
  self.filepath = ''
  
 def initUI(self):
     menubar = self.menuBar()
     fileMenu = menubar.addMenu('Plik')
     saveAction = QtGui.QAction('Zapisz',self)
     saveAction.triggered.connect(self.save)
     fileMenu.addAction(saveAction)
     saveAsAction = QtGui.QAction('Zapisz jako...',self)
     saveAsAction.triggered.connect(self.saveas)
     fileMenu.addAction(saveAsAction)

     names = ['explore','prev','nextt','rotate','grey','resize','closee']
     for name in names:
      action = QtGui.QAction(QtGui.QIcon('icons/'+name + '.png'),name, self)
      action.triggered.connect(getattr(self,name))
      toolbar = self.addToolBar(name)
      toolbar.addAction(action)

     self.setGeometry(300, 300, 350, 250)
     self.setWindowTitle('Main window')    
     self.show()
     
 def save(self):
     filename = self.listOfImages[self.currentImageIndex][:self.listOfImages[self.currentImageIndex].index(".")]
     extension = self.listOfImages[self.currentImageIndex][self.listOfImages[self.currentImageIndex].index("."):]
     self.image.pixmap().save(self.filepath[:str(self.filepath).rfind('/')+1]+filename+extension)

 def saveas(self):
     self.filepath = QtGui.QFileDialog.getSaveFileName(self, 'Save file', 
                '/home')
     self.image.pixmap().save(self.filepath)
    

 def explore(self):
    self.listOfImages = []
    self.filepath = QtGui.QFileDialog.getOpenFileName(self, 'Open file', 
                '/home')
    self.dirpath = self.filepath[:str(self.filepath).rfind('/')+1]
    for file in os.listdir(self.dirpath):
     if file.lower().endswith(".jpg") or file.lower().endswith(".bmp") or file.lower().endswith(".png"):
      self.listOfImages.append(file)
    loadedfile = QtGui.QPixmap(self.filepath)
    loadedfilename = self.filepath[str(self.filepath).rfind('/')+1:]
    self.currentImageIndex = self.listOfImages.index(loadedfilename)
    self.image.setPixmap(loadedfile)
    self.setCentralWidget(self.image)
    
 def prev(self):
    if len(self.listOfImages)>0:
     self.currentImageIndex -= 1
     if self.currentImageIndex < 0:
      self.currentImageIndex = len(self.listOfImages)-1
     loadedfile = QtGui.QPixmap(self.dirpath+"/"+self.listOfImages[self.currentImageIndex])
     self.image.setPixmap(loadedfile)
     self.setCentralWidget(self.image)
    
 def nextt(self):
    if len(self.listOfImages)>0:
     self.currentImageIndex += 1
     if self.currentImageIndex >= len(self.listOfImages):
      self.currentImageIndex = 0
     loadedfile = QtGui.QPixmap(self.dirpath+"/"+self.listOfImages[self.currentImageIndex])
     self.image.setPixmap(loadedfile)
     self.setCentralWidget(self.image)
        
 def rotate(self):
    if not self.image.pixmap() is None:
     self.image.setPixmap(self.image.pixmap().transformed(QtGui.QTransform().rotate(90)))
      
 def grey(self):
    if not self.image.pixmap() is None:
     image = self.image.pixmap().toImage()
     for x in range(0,self.image.pixmap().width()):
         for y in range(0,self.image.pixmap().height()):
             colors = QtGui.QColor(image.pixel(x,y)).getRgb()[:3]
             avg = (sum(colors)/len(colors))
             pixelvalue = int(str(hex(avg))[2:]*3,16)
             image.setPixel(x,y,pixelvalue)
     self.image.setPixmap(QtGui.QPixmap.fromImage(image))
             
      
 def resize(self):
    if not self.image.pixmap() is None:
     self.image.setPixmap(self.image.pixmap().scaledToWidth(self.image.pixmap().width()/2))
      
 def closee(self):
    self.close()

def main():
     app = QtGui.QApplication(sys.argv)
     mw = MainWindow()
     sys.exit(app.exec_())

if __name__ == '__main__':
     main()




