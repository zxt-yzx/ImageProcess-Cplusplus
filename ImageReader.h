#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageReader
{
	//����
	Mat img;	//��ȡ����ͼ��
	string path;//��ȡ�ļ���·��

	//�м����
	string imageType;	//ͼ�������

	//��ȡͼ��
	void read();			//��ȡͼ��
};