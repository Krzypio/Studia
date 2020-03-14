#ifndef STANKUZNIA_H
#define STANKUZNIA_H

#include <QWidget>
#include <QVBoxLayout>

#include <QTextEdit>

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>

#include <QHeaderView>

class StanKuznia : public QWidget
{
    Q_OBJECT
public:
    explicit StanKuznia(QWidget *parent = nullptr);

signals:

public slots:

private:
    QWidget *widget;
    QVBoxLayout *layout;

    void designQuery();
    QSqlQuery *query;
    QSqlQueryModel *queryModel;
    QTableView *tableView;

    void designTableView();

};

#endif // STANKUZNIA_H
