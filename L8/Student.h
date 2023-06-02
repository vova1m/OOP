#pragma once
#include "Person.h"

class Student :
	public Person
{
	string subject;
	int mark;
	friend istream& operator>>(istream& in, Student& s);
	friend ostream& operator<<(ostream& out, const Student& s);
public:
	Student();
	Student(string, int, string, int);
	~Student();
	Student(const Student& s);
	void Show();
	bool is_norm();
	int AvgAge() { return age; }
};