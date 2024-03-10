#include "CBottomBar.h"

CBottomBar::CBottomBar(QWidget* p)
	:QWidget(p)
{
	this->setFixedHeight(100);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:rgb(220,230,240)");
}

CBottomBar::~CBottomBar()
{
}
