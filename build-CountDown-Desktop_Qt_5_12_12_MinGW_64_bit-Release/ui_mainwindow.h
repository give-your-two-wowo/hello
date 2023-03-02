/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *CountDown_label;
    QLabel *systemTime_label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QTimeEdit *BeiJing_timeEdit;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QTimeEdit *UTC_timeEdit;
    QPushButton *Start_pushButton;
    QPushButton *Reset_pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setWindowModality(Qt::NonModal);
        MainWindow->resize(800, 515);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/resource/Timer.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        CountDown_label = new QLabel(centralwidget);
        CountDown_label->setObjectName(QString::fromUtf8("CountDown_label"));

        verticalLayout_3->addWidget(CountDown_label);

        systemTime_label = new QLabel(centralwidget);
        systemTime_label->setObjectName(QString::fromUtf8("systemTime_label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\344\273\277\345\256\213"));
        font.setPointSize(48);
        font.setBold(false);
        font.setWeight(50);
        systemTime_label->setFont(font);

        verticalLayout_3->addWidget(systemTime_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        BeiJing_timeEdit = new QTimeEdit(centralwidget);
        BeiJing_timeEdit->setObjectName(QString::fromUtf8("BeiJing_timeEdit"));
        BeiJing_timeEdit->setCurrentSection(QDateTimeEdit::HourSection);

        verticalLayout->addWidget(BeiJing_timeEdit);


        horizontalLayout->addLayout(verticalLayout);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignBottom|Qt::AlignHCenter);

        horizontalLayout->addWidget(label_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        UTC_timeEdit = new QTimeEdit(centralwidget);
        UTC_timeEdit->setObjectName(QString::fromUtf8("UTC_timeEdit"));

        verticalLayout_2->addWidget(UTC_timeEdit);


        horizontalLayout->addLayout(verticalLayout_2);

        Start_pushButton = new QPushButton(centralwidget);
        Start_pushButton->setObjectName(QString::fromUtf8("Start_pushButton"));

        horizontalLayout->addWidget(Start_pushButton);

        Reset_pushButton = new QPushButton(centralwidget);
        Reset_pushButton->setObjectName(QString::fromUtf8("Reset_pushButton"));

        horizontalLayout->addWidget(Reset_pushButton);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalLayout_3->setStretch(0, 3);
        verticalLayout_3->setStretch(1, 1);
        verticalLayout_3->setStretch(2, 1);

        verticalLayout_4->addLayout(verticalLayout_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "10\345\210\206\351\222\237\350\256\241\346\227\266\345\231\250", nullptr));
        CountDown_label->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        systemTime_label->setText(QApplication::translate("MainWindow", "00:00:00", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\345\214\227\344\272\254\346\227\266", nullptr));
        BeiJing_timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "\343\200\212==\343\200\213", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "UTC\346\227\266", nullptr));
        UTC_timeEdit->setDisplayFormat(QApplication::translate("MainWindow", "HH:mm:ss", nullptr));
        Start_pushButton->setText(QApplication::translate("MainWindow", "\345\274\200\345\247\213", nullptr));
        Reset_pushButton->setText(QApplication::translate("MainWindow", "\345\244\215\344\275\215", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
