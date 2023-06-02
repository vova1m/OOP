#include "pair.h"

Pair::Pair(int first, double second)
    : first(first), second(second) {}

void Pair::print() const {
    std::cout << first << ":" << second << std::endl;
}

Pair Pair::operator-(const Pair& other) const {
    return Pair(first - other.first, second - other.second);
}

Pair Pair::operator+(const int& num) const {
    return Pair(first + num, second);
}

Pair Pair::operator+(const double& num) const {
    return Pair(first, second + num);
}

bool Pair::operator<(const Pair& other) const {
    if (first == other.first) {
        return second < other.second;
    }
    return first < other.first;
}

bool Pair::operator==(const Pair& other) const {
    return first == other.first && second == other.second;
}

int Pair::getFirst() const {
    return first;
}

double Pair::getSecond() const {
    return second;
}

void Pair::setFirst(int first) {
    this->first = first;
}

void Pair::setSecond(double second) {
    this->second = second;
}
