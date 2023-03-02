#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <qfont.h>
#include <qpalette.h>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    InitialStatus();
    m_lastTimer = new QTimer(this);
    connect(m_lastTimer,SIGNAL(timeout()),this,SLOT(on_lastTimer_timeout()));

    m_fristTimer = new QTimer(this);
    connect(m_fristTimer,SIGNAL(timeout()),this,SLOT(on_fristTimer_timeout()));

    m_sysTimeTimer = new QTimer(this);
    connect(m_sysTimeTimer,SIGNAL(timeout()),this,SLOT(m_sysTimeTimer_timeout()));
    m_sysTimeTimer->start(200);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Start_pushButton_clicked()
{

    // 获取设置的时间
    m_setTime = ui->BeiJing_timeEdit->time();
    if(m_setTime < QTime::currentTime())
    {
        QMessageBox::information(this,"提示","当前设置时间小于系统时间，请重试！");
        return ;
    }
    m_lastTimer->start(200);
    // 禁用开始按钮
    ui->Start_pushButton->setEnabled(false);
}


void MainWindow::on_Reset_pushButton_clicked()
{
    // 调用初始化函数
    InitialStatus();
    // 停止 倒计时/正计时定时器
    m_lastTimer->stop();
    m_fristTimer->stop();
    ui->Start_pushButton->setEnabled(true);

}

void MainWindow::m_sysTimeTimer_timeout()
{
   ui->systemTime_label->setText(QTime::currentTime().toString(QString::fromLatin1("HH:mm:ss")));
}

void MainWindow::on_lastTimer_timeout()
{
    // 获取当前时间
    m_curTime = QTime::currentTime();//在变
    int tianmiao = m_curTime.msecsSinceStartOfDay()/1000;//在变
    // 将获取到的时间，转换为字符串输出
    QTime showValue = m_setTime.addSecs(-tianmiao);//不变-在变
    QString timeStr = showValue.toString(QString::fromLatin1("HH:mm:ss"));
    ui->CountDown_label->setText(timeStr);
    if(showValue == QTime(0,0,0))
    {
        m_lastTimer->stop();
        m_fristTimer->start(200);
    }

}

void MainWindow::on_fristTimer_timeout()
{
    // 获取当前时间
    m_curTime = QTime::currentTime(); //在变
    int tianmiao = m_setTime.msecsSinceStartOfDay()/1000;//不变
    // 将获取到的时间，转换为字符串输出
    QTime showValue = m_curTime.addSecs(-tianmiao);//在变-不变
    QString timeStr = showValue.toString(QString::fromLatin1("HH:mm:ss"));
    ui->CountDown_label->setStyleSheet("color: rgb(85, 255, 0);");
    ui->CountDown_label->setText(timeStr);

}
// 初始化
void MainWindow::InitialStatus()
{
    // 设置系统时间字体颜色
    ui->systemTime_label->setStyleSheet("color: rgb(0, 0, 0);");
    ui->systemTime_label->setAlignment(Qt::AlignCenter);

    // 设置倒计时字体颜色时间
    QFont font("微软雅黑");
    font.setPointSize(80);

    ui->CountDown_label->setFont(font);
    ui->CountDown_label->setStyleSheet("color: rgb(255, 255, 0);");
    ui->CountDown_label->setAlignment(Qt::AlignCenter);
    ui->CountDown_label->setText("00:00:00");

    // 设置时间控件默认时间
    QTime curTime = QTime::currentTime();
    int beijing_hour = curTime.hour();
    int UTC_hour = 0;
    int min = curTime.minute();

    if((min+=10) >= 60)
    {
        beijing_hour+=1;
        min %= 60;
    }
    beijing_hour<8? UTC_hour=24-(8-beijing_hour): UTC_hour=beijing_hour-8;
    QTime inputBJ_Time(beijing_hour,min,0);
    QTime inputUTC_Time(UTC_hour,min,0);
    ui->BeiJing_timeEdit->setTime(inputBJ_Time);
    ui->UTC_timeEdit->setTime(inputUTC_Time);

}

// 输入联动
void MainWindow::on_BeiJing_timeEdit_userTimeChanged(const QTime &time)
{
    int hour = time.hour();
    int min = time.minute();
    int sec = time.second();

    int new_hour = 0;
    hour<8? new_hour=24-(8-hour): new_hour=hour-8;
    // 改UTC控件时间
    ui->UTC_timeEdit->setTime(QTime(new_hour,min,sec));
}

// 输入联动
void MainWindow::on_UTC_timeEdit_userTimeChanged(const QTime &time)
{
    int hour = time.hour();
    int min = time.minute();
    int sec = time.second();

    int new_hour = 0;
    hour>16? new_hour = hour+8-24: new_hour=hour+8;
    // 改BeiJing控件时间
    ui->BeiJing_timeEdit->setTime(QTime(new_hour,min,sec));
}

