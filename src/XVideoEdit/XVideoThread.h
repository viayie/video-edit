#pragma once
#include <QThread>
#include <opencv2/core.hpp>
class XVideoThread:public QThread
{
	Q_OBJECT

public:
	~XVideoThread();

	//�߳���ں���
	void run();

	//����ƵԴ�ļ�1
	bool Open(const std::string file);

	//����ģʽ ��ȡ����
	static XVideoThread *Get()
	{
		static XVideoThread vt;
		return &vt;
	}

	//���ص�ǰ����λ��
	double GetPos();

	//��������ת��Ƶ
	bool Seek(int frame);
	bool Seek(double pos);

public:
	int fps = 0;

protected:
	XVideoThread();
	QMutex mutex;


signals:
	//��ʾԭ��Ƶ1ͼ��
	void ViewImge1(cv::Mat mat);
	//��ʾ������Ƶͼ��
	void ViewDes(cv::Mat mat);
};

