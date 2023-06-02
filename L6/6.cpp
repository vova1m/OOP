#include <iostream>
#include "list.h"

int main() {
    List a{ 1, 2, 3 };
    List b{ 4, 5, 6 };
    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "b[2] = " << b[2] << std::endl;
    std::cout << "a size = " << a.size() << std::endl;
    std::cout << "b size = " << b.size() << std::endl;
    std::cout << "a * b = " << a.dot(b) << std::endl;
    List::Iterator it = a.begin() + 1;
    std::cout << "Second element of a = " << *it << std::endl;
    ++it;
    std::cout << "Third element of a = " << *it << std::endl;
    return 0;
}

