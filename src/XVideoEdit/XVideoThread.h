#pragma once
#include <QThread>
#include <opencv2/core.hpp>
class XVideoThread:public QThread
{
	Q_OBJECT

public:
	~XVideoThread();

	//线程入口函数
	void run();
	//打开视频源文件1
	bool Open(const std::string file);
	//单件模式 获取对象
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

