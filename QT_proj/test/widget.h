#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "tokenwindow.h"
#include "treewindow.h"
#include <string>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void tokenWindowClosed();

    void treeWindowClosed();

    void on_runButton_clicked();

    void on_saveButton_clicked();

    void on_clearallButton_clicked();

    void on_tokenButton_clicked();



    void on_treeButton_clicked();

    void on_fileButton_clicked();

    void on_verticalScrollBar_valueChanged(int value);

private:
    Ui::Widget *ui;
    QString text;
    std::string s_err = "";
    std::string t_err = "";
    tokenWindow *tw = nullptr;
    treeWindow *trw = nullptr;
    int linecnt = 0;
};
#endif // WIDGET_H
