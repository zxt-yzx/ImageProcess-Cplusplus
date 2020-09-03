/**
* COPYRIGHT NOTICE
* Copyright (c) 2009,���пƼ���ѧ����Ȩ������
* All rights reserved.
*
* @file (���ļ����ļ���eg:Test.h)
* @brief (���ļ�ʵ�ֵĹ��ܵļ���)
*
* @version 1.1	���汾������
* @auther		�����ߣ�
* @date			���ļ��������ڣ�eg2009��7��15�գ�
*
* �޶��汾������汾
*/

#include"ImageIO.h"

/**   ��ȡͼ��
*
*     @param path string���ͱ���������Ŵ���ȡͼ���·��
*     @return img Mat����ͼ��
*     @note    ����img�Ǵ�������ʱ�洢����Ȼ�󽫷���ֵ������������Mat����
*/
Mat ImageIO::read(string path)
{
	Mat img = imread(path.c_str(),cv::IMREAD_UNCHANGED);	//��ȡͼ��
	return img;
}

/**   д��ͼ��
*
*     @param path string���ͱ���������Ŵ�����ͼ���·��
*     @param img  Mat	���ͱ���������Ŵ�����ͼ��
*     @return void
*     @note    
*/
void ImageIO::write(string path, Mat img)
{
	imwrite(path.c_str(), img);
}





/****************ͼ���ȡstage***********************/
void testImageIO()
{
	string path = R"*+(F:\code\ccplus\Cplus\ImageProcess\ImageProcess\imageData\img-RGB.tif)*+";
	ImageIO imgR;
	Mat img = imgR.read(path);		//ͼ��Ķ�ȡ

	path = R"*+(F:\code\ccplus\Cplus\ImageProcess\ImageProcess\imageData\img1-RGB.bmp)*+";
	imgR.write(path, img);

	return;
}