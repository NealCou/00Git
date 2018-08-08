

//编程往死里编


// 计算球面上两点之间的球面距离
#include<iostream>
#include <math.h>

#define PI 3.1415926
#define R 6371.0
using namespace std;


struct City
{
	string Name;
	double lat, lon;		//lat纬度；lon经度
	int EorW, NorS;			//东经为1，西经为0；北纬为1，南纬为0.
};

double CalSurDis(City &p1,City &p2)
{
	double OA = sin(p1.lat);
	double OB = sin(p2.lat);

	double AB = 0;
	if (p1.EorW == p2.EorW)
	{
		AB = abs(OA - OB);
	}
	else
	{
		AB = OA + OB;
	}

	double Ap1 = cos(p1.lat);
	double Bp2 = cos(p2.lat);

	double angle ;
	if (p1.NorS == p2.NorS)
	{
		angle = abs(p1.lon - p2.lon);
	}
	else
	{
		angle = abs(p1.lon + p2.lon);
	}
	
	double _p1p2 = Ap1*Ap1 + Bp2*Bp2 - 2 * Ap1*Bp2*cos(angle);
	double p1p2 = _p1p2 + AB*AB;

	
	double angle1 = acos((2 - p1p2) / 2);
	//angle1 = angle1 * PI / 180 ;

	return R*angle1;
}

int main()
{
	City p1 = { "a",40,100,1,1 };
	City p2 = { "b",50,100,1,1 };
	p1.lat = p1.lat*PI / 180;
	p2.lat = p2.lat*PI / 180;

	p1.lon = p1.lon*PI / 180;
	p2.lon = p2.lon*PI / 180;
	double Ra = CalSurDis(p1, p2);
	cout << "半径为：" << Ra << endl;
	cin.get();
	return 0;
}