#include <iostream>
#include "list.h"

int main() {
    List a(5);
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;

    std::cout << "a = " << a << std::endl;

    try {
        std::cout << "a[2] = " << a[2] << std::endl;
        std::cout << "a[10] = " << a[10] << std::endl;
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        List b(3);
        b[0] = 2;
        b[1] = 3;
        b[2] = 4;
        int product = a * b;
        std::cout << "a * b = " << product << std::endl;

        List c = a + 2;
        std::cout << "c = " << c << std::endl;
        List d = a + 10;
        std::cout << "d = " << d << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
