#include "XVideoUI.h"
#include <QFileDialog>
#include <string>
#include <iostream>
#include <QMessageBox>
#include "XVideoThread.h"
using namespace std;
XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);//隐藏标题栏

	//原视频显示 信号和槽
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::Get(),
		SIGNAL(ViewImge1(cv::Mat)),
		ui.src1video,
		SLOT(SetImage(cv::Mat))
		);

	//定时刷新进度条
	startTimer(40);
}

void XVideoUI::Open()
{
	QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("请选择视频文件"));
	if (name.isEmpty())	return;
	string file = name.toLocal8Bit().data();//中文路径
	if (!XVideoThread::Get()->Open(file))
	{
		QMessageBox::information(0, "err", name + "open failed");
	}
}

//定时刷新进度条
void XVideoUI::timerEvent(QTimerEvent *e)
{
	double pos = XVideoThread::Get()->GetPos();
	ui.playSlider->setValue(pos * 1000);
}