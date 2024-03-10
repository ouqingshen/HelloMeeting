#include "CFraneLessWidgetBase.h"
#include <qt_windows.h>
#include <windows.h>
#include <windowsx.h>

CFraneLessWidgetBase::CFraneLessWidgetBase(QWidget* p)
{
    this->setWindowFlags(Qt::FramelessWindowHint | Qt::WindowMinMaxButtonsHint);
    setAttribute(Qt::WA_Hover);
}

bool CFraneLessWidgetBase::nativeEvent(const QByteArray& eventType, void* message, long* result)
{
    int m_nBorder = 5;
    Q_UNUSED(eventType)
        MSG* param = static_cast<MSG*>(message);

    switch (param->message)
    {
    case WM_NCHITTEST:
    {
        int nX = GET_X_LPARAM(param->lParam) - this->geometry().x();
        int nY = GET_Y_LPARAM(param->lParam) - this->geometry().y();

        *result = HTCAPTION;

        // if mouse in the border of mainframe,we zoom mainframe
        if ((nX > 0) && (nX < m_nBorder))
            *result = HTLEFT;

        if ((nX > this->width() - m_nBorder) && (nX < this->width()))
            *result = HTRIGHT;

        if ((nY > 0) && (nY < m_nBorder))
            *result = HTTOP;

        if ((nY > this->height() - m_nBorder) && (nY < this->height()))
            *result = HTBOTTOM;

        if ((nX > 0) && (nX < m_nBorder) && (nY > 0)
            && (nY < m_nBorder))
            *result = HTTOPLEFT;

        if ((nX > this->width() - m_nBorder) && (nX < this->width())
            && (nY > 0) && (nY < m_nBorder))
            *result = HTTOPRIGHT;

        if ((nX > 0) && (nX < m_nBorder)
            && (nY > this->height() - m_nBorder) && (nY < this->height()))
            *result = HTBOTTOMLEFT;

        if ((nX > this->width() - m_nBorder) && (nX < this->width())
            && (nY > this->height() - m_nBorder) && (nY < this->height()))
            *result = HTBOTTOMRIGHT;

        if (*result == HTCAPTION)
        {
            return false;
        }
        return true;
    }
    }
    return QWidget::nativeEvent(eventType, message, result);

}