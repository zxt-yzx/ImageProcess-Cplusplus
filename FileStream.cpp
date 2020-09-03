#define _CRT_SECURE_NO_WARNINGS
#include"FileStream.h"
#include"Path.h"




/**
�ļ����������ʽ����ֵ
ios::in		�����뷽ʽ���ļ�
ios::out	�������ʽ���ļ���Ĭ�Ϸ�ʽ��������Ѿ��д����ֵ��ļ�������ԭ�е�����ȫ�����
ios::app	�������ʽ���ļ���д�������������ļ�ĩβ


Ŀǰ����֧�ֵ�ͨ������Ķ�д

��Ȼʹ�õ��Ǿ�����ô�ͱ�ʾ�ǵ�ͨ��������
#define CV_8U   0	uchar		
#define CV_8S   1	char
#define CV_16U  2	ushort
#define CV_16S  3	short
#define CV_32S  4	int
#define CV_32F  5	float
#define CV_64F  6	double
*/

/**��Mat����д���ı��ļ�*/
template<typename T>
int FileStream::writeTextFile(Mat array, string filename, string headers,int _Mode)
{
	ofstream fout;
	fout.open(filename, _Mode);
	if (!headers.empty())	//����ַ�����Ϊ�գ���ô���ַ���д�뵽�ļ���
		fout << headers << endl;	//endl����һ��

	///����һ���ļ�����txt�ļ�����csv�ļ�
	///".txt"  delim='\t'
	///".csv"  delim=','
	char delim;
	if (Path().splitext(filename) == ".csv") delim = ','; else if (Path().splitext(filename) == ".txt") delim = '\t';

	for (int row = 0; row < array.rows; row++)				///��
	{
		T* p = array.ptr<T>(row);							///��ȡ�˵�row��ָ��
		for (int col = 0; col < array.cols; col++)
		{
			T data = p[col];								///��ȡ�˵�row�е�col�е�����
			//����row�����������file��
			if (col != array.cols - 1)
			{
				fout << data << delim;
			}
			else fout << data << endl;
		}
	}

	return 0;
}

/**���ı��ļ��ж������ݵ�Mat������*/
int FileStream::readTextFile(Mat& array, string filename, int skipRows)
{
	vector<double> vec;
	ifstream fin;
	fin.open(filename);

	skipRows++;			//��������ʱ  skipRows=0  ;����skipRow��ʱ��skipRows=skipRows+1;
	while (skipRows--) getline(fin, string());

	/**�ж��ļ��ָ�ķ�ʽ*/
	///����һ���ļ�����txt�ļ�����csv�ļ�
	///".txt"  delim='\t'
	///".csv"  delim=','
	char delim;
	if (Path().splitext(filename) == ".csv") delim = ','; else if (Path().splitext(filename) == ".txt") delim = '\t';


	vector<double> arrayLineDouble;
	string stringData;

	int cols = 0;

	while (getline(fin,stringData))		//��ȡһ�У�getline����ȡ�����ַ����뵽stringData�У���ȡ��'\n'����;����ȡ���ļ�ĩβʱ������ȡ
	{
		vector<string> arrayLinString = Path().split(stringData,delim);
		cols = arrayLinString.size();	//����
		for (int i = 0; i < arrayLinString.size(); i++)
		{
			arrayLineDouble.push_back(atof(arrayLinString[i].c_str()));		//���ַ���ת��Ϊ��ֵ����
		}
	}

	//��vectorת��ΪMat
	array = Mat(arrayLineDouble);
	array = array.reshape(cols, arrayLineDouble.size() / cols).clone();		//������Ϊ�����ڲ��ֲ����������������Ѿ���������Mat��Ŀ�����ǳ���������Ի���Mat(arrayLinDouble���������⣬�����Ҫ��һ�����)
	//cout << "data" << endl;
	//cout << data;
	return 0;
}

/**��Mat����д���ı��ļ�

���ļ�����ȡ�������������ն�ת��Ϊdouble����
*/
int FileStream::writeBinFile(Mat array, string path, string headers, int _Mode)
{
	return 0;
}

/**���ı��ļ��ж������ݵ�Mat������*/
int FileStream::readBinFile(Mat& array, string path, int skipRows,int _Mode)
{
	return 0;
}

void testFileStream()
{
	/**��csv��txt�ı��ļ���д��array*/
	Mat array = Mat::ones(10, 10, CV_64F); string filename = "mat.csv";
	cout << "�����array:" << endl;
	cout << array<<endl;
	//Mat array = Mat::zeros(10, 10, CV_64F); string filename = "mat.txt";
	FileStream fileStream;
	fileStream.writeTextFile<double>(array, filename, string("a,b,c,d"), ios::out);
	//fileStream.writeTextFile<double>(array, filename, string("a\tb\tc\td"), ios::out);

	/**��csv��txt�ı��ļ���д��array*/
	Mat array1;
	fileStream.readTextFile(array1, filename, 0);	//ͷ
	cout << "��ȡ��array1:" << endl;
	cout << array1 << endl;

	return;
}

//void main_FileStream()
void main()
{
	testFileStream();

	system("pause");
	return;
}