import sys
from PyQt5 import QtWidgets
from PyQt5.QtWidgets import QDialog, QApplication, QFileDialog
from PyQt5.uic import loadUi
from generate import generate


class MainWindow(QDialog):
    def __init__(self):
        super(MainWindow, self).__init__()
        loadUi("./GUI/xsd2c.ui", self)
        self.browse.clicked.connect(self.browsefiles)
        self.proceed.clicked.connect(self.convert)

    def browsefiles(self):
        fname = QFileDialog.getOpenFileName(
            self, 'C:/Users/lenovo/Desktop', '*.xsd')
        self.filename.setText(fname[0])

    def convert(self):
        xsd = self.filename.toPlainText()
        output = generate(xsd)
        self.View.append(output)


app = QApplication(sys.argv)
widget = QtWidgets.QStackedWidget()
mainwindow = MainWindow()
widget.addWidget(mainwindow)
widget.setFixedWidth(959)
widget.setFixedHeight(872)
widget.setWindowTitle("XSD2CHeader")
widget.show()
try:
    sys.exit(app.exec_())
except:
    print("Exiting")
