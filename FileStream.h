/**
COPYRIGHT NOTICE
Copyright (c) 2020,华中科技大学（版权声明）
All rights reserved.

@file  (FileStream.h)
@brief (实现基本的文件读取功能)

本文实现的功能的详述
【1】
【2】

@version 1.1	（版本声明）
@auther			（Zhiwei Zhou）
@date			（2020-09-02）

修订版本：最初版本
*/

#pragma once

#include<iostream>
#include <fstream>
#include<string>
#include<vector>
#include"opencv.hpp"
using namespace std;
using namespace cv;



class FileStream
{
public:
	/**将Mat矩阵写入文本文件*/
	template<typename T>			//opencv读取图像数据时候需要知道数据类型
	int writeTextFile(Mat array, string path, string headers,int _Mode);
	/**从文本文件中读入数据到Mat数组中*/
	int readTextFile(Mat& array, string path, int skipRows);

	/**将Mat矩阵写入文本文件*/
	int writeBinFile(Mat array, string path, string headers,int _Mode);
	/**从文本文件中读入数据到Mat数组中*/
	int readBinFile(Mat& array, string path, int skipRows,int _Mode);
};
