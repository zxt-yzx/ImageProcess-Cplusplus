#include<iostream>
using namespace std;
#include<string>
#include<vector>
#include"path.h"

void testString()
{
	//�ַ����Ĺ���
	string *s1 = new string("hello");
	delete s1;
	string s2("hello");
	string s3;
	s3 = "hello";
	string s4 = "hello";

	//�ַ���������
	cout << s4.append("//he") << endl;	//�ַ���ĩβ�����ֵ
	cout << "current s4:" << s4 << endl;
	cout << s4.assign("zhou") << endl;	//�޸��ַ���ֵ
	cout << "current s4:" << s4 << endl;
	cout << s4.at(1) << endl;	//���������µ�ֵ
	cout << s4.c_str() << endl; //��c�������ʽ����
	cout << s4.compare("hello") << endl;
	
	//����·�����ļ��м��ļ���
	string path = R"+*(E:\code\ccplus\Cplus\ImageProcess\ImageProcess\ImageReader.h)+*";	//C++�в�ʹ��ת���ַ�
	int index = path.find_last_of("\\");	//����R"+*(\)+*"   Ҳ������"\\"����ʾ '\'
	string dir = path.substr(0, index);
	string filename = path.substr(index+1);
	cout << "dir:" << dir << endl;
	cout << "filename:"<<filename << endl;

	cout <<"����string"<<string("hello") << endl;
	
}

void testPath()
{
	Path path;
	cout << path.getCurrentWorkDir() << endl;
	cout << path.isdir("E:/deepLearning-Methd") << endl;
	cout << path.isfile(R"*+(E:\code\ѧϰ�ʼ�\C++�����γ̽���.dox)*+") << endl;
	vector<string> file = path.split(R"*+(E:\code\ѧϰ�ʼ�\C++�����γ̽���.dox)*+");
	string dir = file[0];
	string filename = file[1];
	cout << dir << endl;			
	cout << filename << endl;

	cout << path.splitext(R"*+(E:\code\ѧϰ�ʼ�\C++�����γ̽���.dox)*+") << endl;;
}

void main()
{
	//testString();
	testPath();
	system("pause");
}