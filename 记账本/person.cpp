#include"person.h"
void person::begin_write()//输入数据
{
	cout << "早饭"; cin >> this->breakfast;
	cout << "午饭"; cin >> this->lunch;
	cout << "晚饭"; cin >> this->dinner;
	cout << "果汁"; cin >> this->juice;
	cout << "网上购物"; cin >> this->online;
	cout << "超市购物"; cin >> this->market;
	this->sum = breakfast + lunch + dinner + juice + online + market;
}