#pragma once
#include <QObject>
#include <QWidget>
#include "CFraneLessWidgetBase.h"
#include "CTitleBar.h"
#include "CLeftVideoList.h"
#include "CBottomBar.h"
#include "CBigVideoWidget.h"
#include "CAgoraObject.h"
class CMainWidget : public CFraneLessWidgetBase
{
	Q_OBJECT


public:
	CMainWidget(QWidget *p =nullptr);
	~CMainWidget();

private:
	void initUI();
private slots:
	void onLocalJoinedSuccess(const QString& qsChannel, unsigned int uid, int elapsed);
	void onRemoteJoined(uid_t uid, int elapsed);

private:
	CTitleBar* m_pTitleBar = nullptr;
	CLeftVideoList* m_pLeftVideoList = nullptr;
	CBottomBar* m_pBottomBar = nullptr;
	CBigVideoWidget* m_pBigVideoWidget = nullptr;
	CAgoraObject* m_pAgora = nullptr;
};

