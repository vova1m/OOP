#include "List.h"

List::List() : data(nullptr), length(0) {}

List::List(const std::initializer_list<int>& lst) : data(new int[lst.size()]), length(lst.size()) {
    int i = 0;
    for (auto& el : lst) {
        data[i] = el;
        ++i;
    }
}

List::~List() {
    delete[] data;
}

int& List::operator[](int index) {
    return data[index];
}

int List::operator[](int index) const {
    return data[index];
}

int List::size() const {
    return length;
}

int List::dot(const List& other) const {
    int result = 0;
    for (int i = 0; i < length; ++i) {
        result += data[i] * other[i];
    }
    return result;
}

List::Iterator::Iterator(List& lst, int index) : list(lst), currentIndex(index) {}

List::Iterator List::Iterator::operator+(int n) {
    return Iterator(list, currentIndex + n);
}

int& List::Iterator::operator*() {
    return list[currentIndex];
}

bool List::Iterator::operator!=(const Iterator& other) const {
    return currentIndex != other.currentIndex;
}

List::Iterator& List::Iterator::operator++() {
    ++currentIndex;
    return *this;
}

List::Iterator List::begin() {
    return Iterator(*this, 0);
}

List::Iterator List::end() {
    return Iterator(*this, length);
}
