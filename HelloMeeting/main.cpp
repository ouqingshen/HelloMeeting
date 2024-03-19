#include "CLoginDIg.h"
#include <QtWidgets/QApplication>
#include "CMainWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CLoginDIg w;
    CMainWidget mainw;

    if (w.exec()== QDialog::Accepted)
    {
        mainw.show();
        mainw.joinRoom(w.getRoomId());
        return a.exec();
    }
    return 0;
}
