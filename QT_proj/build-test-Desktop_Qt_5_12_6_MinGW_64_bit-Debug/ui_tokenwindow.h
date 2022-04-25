/********************************************************************************
** Form generated from reading UI file 'tokenwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOKENWINDOW_H
#define UI_TOKENWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_tokenWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *tokenEdit;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *tokenWindow)
    {
        if (tokenWindow->objectName().isEmpty())
            tokenWindow->setObjectName(QString::fromUtf8("tokenWindow"));
        tokenWindow->resize(800, 600);
        centralwidget = new QWidget(tokenWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tokenEdit = new QTextEdit(centralwidget);
        tokenEdit->setObjectName(QString::fromUtf8("tokenEdit"));
        tokenEdit->setGeometry(QRect(0, 0, 801, 541));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        tokenEdit->setFont(font);
        tokenWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(tokenWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        tokenWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(tokenWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        tokenWindow->setMenuBar(menubar);

        retranslateUi(tokenWindow);

        QMetaObject::connectSlotsByName(tokenWindow);
    } // setupUi

    void retranslateUi(QMainWindow *tokenWindow)
    {
        tokenWindow->setWindowTitle(QApplication::translate("tokenWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class tokenWindow: public Ui_tokenWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOKENWINDOW_H
