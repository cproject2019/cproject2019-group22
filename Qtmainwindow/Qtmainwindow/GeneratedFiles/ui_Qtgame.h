/********************************************************************************
** Form generated from reading UI file 'Qtgame.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGAME_H
#define UI_QTGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtgame
{
public:
    QPushButton *back2;

    void setupUi(QWidget *Qtgame)
    {
        if (Qtgame->objectName().isEmpty())
            Qtgame->setObjectName(QString::fromUtf8("Qtgame"));
        Qtgame->resize(400, 300);
        back2 = new QPushButton(Qtgame);
        back2->setObjectName(QString::fromUtf8("back2"));
        back2->setGeometry(QRect(330, 260, 56, 17));

        retranslateUi(Qtgame);

        QMetaObject::connectSlotsByName(Qtgame);
    } // setupUi

    void retranslateUi(QWidget *Qtgame)
    {
        Qtgame->setWindowTitle(QApplication::translate("Qtgame", "Qtgame", nullptr));
        back2->setText(QApplication::translate("Qtgame", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qtgame: public Ui_Qtgame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGAME_H
