#include "CMainWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>
#include "CSmallVideoWidget.h"
#include "qscreen.h"
#include <iostream>
#include "commons.h"
#include "ShareScreenDialog.h"
#include <QScreen>  
#include <QApplication>
#include <QTime>

CMainWidget::CMainWidget(QWidget* p)
	:CFraneLessWidgetBase(p)
{
	initUI();
	setWindowIcon(QIcon(":/CLoginDIg/resources/login/logo.png"));
	m_pAgora = new CAgoraObject();

	if (0 != m_pAgora->init()) {
		QMessageBox::information(this, u8"提示", u8"agora init failure!");
		exit(EXIT_FAILURE);
	}

	connect(m_pAgora, &CAgoraObject::sender_joinedChannelSuccess, this, &CMainWidget::onLocalJoinedSuccess);
	connect(m_pAgora, &CAgoraObject::sender_userJoined, this, &CMainWidget::onRemoteJoined);
	connect(m_pTitleBar, &CTitleBar::sig_close, this, [&](){
		close();
		});
}

CMainWidget::~CMainWidget()
{
	if (m_pAgora)
	{
		delete m_pAgora;
		m_pAgora = nullptr;
	}
}

void CMainWidget::joinRoom(const QString roomId, const uint userName)
{
	m_pAgora->joinChannel(roomId, userName);
}

void CMainWidget::resizeEvent(QResizeEvent* event)
{
	static QTime time = QTime();
	time.restart();

	int w = this->width();
	int h = this->height();
	QScreen* screen = QApplication::primaryScreen();
	if (!this->isMaximized() && time.elapsed() > 300)
	{
		this->move((screen->size().width() - w) / 2, (screen->size().height() - h) / 2);
		time.restart();
		//resize(w * 1.1, h * 1.1);
	}

}
void CMainWidget::wheelEvent(QWheelEvent* event)
{
	/*if (event->modifiers()) {
		int delta = event->angleDelta().y();
		if (delta > 0) {
			resize(width() * 1.1, height() * 1.1);
		}
		else if (delta < 0) {
			resize(width() * 0.9, height() * 0.9);
		}
	}*/
}
void CMainWidget::initUI()
{
	m_pTitleBar = new CTitleBar(this);
	this->setFocusPolicy(Qt::StrongFocus);
	m_pLeftVideoList = new CLeftVideoList(this);
	m_pBigVideoWidget = new CBigVideoWidget(this);
	m_pBottomBar = new CBottomBar(this);

	QVBoxLayout* mainVlay = new QVBoxLayout(this);
	mainVlay->setSpacing(0);
	mainVlay->addWidget(m_pTitleBar);

	QHBoxLayout* pHLay = new QHBoxLayout(this);
	QVBoxLayout* pCenter = new QVBoxLayout(this);
	pCenter->addWidget(m_pBigVideoWidget);
	pCenter->addWidget(m_pBottomBar);

	pHLay->addWidget(m_pLeftVideoList);
	pHLay->addLayout(pCenter);
	//pHLay->addWidget(m_pBigVideoWidget);

	mainVlay->addLayout(pHLay);
	//mainVlay->addWidget(m_pBottomBar);

	mainVlay->setContentsMargins(5, 5, 5, 5);

	connect(m_pBottomBar,&CBottomBar::sig_close,this,&CMainWidget::onEndMeeting);
	connect(m_pBottomBar, &CBottomBar::sig_shareScreen,this,&CMainWidget::on_ShareScreen);


}



//本地加入成功
void CMainWidget::onLocalJoinedSuccess(const QString& qsChannel, unsigned int uid, int elapsed)
{
	m_pAgora->LocalVideoPreview(m_pBigVideoWidget->getHwnd(), true);

}
//远程用户加入房间
void CMainWidget::onRemoteJoined(uid_t uid, int elapsed)
{
	CSmallVideoWidget* pSmall = new CSmallVideoWidget();
	m_pLeftVideoList->addVideoWidget(pSmall);

	m_pAgora->RemoteVideoRender(uid, (HWND)(pSmall->winId()));
}

void CMainWidget::onEndMeeting()
{

	close();

}

void CMainWidget::on_ShareScreen()
{
	VecWindowShareInfo vecWindowShare;
	m_pAgora->shareScreen(vecWindowShare);
	ShareScreenDialog* share = new ShareScreenDialog;
	share->initListWidget(vecWindowShare);


	connect(share,&ShareScreenDialog::sig_StartShare,this,&CMainWidget::startShareScreen);
	connect(share,&ShareScreenDialog::sig_StopShare,this,&CMainWidget::stopShareScreen);
	share->exec();
}

void CMainWidget::startShareScreen(int type,void* hwnd)
{
	if (0!=m_pAgora->start_share_screen(type,hwnd))
	{
		QMessageBox::information(this, u8"提示", u8"共享屏幕失败");
	}

}

void CMainWidget::stopShareScreen()
{
	if (0!=m_pAgora->stop_share_window())
	{
		QMessageBox::information(this, u8"提示", u8"取消失败");
	}
}
