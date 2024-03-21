#include "CLeftVideoList.h"
#include <QVBoxLayout>
#include "commons.h"


CLeftVideoList::CLeftVideoList(QWidget* p)
	:QWidget(p)
{
	this->setFixedWidth(SMALL_VIDEO_WIDTH+10);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:rgb(255,255,255)");

	m_pListWidget = new QListWidget(this);
	m_pListWidget->setStyleSheet("background-color:rgb(241, 245, 249)");

	QVBoxLayout* pVlay = new QVBoxLayout(this);
	pVlay->addWidget(m_pListWidget);
	pVlay->setContentsMargins(5, 5, 5, 5);

}

CLeftVideoList::~CLeftVideoList()
{

}

void CLeftVideoList::addVideoWidget(CSmallVideoWidget * pSmall)
{
	
	QListWidgetItem* pItem = new QListWidgetItem();
	m_pListWidget->addItem(pItem);
	m_pListWidget->setItemWidget(pItem,pSmall);

	
	
}
