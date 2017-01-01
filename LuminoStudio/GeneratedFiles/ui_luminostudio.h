/********************************************************************************
** Form generated from reading UI file 'luminostudio.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LUMINOSTUDIO_H
#define UI_LUMINOSTUDIO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LuminoStudioClass
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LuminoStudioClass)
    {
        if (LuminoStudioClass->objectName().isEmpty())
            LuminoStudioClass->setObjectName(QStringLiteral("LuminoStudioClass"));
        LuminoStudioClass->resize(600, 400);
        centralWidget = new QWidget(LuminoStudioClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(60, 180, 93, 28));
        LuminoStudioClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LuminoStudioClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 26));
        LuminoStudioClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LuminoStudioClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LuminoStudioClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LuminoStudioClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LuminoStudioClass->setStatusBar(statusBar);

        retranslateUi(LuminoStudioClass);

        QMetaObject::connectSlotsByName(LuminoStudioClass);
    } // setupUi

    void retranslateUi(QMainWindow *LuminoStudioClass)
    {
        LuminoStudioClass->setWindowTitle(QApplication::translate("LuminoStudioClass", "LuminoStudio", Q_NULLPTR));
        pushButton->setText(QApplication::translate("LuminoStudioClass", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class LuminoStudioClass: public Ui_LuminoStudioClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LUMINOSTUDIO_H
