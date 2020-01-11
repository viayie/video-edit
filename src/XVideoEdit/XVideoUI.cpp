#include "XVideoUI.h"
#include <QFileDialog>
#include <string>
#include <iostream>
#include <QMessageBox>
#include "XVideoThread.h"
#include "XFilter.h"
using namespace std;

static bool pressSlider = false;//�ж��Ƿ�ѹ������

XVideoUI::XVideoUI(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);//���ر�����

	//ԭ��Ƶ��ʾ �źźͲ�
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::Get(),
		SIGNAL(ViewImge1(cv::Mat)),
		ui.src1video,
		SLOT(SetImage(cv::Mat))
		);

	//�����Ƶ��ʾ �źźͲ�
	QObject::connect(XVideoThread::Get(),
		SIGNAL(ViewDes(cv::Mat)),
		ui.desvideo,
		SLOT(SetImage(cv::Mat))
		);

	//��ʱˢ�½�����
	startTimer(40);
}

void XVideoUI::Open()
{
	QString name = QFileDialog::getOpenFileName(this, QString::fromLocal8Bit("��ѡ����Ƶ�ļ�"));
	if (name.isEmpty())	return;
	string file = name.toLocal8Bit().data();//����·��
	if (!XVideoThread::Get()->Open(file))
	{
		QMessageBox::information(0, "err", name + "open failed");
	}
}

//��ʱˢ�½�����
void XVideoUI::timerEvent(QTimerEvent *e)
{
	if (pressSlider)	return;//�����ѹ�������Ͳ�ˢ����

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

void XVideoUI::SetPos(int pos)//�������϶�
{
	XVideoThread::Get()->Seek((double)pos / 1000.0);
}

void XVideoUI::Set()//���ù�����
{
	XFilter::Get()->Clear();

	//�ԱȶȺ�����
	if (ui.bright->value() > 0 || ui.contrast->value() > 1.0) {
		XFilter::Get()->Add(XTask{
			XTASK_GAIN,//����
			{(double)ui.bright->value(), ui.contrast->value()}//����
		});
	}
}