#include"ImageIO.h"

/**
Ŀǰ�Ѿ���֤�ܹ���ȡ������Щͼ������
RGBͼ��
	.png\.bmp\.tif
32bitͼ��
	.png\.bmp\.tif
16bitͼ��
	.png\.bmp\.tif
8bitͼ��
	.png\.bmp\.tif
*	
*/
Mat ImageIO::read(string path)
{
	Mat img = imread(path.c_str(),cv::IMREAD_UNCHANGED);	//��ȡͼ��
	return img;
}

/**
*Ŀǰ�Ѿ���֤�ܹ�д��������Щͼ������
*RGBͼ��
*	.png\.bmp\.tif
*32bitͼ��
*	.png\.bmp\.tif
*16bitͼ��
*	.png\.bmp\.tif
*8bitͼ��
*	.png\.bmp\.tif
*/
void ImageIO::write(string path, Mat img)
{
	imwrite(path.c_str(), img);
}
