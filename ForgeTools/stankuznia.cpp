#include "stankuznia.h"
#include <QtDebug>

StanKuznia::StanKuznia(QWidget *parent) : QWidget(parent)
{
    widget = new QTextEdit;
    query = new QSqlQuery;
    queryModel = new QSqlQueryModel;
    tableView = new QTableView;

    layout = new QVBoxLayout;
    layout->addWidget(widget);
    layout->addWidget(tableView);
    this->setLayout(layout);

    designTableView();
    designQuery();
}

void StanKuznia::designQuery()
{
    //SqlQuery
    QString zapytanie = "SELECT * FROM cecha";
    query->prepare(zapytanie);
    query->exec();
    //SqlModel
    queryModel->setQuery(*query);
    //TableView
    tableView->setModel(queryModel);
}

void StanKuznia::designTableView()
{
    tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    tableView->verticalHeader()->setContextMenuPolicy(Qt::CustomContextMenu);
    QFont fnt;
        fnt.setPointSize(12);
        fnt.setFamily("Arial");
    tableView->setFont(fnt);
    tableView->horizontalHeader()->setFont(fnt);
    tableView->resizeColumnsToContents();
    //tableView->resizeRowsToContents();
    tableView->hideColumn(1);
}
