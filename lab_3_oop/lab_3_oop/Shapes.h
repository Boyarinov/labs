#pragma once
#include "main.h"

class Shape // базовый класс для всех фигур 
{
public:
	point* apexes; // точки, из которых строится фигура
	virtual double getArea() // виртуальный метод, возвращающий площадь объекта
	{
		return 0;
	}
	virtual double getPeremeter() // виртуальный метод, возвращающий периметр объекта
	{
		return 0;
	}
	virtual string getType() // виртуальная функция, возвращающий тип объекта
	{
		return "null";
	}
	static Shape* newFigure(char ch); // статический метод, создающий объект одного из дочерних для "Shape" классов
	virtual ~Shape() // дескриптор, очищающий выделеную под "apexes" память
	{
		delete[] apexes;
	}
	virtual point CentreOfGravity() = 0; // виртуальный метод, возвращающий центр тяжести объекта
	virtual void Rotate(int angle) = 0; // виртуальный метод, который поворачивает фигуру
	virtual void Move(point offset) = 0; // виртуальный метод, который двигает фигуру
	virtual void Move(int x, int y) = 0; // виртуальный метод, который двигает фигуру
};



class Parallerogram : public Shape // класс "параллерограмм"
{
protected:
	point opposite = { 0,0 }; // точка, находящаяся дальше всех от первой введёной
public:
	Parallerogram(); // конструктор, инициализирующий фигуру
	string getType(); // виртуальная функция, возвращающий тип объекта
	void Rotate(int angle); // виртуальный метод, который поворачивает фигуру
	void Move(point offset); // виртуальный метод, который двигает фигуру
	void Move(int x, int y); // виртуальный метод, который двигает фигуру
	double getArea(); // виртуальный метод, возвращающий площадь объекта
	double getPeremeter(); // виртуальный метод, возвращающий периметр объекта
	point CentreOfGravity(); // виртуальный метод, возвращающий центр тяжести объекта
};

Parallerogram::Parallerogram()
{
	apexes = new point[4];
	for (int i = 0; i < 4; i++)
	{
		cout << "Введите координаты " << i + 1 << " вершины через пробел: "; cin >> apexes[i].x >> apexes[i].y;
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


class Triangle : public Shape // класс "треугольник"
{
public:
	Triangle(); // конструктор, инициализирующий фигуру
	string getType(); // виртуальный метод, возвращающий тип объекта
	void Rotate(int angle); // виртуальный метод, который вращает фигуру
	void Move(point offset); // виртуальный метод, который двигает фигуру 
	void Move(int x, int y); // виртуальный метод, который двигает фигуру
	double getArea(); // виртуальный метод, возвращающий площадь объекта
	double getPeremeter(); // виртуальный метод, возвращающий периметр объекта
	point CentreOfGravity(); // виртуальный метод, возвращающий центр тяжести объекта
};

Triangle::Triangle()
{
	apexes = new point[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "Введите координаты " << i + 1 << " вершины через пробел:"; cin >> apexes[i].x >> apexes[i].y;
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


class Empty : public Shape // пустой класс, создающийся без если требуется создать фигуру, не описанную в программе заранее
{
public:
	string getType(); // виртуальный метод, возвращающий тип объекта
	void Rotate(int angle); // виртуальный метод, который вращает фигуру
	void Move(point offset); // виртуальный метод, который двигает фигуру 
	void Move(int x, int y); // виртуальный метод, который двигает фигуру
	double getArea(); // виртуальный метод, возвращающий площадь объекта
	double getPeremeter(); // виртуальный метод, возвращающий периметр объекта
	point CentreOfGravity(); // виртуальный метод, возвращающий центр тяжести объекта
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