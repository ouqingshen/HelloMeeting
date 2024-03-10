#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWidget.h"
#include "CTitleBar.h"
#include "CFraneLessWidgetBase.h"

class MainWidget : public CFraneLessWidgetBase
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);


private:
    void initUI();
private slots:

    void on_closeSlot();


private:
    CTitleBar* m_pTitleBar = nullptr;
};
