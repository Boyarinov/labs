#include <iostream>
#include "Shapes.h"
#include "Operations.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	// ������������� ��� ���������� ��� �������
	Shape* o1 = NULL;
	Shape* o2 = NULL;
	Shape* o3 = NULL;

	// �������� ������������ � ����� ��� ���� �� �����
	o1 = Shape::newFigure('t');
	cout << o1->getType() << endl;

	// �������� ��������������� � ����� ��� ���� �� �����
	o2 = Shape::newFigure('p');
	cout << o2->getType() << endl;

	// �������� ������� ������ "Empty" � ����� ��� ���� �� �����
	o3 = Shape::newFigure('2');
	cout << o3->getType() << endl;


	// ��������� ���� �������� ����� ����� Operations::Compare � ����� ���������� �� �����
	cout << o1->getType() << " ������ " << o2->getType() << ": " << Operations::Compare(o1, o2) << endl;

	return 0;
}