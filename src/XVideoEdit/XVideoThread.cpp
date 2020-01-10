#include "XVideoThread.h"
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>
using namespace std;
using namespace cv;

//视频源1
static VideoCapture cap1;
static bool isExit = false;//软件是否退出

XVideoThread::XVideoThread()
{
	start();
}

XVideoThread::~XVideoThread()
{
	mutex.lock();
	isExit = true;
	mutex.unlock();
}

//线程入口函数
void XVideoThread::run()
{
	Mat mat1;
	for (;;) {
		mutex.lock();
		if (isExit) {
			mutex.unlock();
			break;
		}
		//判断视频是否打开
		if (!cap1.isOpened()) {
			mutex.unlock();
			msleep(5);
			continue;
		}
		//读取一帧视频，解码并颜色转换
		if (!cap1.read(mat1) || mat1.empty()) {
			mutex.unlock();
			msleep(5);
			continue;
		}
		//显示图像
		ViewImge1(mat1);
		//msleep(40);
		int s = 1000/fps;
		msleep(s);
		mutex.unlock();
	}
}

//打开视频源文件1
bool XVideoThread::Open(const std::string file)
{
	mutex.lock();
	bool re = cap1.open(file);
	mutex.unlock();
	cout << "open " << file << ":" << re << endl;
	if(!re) 
		return re;
	fps = cap1.get(CAP_PROP_FPS);
	if (fps <= 0)
		fps = 25;
	return true;
}

double XVideoThread::GetPos()
{
	double pos = 0;
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return pos;
	}
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	double cur = cap1.get(CAP_PROP_POS_FRAMES);
	if(count > 0.001)
		pos = cur / count;//算出比例
	mutex.unlock();
	return pos;
}

//跳转视频 
///@para frame int 帧位置
bool XVideoThread::Seek(int frame)
{
	mutex.lock();
	if (!cap1.isOpened()) {
		mutex.unlock();
		return false;
	}

	int re = cap1.set(CAP_PROP_POS_FRAMES, frame);

	mutex.unlock();
	return re;
}

bool XVideoThread::Seek(double pos)
{
	double count = cap1.get(CAP_PROP_FRAME_COUNT);
	int frame = pos * count;
	return Seek(frame);
}