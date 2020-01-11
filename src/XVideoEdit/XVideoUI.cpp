#include "XVideoUI.h"
#include <QFileDialog>
#include <string>
#include <iostream>
#include <QMessageBox>
#include "XVideoThread.h"
#include "XFilter.h"
using namespace std;

static bool pressSlider = false;//判断是否按压进度条

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

	//输出视频显示 信号和槽
	QObject::connect(XVideoThread::Get(),
		SIGNAL(ViewDes(cv::Mat)),
		ui.desvideo,
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
	if (pressSlider)	return;//如果按压进度条就不刷新了

	double pos = XVideoThread::Get()->GetPos();
	ui.playSlider->setValue(pos * 1000);
}

void XVideoUI::SliderPress()
{
	pressSlider = true;
}

void XVideoUI::SliderRelease()
{
	pressSlider = false;
}

void XVideoUI::SetPos(int pos)//滑动条拖动
{
	XVideoThread::Get()->Seek((double)pos / 1000.0);
}

void XVideoUI::Set()//设置过滤器
{
	XFilter::Get()->Clear();

	//对比度和亮度
	if (ui.bright->value() > 0 || ui.contrast->value() > 1.0) {
		XFilter::Get()->Add(XTask{
			XTASK_GAIN,//类型
			{(double)ui.bright->value(), ui.contrast->value()}//参数
		});
	}
}