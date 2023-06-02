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
            cout << "Оценка студента - удоблетворительна!";
        }      
        if (grade > 3 && grade < 5) {
            cout << "Оценка студнта - хорошо!" << endl;
        }
        if (grade > 4) {
            cout << "Оценка студента - отлично!" << endl;
        }
    } else {
        cout << "Оценка студента неудовлетворительна!" << endl;
    }
}

   istream& operator>>(istream& is, Student& s) {
    string n, sub;
    int a, g;

    cout << "Введите имя студента: ";
    is >> n;
    s.setName(n);

    cout << "Введите возраст студента: ";
    is >> a;
    s.setAge(a);

    cout << "Введите название предмета: ";
    is >> sub;
    s.setSubject(sub);

    cout << "Введите оценку: ";
    is >> g;
    s.setGrade(g);

    return is;
}

int main() {
    setlocale(0, "Rus");
    Student student;
    cin >> student;

    cout << " Имя: " << student.getName() << endl;
    cout << " Возраст: " << student.getAge() << endl;
    cout << " Предмет: " << student.getSubject() << endl;
    cout << " Оценка: " << student.getGrade() << endl;

    student.checkGrade();

    return 0;
}
