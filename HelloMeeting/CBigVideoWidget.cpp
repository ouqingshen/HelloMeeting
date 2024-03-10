#include "CBigVideoWidget.h"

CBigVideoWidget::CBigVideoWidget(QWidget* p)
	:QWidget(p)
{
	this->setMinimumSize(800,600);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:rgb(210,220,230)");
}

CBigVideoWidget::~CBigVideoWidget()
{

}

HWND CBigVideoWidget::getHwnd() const
{
	return (HWND)(this->winId());
}
