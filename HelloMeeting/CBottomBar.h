#pragma once
#include <qwidget.h>
#include <QPushButton>
#include "CBottomBarTools.h"

class CBottomBar :
    public QWidget
{
    Q_OBJECT

public:
    CBottomBar(QWidget * p=nullptr);
    ~CBottomBar();
    
signals:
    void sig_close();
    void sig_shareScreen();
private :
    void initUI();

private:

    CBottomBarTools* m_pAudioToolButton = nullptr;
    CBottomBarTools* m_pCameraToolButton = nullptr;
    CBottomBarTools* m_pShareScreenToolButton = nullptr;
    CBottomBarTools* m_pSecurityToolButton = nullptr;
    CBottomBarTools* m_pInvitationToolButton = nullptr;
    CBottomBarTools* m_pManageMemberToolButton = nullptr;
    CBottomBarTools* m_pChatToolButton = nullptr;
    CBottomBarTools* m_pRecordToolButton = nullptr;
    CBottomBarTools* m_pGroupDiscussionToolButton = nullptr;
    CBottomBarTools* m_pApplicationToolButton = nullptr;
    CBottomBarTools* m_pSetToolButton = nullptr;
    CBottomBarTools* m_pFullScreenButton = nullptr;
    CBottomBarTools* m_pEndMeetingButton = nullptr;
   
};

