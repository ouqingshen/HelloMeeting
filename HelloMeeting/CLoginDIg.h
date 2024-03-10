#pragma once

#include <QtWidgets/QDialog>
#include "ui_CLoginDIg.h"

class CLoginDIg : public QDialog
{
    Q_OBJECT

public:
    CLoginDIg(QWidget *parent = nullptr);
    ~CLoginDIg();
public slots:
    void on_btnJoin_clicked();

private:
    Ui::CLoginDIgClass ui;
};
