#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

using namespace std;

struct City          //���нṹ��
{
	string name;
	int EorW;//������������������1������0
	int NorS;//��γ������γ����γ1����γ0
	double lon;//����
	double lat;//γ��
	City()
	{
		EorW = 1;
		NorS = 1;
	}
};

const double PI = 3.1415926;
const double R = 6371.0;//����뾶

int Iputn()   //input number�����������
{
	int n;
	bool flag = true;
	while (flag)
	{
		cout << "��������и���������������" << '\n';
		cin >> n;
		if (0 >= n)
		{
			cout << "�������벻����Ҫ�����������밴1���˳��밴0��" << '\n';
			int choice;
			cin >> choice;
			if (0 != choice) { flag = false; }
		}
		if (flag)flag = false;
		else flag = true;
	}
	return n;
}

int ChoDir(int dir)   //choose direction  ѡ���򣨶��������ϱ�γ��
{
	string str1, str2;
	if (0 == dir) { str1 = "����"; str2 = "����"; }
	else { str1 = "��γ"; str2 = "��γ"; }
	bool flag = true;
	int choice;
	while (flag)
	{
		cout << "����ѡ��" << str1 << "����" << str2 << "��" << "1." << str1 << "��" << "0." << str2 << '\n';
		cin >> choice;
		if (choice < 0 || choice>1)
		{
			cout << "�������벻����Ҫ�����������밴1���˳������밴0��" << '\n';
			int choice1;
			cin >> choice1;
			if (0 != choice1)flag = false;
		}
		if (flag)flag = false;
		else flag = true;
	}
	return choice;
}

double Iputcoo(int option)  //input coordinate    ��������
{
	string str;
	double up;
	if (1 == option) { str = "����"; up = 180.0; }
	else if (2 == option) { str = "����"; up = 180.0; }
	else if (3 == option) { str = "��γ"; up = 90.0; }
	else { str = "��γ"; up = 90.0; }
	double coor;
	bool flag = true;
	while (flag)
	{
		cout << "��������" << str << "��0��" << up << "�������������" << '\n';
		cin >> coor;
		if (coor<0.0 || coor>up)
		{
			cout << "�������벻����Ҫ�����������밴1���˳��밴0��" << '\n';
			int choise;
			cin >> choise;
			if (0 != choise)flag = false;
		}
		if (flag)flag = false;
		else flag = true;
	}
	return coor;
}

double Calcu(City& P1, City& P2)      //calculate ��������������
{
	if (P1.name == P2.name)return 0.0;
	//��AB
	double AB;
	double OA = sin(P1.lat); double OB = sin(P2.lat);
	if (P1.NorS == P2.NorS) AB = fabs(OA - OB);
	else AB = OA + OB;
	//��н�
	double angle;
	if (P1.EorW == P2.EorW)  angle = fabs(P1.lon - P2.lon);
	else angle = P1.lon + P2.lon;
	//��P1A��P2B

	double P1A = cos(P1.lat); double P2B = cos(P2.lat);
	//��_P1P2_2   ��P1'P2��ƽ����
	double _P1P2_2 = P1A*P1A + P2B*P2B - 2 * cos(angle)*P1A*P2B;
	//��P1P2_2   ��P1P2��ƽ����
	double P1P2_2 = _P1P2_2 + AB*AB;
	//��н�1   ��OP1��OP2��ļнǣ�
	double angle1 = acos((2 - P1P2_2) / 2.0);
	//�������
	return R*angle1;
}

int main1()
{
	int num = Iputn();                //�����������
	if (0 >= num) { exit(1); }
	struct City* city = new City[num];//��������
	for (int i = 0; i < num; i++)
	{
		getchar();                               //�����������
		cout << "�����������" << i + 1 << "�����ƣ�" << '\n';
		getline(cin, city[i].name);
		int choice = ChoDir(0);                  //���붫����
		if (choice < 0 || choice>1) { delete[] city; exit(1); }
		if (1 == choice)
		{
			double elon = Iputcoo(1);
			if (elon<0.0 || elon>180.0)
			{
				delete[] city;
				exit(1);
			}
			city[i].lon = PI*elon / 180.0;     //�Ƕ�ת����
			city[i].EorW = 1;      //����
		}
		else
		{
			double wlon = Iputcoo(2);
			if (wlon<0.0 || wlon>180.0)
			{
				delete[] city;
				exit(1);
			}
			city[i].lon = PI*wlon / 180.0;
			city[i].EorW = 0;      //����
		}
		choice = ChoDir(1);                  //�����ϱ�γ
		if (choice < 0 || choice>1) { delete[] city; exit(1); }
		if (1 == choice)
		{
			double nlat = Iputcoo(3);
			if (nlat<0.0 || nlat>90.0)
			{
				delete[] city;
				exit(1);
			}
			city[i].lat = PI*nlat / 180.0;
			city[i].NorS = 1;      //��γ
		}
		else
		{
			double slat = Iputcoo(4);
			if (slat<0.0 || slat>90.0)
			{
				delete[] city;
				exit(1);
			}
			city[i].lat = PI*slat / 180.0;
			city[i].NorS = 0;        //��γ
		}
	}
	cout << "Start\\End   ";
	for (int i = 0; i < num; i++)
		cout << setw(12) << setiosflags(ios::left) << city[i].name;
	cout << '\n';
	for (int i = 0; i < num; i++)
	{
		cout << setw(12) << setiosflags(ios::left) << city[i].name;
		for (int j = 0; j < num; j++)
			cout << setw(12) << setiosflags(ios::fixed) << setprecision(2) << Calcu(city[i], city[j]);
		cout << '\n';
	}
	delete[] city;//delete��new������
	return 0;
}