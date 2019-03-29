#include <iostream>
#include "Shapes.h"
#include "Operations.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	// инициализация трёх переменных под объекты
	Shape* o1 = NULL;
	Shape* o2 = NULL;
	Shape* o3 = NULL;

	// создание треугольника и вывод его типа на экран
	o1 = Shape::newFigure('t');
	cout << o1->getType() << endl;

	// создание паралеррограмма и вывод его типа на экран
	o2 = Shape::newFigure('p');
	cout << o2->getType() << endl;

	// создание объекта класса "Empty" и вывод его типа на экран
	o3 = Shape::newFigure('2');
	cout << o3->getType() << endl;


	// сравнение двух объектов через метод Operations::Compare и вывод результата на экран
	cout << o1->getType() << " больше " << o2->getType() << ": " << Operations::Compare(o1, o2) << endl;

	return 0;
}