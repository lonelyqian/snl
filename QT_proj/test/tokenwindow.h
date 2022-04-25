#ifndef TOKENWINDOW_H
#define TOKENWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <string>
namespace Ui {
class tokenWindow;
}

class tokenWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit tokenWindow(QWidget *parent = nullptr, std::string s = "");
    ~tokenWindow();
    std::string token;
protected:
    void closeEvent(QCloseEvent* event);
signals:
    void windowClosed();
private:
    Ui::tokenWindow *ui;

};

#endif // TOKENWINDOW_H
