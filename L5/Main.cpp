#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Person p("Петя", 25);
    std::cout << "Имя: " << p.getName() << ", Возраст: " << p.getAge() << std::endl;
    p.setName("Катя");
    p.setAge(20);
    std::cout << "Имя: " << p.getName() << ", Возраст: " << p.getAge() << std::endl;

    Student s("Иван", 19, "Физкультура", 3);
    std::cout << "Имя: " << s.getName() << ", Возраст: " << s.getAge() << ", Предмет: " << s.getSubject() << ", Оценка: " << s.getGrade() << std::endl;
    s.setSubject("Физика");
    s.setGrade(4);
    std::cout << "Имя: " << s.getName() << ", Возраст: " << s.getAge() << ", Предмет: " << s.getSubject() << ", Оценка: " << s.getGrade() << std::endl;
    s.setGrade(2);
    s.printMessage();
    return 0;
}
