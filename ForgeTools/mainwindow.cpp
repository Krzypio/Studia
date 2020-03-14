#include <QtWidgets>

#include "mainwindow.h"

//! [0]
MainWindow::MainWindow()
{
    //initialize
    magazynWidget = new StanMagazyn;
    kuzniaWidget = new StanKuznia;

    //end initialize
    QWidget *widget = new QWidget;
    setCentralWidget(widget);
//! [0]

//! [1]
    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                              "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(5, 5, 5, 5);
    layout->addWidget(topFiller);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);
//! [1]

//! [2]
    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("Narzędzia na kuźnię"));
    setMinimumSize(160, 160);
    resize(480, 320);
}
//! [2]

/*//! [3]
#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU
//! [3]*/

void MainWindow::magazyn()
{
    centralWidget()->setParent(0);
    setCentralWidget(magazynWidget);
}

void MainWindow::kuznia()
{
    centralWidget()->setParent(0);
    setCentralWidget(kuzniaWidget);
}

//! [4]
void MainWindow::createActions()
{
//! [5]
    magazynAct = new QAction(tr("&Magazyn"), this);
    magazynAct->setShortcuts(QKeySequence::New);
    magazynAct->setStatusTip(tr("Wyświetl tabele magazynu"));
    connect(magazynAct, &QAction::triggered, this, &MainWindow::magazyn);
//! [4]

    kuzniaAct = new QAction(tr("&Kuznia"), this);
    kuzniaAct->setShortcuts(QKeySequence::Open);
    kuzniaAct->setStatusTip(tr("Wyświetl tabele kuźni"));
    connect(kuzniaAct, &QAction::triggered, this, &MainWindow::kuznia);
//! [5]
}
//! [8]
void MainWindow::createMenus()
{
//! [9] //! [10]
    fileMenu = menuBar()->addMenu(tr("&Stany"));
    fileMenu->addAction(magazynAct);
    fileMenu->addAction(kuzniaAct);
}
//! [12]
