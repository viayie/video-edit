#include "XImagePro.h"

//����ԭͼ������������
void XImagePro::Set(cv::Mat mat1, cv::Mat mat2)
{
	if (mat1.empty())return;
	this->src1 = mat1;
	this->src2 = mat2;
	this->src1.copyTo(des);
}

//�������ȺͶԱȶ�
///@para bright double ���� 0~100
///@para contrast int �Աȶ� 1.0 ~ 3.0
void XImagePro::Gain(double bright, double contrast)
{
	if (des.empty())return;
	des.convertTo(des, -1, contrast, bright);
}
XImagePro::XImagePro()
{
}


XImagePro::~XImagePro()
{
}

