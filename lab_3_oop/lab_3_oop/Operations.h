#pragma once
#include "main.h"
#include "Shapes.h"

static class Operations // ����������� ����� � ���������� ��� ���������
{
public:
	static bool Compare(Shape* obj1, Shape* obj2) // ��������� �������� ���� ��������
	{
		return obj1->getArea() > obj2->getArea();
	}
};