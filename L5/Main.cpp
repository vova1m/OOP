#include <iostream>
#include "Person.h"
#include "Student.h"

int main() {
    setlocale(LC_ALL, "Rus");
    Person p("����", 25);
    std::cout << "���: " << p.getName() << ", �������: " << p.getAge() << std::endl;
    p.setName("����");
    p.setAge(20);
    std::cout << "���: " << p.getName() << ", �������: " << p.getAge() << std::endl;

    Student s("����", 19, "�����������", 3);
    std::cout << "���: " << s.getName() << ", �������: " << s.getAge() << ", �������: " << s.getSubject() << ", ������: " << s.getGrade() << std::endl;
    s.setSubject("������");
    s.setGrade(4);
    std::cout << "���: " << s.getName() << ", �������: " << s.getAge() << ", �������: " << s.getSubject() << ", ������: " << s.getGrade() << std::endl;
    s.setGrade(2);
    s.printMessage();
    return 0;
}
