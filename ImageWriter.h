#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageWriter
{
	//����
	Mat img;	//��д���ͼ��
	string path;//д���ļ���·��

	//�м����
	string imageType;	//д��ͼ�������

	bool write();	    //д��ͼ�� 
};