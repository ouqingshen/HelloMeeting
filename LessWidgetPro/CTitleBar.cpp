#include "CTitleBar.h"
#include <QHBoxLayout>
#include <qt_windows.h>

CTitleBar::CTitleBar(QWidget* p)
{
	setAttribute(Qt::WA_StyledBackground, true);
	
	initUI();
}

CTitleBar::~CTitleBar()
{
}

void CTitleBar::initUI()
{
	setAttribute(Qt::WA_StyledBackground);
	this->setFixedHeight(32 + 5 * 2);
	this->setStyleSheet("background-color:rgb(54,54,54)");
	m_pLogo = new QLabel(this);
	m_pLogo->setFixedSize(32, 32);
	m_pLogo->setStyleSheet("background-image:url(:/MainWidget/resources/logo.png)");
	m_pTitleTextLabel = new QLabel(this);
	m_pTitleTextLabel->setText(u8"HelloMeeting");
	m_pTitleTextLabel->setFixedWidth(120);


	m_pMinBtn = new QPushButton(this);
	m_pMinBtn->setFixedSize(32,32);

	m_pMaxBtn = new QPushButton(this);
	m_pMaxBtn->setFixedSize(32, 32);
	m_pMaxBtn->setStyleSheet("QPushButton{background-image:url(:/MainWidget/resources/max.svg);border:none}");

	m_pCloseBtn = new QPushButton(this);
	m_pCloseBtn->setFixedSize(32, 32);
	m_pCloseBtn->setStyleSheet("");


	QHBoxLayout* pHlay = new QHBoxLayout(this);
	pHlay->addWidget(m_pLogo);
	pHlay->addWidget(m_pTitleTextLabel);
	pHlay->addStretch();
	pHlay->addWidget(m_pMinBtn);
	pHlay->addWidget(m_pMaxBtn);
	pHlay->addWidget(m_pCloseBtn);

	pHlay->setContentsMargins(5,5,5,5);

	connect(m_pMinBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pMaxBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);
	connect(m_pCloseBtn, &QPushButton::clicked, this, &CTitleBar::onClicked);

}

void CTitleBar::mousePressEvent(QMouseEvent* event)
{
	if (ReleaseCapture())
	{
		QWidget* pWindow = this->window();
		if (pWindow->isTopLevel())
		{
			SendMessage(HWND(pWindow->winId()),WM_SYSCOMMAND,SC_MOVE+HTCAPTION,0);
		}
	}
}
void CTitleBar::mouseDoubleClickEvent(QMouseEvent* event)
{
	m_pMaxBtn->click();
}
void CTitleBar::onClicked() {
	QPushButton* pButton = qobject_cast<QPushButton*>(sender());
	QWidget* pWindow = this->window();
	if (pButton==m_pMaxBtn)
	{
		if (pWindow->isMaximized())
		{
			pWindow->showNormal();
		}
		else {
			pWindow->showMaximized();
		}
	}
	else if (pButton==m_pMinBtn)
	{
		pWindow->showMinimized();
	}
	else if (pButton==m_pCloseBtn)
	{
		emit &CTitleBar::sig_close;
	}
}
