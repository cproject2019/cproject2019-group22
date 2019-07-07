/********************************************************************************
** Form generated from reading UI file 'Qtmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTMAINWINDOW_H
#define UI_QTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtmainwindowClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pm;
    QSpacerItem *verticalSpacer;
    QPushButton *p2p;
    QSpacerItem *verticalSpacer_2;
    QPushButton *setting;
    QSpacerItem *verticalSpacer_3;
    QPushButton *leave;
    QLabel *label_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtmainwindowClass)
    {
        if (QtmainwindowClass->objectName().isEmpty())
            QtmainwindowClass->setObjectName(QString::fromUtf8("QtmainwindowClass"));
        QtmainwindowClass->resize(557, 700);
        QtmainwindowClass->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(QtmainwindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 250, 301, 181));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font.setPointSize(37);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8(""));
        label->setMidLineWidth(0);
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(350, 270, 211, 291));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pm = new QPushButton(verticalLayoutWidget);
        pm->setObjectName(QString::fromUtf8("pm"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pm->sizePolicy().hasHeightForWidth());
        pm->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font1.setPointSize(16);
        pm->setFont(font1);
        pm->setStyleSheet(QString::fromUtf8("border-image: url(:/Qtmainwindow/1.png);"));
        pm->setIconSize(QSize(12, 12));

        verticalLayout->addWidget(pm);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        p2p = new QPushButton(verticalLayoutWidget);
        p2p->setObjectName(QString::fromUtf8("p2p"));
        sizePolicy.setHeightForWidth(p2p->sizePolicy().hasHeightForWidth());
        p2p->setSizePolicy(sizePolicy);
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font2.setPointSize(15);
        p2p->setFont(font2);
        p2p->setStyleSheet(QString::fromUtf8("border-image: url(:/Qtmainwindow/1.png);"));

        verticalLayout->addWidget(p2p);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        setting = new QPushButton(verticalLayoutWidget);
        setting->setObjectName(QString::fromUtf8("setting"));
        sizePolicy.setHeightForWidth(setting->sizePolicy().hasHeightForWidth());
        setting->setSizePolicy(sizePolicy);
        setting->setFont(font2);
        setting->setStyleSheet(QString::fromUtf8("border-image: url(:/Qtmainwindow/1.png);"));

        verticalLayout->addWidget(setting);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);

        leave = new QPushButton(verticalLayoutWidget);
        leave->setObjectName(QString::fromUtf8("leave"));
        sizePolicy.setHeightForWidth(leave->sizePolicy().hasHeightForWidth());
        leave->setSizePolicy(sizePolicy);
        leave->setFont(font2);
        leave->setStyleSheet(QString::fromUtf8("border-image: url(:/Qtmainwindow/1.png);"));

        verticalLayout->addWidget(leave);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 561, 671));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/Qtmainwindow/123 (4).jpg);"));
        QtmainwindowClass->setCentralWidget(centralWidget);
        label_2->raise();
        label->raise();
        verticalLayoutWidget->raise();
        menuBar = new QMenuBar(QtmainwindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 557, 18));
        QtmainwindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtmainwindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtmainwindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(QtmainwindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtmainwindowClass->setStatusBar(statusBar);

        retranslateUi(QtmainwindowClass);

        QMetaObject::connectSlotsByName(QtmainwindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtmainwindowClass)
    {
        QtmainwindowClass->setWindowTitle(QApplication::translate("QtmainwindowClass", "Qtmainwindow", nullptr));
        label->setText(QApplication::translate("QtmainwindowClass", "\344\270\255\345\233\275\350\261\241\346\243\213", nullptr));
        pm->setText(QApplication::translate("QtmainwindowClass", "\344\272\272\346\234\272\345\257\271\345\274\210", nullptr));
        p2p->setText(QApplication::translate("QtmainwindowClass", "\344\272\272\344\272\272\345\257\271\345\274\210", nullptr));
        setting->setText(QApplication::translate("QtmainwindowClass", "\350\256\276\347\275\256", nullptr));
        leave->setText(QApplication::translate("QtmainwindowClass", "\351\200\200\345\207\272", nullptr));
        label_2->setText(QApplication::translate("QtmainwindowClass", "T", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtmainwindowClass: public Ui_QtmainwindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTMAINWINDOW_H
