#include "file_work.h"

FileWork::FileWork(const char* filename)
    : filename(filename) {
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
}

FileWork::~FileWork() {
    if (file.is_open()) {
        file.close();
    }
}

void FileWork::append(const Pair& pair) {
    file.seekp(0, std::ios::end);
    file.write(reinterpret_cast<const char*>(&pair), sizeof(pair));
}

void FileWork::read() {
    file.seekg(0, std::ios::beg);
    Pair pair;
    while (file.read(reinterpret_cast<char*>(&pair), sizeof(pair))) {
        pair.print();
    }
}

void FileWork::removeLessThan(const Pair& pair) {
    std::fstream temp(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    file.seekg(0, std::ios::beg);
    Pair current_pair;
    while (file.read(reinterpret_cast<char*>(&current_pair), sizeof(current_pair))) {
        if (!(current_pair < pair)) {
            temp.write(reinterpret_cast<const char*>(&current_pair), sizeof(current_pair));
        }
    }
    file.close();
    temp.close();
    remove(filename);
    rename("temp.bin", filename);
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
}

void FileWork::increaseByL(const Pair& pair, const Pair& L) {
    std::fstream temp(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    file.seekg(0, std::ios::beg);
    Pair current_pair;
    while (file.read(reinterpret_cast<char*>(&current_pair), sizeof(current_pair))) {
        if (current_pair == pair) {
            current_pair.setFirst(current_pair.getFirst() + L.getFirst());
            current_pair.setSecond(current_pair.getSecond() + L.getSecond());
        }
        temp.write(reinterpret_cast<const char*>(&current_pair), sizeof(current_pair));
    }
    file.close();
    temp.close();
    remove(filename);
    rename("temp.bin", filename);
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
}

void FileWork::insertAfter(const Pair& pair, const Pair* const values, const int& size) {
    std::fstream temp(filename, std::ios::in | std::ios::out | std::ios::binary | std::ios::trunc);
    file.seekg(0, std::ios::beg);
    Pair current_pair;
    while (file.read(reinterpret_cast<char*>(&current_pair), sizeof(current_pair))) {
        temp.write(reinterpret_cast<const char*>(&current_pair), sizeof(current_pair));
        if (current_pair == pair) {
            for (int i = 0; i < size; i++) {
                temp.write(reinterpret_cast<const char*>(&values[i]), sizeof(values[i]));
            }
        }
    }
    file.close();
    temp.close();
    remove(filename);
    rename("temp.bin", filename);
    file.open(filename, std::ios::in | std::ios::out | std::ios::binary);
}
