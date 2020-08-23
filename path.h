#pragma once

#include<string>
#include<vector>
using namespace std;

class Path
{
public:
	string getCurrentWorkDir();				//��ȡ��ǰ����Ŀ¼
	bool isdir(string path);				//�Ƿ����ļ���
	bool isfile(string filename);			//�Ƿ����ļ�
	vector<string> split(string path);		//������ļ��� �ļ���������'\'�ָ�
	string splitext(string path);			//�������׺  ������'.'�ָ�
};
