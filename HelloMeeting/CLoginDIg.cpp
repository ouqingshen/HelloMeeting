#include "CLoginDIg.h"
#include <qdebug.h>

CLoginDIg::CLoginDIg(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

CLoginDIg::~CLoginDIg()
{}

void CLoginDIg::on_btnJoin_clicked() {

    accept();
}
