#pragma once
#ifndef PERSON_H
#define PERSON_H

#include "Object.h"
#include <string>

class Person : public Object {
public:
    Person(const std::string& name, int age);
    void setName(const std::string& name);
    void setAge(int age);
    std::string getName() const;
    int getAge() const;
private:
    std::string name;
    int age;
};
#endif