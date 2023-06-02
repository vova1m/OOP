#include <iostream>
#include "list.h"

int main()
{
    try
    {
        std::vector<int> data = { 1, 2, 3, 4, 5 };
        List list(data);

        std::cout << "list[2]: " << list[2] << std::endl;
        std::cout << "list size: " << list.size() << std::endl;

        std::vector<int> other = { 2, 3, 4, 5, 6 };
        auto result = list * other;
        std::cout << "list * other: ";
        for (const auto& value : result)
        {
            std::cout << value << " ";
        }
        std::cout << std::endl;

        list.jump(3);
        std::cout << "list[0]: " << list[0] << std::endl;
        std::cout << "list size: " << list.size() << std::endl;

        // Testing exceptions
        // IndexError
        try
        {
            std::cout << "list[10]: " << list[10] << std::endl;
        }
        catch (const IndexError& e)
        {
            std::cerr << "IndexError: " << e.what() << std::endl;
        }

        // SizeError
        try
        {
            std::vector<int> invalid = { 1, 2, 3 };
            auto invalidResult = list * invalid;
        }
        catch (const SizeError& e)
        {
            std::cerr << "SizeError: " << e.what() << std::endl;
        }

        // Testing copy constructor
        List copy = list;
        std::cout << "copy[0]: " << copy[0] << std::endl;
        std::cout << "copy size: " << copy.size() << std::endl;

        // Testing assignment operator
        List assigned;
        assigned = list;
        std::cout << "assigned[0]: " << assigned[0] << std::endl;
        std::cout << "assigned size: " << assigned.size() << std::endl;

        // Testing self-assignment
        assigned = assigned;
        std::cout << "assigned[0]: " << assigned[0] << std::endl;
        std::cout << "assigned size: " << assigned.size() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
