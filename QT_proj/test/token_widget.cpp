#include "token_widget.h"
#include "ui_token_widget.h"

token_widget::token_widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::token_widget)
{
    ui->setupUi(this);
}

token_widget::~token_widget()
{
    delete ui;
}
void token_widget::closeEvent(QCloseEvent* event)
{
    emit windowClosed();
}
