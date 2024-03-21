#pragma once

#include <QtWidgets/QDialog>
#include "ui_CLoginDIg.h"

class CLoginDIg : public QDialog
{
    Q_OBJECT

public:
    CLoginDIg(QWidget *parent = nullptr);
    ~CLoginDIg();

    QString getRoomId() const;
    uint getUserName() const;

    void mousePressEvent(QMouseEvent* event) override;

public slots:
    void on_titleBar_clicked();
    void btnJoin_clicked();

private:
    Ui::CLoginDIgClass ui;


};
