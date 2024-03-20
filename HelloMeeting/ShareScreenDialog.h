#pragma once
#include <QDialog>
#include <QListWidget>
#include "commons.h"
#include <qlabel.h>
#include <qpushbutton.h>
#include <QMouseEvent>
class ShareScreenDialog:public QDialog
{
	Q_OBJECT

public:
	ShareScreenDialog(QDialog* parent=nullptr);
	~ShareScreenDialog();
	void initListWidget(const VecWindowShareInfo& vec);
private:
	void clearMap();
	
	void mousePressEvent(QMouseEvent* event)override;
	void mouseMoveEvent(QMouseEvent* event)override;

signals:
	void sig_StartShare(int type,void* hwnd);
	void sig_StopShare();

private slots:
	void onClose();
	void onCancel();
	void onStartShare();
	void onDesktopItemSelected();
	void onAppItemSelected();

private:
	QWidget* m_pTitleWidget = nullptr;
	QLabel* m_pTitleLabel = nullptr;
	QPushButton* m_pBtnMin = nullptr;
	QPushButton* m_pBtnClose = nullptr;
	QLabel* m_pLabel_Screen = nullptr;
	QListWidget* m_pLWScreen = nullptr;
	QLabel* m_pLabel_APP = nullptr;
	QListWidget* m_pLWAPP = nullptr;
	QPushButton* m_pBtnCancel = nullptr;
	QPushButton* m_pBtnStart = nullptr;


	QPoint windowPos;
	QPoint mousePos;
	QPoint dPos;


	int m_selectedType = -1;
	map<int, void*> m_mapScreen;
	map<int, void*> m_mapApp;

};

