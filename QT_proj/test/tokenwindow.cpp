#include "tokenwindow.h"
#include "ui_tokenwindow.h"
#include <string>
tokenWindow::tokenWindow(QWidget *parent, std::string s) :
    QMainWindow(parent),
    token(s),
    ui(new Ui::tokenWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("token");
    QString token_q = QString::fromStdString(token);
    ui->tokenEdit->setText(token_q);
}

tokenWindow::~tokenWindow()
{
    delete ui;
}
void tokenWindow::closeEvent(QCloseEvent* event)
{
    emit windowClosed();
}
