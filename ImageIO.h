#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageIO
{
public:

	Mat read(string path);				//��ȡͼ��
	void write(string path, Mat img);	//д��ͼ��
};