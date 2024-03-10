/*
左边的视频列表窗口
*/

#pragma once
#include <qwidget.h>
#include <QListWidget>

class CLeftVideoList :
    public QWidget
{
    Q_OBJECT

public:
    CLeftVideoList(QWidget* p=nullptr);
    ~CLeftVideoList();


    void addVideoWidget();

private:
    QListWidget* m_pListWidget = nullptr;

};

