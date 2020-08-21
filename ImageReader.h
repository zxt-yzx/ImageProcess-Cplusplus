#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageReader
{
	//输入
	Mat img;	//读取到的图像
	string path;//读取文件的路径

	//中间变量
	string imageType;	//图像的类型

	//读取图像
	void read();			//读取图像
};