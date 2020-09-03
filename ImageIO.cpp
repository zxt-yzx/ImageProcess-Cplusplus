/**
* COPYRIGHT NOTICE
* Copyright (c) 2009,华中科技大学（版权声明）
* All rights reserved.
*
* @file (本文件的文件名eg:Test.h)
* @brief (本文件实现的功能的简述)
*
* @version 1.1	（版本声明）
* @auther		（作者）
* @date			（文件创建日期，eg2009年7月15日）
*
* 修订版本：最初版本
*/

#include"ImageIO.h"

/**   读取图像
*
*     @param path string类型变量，存放着待读取图像的路径
*     @return img Mat类型图像
*     @note    返回img是创建了临时存储区域，然后将返回值拷贝给主函数Mat变量
*/
Mat ImageIO::read(string path)
{
	Mat img = imread(path.c_str(),cv::IMREAD_UNCHANGED);	//读取图像
	return img;
}

/**   写入图像
*
*     @param path string类型变量，存放着待保存图像的路径
*     @param img  Mat	类型变量，存放着待保存图像
*     @return void
*     @note    
*/
void ImageIO::write(string path, Mat img)
{
	imwrite(path.c_str(), img);
}





/****************图像读取stage***********************/
void testImageIO()
{
	string path = R"*+(F:\code\ccplus\Cplus\ImageProcess\ImageProcess\imageData\img-RGB.tif)*+";
	ImageIO imgR;
	Mat img = imgR.read(path);		//图像的读取

	path = R"*+(F:\code\ccplus\Cplus\ImageProcess\ImageProcess\imageData\img1-RGB.bmp)*+";
	imgR.write(path, img);

	return;
}