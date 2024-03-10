#include "CMainWidget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QMessageBox>

CMainWidget::CMainWidget(QWidget* p)
	:CFraneLessWidgetBase(p)
{
	initUI();

	m_pAgora = new CAgoraObject();

	if (0 != m_pAgora->init()) {
		QMessageBox::information(this, u8"提示", u8"agora init failure!");
		exit(EXIT_FAILURE);
	}
	connect(m_pAgora, &CAgoraObject::sender_joinedChannelSuccess, this, &CMainWidget::onLocalJoinedSuccess);
	connect(m_pAgora, &CAgoraObject::sender_userJoined, this, &CMainWidget::onRemoteJoined);

}

CMainWidget::~CMainWidget()
{
}

void CMainWidget::initUI()
{
	m_pTitleBar = new CTitleBar(this);
	m_pLeftVideoList = new CLeftVideoList(this);
	m_pBigVideoWidget = new CBigVideoWidget(this);
	m_pBottomBar = new CBottomBar(this);

	QVBoxLayout* mainVlay = new QVBoxLayout(this);
	mainVlay->setSpacing(0);
	mainVlay->addWidget(m_pTitleBar);

	QHBoxLayout* pHLay = new QHBoxLayout(this);

	pHLay->addWidget(m_pLeftVideoList);
	pHLay->addWidget(m_pBigVideoWidget);

	mainVlay->addLayout(pHLay);
	mainVlay->addWidget(m_pBottomBar);

	mainVlay->setContentsMargins(0, 0, 0, 0);
}

//本地加入成功
void CMainWidget::onLocalJoinedSuccess(const QString& qsChannel, unsigned int uid, int elapsed)
{
	HWND hwnd = (HWND)(ui.widget_local->winId());

	BOOL previewSuccess = m_pAgora->LocalVideoPreview(hwnd, true);
	if (!previewSuccess) {
		qDebug() << u8"预览失败";
	}
	else
	{
		qDebug() << u8"预览成功";
	}

}
//远程用户加入房间
void CMainWidget::onRemoteJoined(uid_t uid, int elapsed)
{
	m_pAgora->RemoteVideoRender(uid, (HWND)(ui.widget_remote->winId()));
}
