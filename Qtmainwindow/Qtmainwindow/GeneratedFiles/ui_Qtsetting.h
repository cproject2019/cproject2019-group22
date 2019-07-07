/********************************************************************************
** Form generated from reading UI file 'Qtsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSETTING_H
#define UI_QTSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Qtsetting
{
public:
    QPushButton *back1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSlider *soundbs;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QRadioButton *soundon;
    QRadioButton *soundoff;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QRadioButton *dsimple;
    QRadioButton *dmid;
    QRadioButton *ddifficult;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_5;
    QRadioButton *mouse;
    QRadioButton *key;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QRadioButton *music1;
    QRadioButton *music2;
    QRadioButton *music3;
    QLabel *label_2;
    QLabel *label_6;

    void setupUi(QWidget *Qtsetting)
    {
        if (Qtsetting->objectName().isEmpty())
            Qtsetting->setObjectName(QString::fromUtf8("Qtsetting"));
        Qtsetting->resize(701, 421);
        Qtsetting->setLayoutDirection(Qt::LeftToRight);
        back1 = new QPushButton(Qtsetting);
        back1->setObjectName(QString::fromUtf8("back1"));
        back1->setGeometry(QRect(570, 360, 41, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font.setPointSize(13);
        back1->setFont(font);
        back1->setStyleSheet(QString::fromUtf8("border-image: url(:/new/background/22222.png);"));
        verticalLayoutWidget = new QWidget(Qtsetting);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(130, 80, 441, 251));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        label_8->setFont(font1);

        horizontalLayout_7->addWidget(label_8);

        soundbs = new QSlider(verticalLayoutWidget);
        soundbs->setObjectName(QString::fromUtf8("soundbs"));
        soundbs->setMaximum(100);
        soundbs->setPageStep(2);
        soundbs->setValue(27);
        soundbs->setSliderPosition(27);
        soundbs->setOrientation(Qt::Horizontal);
        soundbs->setInvertedAppearance(false);
        soundbs->setTickPosition(QSlider::TicksBelow);
        soundbs->setTickInterval(2);

        horizontalLayout_7->addWidget(soundbs);


        verticalLayout_4->addLayout(horizontalLayout_7);


        verticalLayout->addLayout(verticalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        horizontalLayout_2->addWidget(label_3);

        soundon = new QRadioButton(verticalLayoutWidget);
        soundon->setObjectName(QString::fromUtf8("soundon"));
        soundon->setFont(font1);

        horizontalLayout_2->addWidget(soundon);

        soundoff = new QRadioButton(verticalLayoutWidget);
        soundoff->setObjectName(QString::fromUtf8("soundoff"));
        soundoff->setFont(font1);

        horizontalLayout_2->addWidget(soundoff);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        horizontalLayout_3->addWidget(label_4);

        dsimple = new QRadioButton(verticalLayoutWidget);
        dsimple->setObjectName(QString::fromUtf8("dsimple"));
        dsimple->setFont(font1);

        horizontalLayout_3->addWidget(dsimple);

        dmid = new QRadioButton(verticalLayoutWidget);
        dmid->setObjectName(QString::fromUtf8("dmid"));
        dmid->setFont(font1);

        horizontalLayout_3->addWidget(dmid);

        ddifficult = new QRadioButton(verticalLayoutWidget);
        ddifficult->setObjectName(QString::fromUtf8("ddifficult"));
        ddifficult->setFont(font1);

        horizontalLayout_3->addWidget(ddifficult);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        horizontalLayout_4->addWidget(label_5);

        mouse = new QRadioButton(verticalLayoutWidget);
        mouse->setObjectName(QString::fromUtf8("mouse"));
        mouse->setFont(font1);

        horizontalLayout_4->addWidget(mouse);

        key = new QRadioButton(verticalLayoutWidget);
        key->setObjectName(QString::fromUtf8("key"));
        key->setFont(font1);

        horizontalLayout_4->addWidget(key);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        horizontalLayout_5->addWidget(label);

        music1 = new QRadioButton(verticalLayoutWidget);
        music1->setObjectName(QString::fromUtf8("music1"));
        music1->setFont(font1);

        horizontalLayout_5->addWidget(music1);

        music2 = new QRadioButton(verticalLayoutWidget);
        music2->setObjectName(QString::fromUtf8("music2"));
        music2->setFont(font1);

        horizontalLayout_5->addWidget(music2);

        music3 = new QRadioButton(verticalLayoutWidget);
        music3->setObjectName(QString::fromUtf8("music3"));
        music3->setFont(font1);

        horizontalLayout_5->addWidget(music3);


        verticalLayout->addLayout(horizontalLayout_5);

        label_2 = new QLabel(Qtsetting);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 0, 701, 421));
        label_2->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/123 (3).jpg);"));
        label_6 = new QLabel(Qtsetting);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 20, 121, 31));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\255\227\351\255\20255\345\217\267-\351\276\231\345\220\237\346\211\213\344\271\246"));
        font2.setPointSize(27);
        label_6->setFont(font2);
        label_2->raise();
        back1->raise();
        verticalLayoutWidget->raise();
        label_6->raise();

        retranslateUi(Qtsetting);

        QMetaObject::connectSlotsByName(Qtsetting);
    } // setupUi

    void retranslateUi(QWidget *Qtsetting)
    {
        Qtsetting->setWindowTitle(QApplication::translate("Qtsetting", "Qtsetting", nullptr));
        back1->setText(QApplication::translate("Qtsetting", "\350\277\224\345\233\236", nullptr));
        label_8->setText(QApplication::translate("Qtsetting", "\351\237\263\351\207\217\345\244\247\345\260\217\357\274\232", nullptr));
        label_3->setText(QApplication::translate("Qtsetting", "\351\237\263\346\225\210\345\274\200\345\205\263\357\274\232", nullptr));
        soundon->setText(QApplication::translate("Qtsetting", "\345\274\200", nullptr));
        soundoff->setText(QApplication::translate("Qtsetting", "\345\205\263", nullptr));
        label_4->setText(QApplication::translate("Qtsetting", "\347\224\265\350\204\221\351\232\276\345\272\246\357\274\232", nullptr));
        dsimple->setText(QApplication::translate("Qtsetting", "\347\256\200\345\215\225", nullptr));
        dmid->setText(QApplication::translate("Qtsetting", "\344\270\255\347\255\211", nullptr));
        ddifficult->setText(QApplication::translate("Qtsetting", "\345\233\260\351\232\276", nullptr));
        label_5->setText(QApplication::translate("Qtsetting", "\346\223\215\344\275\234\346\250\241\345\274\217\357\274\232", nullptr));
        mouse->setText(QApplication::translate("Qtsetting", "\351\274\240\346\240\207", nullptr));
        key->setText(QApplication::translate("Qtsetting", "\351\224\256\347\233\230", nullptr));
        label->setText(QApplication::translate("Qtsetting", "\350\203\214\346\231\257\351\237\263\344\271\220\357\274\232", nullptr));
        music1->setText(QApplication::translate("Qtsetting", "\351\237\263\344\271\2201", nullptr));
        music2->setText(QApplication::translate("Qtsetting", "\351\237\263\344\271\2202", nullptr));
        music3->setText(QApplication::translate("Qtsetting", "\351\237\263\344\271\2203", nullptr));
        label_2->setText(QString());
        label_6->setText(QApplication::translate("Qtsetting", "\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Qtsetting: public Ui_Qtsetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSETTING_H
