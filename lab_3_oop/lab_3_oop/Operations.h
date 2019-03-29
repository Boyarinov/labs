#pragma once
#include "main.h"
#include "Shapes.h"

static class Operations // статический класс с операциями над объектами
{
public:
	static bool Compare(Shape* obj1, Shape* obj2) // сравнение площадей двух объектов
	{
		return obj1->getArea() > obj2->getArea();
	}
};