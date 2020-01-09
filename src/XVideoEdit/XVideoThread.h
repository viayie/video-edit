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

public:
	int fps = 0;

protected:
	XVideoThread();
	QMutex mutex;


signals:
	void ViewImge1(cv::Mat mat);
};

