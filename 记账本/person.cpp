#include"person.h"
void person::begin_write()//��������
{
	cout << "�緹"; cin >> this->breakfast;
	cout << "�緹"; cin >> this->lunch;
	cout << "��"; cin >> this->dinner;
	cout << "��֭"; cin >> this->juice;
	cout << "���Ϲ���"; cin >> this->online;
	cout << "���й���"; cin >> this->market;
	this->sum = breakfast + lunch + dinner + juice + online + market;
}