#include "CLoginDIg.h"
#include <qdebug.h>
#include <qt_windows.h>
#include <qmessagebox.h>
#include <QGraphicsDropShadowEffect>
CLoginDIg::CLoginDIg(QWidget *parent)
    : QDialog(parent)
{

    setWindowIcon(QIcon(":/CLoginDIg/resources/login/logo.png"));
    setProperty("inheritStyle", false);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    ui.setupUi(this);
    ui.widget_right->setStyleSheet("background-image: url(:/CLoginDIg/resources/login/login_right.jpg)");
 
    ui.lineEdit_roomId->setText("10001");
    ui.lineEdit_pwd->setFixedHeight(40);
    ui.lineEdit_roomId->setFixedHeight(40);
    ui.lineEdit_userName->setFixedHeight(40);

    ui.btnJoin->setFixedHeight(50);

    ui.label_logo->setText("");
    QPixmap pixmap(":/CLoginDIg/resources/login/logo.png");
    pixmap = pixmap.scaled(40, 40, Qt::KeepAspectRatio, Qt::SmoothTransformation);  // 保持比例缩放
    ui.label_logo->setPixmap(pixmap);

    ui.btnMin->setText("");
    ui.btnClose->setText("");
    ui.btnMin->setFixedSize(32,32);
    ui.btnClose->setFixedSize(32,32);


    connect(ui.btnMin,&QPushButton::clicked,this,&CLoginDIg::on_titleBar_clicked);
    connect(ui.btnClose,&QPushButton::clicked,this,&CLoginDIg::on_titleBar_clicked);
}

CLoginDIg::~CLoginDIg()
{}

QString CLoginDIg::getRoomId() const
{
    return ui.lineEdit_roomId->text();
}

void CLoginDIg::mousePressEvent(QMouseEvent* event)
{
    if (ReleaseCapture())
    {
        QWidget* pWindow = this->window();
        if (pWindow->isTopLevel())
        {
            SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
        }
    }
}


void CLoginDIg::on_btnJoin_clicked() {
    QString roomId = ui.lineEdit_roomId->text();
    if (roomId.isEmpty())
    {
        QMessageBox::warning(this, u8"警告", u8"会议号不能为空！！！！！");
        return;
    }
    accept();
}

void CLoginDIg::on_titleBar_clicked() {
    QPushButton* p_button = qobject_cast<QPushButton*>(sender());
    QWidget* t_window = this->window();
    if (p_button==ui.btnMin)
    {
        t_window->showMinimized();
    }
    else if (p_button==ui.btnClose)
    {
        t_window->close();
    }
  
}