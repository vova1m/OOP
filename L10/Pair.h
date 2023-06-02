#pragma once
#ifndef PAIR_H
#define PAIR_H

#include <iostream>

class Pair {
public:
    Pair(int first = 0, double second = 0.0);
    void print() const;
    Pair operator-(const Pair& other) const;
    Pair operator+(const int& num) const;
    Pair operator+(const double& num) const;
    bool operator<(const Pair& other) const;
    bool operator==(const Pair& other) const;

    int getFirst() const;
    double getSecond() const;
    void setFirst(int first);
    void setSecond(double second);

private:
    int first;
    double second;
};

#endif // PAIR_H
