#include "CBigVideoWidget.h"

CBigVideoWidget::CBigVideoWidget(QWidget* p)
	:QWidget(p)
{
	setAttribute(Qt::WA_OpaquePaintEvent);
	this->setMinimumSize(800,600);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:rgb(210,220,230)");
	this->setContentsMargins(0, 0, 0, 0);
}

CBigVideoWidget::~CBigVideoWidget()
{

}

HWND CBigVideoWidget::getHwnd() const
{
	return (HWND)(this->winId());
}
