#include "treewindow.h"
#include "ui_treewindow.h"
#include <string>
treeWindow::treeWindow(QWidget *parent, std::string t) :
    QMainWindow(parent),
    tree(t),
    ui(new Ui::treeWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("tree");
    QString tree_q = QString::fromStdString(tree);
    ui->treeEdit->setText(tree_q);
}

treeWindow::~treeWindow()
{
    delete ui;
}
void treeWindow::closeEvent(QCloseEvent* event)
{
    emit windowClosed();
}
