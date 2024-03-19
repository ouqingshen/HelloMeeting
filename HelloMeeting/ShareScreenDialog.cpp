#include "ShareScreenDialog.h"
#include <QVBoxLayout>
#include <QHBoxLayout>





ShareScreenDialog::ShareScreenDialog(QDialog* parent)
	:QDialog(parent)
{
	this->overrideWindowFlags(Qt::SubWindow|Qt::Tool);
	this->setAttribute(Qt::WA_StyledBackground);

	m_pTitleWidget = new QWidget(this);
	m_pTitleWidget->setFixedHeight(42);
	m_pTitleWidget->setStyleSheet("backgroud-color:rgb(54,54,54)");

	setWindowTitle(u8"请选择需要共享的内容");

	m_pLabel_Screen = new QLabel(this);
	m_pLabel_Screen->setText(u8"桌面");
	QVBoxLayout* vBoxLayout = new QVBoxLayout(this);
	

	

	int LWSPACE = 20;
	m_pLWScreen = new QListWidget(this);
	m_pLWScreen->setSpacing(LWSPACE);
	int w1 = SHARE_WINDOW_ITEM_WIDTH * 4 + 5 * LWSPACE;
	int h1 = SHARE_WINDOW_ITEM_HENGHT + 45 + LWSPACE * 2 + 10;
	m_pLWScreen->setFixedSize(w1,h1);
	m_pLWScreen->setIconSize(QSize(SHARE_WINDOW_ITEM_WIDTH,SHARE_WINDOW_ITEM_HENGHT+45));
	m_pLWScreen->setViewMode(QListView::IconMode);
	m_pLWScreen->setWrapping(true);
	m_pLWScreen->setFlow(QListView::LeftToRight);


	m_pLabel_APP = new QLabel(this);
	m_pLabel_APP->setText(u8"应用");

	m_pLWAPP = new QListWidget(this);
	m_pLWAPP->setSpacing(LWSPACE);

	m_pLWAPP->setFixedSize(w1, h1);
	m_pLWAPP->setIconSize(QSize(SHARE_WINDOW_ITEM_WIDTH, SHARE_WINDOW_ITEM_HENGHT + 45));
	m_pLWAPP->setViewMode(QListView::IconMode);
	m_pLWAPP->setWrapping(true);
	m_pLWAPP->setFlow(QListView::LeftToRight);

	m_pBtnStart = new QPushButton(this);
	m_pBtnStart->setText(u8"开始共享");

	m_pBtnCancel = new QPushButton(this);
	m_pBtnCancel->setText(u8"取消");

	vBoxLayout->addWidget(m_pLabel_Screen);
	vBoxLayout->addWidget(m_pLWScreen);
	vBoxLayout->addWidget(m_pLabel_APP);
	vBoxLayout->addWidget(m_pLWAPP);
	vBoxLayout->addWidget(m_pLWAPP);
	vBoxLayout->addWidget(m_pBtnStart);
	vBoxLayout->addWidget(m_pBtnCancel);

	connect(m_pBtnCancel,&QPushButton::clicked,this,&ShareScreenDialog::onCancel);

	connect(m_pBtnStart,&QPushButton::clicked,this,&ShareScreenDialog::onStartShare);
	
	connect(m_pLWScreen,&QListWidget::itemClicked,this,&ShareScreenDialog::onDesktopItemSelected);
	connect(m_pLWAPP,&QListWidget::itemClicked,this,&ShareScreenDialog::onAppItemSelected);

}

ShareScreenDialog::~ShareScreenDialog()
{
}

void ShareScreenDialog::initListWidget(const VecWindowShareInfo& vec)
{
	int desktopId = 0;
	int appId = 0;
	for (auto ele:vec)
	{
		string namestr(ele.name);
		QListWidgetItem* it1 = new QListWidgetItem(QIcon(ele.pixmap), QString::fromStdString(ele.name));
		it1->setSizeHint(QSize(SHARE_WINDOW_ITEM_WIDTH, SHARE_WINDOW_ITEM_HENGHT + 45));

		if (ele.windowType==window_share_info::Screen)
		{
			m_pLWScreen->addItem(it1);
			m_mapScreen[desktopId] = ele.hwmd;
			desktopId++;
		}
		else
		{
			m_pLWAPP->addItem(it1);
			m_mapApp[appId] = ele.hwmd;
			appId++;
		}
	}


}

void ShareScreenDialog::clearMap()
{
	m_mapApp.clear();
	m_mapScreen.clear();
	close();
	
}

void ShareScreenDialog::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) {
		// 记录鼠标点击时的位置
		mousePos = event->globalPos();
		// 记录窗口当前的位置
		windowPos = this->pos();
		// 计算鼠标相对于窗口的位置
		dPos = mousePos - windowPos;
	}
}

void ShareScreenDialog::mouseMoveEvent(QMouseEvent* event)
{
	if (event->buttons() & Qt::LeftButton) {
		// 计算窗口应该移动到的位置
		QPoint newPos = event->globalPos() - dPos;
		// 移动窗口
		this->move(newPos);
	}
}




void ShareScreenDialog::onClose()
{
	this->close();
}

void ShareScreenDialog::onCancel()
{
	clearMap();
	
}

void ShareScreenDialog::onStartShare()
{
	void* hwnd = NULL;
	switch (m_selectedType)
	{
	case 0:
	{
		int shareIndex = m_pLWScreen->currentIndex().row();
		hwnd = m_mapScreen[shareIndex];
	}
	break;
	case 1:
	{
		int shareIndx = m_pLWAPP->currentIndex().row();
		hwnd = m_mapApp[shareIndx];
	}

	break;
	default:
		break;
	}
	emit sig_StartShare(m_selectedType,hwnd);
	clearMap();
	close();
}

void ShareScreenDialog::onDesktopItemSelected()
{
	m_selectedType = 0;
}

void ShareScreenDialog::onAppItemSelected()
{
	m_selectedType = 1;
}
