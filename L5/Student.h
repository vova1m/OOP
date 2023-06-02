#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <string>

class Student : public Person {
public:
    Student(const std::string& name, int age, const std::string& subject, int grade);
    void setSubject(const std::string& subject);
    void setGrade(int grade);
    std::string getSubject() const;
    int getGrade() const;
    void printMessage() const;
private:
    std::string subject;
    int grade;
};
#endif