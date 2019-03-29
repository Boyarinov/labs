#pragma once
#include "main.h"

class Shape // ������� ����� ��� ���� ����� 
{
public:
	point* apexes; // �����, �� ������� �������� ������
	virtual double getArea() // ����������� �����, ������������ ������� �������
	{
		return 0;
	}
	virtual double getPeremeter() // ����������� �����, ������������ �������� �������
	{
		return 0;
	}
	virtual string getType() // ����������� �������, ������������ ��� �������
	{
		return "null";
	}
	static Shape* newFigure(char ch); // ����������� �����, ��������� ������ ������ �� �������� ��� "Shape" �������
	virtual ~Shape() // ����������, ��������� ��������� ��� "apexes" ������
	{
		delete[] apexes;
	}
	virtual point CentreOfGravity() = 0; // ����������� �����, ������������ ����� ������� �������
	virtual void Rotate(int angle) = 0; // ����������� �����, ������� ������������ ������
	virtual void Move(point offset) = 0; // ����������� �����, ������� ������� ������
	virtual void Move(int x, int y) = 0; // ����������� �����, ������� ������� ������
};



class Parallerogram : public Shape // ����� "��������������"
{
protected:
	point opposite = { 0,0 }; // �����, ����������� ������ ���� �� ������ �������
public:
	Parallerogram(); // �����������, ���������������� ������
	string getType(); // ����������� �������, ������������ ��� �������
	void Rotate(int angle); // ����������� �����, ������� ������������ ������
	void Move(point offset); // ����������� �����, ������� ������� ������
	void Move(int x, int y); // ����������� �����, ������� ������� ������
	double getArea(); // ����������� �����, ������������ ������� �������
	double getPeremeter(); // ����������� �����, ������������ �������� �������
	point CentreOfGravity(); // ����������� �����, ������������ ����� ������� �������
};

Parallerogram::Parallerogram()
{
	apexes = new point[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "������� ���������� " << i + 1 << " ������� ����� ������: "; cin >> apexes[i].x >> apexes[i].y;
	}
	double len[3];
	double max_len = 0;
	int maxLenIndex = 0;
	for (int i = 1; i < 4; i++)
	{
		len[i - 1] = FindLength(apexes[0], apexes[i]);
		if (max_len < len[i - 1])
		{
			max_len = len[i - 1];
			maxLenIndex = i;
		}

	}
	opposite = apexes[maxLenIndex];
}

string Parallerogram::getType()
{
	return "Parallerogram";
}

void Parallerogram::Rotate(int angle)
{

	for (int i = 0; i < 4; i++)
	{
		point tmp;
		tmp.x = apexes[i].x;
		tmp.y = apexes[i].y;
		apexes[i].x = tmp.x * cos(angle) - tmp.y * sin(angle);
		apexes[i].y = tmp.x * sin(angle) + tmp.y * cos(angle);
	}
}

void Parallerogram::Move(point offset)
{
	for (int i = 0; i < 4; i++)
		apexes[i] = apexes[i] + offset;
}

void Parallerogram::Move(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		apexes[i].x = apexes[i].x + x;
		apexes[i].y = apexes[i].y + y;
	}
}

double Parallerogram::getArea()
{
	double AB = sqrt(pow(apexes[1].x - apexes[0].x, 2) + pow(apexes[1].y - apexes[0].y, 2));
	double AD = sqrt(pow(apexes[3].x - apexes[0].x, 2) + pow(apexes[3].y - apexes[0].y, 2));
	double cosA = (((apexes[1].x - apexes[0].x) * (apexes[3].x - apexes[0].x)) - ((apexes[1].y - apexes[0].y) * (apexes[3].y - apexes[0].y))) / (AB * AD);
	double sinA = sqrt(1 - pow(cosA, 2));
	double sum = AB * AD * sinA;
	return sum;
}

double Parallerogram::getPeremeter()
{
	double sum = 0;
	for (int i = 0; i < 4; i++)
	{
		sum += FindLength(apexes[i], apexes[(i + 1) % 4]);
	}
	return sum;
}

