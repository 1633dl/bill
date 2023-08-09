#include<iostream>
using namespace std;
#include"person.h"
#include<fstream>
#include<string>
#define FILENAME "新记账本.txt"
class manager
{
public:
	manager();
	~manager();
	int month;//月份
	int day;//日期
	int m_day;//每个月的天数
	bool is_begin;//判断这个月是否创建
	float sum;//每月的总计
	person *bill;

	//赋值运算符重载
	manager& operator=(manager&m)
	{
		if (this->bill != NULL)
		{
			delete[]bill;
			bill = NULL;
		}
		this->month = m.month;
		this->day = m.day;
		this->m_day = m.m_day;
		this->is_begin = m.is_begin;
		this->sum = m.sum;

		bill = new person[m_day];
		for (int i = 0; i < this->day; i++)
		{
			bill[i] = m.bill[i];
		}
		return *this;
	}
	void into_txt(int begin_day);//记录到文档里面
	void  read_txt();//读文件
	void show();
	void creat_data();//创建数据
};