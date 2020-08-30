#include"Path.h"
#include<direct.h>
#include<io.h>

//1����������ǿ��Դ洢'\'��
//2��_getcwd()��ֱ�ӽ�'\'�洢���ڴ��е�
//3�������ֶ����ڴ��д洢'\'��Ҫ"\\"
string Path::getCurrentWorkDir()
{
	char buff[1000];
	_getcwd(buff, 1000);
	return string(buff);	//���ػ�ȡ�ĵ�ǰ��ַ string
}


/*
ͷ�ļ���<io.h>
����ԭ�ͣ�int _access(const char *pathname, int mode);
������pathname Ϊ�ļ�·����Ŀ¼·�� mode Ϊ����Ȩ�ޣ��ڲ�ͬϵͳ�п����ò��ܵĺ궨�����¶��壩
����ֵ������ļ�����ָ���ķ���Ȩ�ޣ���������0������ļ������ڻ��߲��ܷ���ָ����Ȩ�ޣ��򷵻�-1.
��ע����pathnameΪ�ļ�ʱ��_access�����ж��ļ��Ƿ���ڣ����ж��ļ��Ƿ������modeֵָ����ģʽ���з��ʡ���pathnameΪĿ¼ʱ��_accessֻ�ж�ָ��Ŀ¼�Ƿ���ڣ���Windows NT��Windows 2000�У����е�Ŀ¼��ֻ�ж�дȨ�ޡ�
mode��ֵ�ͺ���������ʾ��
00����ֻ����ļ��Ƿ����
02����дȨ��
04������Ȩ��
06������дȨ��
*/
bool Path::isdir(string path)	//�Ƿ����ļ���
{
	if (_access(path.c_str(), 0) != -1)
		return true;
	else
		return false;
}

bool Path::isfile(string filename)	//�Ƿ����ļ�
{
	if (_access(filename.c_str(), 0) != -1)
		return true;
	else
		return false;
}

vector<string> Path::split(string path)		//������ļ��� �ļ���������'\'�ָ�
{
	int index = path.find_last_of("\\");	//����R"+*(\)+*"   Ҳ������"\\"����ʾ '\'
	string dir = path.substr(0, index);
	string filename = path.substr(index + 1);
	vector<string> a;
	a.push_back(dir);		//a[0]  dir
	a.push_back(filename);  //a[1]  filename
	return a;
}

string Path::splitext(string path)	//�������׺  ������'.'�ָ�
{
	int index = path.find_last_of(".");	//����R"+*(\)+*"   Ҳ������"\\"����ʾ '\'
	string fileType = path.substr(index);

	return fileType;
}