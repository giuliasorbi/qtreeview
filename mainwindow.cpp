#include <QTreeView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "mainwindow.h"


MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
{
    treeView = new QTreeView(this);
    setCentralWidget(treeView);
    standardModel = new QStandardItemModel;

    QStandardItem* rootNode = standardModel->invisibleRootItem();

    QStandardItem* americaItem = new QStandardItem("America");
    QStandardItem* mexicoItem =  new QStandardItem("Canada");
    QStandardItem* usaItem =     new QStandardItem("USA");
    QStandardItem* bostonItem =  new QStandardItem("Boston");
    QStandardItem* europeItem =  new QStandardItem("Europe");
    QStandardItem* italyItem =   new QStandardItem("Italy");
    QStandardItem* romeItem =    new QStandardItem("Rome");
    QStandardItem* veronaItem =  new QStandardItem("Verona");

    rootNode->appendRow(americaItem);
    rootNode->appendRow(europeItem);

    americaItem->appendRow(mexicoItem);
    americaItem->appendRow(usaItem);

    usaItem->appendRow(bostonItem);

    europeItem->  appendRow(italyItem);

    italyItem->   appendRow(romeItem);
    italyItem->   appendRow(veronaItem);

    treeView->setModel(standardModel);
    treeView->expandAll();

    QItemSelectionModel* selectionModel = treeView->selectionModel();

    connect(selectionModel, SIGNAL(selectionChanged(const QItemSelection& ,const QItemSelection&)),
            this, SLOT(selectionChangedSlot(const QItemSelection&, const QItemSelection&)));
}

void MainWindow::selectionChangedSlot(const QItemSelection&, const QItemSelection&) // new selection, old selection
{
    const QModelIndex index = treeView->selectionModel()->currentIndex();
    QString selectedText = index.data(Qt::DisplayRole).toString(); // text of the selected item

    int hierarchyLevel = 1;
    QModelIndex seekRoot = index;

    // Top level items do not have parents and..
    // ..the parent() method will return a default constructed QModelIndex()

    while(seekRoot.parent() != QModelIndex()) {
        seekRoot = seekRoot.parent();
        hierarchyLevel++;
    }

    QString showString = QString("%1, Level %2").arg(selectedText).arg(hierarchyLevel);
    setWindowTitle(showString);
}


