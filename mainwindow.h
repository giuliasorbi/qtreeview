#include <QMainWindow>

// forward declarations
class QTreeView;
class QStandardItemModel;
class QStandardItem;

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QTreeView* treeView;
    QStandardItemModel* standardModel;
    QList<QStandardItem *> prepareRow( const QString& first, const QString& second, const QString& third );
public:
    MainWindow(QWidget* parent = nullptr);
};
