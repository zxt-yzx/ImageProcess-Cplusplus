#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageWriter
{
	//输入
	Mat img;	//待写入的图像
	string path;//写入文件的路径

	//中间变量
	string imageType;	//写入图像的类型

	bool write();	    //写入图像 
};