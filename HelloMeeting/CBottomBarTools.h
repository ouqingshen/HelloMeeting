#pragma once
#include <QToolButton>
#include <QEvent>
class CBottomBarTools :
    public QToolButton
{
    Q_OBJECT



public:
    CBottomBarTools(QString text,QString normalImageUrl, QString normalImageHoverUrl,
        QString clickedImageUrl,QString clickedImageHoverUrl,bool clicked,QWidget* parent);
    ~CBottomBarTools();

    bool event(QEvent* e) override;
    void setOpen(bool open) {
        m_StateOpen = open;
    }


signals:
    void sig_clicked();

private:
    QString m_text;
    QString m_normalImageUrl;
    QString m_normalImageHoverUrl;
    QString m_clickedImageUrl;
    QString m_clickedImageHoverUrl;


    bool m_StateOpen = false;
};

