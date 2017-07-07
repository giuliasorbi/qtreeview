#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTreeView; //forward declarations
class QStandardItemModel;
class QItemSelection;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTreeView* treeView;
    QStandardItemModel* standardModel;
private slots:
    void selectionChangedSlot(const QItemSelection& newSelection, const QItemSelection& oldSelection);
public:
    MainWindow(QWidget* parent = nullptr);
};

#endif // MAINWINDOW_H
