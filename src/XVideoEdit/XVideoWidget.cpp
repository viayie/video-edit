#include "XVideoWidget.h"
#include <QPainter>
#include <opencv2/imgproc.hpp>
using namespace cv;
void XVideoWidget::paintEvent(QPaintEvent *e)
{
	QPainter p;
	p.begin(this);
	p.drawImage(QPoint(0, 0), img);
	p.end();
}

XVideoWidget::XVideoWidget(QWidget *p):QOpenGLWidget(p)
{
}


XVideoWidget::~XVideoWidget()
{
}

void XVideoWidget::SetImage(cv::Mat mat)
{
	if (img.isNull()) {
		uchar *buf = new uchar[width() * height() * 3];
		img = QImage(buf, width(), height(), QImage::Format_RGB888);
	}
	Mat des;
	cv::resize(mat, des, Size(img.size().width(), img.size().height()));
	cv::cvtColor(des, des, COLOR_BGR2RGB);
	memcpy(img.bits(), des.data, des.cols * des.rows * des.elemSize());
	
	update();//刷新界面,调用paintEvent
}
