#include "widget.h"
#include "ui_widget.h"
#include "start.h"
#include <string>
#include "QFileDialog"
#include <QMessageBox>
#include <QDebug>
#include <QScrollBar>
#include <QTextCodec>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("只有前三步的编译器");
    this->setMaximumSize(1600,1000);
    this->setMinimumSize(1600,1000);
    ui->codeEdit->setMaximumSize(800,600);
    ui->codeEdit->setMinimumSize(800,600);
    ui->errorEdit->setMinimumSize(800,200);
    ui->linenoEdit->setMinimumHeight(600);
    connect(ui->codeEdit->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(on_verticalScrollBar_valueChanged(int)));
    connect(ui->linenoEdit->verticalScrollBar(), SIGNAL(valueChanged(int)), this, SLOT(on_verticalScrollBar_valueChanged(int)));
}
Widget::~Widget()
{
    delete ui;
}
void Widget::on_runButton_clicked()
{
    s_err = ""; t_err = "";
    ui->errorEdit->setText("");
    string s = text.toStdString();
    string ans = start(s, s_err, t_err);
    //cout << "safe\n";
    QString err = QString::fromStdString(ans);
    //cout << "q\n";
    ui->errorEdit->setText(err);
}

void Widget::on_saveButton_clicked()
{
    s_err = ""; t_err = ""; linecnt = 0;
    text = ui->codeEdit->toPlainText();
    string s = text.toStdString();
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '\n')
                linecnt++;
    QString linetext = "";
    for(int i  = 0; i <= linecnt; i++)
    {
        linetext += QString::number(i);
        linetext += '\n';
    }
    //cout << linecnt  << endl;
    ui->linenoEdit->setText(linetext);
}

void Widget::on_clearallButton_clicked()
{
    text = "";
    ui->codeEdit->setText("");
    ui->errorEdit->setText("");
}

void Widget::on_tokenButton_clicked()
{
   if(!tw)
   {
       tw = new tokenWindow(this,s_err);
       bool ok = connect(tw,SIGNAL(windowClosed()),this,SLOT(tokenWindowClosed()));
       tw->show();
   }


}
void Widget::tokenWindowClosed()
{
    delete tw;
    tw = nullptr;
}

void Widget::on_treeButton_clicked()
{
    if(!trw)
    {
        trw = new treeWindow(this, t_err);
        bool ok = connect(trw,SIGNAL(windowClosed()),this,SLOT(treeWindowClosed()));
        cout << "treee" << ok;
        trw->show();
    }
}
void Widget::treeWindowClosed()
{
    delete trw;
    trw = nullptr;
}

void Widget::on_fileButton_clicked()
{
    QStringList infoList;
    //获取文件名
    QString fileName = QFileDialog::getOpenFileName(
                this,
                tr("open a file."),
                "",
                tr("text(*.txt);;video files(*.avi *.mp4 *.wmv);;All files(*.*)"));

    if (fileName.isEmpty())
    {
        QMessageBox::warning(this, "Warning!", "Failed to open the txt!");
    }
    else
    {
        ui->filenameEdit->setText(fileName);
        QFile file(fileName);
        //打开文件
        if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
            qDebug()<<"Can't open the file!"<<endl;
        }
        QString ttext = "";
        while (!file.atEnd())
        {
            QByteArray line = file.readLine();

            QTextCodec::ConverterState state;
            QString str = QTextCodec::codecForName("UTF-8")->toUnicode(line.constData(), line.size(), &state);
            if (state.invalidChars > 0)
            {
                str = QTextCodec::codecForName("GBK")->toUnicode(line);
            }
            ttext += str;
        }
        ui->codeEdit->setText(ttext);
    }
}

void Widget::on_verticalScrollBar_valueChanged(int value)
{
    QScrollBar *scrollbar1 = ui->codeEdit->verticalScrollBar();
    QScrollBar *scrollbar2 = ui->linenoEdit ->verticalScrollBar();

    scrollbar1->setValue(value);
    scrollbar2->setValue(value);
}
