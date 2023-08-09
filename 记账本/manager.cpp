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

//������Ϣ
void manager::creat_data()
{
	cout << "����"; cin >> day;
	if (this->day > this->m_day)
	{
		cout << "���ڴ���" << endl;
		this->day = 0;
		return;
	}
	char c;
	int begin_day = this->day;//��ʼ������
	for (int i = day - 1; i < m_day; i++)
	{
		cout << "��ʼ����" << endl;
		cout << "��" << this->day << "��" << endl;
		bill[i].begin_write();
		this->sum += this->bill[i].sum;//�����ܼ�
		cout << "�Ƿ����" << endl;
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
//չʾ֮ǰ���˵�
void manager::show()
{
	if (!this->is_begin)
	{
		cout << "��û�д���" << endl;
		return;
	}
	cout << this->month << "�µ����ѡ�������" << endl;
	for (int i = 0; i < this->day; i++)
	{
		cout << this->month << "��" << i + 1 << "��" << endl;
		cout << "�緹" << this->bill[i].breakfast << " �緹" << this->bill[i].lunch << " ��"
			<< this->bill[i].dinner << " ����" << this->bill[i].juice << " ���Ϲ���"
			<< this->bill[i].online << " ���й���" << this->bill[i].market << endl;
		cout << "�����ܼ�" << bill[i].sum << endl;
	}
	if (this->day == this->m_day)
	{
		cout << "������ܼơ�����������" << this->sum << endl;
	}
}
//��д�����Ϣת���ı��ĵ���
void manager::into_txt(int begin_day)
{
	ofstream ofs;
	if (!is_begin)//�ļ���һ�δ���
	{
		ofs.open(FILENAME, ios::out);
		ofs << this->month << "��������" << endl;
		for (int i = 0; i < this->day; i++)
		{
			ofs << this->bill[i].breakfast << " " << this->bill[i].lunch << " " <<
				bill[i].dinner << " " << bill[i].juice << " " << this->bill[i].online << " "
				<< this->bill[i].market << endl<< this->bill[i].sum << endl;
		}
	}
	else//�ļ��Ѿ���������
	{
		ofs.open(FILENAME, ios::app);
		for (int i = begin_day - 1; i < this->day; i++)
		{
			ofs << this->bill[i].breakfast << " " << this->bill[i].lunch << " " <<
				bill[i].dinner << " " << bill[i].juice << " " << this->bill[i].online << " "
				<< this->bill[i].market << endl << this->bill[i].sum << endl;
		}
	}
	if (this->day == this->m_day)//�������һ��
		ofs << "���" << this->month << "�ܼƻ��ˡ���" << this->sum << endl;
	ofs.close();
}
//���ļ�
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
		this->month = txt_month;//��ȡ�·ݲ�����һ���µ���
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
		int i = 0;//�ж�����
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
			if (i == this->m_day)//��һ�����Ѿ���ȡ���
				break;
		}
		this->day = i;//ͬ������
		this->is_begin = true;
		ifs.close();
	}
}