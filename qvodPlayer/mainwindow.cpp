#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //设置主界面背景
    QPixmap pixmap(":/image/background.jpg");
    QPalette palette;
    palette.setBrush(backgroundRole(), QBrush(pixmap));
    setPalette(palette);

    //创建mediaplayer
    QMediaPlayer * mediaPlayer = new QMediaPlayer(this);
    //设置mediaplayer对应的QVideoWidget 播放窗口
    mediaPlayer->setVideoOutput(ui->videoWidget);

    //设置播放属性
//    //1、监听信号变化函数
//    connect(this->mediaPlayer, &QMediaPlayer::stateChanged, this, &MainWindow::mediaStateChanged);
//    //2、播放进度信号变化函数
//    connect(this->mediaPlayer, &QMediaPlayer::positionChanged, this, &MainWindow::changePosition);
//    //3、播放信号长度变化
//    connect(this->mediaPlayer, &QMediaPlayer::durationChanged, this, &MainWindow::durationChanged);


    //设置播放内容
    mediaPlayer->setMedia(QUrl::fromLocalFile("D://qycache//download//水调歌头MV版//output.mp4"));


    //设置播放按钮
    ui->toolButton->setToolTip("播放");
    ui->toolButton->setAutoRaise(true);
    ui->toolButton->setIcon(QPixmap(":/image/播放white.png"));

}

MainWindow::~MainWindow()
{
    delete ui;
    if (mediaPlayer != nullptr) {
        delete mediaPlayer;
        mediaPlayer = nullptr;
    }
}

void MainWindow::play() {
    //获取播放状态
//    switch (mediaPlayer->state()) {
//        case QMediaPlayer::PlayingState:
//            mediaPlayer->pause();
//            break;
//    default:
//        mediaPlayer->play();
//        break;
//    }
    qDebug() << "HERE" << endl;
    QMediaPlayer::State playerState = this->mediaPlayer->state();
    if (playerState == QMediaPlayer::PlayingState) {
        this->mediaPlayer->pause();
    }
    else {
        this->mediaPlayer->play();
    }
}

void MainWindow::mediaStateChanged(QMediaPlayer::State state) {
    //mediaplayer播放状态

}

void MainWindow::changePosition(qint64 position) {
    //设置mediaplayer播放过程中动态调整播放进度

}

void MainWindow::setPosition(int position) {
    //获取mediaplayer进度条调整位置

}

void MainWindow::durationChanged(qint64 position) {
    //设置进度条的范围

}


void MainWindow::on_toolButton_clicked()
{
//    play();
    //设置播放按钮暂停样式
    ui->toolButton->setToolTip("暂停");
    ui->toolButton->setIcon(QPixmap(":/image/暂停white.png"));
}


