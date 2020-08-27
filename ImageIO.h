#pragma once

#include "opencv.hpp"
#include <iostream>
#include <string>
using namespace std;
using namespace cv;

class ImageIO
{
public:

	Mat read(string path);				//¶ÁÈ¡Í¼Ïñ
	void write(string path, Mat img);	//Ğ´ÈëÍ¼Ïñ
};