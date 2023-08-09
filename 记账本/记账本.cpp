#include<iostream>
#include<fstream>
#include"manager.h"
using namespace std;
//Ŀ�꣺
//ÿ�춼д�˵�����ʾ�����¼��ţ�ÿ�ʻ�������ϸ��ÿ������и��ܼ�
//ÿ�»��˶���Ǯ

//��ʾ�˵�
void show_menu()
{
	cout << "1����ʾ֮ǰ�˵�" << endl;
	cout << "2����ʼ��¼����" << endl;
	cout << "3���˳��˵�" << endl;
}
void read_txt(manager mm[12])
{
	manager temp;//��ʱ����
	int t_day;//��ʱ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int month;//��¼���·�
	string a;//��¼ʡ�Ժ�
	float breakfrast, lunch, dinner, juice, online, market, sum;
	if (ifs.is_open())
	{
		cout << "��ȡ�ɹ�!" << endl;
		while (ifs >> month&&ifs >> a)
		{
			temp.month = month;//ͬ���·�
			temp.is_begin = true;//����չʾ�˵�show����
			switch (month)
			{
				//ͬ�����������������һ���µ�person����
			case 1:case 3:case 5:case 7: case 8:case 10:case 12:
				temp.m_day = 31;
				temp.bill = new person[31];
				break;
			case 2:
				temp.m_day = 28;
				temp.bill = new person[28];
				break;
			default:
				temp.m_day = 30;
				temp.bill = new person[30];
				break;
			}
			int i = 0;
			while (ifs >> breakfrast&&ifs >> lunch&&ifs >> dinner&&ifs >> juice&&ifs >> online
				&&ifs >> market&&ifs >> sum)
			{
				temp.bill[i].sum = sum;
				temp.bill[i].breakfast = breakfrast;
				temp.bill[i].lunch = lunch;
				temp.bill[i].dinner = dinner;
				temp.bill[i].juice = juice;
				temp.bill[i].online = online;
				temp.bill[i].market = market;
				temp.sum += sum;//�ܼƵ�ͬ��
				i++;
				if (i == temp.m_day)//��һ�����Ѿ���ȡ���
					break;
			}
			temp.day = i;//ͬ������
			mm[temp.month-1] = temp;
		}
	}
	else
	{
		cout << "�ļ���δ����!" << endl;
	}
	ifs.close();
}
int select_m(int month)
{
	cout << "��������Ҫ��ѯ���·�:" << endl;
	cin >> month;
	return month;
}
int main()
{
	manager mm[12];
	for (int i = 0; i < 12; i++)
	{
		mm[i].month = i + 1;
	}
	read_txt(mm);
	int month = 0;
	int choice = 1;
	while (choice)
	{
		show_menu();
		cin >> choice;
		if (choice == 3)
		{
			system("pause");
			exit(1);
		}
		month = select_m(month);//ѡ��鿴���·�
		switch (choice)
		{
		case 1:
			mm[month-1].show();
			system("pause");
			system("cls");
			break;
		case 2:
			mm[month - 1].creat_data();
			system("paise");
			system("cls"); break;
		case 3:
			cout << "sum::" << mm[month - 1].sum << endl;
			system("pause");
			break;
		default:break;
		}
	}
	system("pause");
	return 0;
}