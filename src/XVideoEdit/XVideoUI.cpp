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
	setWindowFlags(Qt::FramelessWindowHint);//���ر�����

	//ԭ��Ƶ��ʾ �źźͲ�
	qRegisterMetaType<cv::Mat>("cv::Mat");
	QObject::connect(XVideoThread::Get(),
		SIGNAL(ViewImge1(cv::Mat)),
		ui.src1video,
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
	double pos = XVideoThread::Get()->GetPos();
	ui.playSlider->setValue(pos * 1000);
}