point Parallerogram::CentreOfGravity()
{
	point centre;
	centre.x = (apexes[0].x + opposite.x) / 2;
	centre.y = (apexes[0].y + opposite.y) / 2;
	return centre;

}


class Triangle : public Shape // ����� "�����������"
{
public:
	Triangle(); // �����������, ���������������� ������
	string getType(); // ����������� �����, ������������ ��� �������
	void Rotate(int angle); // ����������� �����, ������� ������� ������
	void Move(point offset); // ����������� �����, ������� ������� ������ 
	void Move(int x, int y); // ����������� �����, ������� ������� ������
	double getArea(); // ����������� �����, ������������ ������� �������
	double getPeremeter(); // ����������� �����, ������������ �������� �������
	point CentreOfGravity(); // ����������� �����, ������������ ����� ������� �������
};

Triangle::Triangle()
{
	apexes = new point[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "������� ���������� " << i + 1 << " ������� ����� ������:"; cin >> apexes[i].x >> apexes[i].y;
	}
}

string Triangle::getType()
{
	return "Triangle";
}

void Triangle::Rotate(int angle)
{

	for (int i = 0; i < 3; i++)
	{
		point tmp;
		tmp.x = apexes[i].x;
		tmp.y = apexes[i].y;
		apexes[i].x = tmp.x * cos(angle) - tmp.y * sin(angle);
		apexes[i].y = tmp.x * sin(angle) + tmp.y * cos(angle);
	}
}

void Triangle::Move(point offset)
{
	for (int i = 0; i < 3; i++)
		apexes[i] = apexes[i] + offset;
}

void Triangle::Move(int x, int y)
{
	for (int i = 0; i < 3; i++)
	{
		apexes[i].x = apexes[i].x + x;
		apexes[i].y = apexes[i].y + y;
	}
}

double Triangle::getArea()
{
	double sum = 0.5 * (((apexes[0].x - apexes[2].x) * (apexes[1].y - apexes[2].y)) - ((apexes[0].y - apexes[2].y) * (apexes[1].x - apexes[2].x)));
	if (sum < 0)
		sum *= -1;
	return sum;
}

double Triangle::getPeremeter()
{
	double sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += FindLength(apexes[i], apexes[(i + 1) % 3]);
	}
	return sum;
}

point Triangle::CentreOfGravity()
{
	point centre;
	centre.x = (apexes[0].x + apexes[1].x + apexes[2].x) / 3.0;
	centre.y = (apexes[0].y + apexes[1].y + apexes[2].y) / 3.0;
	return centre;

}


class Empty : public Shape // ������ �����, ����������� ��� ���� ��������� ������� ������, �� ��������� � ��������� �������
{
public:
	string getType(); // ����������� �����, ������������ ��� �������
	void Rotate(int angle); // ����������� �����, ������� ������� ������
	void Move(point offset); // ����������� �����, ������� ������� ������ 
	void Move(int x, int y); // ����������� �����, ������� ������� ������
	double getArea(); // ����������� �����, ������������ ������� �������
	double getPeremeter(); // ����������� �����, ������������ �������� �������
	point CentreOfGravity(); // ����������� �����, ������������ ����� ������� �������
};


string Empty::getType()
{
	return "Invalid Shape";
}

void Empty::Rotate(int angle)
{
	cout << "Can't rotate: Invalid Shape" << endl;
}

void Empty::Move(point offset)
{
	cout << "Can't rotate: Invalid Shape" << endl;
}

void Empty::Move(int x, int y)
{
	cout << "Can't move: Invalid Shape" << endl;
}

double Empty::getArea()
{
	return 0;
}

double Empty::getPeremeter()
{
	return 0;
}

point Empty::CentreOfGravity()
{
	return point{ 0, 0 };
}

Shape* Shape::newFigure(char ch) 
{
	ch = toupper(ch);
	Shape* newClass = 0;
	switch (ch)
	{
	case 'T':
		newClass = new Triangle();
		break;
	case 'P':
		newClass = new Parallerogram();
		break;
	default:
		newClass = new Empty();
		break;
	}
	return newClass;
}