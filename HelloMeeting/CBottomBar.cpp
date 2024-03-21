#include "CBottomBar.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <qlabel.h>


CBottomBar::CBottomBar(QWidget* p)
	:QWidget(p)
{
	initUI();
	this->setFixedHeight(90);
	setAttribute(Qt::WA_StyledBackground);
	setStyleSheet("background-color:rgb(255,255,255)");
}

CBottomBar::~CBottomBar()
{
}

void CBottomBar::initUI()
{
    /*
    CBottomBarTool* m_pAudioToolButton = nullptr;
    CBottomBarTool* m_pCameraToolButton = nullptr;
    CBottomBarTool* m_pShareScreenToolButton = nullptr;
    CBottomBarTool* m_pSecurityToolButton = nullptr;
    CBottomBarTool* m_pInvitationToolButton = nullptr;
    CBottomBarTool* m_pManageMemberToolButton = nullptr;
    CBottomBarTool* m_pChatToolButton = nullptr;
    CBottomBarTool* m_pRecordToolButton = nullptr;
    CBottomBarTool* m_pGroupDiscussionToolButton = nullptr;
    CBottomBarTool* m_pApplicationToolButton = nullptr;
    CBottomBarTool* m_pSetToolButton = nullptr;
    CBottomBarTool* m_pFullScreenButton = nullptr;
    CBottomBarTool* m_pEndMeetingButton = nullptr;
     */

   
     m_pAudioToolButton            = new CBottomBarTools(u8"麦克风",":/BottomBar/resources/bottomBar/microphone_on.svg",
        ":/BottomBar/resources/bottomBar/microphone_hover.svg",
        ":/BottomBar/resources/bottomBar/microphone_off.svg",":/BottomBar/resources/bottomBar/microphoneHover_off.svg", true, this);
     m_pCameraToolButton           = new CBottomBarTools(u8"摄像头", ":/BottomBar/resources/bottomBar/Camera.svg",
        ":/BottomBar/resources/bottomBar/Camera.svg",
        ":/BottomBar/resources/bottomBar/Camera.svg", ":/BottomBar/resources/bottomBar/Camera.svg", true, this);
    m_pShareScreenToolButton      = new CBottomBarTools(u8"屏幕共享",":/BottomBar/resources/bottomBar/ScreenShare.svg",
        ":/BottomBar/resources/bottomBar/ScreenShare.svg",
        ":/BottomBar/resources/bottomBar/ScreenShare.svg",":/BottomBar/resources/bottomBar/ScreenShare.svg", true, this);
    m_pSecurityToolButton         = new CBottomBarTools(u8"安全",":/BottomBar/resources/bottomBar/security.svg",
        ":/BottomBar/resources/bottomBar/security.svg",
        ":/BottomBar/resources/bottomBar/security.svg",":/BottomBar/resources/bottomBar/security.svg", true, this);
    m_pInvitationToolButton       = new CBottomBarTools(u8"邀请",":/BottomBar/resources/bottomBar/invite.svg",
        ":/BottomBar/resources/bottomBar/invite.svg",
        ":/BottomBar/resources/bottomBar/invite.svg",":/BottomBar/resources/bottomBar/invite.svg", true, this);
    m_pManageMemberToolButton     = new CBottomBarTools(u8"成员管理",":/BottomBar/resources/bottomBar/memberManagement.svg",
        ":/BottomBar/resources/bottomBar/memberManagement.svg",
        ":/BottomBar/resources/bottomBar/memberManagement.svg",":/BottomBar/resources/bottomBar/memberManagement.svg", true, this);
    m_pChatToolButton             = new CBottomBarTools(u8"聊天",":/BottomBar/resources/bottomBar/chat.svg",
        ":/BottomBar/resources/bottomBar/chat.svg",
        ":/BottomBar/resources/bottomBar/chat.svg",":/BottomBar/resources/bottomBar/chat.svg", true, this);

    m_pGroupDiscussionToolButton  = new CBottomBarTools(u8"群组聊天",":/BottomBar/resources/bottomBar/groupschat.svg",
        ":/BottomBar/resources/bottomBar/groupschat.svg",
        ":/BottomBar/resources/bottomBar/groupschat.svg",":/BottomBar/resources/bottomBar/groupschat.svg.", true, this);
    m_pApplicationToolButton      = new CBottomBarTools(u8"应用",":/BottomBar/resources/bottomBar/application.svg",
        ":/BottomBar/resources/bottomBar/application.svg",
        ":/BottomBar/resources/bottomBar/application.svg",":/BottomBar/resources/bottomBar/application.svg", true, this);
    m_pSetToolButton              = new CBottomBarTools(u8"设置",":/BottomBar/resources/bottomBar/setting.svg",
        ":/BottomBar/resources/bottomBar/setting.svg",
        ":/BottomBar/resources/bottomBar/setting.svg",":/BottomBar/resources/bottomBar/setting.svg", true, this);
    m_pFullScreenButton           = new CBottomBarTools(u8"全屏",":/BottomBar/resources/bottomBar/allScreen.svg",
        ":/BottomBar/resources/bottomBar/allScreen.svg",
        ":/BottomBar/resources/bottomBar/allScreen.svg",":/BottomBar/resources/bottomBar/allScreen.svg", true, this);
   

    

   
   // QVBoxLayout* layout = new QVBoxLayout(this);

    
    QHBoxLayout* layout = new QHBoxLayout(this);
    layout->addWidget(m_pAudioToolButton);
    layout->addWidget(m_pCameraToolButton);
    layout->addStretch();
    layout->addWidget(m_pShareScreenToolButton);
    layout->addWidget(m_pSecurityToolButton);
    layout->addWidget(m_pInvitationToolButton);
    layout->addWidget(m_pManageMemberToolButton);
    layout->addWidget(m_pChatToolButton);

    layout->addWidget(m_pGroupDiscussionToolButton);
    layout->addWidget(m_pApplicationToolButton);
    layout->addWidget(m_pSetToolButton);
    layout->addWidget(m_pFullScreenButton);
    layout->addStretch();
    QPushButton* endingMeeting_button = new QPushButton;
    layout->addStretch();
    endingMeeting_button->setText(u8"结束会议");
    endingMeeting_button->setFixedSize(100,40);
    endingMeeting_button->setStyleSheet("QPushButton { border: 1px solid red; background-color: white; color: red; font: 16px;border-radius: 8px } QPushButton:hover { background-color: red; color: white;border-radius: 8px }");

    layout->addWidget(endingMeeting_button);


    connect(endingMeeting_button,&QPushButton::clicked,this,&CBottomBar::sig_close);
    connect(m_pShareScreenToolButton, &CBottomBarTools::sig_clicked, this, &CBottomBar::sig_shareScreen);


}
