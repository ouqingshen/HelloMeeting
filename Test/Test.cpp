#include "Test.h"
#include "qpushbutton.h"

Test::Test(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestClass())
{
    ui->setupUi(this);
   // ui->pushButton->setStyleSheet("QPushButton{background-color:rgb(0,255,255),background-image:url(:/Test/resources/min.svg)}");

}

Test::~Test()
{
    delete ui;
}
