#include <QTreeView>
#include <QStandardItemModel>
#include <QStandardItem>
#include "mainwindow.h"


const int ROWS = 2;
const int COLUMNS = 3;

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    treeView = new QTreeView(this);
    setCentralWidget(treeView);
    standardModel = new QStandardItemModel ;

    QList<QStandardItem*> preparedRow =prepareRow("first", "second", "third");
    QStandardItem* item = standardModel->invisibleRootItem();
    item->appendRow(preparedRow);

    QList<QStandardItem*> secondRow =prepareRow("111", "222", "333");

    preparedRow.first()->appendRow(secondRow);

    treeView->setModel(standardModel);
    treeView->expandAll();
}

QList<QStandardItem*> MainWindow::prepareRow(const QString& first, const QString& second, const QString& third)
{
    QList<QStandardItem*> rowItems;
    rowItems << new QStandardItem(first);
    rowItems << new QStandardItem(second);
    rowItems << new QStandardItem(third);
    return rowItems;
}
