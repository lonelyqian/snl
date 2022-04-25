/********************************************************************************
** Form generated from reading UI file 'treewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TREEWINDOW_H
#define UI_TREEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_treeWindow
{
public:
    QWidget *centralwidget;
    QTextEdit *treeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *treeWindow)
    {
        if (treeWindow->objectName().isEmpty())
            treeWindow->setObjectName(QString::fromUtf8("treeWindow"));
        treeWindow->resize(800, 600);
        centralwidget = new QWidget(treeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        treeEdit = new QTextEdit(centralwidget);
        treeEdit->setObjectName(QString::fromUtf8("treeEdit"));
        treeEdit->setGeometry(QRect(0, 0, 811, 541));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(12);
        treeEdit->setFont(font);
        treeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(treeWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        treeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(treeWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        treeWindow->setStatusBar(statusbar);

        retranslateUi(treeWindow);

        QMetaObject::connectSlotsByName(treeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *treeWindow)
    {
        treeWindow->setWindowTitle(QApplication::translate("treeWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class treeWindow: public Ui_treeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TREEWINDOW_H
