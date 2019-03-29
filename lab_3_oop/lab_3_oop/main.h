#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct point // ��������� "�����"
{
	double x, y;
};

inline double FindLength(point a, point b) // ���������� ����� ����� ����� ������� 
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

ostream& operator<<(ostream& os, const point& pt) // ���������� ��������� "<<" ��� �������� ������ �����
{
	os << "X: " << pt.x << "|Y: " << pt.y;
	return os;
}

point operator + (const point &p1, const point &p2) // ���������� ��������� "+" ��� �������� �����
{
	point response;
	response.x = p1.x + p2.x;
	response.y = p1.y + p2.y;
	return response;
}



