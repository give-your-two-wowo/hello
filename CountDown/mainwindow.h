#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QTime>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    // 开始按钮槽
    void on_Start_pushButton_clicked();
    // 复位按钮槽
    void on_Reset_pushButton_clicked();
    // 显示系统时间定时器槽
    void m_sysTimeTimer_timeout();
    // 倒计时定时器槽
    void on_lastTimer_timeout();
    // 正计时定时器槽
    void on_fristTimer_timeout();

    void on_BeiJing_timeEdit_userTimeChanged(const QTime &time);

    void on_UTC_timeEdit_userTimeChanged(const QTime &time);

private:
    // 软件初始显示状态
    void InitialStatus();

private:
    Ui::MainWindow *ui;
    QTime m_setTime;
    QTime m_curTime;
    QTimer* m_sysTimeTimer;
    QTimer* m_lastTimer;
    QTimer* m_fristTimer;
};
#endif // MAINWINDOW_H
