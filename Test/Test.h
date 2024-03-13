#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Test.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TestClass; };
QT_END_NAMESPACE

class Test : public QMainWindow
{
    Q_OBJECT

public:
    Test(QWidget *parent = nullptr);
    ~Test();

private:
    Ui::TestClass *ui;
};
