#pragma once

#include<string>
#include<vector>
using namespace std;

class Path
{
public:
	string getCurrentWorkDir();				//获取当前工作目录
	bool isdir(string path);				//是否是文件夹
	bool isfile(string filename);			//是否是文件
	vector<string> split(string path);		//分离出文件夹 文件名，按照'\'分割
	string splitext(string path);			//分离出后缀  ，按照'.'分割
};
