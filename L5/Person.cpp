#include "Person.h"

Person::Person(const std::string& name, int age)
    : name(name), age(age)
{}

void Person::setName(const std::string& name) {
    this->name = name;
}

void Person::setAge(int age) {
    this->age = age;
}

std::string Person::getName() const {
    return name;
}

int Person::getAge() const {
    return age;
}
