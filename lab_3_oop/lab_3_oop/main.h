#pragma once

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct point // структура "точка"
{
	double x, y;
};

inline double FindLength(point a, point b) // вычисление длины между двумя точками 
{
	return sqrt(pow((a.x - b.x), 2) + pow((a.y - b.y), 2));
}

ostream& operator<<(ostream& os, const point& pt) // перегрузка оператора "<<" для удобного вывода точек
{
	os << "X: " << pt.x << "|Y: " << pt.y;
	return os;
}

point operator + (const point &p1, const point &p2) // перегрузка оператора "+" для сложения точек
{
	point response;
	response.x = p1.x + p2.x;
	response.y = p1.y + p2.y;
	return response;
}



