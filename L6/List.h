#pragma once
#include <initializer_list>

class List {
public:
    List();
    List(const std::initializer_list<int>& lst);
    ~List();
    int& operator[](int index);
    int operator[](int index) const;
    int size() const;
    int dot(const List& other) const;

    class Iterator {
    public:
        Iterator(List& lst, int index);
        Iterator operator+(int n);
        int& operator*();
        bool operator!=(const Iterator& other) const;
        Iterator& operator++();
    private:
        List& list;
        int currentIndex;
    };

    Iterator begin();
    Iterator end();

private:
    int* data;
    int length;
};
