/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QTextEdit *codeEdit;
    QTextEdit *errorEdit;
    QLineEdit *lineEdit;
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *tokenButton;
    QPushButton *saveButton;
    QPushButton *treeButton;
    QPushButton *runButton;
    QPushButton *fileButton;
    QPushButton *clearallButton;
    QTextEdit *linenoEdit;
    QLineEdit *filenameEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1595, 839);
        codeEdit = new QTextEdit(Widget);
        codeEdit->setObjectName(QString::fromUtf8("codeEdit"));
        codeEdit->setGeometry(QRect(90, 40, 751, 481));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        font.setPointSize(14);
        codeEdit->setFont(font);
        errorEdit = new QTextEdit(Widget);
        errorEdit->setObjectName(QString::fromUtf8("errorEdit"));
        errorEdit->setGeometry(QRect(90, 740, 581, 181));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221 Light"));
        errorEdit->setFont(font1);
        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(120, 710, 113, 21));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(1231, 122, 299, 163));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        tokenButton = new QPushButton(layoutWidget);
        tokenButton->setObjectName(QString::fromUtf8("tokenButton"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Agency FB"));
        font2.setPointSize(20);
        tokenButton->setFont(font2);

        gridLayout->addWidget(tokenButton, 0, 0, 1, 1);

        saveButton = new QPushButton(layoutWidget);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setFont(font2);

        gridLayout->addWidget(saveButton, 0, 1, 1, 1);

        treeButton = new QPushButton(layoutWidget);
        treeButton->setObjectName(QString::fromUtf8("treeButton"));
        treeButton->setFont(font2);

        gridLayout->addWidget(treeButton, 1, 0, 1, 1);

        runButton = new QPushButton(layoutWidget);
        runButton->setObjectName(QString::fromUtf8("runButton"));
        runButton->setFont(font2);

        gridLayout->addWidget(runButton, 1, 1, 1, 1);

        fileButton = new QPushButton(layoutWidget);
        fileButton->setObjectName(QString::fromUtf8("fileButton"));
        fileButton->setFont(font2);

        gridLayout->addWidget(fileButton, 2, 0, 1, 1);

        clearallButton = new QPushButton(layoutWidget);
        clearallButton->setObjectName(QString::fromUtf8("clearallButton"));
        clearallButton->setFont(font2);

        gridLayout->addWidget(clearallButton, 2, 1, 1, 1);

        linenoEdit = new QTextEdit(Widget);
        linenoEdit->setObjectName(QString::fromUtf8("linenoEdit"));
        linenoEdit->setGeometry(QRect(30, 40, 61, 481));
        linenoEdit->setFont(font);
        filenameEdit = new QLineEdit(Widget);
        filenameEdit->setObjectName(QString::fromUtf8("filenameEdit"));
        filenameEdit->setGeometry(QRect(90, 20, 741, 21));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        lineEdit->setText(QApplication::translate("Widget", "\347\274\226\350\257\221\344\277\241\346\201\257\357\274\232", nullptr));
        tokenButton->setText(QApplication::translate("Widget", "\346\230\276\347\244\272token\345\272\217\345\210\227", nullptr));
        saveButton->setText(QApplication::translate("Widget", "\344\277\235\345\255\230", nullptr));
        treeButton->setText(QApplication::translate("Widget", "\346\230\276\347\244\272\350\257\255\346\263\225\346\240\221", nullptr));
        runButton->setText(QApplication::translate("Widget", "\347\274\226\350\257\221", nullptr));
        fileButton->setText(QApplication::translate("Widget", "\344\273\216\346\234\254\345\234\260\345\257\274\345\205\245", nullptr));
        clearallButton->setText(QApplication::translate("Widget", "\346\270\205\347\251\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
