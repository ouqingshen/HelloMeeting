#pragma once
#include <qwidget.h>
#include <QLabel>
#include <qpushbutton.h>
class CTitleBar : public QWidget
{
	Q_OBJECT

public:
	CTitleBar(QWidget* p = nullptr);
	~CTitleBar();

private:
	void initUI();

	void mousePressEvent(QMouseEvent* event) override;
	void mouseDoubleClickEvent(QMouseEvent* event);

private slots:
	void onClicked();

signals:
	void sig_close();

private:
	QLabel* m_pLogo;
	QLabel* m_pTitleTextLabel;

	QPushButton* m_pSetBtn;
	QPushButton* m_pMinBtn;
	QPushButton * m_pMaxBtn;
	QPushButton * m_pCloseBtn;


};

