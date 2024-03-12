#include "CLoginDIg.h"
#include <qdebug.h>
#include <qt_windows.h>
CLoginDIg::CLoginDIg(QWidget *parent)
    : QDialog(parent)
{
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    ui.setupUi(this);

    ui.btnMin->setText("");
    ui.btnMin->setFixedSize(32, 32);
    /*
    ui.btnMin->setStyleSheet(
        "QPushButton{"
        "background-image:url(:/CLoginDIg/resources/login/min.svg);"
        "border:none"
        "}"
        "QPushButton:hover{"
        "background-color:rgb(99,99,99);"
        "background-image:url(:/CLoginDIg/resources/login/min_hover.svg);"
        "border:none"
        "}"
    );
    */

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
        return;
    }
    accept();
}


