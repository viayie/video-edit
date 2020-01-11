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

	//返回当前播放位置
	double GetPos();

	//进度条跳转视频
	bool Seek(int frame);
	bool Seek(double pos);

public:
	int fps = 0;

protected:
	XVideoThread();
	QMutex mutex;


signals:
	//显示原视频1图像
	void ViewImge1(cv::Mat mat);
	//显示生成视频图像
	void ViewDes(cv::Mat mat);
};

