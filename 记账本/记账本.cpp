#include<iostream>
#include<fstream>
#include"manager.h"
using namespace std;
//目标：
//每天都写账单，显示出几月几号，每笔花销的详细，每天最后都有个总计
//每月花了多少钱
//目前还没有对于2月份天数的判断，默认2月份是28天
//显示菜单
void show_menu()
{
	cout << "1、显示之前账单" << endl;
	cout << "2、开始记录花销" << endl;
	cout << "3、退出账单" << endl;
}
void read_txt(manager mm[12])
{
	manager temp;//临时的类
	int t_day;//临时的天数
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int month;//记录的月份
	string a;//记录省略号
	float breakfrast, lunch, dinner, juice, online, market, sum;
	if (ifs.is_open())
	{
		cout << "读取成功!" << endl;
		while (ifs >> month&&ifs >> a)
		{
			temp.month = month;//同步月份
			temp.is_begin = true;//用于展示账单show函数
			switch (month)
			{
				//同步最大天数，并创建一个新的person数组
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
				temp.sum += sum;//总计的同步
				i++;
				if (i == temp.m_day)//这一个月已经读取完毕
					break;
			}
			temp.day = i;//同步日期
			mm[temp.month-1] = temp;
		}
	}
	else
	{
		cout << "文件还未创建!" << endl;
	}
	ifs.close();
}
int select_m(int month)
{
	cout << "请输入你要查询的月份:" << endl;
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
		month = select_m(month);//选择查看的月份
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
