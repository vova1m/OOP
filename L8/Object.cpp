#include "Object.h"
#include <iostream>

Object::~Object()
{
	std::cout << "������ ���������� ������� �������� ������ Object" << std::endl;
}

Object::Object()
{
	std::cout << "������ ����������� ������� �������� ������ Object" << std::endl;
}