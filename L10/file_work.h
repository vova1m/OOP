#pragma once
#ifndef FILE_WORK_H
#define FILE_WORK_H

#include <fstream>
#include "pair.h"

class FileWork {
public:
    FileWork(const char* filename);
    ~FileWork();
    void append(const Pair& pair);
    void read();
    void removeLessThan(const Pair& pair);
    void increaseByL(const Pair& pair, const Pair& L);
    void insertAfter(const Pair& pair, const Pair* const values, const int& size);
private:
    const char* filename;
    std::fstream file;
};

#endif // FILE_WORK_H
