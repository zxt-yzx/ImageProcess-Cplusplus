#define _CRT_SECURE_NO_WARNINGS
#include"FileStream.h"
#include"Path.h"




/**
文件输入输出方式设置值
ios::in		以输入方式打开文件
ios::out	以输出方式打开文件（默认方式），如果已经有此名字的文件，则将其原有的内容全部清除
ios::app	以输出方式打开文件，写入的数据添加在文件末尾


目前仅仅支持单通道数组的读写

既然使用的是矩阵，那么就表示是单通道的数据
#define CV_8U   0	uchar		
#define CV_8S   1	char
#define CV_16U  2	ushort
#define CV_16S  3	short
#define CV_32S  4	int
#define CV_32F  5	float
#define CV_64F  6	double
*/

/**将Mat矩阵写入文本文件*/
template<typename T>
int FileStream::writeTextFile(Mat array, string filename, string headers,int _Mode)
{
	ofstream fout;
	fout.open(filename, _Mode);
	if (!headers.empty())	//如果字符串不为空，那么将字符串写入到文件中
		fout << headers << endl;	//endl结束一行

	///解析一下文件名是txt文件还是csv文件
	///".txt"  delim='\t'
	///".csv"  delim=','
	char delim;
	if (Path().splitext(filename) == ".csv") delim = ','; else if (Path().splitext(filename) == ".txt") delim = '\t';

	for (int row = 0; row < array.rows; row++)				///行
	{
		T* p = array.ptr<T>(row);							///获取了第row行指针
		for (int col = 0; col < array.cols; col++)
		{
			T data = p[col];								///获取了第row行第col列的数据
			//将第row行数据输出到file中
			if (col != array.cols - 1)
			{
				fout << data << delim;
			}
			else fout << data << endl;
		}
	}

	return 0;
}

/**从文本文件中读入数据到Mat数组中*/
int FileStream::readTextFile(Mat& array, string filename, int skipRows)
{
	vector<double> vec;
	ifstream fin;
	fin.open(filename);

	skipRows++;			//跳过首行时  skipRows=0  ;跳过skipRow行时，skipRows=skipRows+1;
	while (skipRows--) getline(fin, string());

	/**判断文件分割的方式*/
	///解析一下文件名是txt文件还是csv文件
	///".txt"  delim='\t'
	///".csv"  delim=','
	char delim;
	if (Path().splitext(filename) == ".csv") delim = ','; else if (Path().splitext(filename) == ".txt") delim = '\t';


	vector<double> arrayLineDouble;
	string stringData;

	int cols = 0;

	while (getline(fin,stringData))		//读取一行，getline将读取到的字符放入到stringData中，读取到'\n'结束;当读取到文件末尾时结束读取
	{
		vector<string> arrayLinString = Path().split(stringData,delim);
		cols = arrayLinString.size();	//列数
		for (int i = 0; i < arrayLinString.size(); i++)
		{
			arrayLineDouble.push_back(atof(arrayLinString[i].c_str()));		//将字符串转换为数值类型
		}
	}

	//将vector转换为Mat
	array = Mat(arrayLineDouble);
	array = array.reshape(cols, arrayLineDouble.size() / cols).clone();		//这里因为函数内部局部变量的生命周期已经结束，而Mat类的拷贝是浅拷贝，所以会有Mat(arrayLinDouble的析构问题，因此需要做一次深拷贝)
	//cout << "data" << endl;
	//cout << data;
	return 0;
}

/**将Mat矩阵写入文本文件

从文件中提取的所有数据最终都转换为double类型
*/
int FileStream::writeBinFile(Mat array, string path, string headers, int _Mode)
{
	return 0;
}

/**从文本文件中读入数据到Mat数组中*/
int FileStream::readBinFile(Mat& array, string path, int skipRows,int _Mode)
{
	return 0;
}

void testFileStream()
{
	/**向csv或txt文本文件中写入array*/
	Mat array = Mat::ones(10, 10, CV_64F); string filename = "mat.csv";
	cout << "输入的array:" << endl;
	cout << array<<endl;
	//Mat array = Mat::zeros(10, 10, CV_64F); string filename = "mat.txt";
	FileStream fileStream;
	fileStream.writeTextFile<double>(array, filename, string("a,b,c,d"), ios::out);
	//fileStream.writeTextFile<double>(array, filename, string("a\tb\tc\td"), ios::out);

	/**向csv或txt文本文件中写入array*/
	Mat array1;
	fileStream.readTextFile(array1, filename, 0);	//头
	cout << "读取的array1:" << endl;
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