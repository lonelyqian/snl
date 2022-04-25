#ifndef TOKEN_WIDGET_H
#define TOKEN_WIDGET_H
#include <QCloseEvent>
#include <QWidget>

namespace Ui {
class token_widget;
}

class token_widget : public QWidget
{
    Q_OBJECT

public:
    explicit token_widget(QWidget *parent = nullptr);
    ~token_widget();
protected:
    void closeEvent(QCloseEvent *event);
signals:
    void windowClosed();
private:
    Ui::token_widget *ui;
};

#endif // TOKEN_WIDGET_H
