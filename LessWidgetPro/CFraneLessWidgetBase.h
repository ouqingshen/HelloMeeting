#pragma once
#include <qwidget.h>
class CFraneLessWidgetBase :
    public QWidget
{


public:
    CFraneLessWidgetBase(QWidget* p = nullptr);
    ~CFraneLessWidgetBase() {};


private:
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;

};

