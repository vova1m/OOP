#include <iostream>
#include "Person.h"
using namespace std;

class Student : public Person {
private:
    string subject;
    int grade;

public:
    Student(string n = "", int a = 0, string s = "", int g = 0);

    void setSubject(string s);
    void setGrade(int g);
    string getSubject();
    int getGrade();
    void checkGrade();

    friend istream& operator>>(istream& is, Student& s);
};

Student::Student(string n, int a, string s, int g) : Person(n, a) {
    subject = s;
    grade = g;
}

void Student::setSubject(string s) {
    subject = s;
}

void Student::setGrade(int g) {
    grade = g;
}

    string Student::getSubject() {
    return subject;
}

int Student::getGrade() {
    return grade;
}

void Student::checkGrade() {
    if (grade > 2) {
        if (grade < 4) {
            cout << "������ �������� - �����������������!";
        }      
        if (grade > 3 && grade < 5) {
            cout << "������ ������� - ������!" << endl;
        }
        if (grade > 4) {
            cout << "������ �������� - �������!" << endl;
        }
    } else {
        cout << "������ �������� �������������������!" << endl;
    }
}

   istream& operator>>(istream& is, Student& s) {
    string n, sub;
    int a, g;

    cout << "������� ��� ��������: ";
    is >> n;
    s.setName(n);

    cout << "������� ������� ��������: ";
    is >> a;
    s.setAge(a);

    cout << "������� �������� ��������: ";
    is >> sub;
    s.setSubject(sub);

    cout << "������� ������: ";
    is >> g;
    s.setGrade(g);

    return is;
}

int main() {
    setlocale(0, "Rus");
    Student student;
    cin >> student;

    cout << " ���: " << student.getName() << endl;
    cout << " �������: " << student.getAge() << endl;
    cout << " �������: " << student.getSubject() << endl;
    cout << " ������: " << student.getGrade() << endl;

    student.checkGrade();

    return 0;
}
