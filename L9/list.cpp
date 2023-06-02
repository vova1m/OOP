#include "list.h"

List::List() : data(nullptr), size(0) {}

List::List(int size) : size(size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = 0;
    }
}

List::List(const List& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}

List::~List() {
    delete[] data;
}

List& List::operator=(const List& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

int& List::operator[](int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const int& List::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

int List::operator*(const List& other) const {
    if (size != other.size) {
        throw std::invalid_argument("Lists have different sizes");
    }
    int result = 0;
    for (int i = 0; i < size; ++i) {
        result += data[i] * other.data[i];
    }
    return result;
}

List List::operator+(int n) const {
    if (n < 0 || n >= size) {
        throw std::out_of_range("Index out of range");
    }
    List result(size - n);
    for (int i = 0; i < size - n; ++i) {
        result.data[i] = data[i + n];
    }
    return result;
}

int List::length() const {
    return size;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
    os << "[";
    for (int i = 0; i < list.size; ++i) {
        os << list.data[i];
        if (i != list.size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}
