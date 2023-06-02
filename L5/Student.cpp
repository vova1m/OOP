#include "Student.h"
#include <iostream>

Student::Student(const std::string& name, int age, const std::string& subject, int grade)
    : Person(name, age), subject(subject), grade(grade)
{}

void Student::setSubject(const std::string& subject) {
    this->subject = subject;
}

void Student::setGrade(int grade) {
    this->grade = grade;
}

std::string Student::getSubject() const {
    return subject;
}

int Student::getGrade() const {
    return grade;
}

void Student::printMessage() const {
    if (grade < 4) {
        std::cout << "Неудовлетворительная оценка по предмету " << subject << "!\n";
    }
}
