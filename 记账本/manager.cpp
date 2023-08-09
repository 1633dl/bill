#include"manager.h"
manager::~manager()
{
	if (bill != NULL)
	{
		delete[]bill;
		bill = NULL;
	}
}

manager::manager()
{
	switch (this->month)
	{
	case 1:case 3:case 5:case 7: case 8:case 10:case 12:
		this->m_day = 31;
		bill = new person[31];
		break;
	case 2:
		this->m_day = 28;
		bill = new person[28];
		break;
	default:
		this->m_day = 30;
		bill = new person[30];
		break;
	}
	this->is_begin = false;
	this->sum = 0;
}

//创建信息
void manager::creat_data()
{
	cout << "日期"; cin >> day;
	if (this->day > this->m_day)
	{
		cout << "日期错误" << endl;
		this->day = 0;
		return;
	}
	char c;
	int begin_day = this->day;//开始的日期
	for (int i = day - 1; i < m_day; i++)
	{
		cout << "开始输入" << endl;
		cout << "第" << this->day << "天" << endl;
		bill[i].begin_write();
		this->sum += this->bill[i].sum;//更新总计
		cout << "是否继续" << endl;
		cin >> c;
		if (c == 'n')
			break;
		this->day++;
		system("pause");
		system("cls");
	}
	this->into_txt(begin_day);
	this->is_begin = true;
}
//展示之前的账单
void manager::show()
{
	if (!this->is_begin)
	{
		cout << "还没有创建" << endl;
		return;
	}
	cout << this->month << "月的消费…………" << endl;
	for (int i = 0; i < this->day; i++)
	{
		cout << this->month << "月" << i + 1 << "日" << endl;
		cout << "早饭" << this->bill[i].breakfast << " 午饭" << this->bill[i].lunch << " 晚饭"
			<< this->bill[i].dinner << " 饮料" << this->bill[i].juice << " 网上购物"
			<< this->bill[i].online << " 超市购物" << this->bill[i].market << endl;
		cout << "……总计" << bill[i].sum << endl;
	}
	if (this->day == this->m_day)
	{
		cout << "这个月总计………………" << this->sum << endl;
	}
}
//将写入的信息转到文本文档中
void manager::into_txt(int begin_day)
{
	ofstream ofs;
	if (!is_begin)//文件第一次创建
	{
		ofs.open(FILENAME, ios::out);
		ofs << this->month << "…………" << endl;
		for (int i = 0; i < this->day; i++)
		{
			ofs << this->bill[i].breakfast << " " << this->bill[i].lunch << " " <<
				bill[i].dinner << " " << bill[i].juice << " " << this->bill[i].online << " "
				<< this->bill[i].market << endl<< this->bill[i].sum << endl;
		}
	}
	else//文件已经被创建过
	{
		ofs.open(FILENAME, ios::app);
		for (int i = begin_day - 1; i < this->day; i++)
		{
			ofs << this->bill[i].breakfast << " " << this->bill[i].lunch << " " <<
				bill[i].dinner << " " << bill[i].juice << " " << this->bill[i].online << " "
				<< this->bill[i].market << endl << this->bill[i].sum << endl;
		}
	}
	if (this->day == this->m_day)//到达最后一天
		ofs << "这个" << this->month << "总计花了……" << this->sum << endl;
	ofs.close();
}
//读文件
void manager::read_txt()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	string a;
	float breakfrast, lunch, dinner, juice, online, market,sum;
	int txt_month = 0;
	if (ifs.is_open())
	{
		ifs >> txt_month;
		this->month = txt_month;//读取月份并创建一个新的类
		ifs >> a;
		switch (this->month)
		{
		case 1:case 3:case 5:case 7: case 8:case 10:case 12:
			this->m_day = 31;
			bill = new person[31];
			break;
		case 2:
			this->m_day = 28;
			bill = new person[28];
			break;
		default:
			this->m_day = 30;
			bill = new person[30];
			break;
		}
		int i = 0;//判断天数
		while (ifs >> breakfrast&&ifs >> lunch&&ifs >> dinner&&ifs >> juice&&ifs >> online
			&&ifs >> market&&ifs >> sum)
		{
			this->bill[i].breakfast = breakfrast;
			this->bill[i].lunch = lunch;
			this->bill[i].dinner = dinner;
			this->bill[i].juice = juice;
			this->bill[i].online = online;
			this->bill[i].market = market;
			this->bill[i].sum = sum;
			i++;
			this->sum += sum;
			if (i == this->m_day)//这一个月已经读取完毕
				break;
		}
		this->day = i;//同步日期
		this->is_begin = true;
		ifs.close();
	}
}