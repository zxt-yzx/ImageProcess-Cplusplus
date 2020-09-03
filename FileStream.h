/**
COPYRIGHT NOTICE
Copyright (c) 2020,���пƼ���ѧ����Ȩ������
All rights reserved.

@file  (FileStream.h)
@brief (ʵ�ֻ������ļ���ȡ����)

����ʵ�ֵĹ��ܵ�����
��1��
��2��

@version 1.1	���汾������
@auther			��Zhiwei Zhou��
@date			��2020-09-02��

�޶��汾������汾
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
	/**��Mat����д���ı��ļ�*/
	template<typename T>			//opencv��ȡͼ������ʱ����Ҫ֪����������
	int writeTextFile(Mat array, string path, string headers,int _Mode);
	/**���ı��ļ��ж������ݵ�Mat������*/
	int readTextFile(Mat& array, string path, int skipRows);

	/**��Mat����д���ı��ļ�*/
	int writeBinFile(Mat array, string path, string headers,int _Mode);
	/**���ı��ļ��ж������ݵ�Mat������*/
	int readBinFile(Mat& array, string path, int skipRows,int _Mode);
};
