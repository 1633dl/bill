#include<iostream>
using namespace std;
class person
{
public:
	float breakfast, lunch, dinner;
	float sum;//总计
	float juice;//果汁
	float online;//网上购物
	float market;//超市购物
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
	void begin_write();//输入数据
};