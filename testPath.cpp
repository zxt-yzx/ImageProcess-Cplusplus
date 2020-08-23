#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"path.h"

void testString()
{
	//字符串的构造
	string *s1 = new string("hello");
	delete s1;
	string s2("hello");
	string s3;
	s3 = "hello";
	string s4 = "hello";

	//字符串处理函数
	cout << s4.append("//he") << endl;	//字符串末尾添加新值
	cout << "current s4:" << s4 << endl;
	cout << s4.assign("zhou") << endl;	//修改字符串值
	cout << "current s4:" << s4 << endl;
	cout << s4.at(1) << endl;	//返回索引下的值
	cout << s4.c_str() << endl; //以c数组的形式返回
	cout << s4.compare("hello") << endl;
	
	//分离路径的文件夹及文件名
	string path = R"+*(E:\code\ccplus\Cplus\ImageProcess\ImageProcess\ImageReader.h)+*";	//C++中不使用转义字符
	int index = path.find_last_of("\\");	//查找R"+*(\)+*"   也可以用"\\"来表示 '\'
	string dir = path.substr(0, index);
	string filename = path.substr(index+1);
	cout << "dir:" << dir << endl;
	cout << "filename:"<<filename << endl;

	cout <<"构造string"<<string("hello") << endl;
	
}

void testPath()
{
	Path path;
	cout << path.getCurrentWorkDir() << endl;
	cout << path.isdir("E:/deepLearning-Methd") << endl;
	cout << path.isfile(R"*+(E:\code\学习笔记\C++基础课程讲义.dox)*+") << endl;
	vector<string> file = path.split(R"*+(E:\code\学习笔记\C++基础课程讲义.dox)*+");
	string dir = file[0];
	string filename = file[1];
	cout << dir << endl;			
	cout << filename << endl;

	cout << path.splitext(R"*+(E:\code\学习笔记\C++基础课程讲义.dox)*+") << endl;;
}

void main()
{
	//testString();
	testPath();
	system("pause");
}