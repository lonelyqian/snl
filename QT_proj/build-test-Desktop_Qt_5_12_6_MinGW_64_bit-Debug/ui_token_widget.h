/********************************************************************************
** Form generated from reading UI file 'token_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOKEN_WIDGET_H
#define UI_TOKEN_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_token_widget
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *token_widget)
    {
        if (token_widget->objectName().isEmpty())
            token_widget->setObjectName(QString::fromUtf8("token_widget"));
        token_widget->resize(1173, 300);
        textBrowser = new QTextBrowser(token_widget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setGeometry(QRect(900, 100, 256, 192));

        retranslateUi(token_widget);

        QMetaObject::connectSlotsByName(token_widget);
    } // setupUi

    void retranslateUi(QWidget *token_widget)
    {
        token_widget->setWindowTitle(QApplication::translate("token_widget", "Form", nullptr));
        textBrowser->setHtml(QApplication::translate("token_widget", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'SimSun';\">56465</span></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class token_widget: public Ui_token_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOKEN_WIDGET_H
