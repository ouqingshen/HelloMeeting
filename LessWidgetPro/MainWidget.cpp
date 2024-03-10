#include "MainWidget.h"
#include <QVBoxLayout>
#include <qmessagebox.h>



MainWidget::MainWidget(QWidget *parent)
    : CFraneLessWidgetBase(parent)
{
    this->setWindowFlags(Qt::FramelessWindowHint| Qt::WindowMinMaxButtonsHint);
   setAttribute(Qt::WA_Hover);
    initUI();
}

void MainWidget::initUI()
{
    m_pTitleBar = new CTitleBar(this);

    QWidget* w = new QWidget(this);
    w->setFixedSize(800,600);

    QVBoxLayout* pVlay = new QVBoxLayout(this);
    pVlay->addWidget(m_pTitleBar);
    pVlay->addWidget(w);
    pVlay->addStretch();
   pVlay->setContentsMargins(0,0,0,0);

   connect(m_pTitleBar,&CTitleBar::sig_close,this,&MainWidget::on_closeSlot);
}

void MainWidget::on_closeSlot() {
    QMessageBox::StandardButton _exit = QMessageBox::warning(this, u8"提示", u8"确定要退出吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);

    if (_exit==QMessageBox::Yes)
    {
        close();
    }
     
}