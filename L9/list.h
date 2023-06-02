#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <stdexcept>

class List {
private:
    int* data;
    int size;

public:
    List();
    List(int size);
    List(const List& other);
    ~List();

    List& operator=(const List& other);
    int& operator[](int index);
    const int& operator[](int index) const;
    int operator*(const List& other) const;
    List operator+(int n) const;

    int length() const;

    friend std::ostream& operator<<(std::ostream& os, const List& list);
};

#endif

