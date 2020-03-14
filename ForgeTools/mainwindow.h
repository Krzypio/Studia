#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "stankuznia.h"
#include "stanmagazyn.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

//! [0]
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

/*protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
//! [0]
*/
//! [1]
private slots:
    void magazyn();
    void kuznia();
//! [1]

//! [2]
private:
    void createActions();
    void createMenus();
//! [2]

//! [3]
    QMenu *fileMenu;
    QAction *magazynAct;
    QAction *kuzniaAct;
    QLabel *infoLabel;
    StanKuznia *kuzniaWidget;
    StanMagazyn *magazynWidget;
};
//! [3]

#endif
