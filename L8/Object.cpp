#include "Object.h"
#include <iostream>

Object::~Object()
{
	std::cout << "¬ызван деструктор объекта базового класса Object" << std::endl;
}

Object::Object()
{
	std::cout << "¬ызван конструктор объекта базового класса Object" << std::endl;
}