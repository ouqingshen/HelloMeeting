#include "CSmallVideoWidget.h"
#include "commons.h"


CSmallVideoWidget::CSmallVideoWidget(QWidget* p)
	:QWidget(p)
{
	this->setFixedSize(SMALL_VIDEO_WIDTH,SMALL_VIDEO_HEIGHT);
}

CSmallVideoWidget::~CSmallVideoWidget()
{
	
}
