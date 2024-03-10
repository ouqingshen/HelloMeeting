#pragma once
#include <qwidget.h>
class CBigVideoWidget :public QWidget
{
	Q_OBJECT

public:
	CBigVideoWidget(QWidget* p = nullptr);
	~CBigVideoWidget();

	HWND getHwnd() const;

private:

};

