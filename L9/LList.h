#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
#include "error.h"

class List
{
public:
    List() = default;
    explicit List(const std::vector<int>& data);
    List(const List& other);
    List(List&& other) noexcept;
    ~List();
    List& operator=(const List& other);
    List& operator=(List&& other) noexcept;

    int& operator[](int index);
    const int& operator[](int index) const;

    int size() const;

    std::vector<int> operator*(const std::vector<int>& other) const;

    void jump(int n);

private:
    struct Node
    {
        int data;
        Node* next = nullptr;
    };

    Node* m_head = nullptr;
    int m_size = 0;

    void deleteList();
};

#endif // LIST_H
