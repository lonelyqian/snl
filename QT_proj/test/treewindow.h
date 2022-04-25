#ifndef TREEWINDOW_H
#define TREEWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <string>
namespace Ui {
class treeWindow;
}

class treeWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit treeWindow(QWidget *parent = nullptr, std::string t = "");
    ~treeWindow();
    std::string tree = "";
protected:
    void closeEvent(QCloseEvent* event);
signals:
    void windowClosed();
private:
    Ui::treeWindow *ui;
};

#endif // TREEWINDOW_H
