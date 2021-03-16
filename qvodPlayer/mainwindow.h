#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include <QMediaPlayer>
#include <QUrl>
#include <QDebug>

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
    void on_toolButton_clicked();

private:
    Ui::MainWindow *ui;

    QMediaPlayer * mediaPlayer;//QVideoWidget

    //播放
    void play();
    //播放状态
    void mediaStateChanged(QMediaPlayer::State state);
    //改变播放位置
    void changePosition(qint64 position);
    //获取播放位置
    void setPosition(int position);
    //播放长度
    void durationChanged(qint64 position);


};
#endif // MAINWINDOW_H
