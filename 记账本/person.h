#include<iostream>
using namespace std;
class person
{
public:
	float breakfast, lunch, dinner;
	float sum;//�ܼ�
	float juice;//��֭
	float online;//���Ϲ���
	float market;//���й���
	person& operator=(person&p)
	{
		this->breakfast = p.breakfast;
		this->lunch = p.lunch;
		this->dinner = p.dinner;
		this->juice = p.juice;
		this->online = p.online;
		this->market = p.market;
		this->sum = p.sum;
		return *this;
	}
	void begin_write();//��������
};