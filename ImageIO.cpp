#include"ImageIO.h"

/**
目前已经验证能够读取如下这些图像类型
RGB图像：
	.png\.bmp\.tif
32bit图像
	.png\.bmp\.tif
16bit图像
	.png\.bmp\.tif
8bit图像
	.png\.bmp\.tif
*	
*/
Mat ImageIO::read(string path)
{
	Mat img = imread(path.c_str(),cv::IMREAD_UNCHANGED);	//读取图像
	return img;
}

/**
*目前已经验证能够写入如下这些图像类型
*RGB图像：
*	.png\.bmp\.tif
*32bit图像
*	.png\.bmp\.tif
*16bit图像
*	.png\.bmp\.tif
*8bit图像
*	.png\.bmp\.tif
*/
void ImageIO::write(string path, Mat img)
{
	imwrite(path.c_str(), img);
}
