#include"Path.h"
#include<direct.h>
#include<io.h>

//1）计算机中是可以存储'\'的
//2）_getcwd()是直接将'\'存储在内存中的
//3）我们手动向内存中存储'\'需要"\\"
string Path::getCurrentWorkDir()
{
	char buff[1000];
	_getcwd(buff, 1000);
	return string(buff);	//返回获取的当前地址 string
}


/*
头文件：<io.h>
函数原型：int _access(const char *pathname, int mode);
参数：pathname 为文件路径或目录路径 mode 为访问权限（在不同系统中可能用不能的宏定义重新定义）
返回值：如果文件具有指定的访问权限，则函数返回0；如果文件不存在或者不能访问指定的权限，则返回-1.
备注：当pathname为文件时，_access函数判断文件是否存在，并判断文件是否可以用mode值指定的模式进行访问。当pathname为目录时，_access只判断指定目录是否存在，在Windows NT和Windows 2000中，所有的目录都只有读写权限。
mode的值和含义如下所示：
00——只检查文件是否存在
02——写权限
04——读权限
06——读写权限
*/
bool Path::isdir(string path)	//是否是文件夹
{
	if (_access(path.c_str(), 0) != -1)
		return true;
	else
		return false;
}

bool Path::isfile(string filename)	//是否是文件
{
	if (_access(filename.c_str(), 0) != -1)
		return true;
	else
		return false;
}

vector<string> Path::split(string path)		//分离出文件夹 文件名，按照'\'分割
{
	int index = path.find_last_of("\\");	//查找R"+*(\)+*"   也可以用"\\"来表示 '\'
	string dir = path.substr(0, index);
	string filename = path.substr(index + 1);
	vector<string> a;
	a.push_back(dir);		//a[0]  dir
	a.push_back(filename);  //a[1]  filename
	return a;
}

string Path::splitext(string path)	//分离出后缀  ，按照'.'分割
{
	int index = path.find_last_of(".");	//查找R"+*(\)+*"   也可以用"\\"来表示 '\'
	string fileType = path.substr(index);

	return fileType;
}