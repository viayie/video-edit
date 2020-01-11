/********************************************************************************
** Form generated from reading UI file 'XVideoUI.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_XVIDEOUI_H
#define UI_XVIDEOUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>
#include "xvideowidget.h"

QT_BEGIN_NAMESPACE

class Ui_XVideoUIClass
{
public:
    QPushButton *closeButton;
    XVideoWidget *src1video;
    QPushButton *openButton;
    QSlider *playSlider;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *bright;
    QDoubleSpinBox *contrast;
    QPushButton *setButton;
    XVideoWidget *desvideo;

    void setupUi(QWidget *XVideoUIClass)
    {
        if (XVideoUIClass->objectName().isEmpty())
            XVideoUIClass->setObjectName(QStringLiteral("XVideoUIClass"));
        XVideoUIClass->resize(901, 600);
        XVideoUIClass->setStyleSheet(QString::fromUtf8("QPushButton:hover\n"
"{ \n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(120, 120, 120, 255), stop:0.495 rgba(39, 39, 39, 255), stop:0.505 rgba(39,39, 39, 255), stop:1 rgba(120, 120,120, 255));\n"
"	border: none;\n"
"	border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"QPushButton:!hover\n"
"{ \n"
"	background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:1, stop:0 rgba(39, 39, 39, 255), stop:0.495 rgba(120, 120, 120, 255), stop:0.505 rgba(120,120, 120, 255), stop:1 rgba(39, 39,39, 255));\n"
"	border: none;\n"
"	border-radius:5px;\n"
"	color: rgb(255, 255, 255);\n"
"	font: 75 12pt \"\351\273\221\344\275\223\";\n"
"}\n"
"#XVideoUIClass\n"
"{\n"
"	background-color: rgb(53, 53, 53);\n"
"}\n"
"QLabel\n"
"{\n"
"color: rgb(255, 255, 255);\n"
"	font: 9pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"}\n"
""));
        closeButton = new QPushButton(XVideoUIClass);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(840, 10, 51, 21));
        closeButton->setStyleSheet(QLatin1String("background-color: rgb(53, 53, 53);\n"
""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/XVideoUI/Resources/close.png"), QSize(), QIcon::Normal, QIcon::Off);
        closeButton->setIcon(icon);
        closeButton->setIconSize(QSize(40, 20));
        closeButton->setFlat(true);
        src1video = new XVideoWidget(XVideoUIClass);
        src1video->setObjectName(QStringLiteral("src1video"));
        src1video->setGeometry(QRect(0, 0, 380, 280));
        openButton = new QPushButton(XVideoUIClass);
        openButton->setObjectName(QStringLiteral("openButton"));
        openButton->setGeometry(QRect(490, 530, 60, 30));
        openButton->setMinimumSize(QSize(60, 30));
        openButton->setMaximumSize(QSize(60, 30));
        openButton->setIconSize(QSize(60, 60));
        playSlider = new QSlider(XVideoUIClass);
        playSlider->setObjectName(QStringLiteral("playSlider"));
        playSlider->setGeometry(QRect(10, 320, 381, 21));
        playSlider->setMaximum(999);
        playSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(XVideoUIClass);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 390, 71, 21));
        label_2 = new QLabel(XVideoUIClass);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(350, 440, 91, 20));
        bright = new QSpinBox(XVideoUIClass);
        bright->setObjectName(QStringLiteral("bright"));
        bright->setGeometry(QRect(460, 390, 171, 22));
        QFont font;
        font.setFamily(QStringLiteral("Source Code Pro"));
        bright->setFont(font);
        contrast = new QDoubleSpinBox(XVideoUIClass);
        contrast->setObjectName(QStringLiteral("contrast"));
        contrast->setGeometry(QRect(460, 440, 171, 22));
        contrast->setFont(font);
        contrast->setMinimum(1);
        contrast->setMaximum(3);
        contrast->setSingleStep(0.1);
        setButton = new QPushButton(XVideoUIClass);
        setButton->setObjectName(QStringLiteral("setButton"));
        setButton->setGeometry(QRect(800, 400, 60, 30));
        setButton->setMinimumSize(QSize(60, 30));
        setButton->setMaximumSize(QSize(60, 30));
        setButton->setIconSize(QSize(60, 60));
        desvideo = new XVideoWidget(XVideoUIClass);
        desvideo->setObjectName(QStringLiteral("desvideo"));
        desvideo->setGeometry(QRect(420, 0, 380, 280));

        retranslateUi(XVideoUIClass);
        QObject::connect(closeButton, SIGNAL(clicked()), XVideoUIClass, SLOT(close()));
        QObject::connect(openButton, SIGNAL(clicked(bool)), XVideoUIClass, SLOT(Open()));
        QObject::connect(playSlider, SIGNAL(sliderPressed()), XVideoUIClass, SLOT(SliderPress()));
        QObject::connect(playSlider, SIGNAL(sliderReleased()), XVideoUIClass, SLOT(SliderRelease()));
        QObject::connect(playSlider, SIGNAL(sliderMoved(int)), XVideoUIClass, SLOT(SetPos(int)));
        QObject::connect(setButton, SIGNAL(clicked()), XVideoUIClass, SLOT(Set()));

        QMetaObject::connectSlotsByName(XVideoUIClass);
    } // setupUi

    void retranslateUi(QWidget *XVideoUIClass)
    {
        XVideoUIClass->setWindowTitle(QApplication::translate("XVideoUIClass", "XVideoUI", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        closeButton->setToolTip(QApplication::translate("XVideoUIClass", "\345\205\263\351\227\255", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        closeButton->setText(QString());
        openButton->setText(QApplication::translate("XVideoUIClass", "\346\211\223\345\274\200", Q_NULLPTR));
        label->setText(QApplication::translate("XVideoUIClass", "\344\272\256\345\272\246[0~100]", Q_NULLPTR));
        label_2->setText(QApplication::translate("XVideoUIClass", "\345\257\271\346\257\224\345\272\246[1.0~3.0]", Q_NULLPTR));
        setButton->setText(QApplication::translate("XVideoUIClass", "\350\256\276\347\275\256", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class XVideoUIClass: public Ui_XVideoUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_XVIDEOUI_H
