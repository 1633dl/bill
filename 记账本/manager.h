#include<iostream>
using namespace std;
#include"person.h"
#include<fstream>
#include<string>
#define FILENAME "�¼��˱�.txt"
class manager
{
public:
	manager();
	~manager();
	int month;//�·�
	int day;//����
	int m_day;//ÿ���µ�����
	bool is_begin;//�ж�������Ƿ񴴽�
	float sum;//ÿ�µ��ܼ�
	person *bill;

	//��ֵ���������
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
	void into_txt(int begin_day);//��¼���ĵ�����
	void  read_txt();//���ļ�
	void show();
	void creat_data();//��������
};