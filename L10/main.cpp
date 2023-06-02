#include <iostream>
#include "pair.h"
#include "file_work.h"

void print_menu() {
	std::cout << "Choose an option:" << std::endl;
	std::cout << "1. Append a pair to the file" << std::endl;
	std::cout << "2. Read the file" << std::endl;
	std::cout << "3. Remove pairs less than given" << std::endl;
	std::cout << "4. Increase a pair by a given value" << std::endl;
	std::cout << "5. Insert pairs after a given one" << std::endl;
	std::cout << "0. Exit" << std::endl;
}

int main() {
	const char* filename = "pairs.bin";
	FileWork file(filename);
	int option;
	do {
		print_menu();
		std::cin >> option;
		switch (option) {
		case 1: {
			int first;
			double second;
			std::cout << "Enter the first and second elements of the pair:" << std::endl;
			std::cin >> first >> second;
			Pair pair(first, second);
			file.append(pair);
			std::cout << "Pair appended to the file" << std::endl;
			break;
		}
		case 2: {
			file.read();
			break;
		}
		case 3: {
			int first;
			double second;
			std::cout << "Enter the first and second elements of the pair:" << std::endl;
			std::cin >> first >> second;
			Pair pair(first, second);
			file.removeLessThan(pair);
			std::cout << "Pairs less than " << first << ":" << second << " removed from the file" << std::endl;
			break;
		}
		case 4: {
			int first;
			double second;
			std::cout << "Enter the first and second elements of the pair to be increased:" << std::endl;
			std::cin >> first >> second;
			Pair pair(first, second);
			std::cout << "Enter the value to increase the pair by:" << std::endl;
			std::cin >> first >> second;
			Pair L(first, second);
			file.increaseByL(pair, L);
			std::cout << "Pair " << first << ":" << second << " increased by " << L.getFirst() << ":" << L.getSecond() << std::endl;
			break;
		}
		case 5: {
			int first;
			double second;
			std::cout << "Enter the first and second elements of the pair after which new pairs will be inserted:" << std::endl;
			std::cin >> first >> second;
			Pair pair(first, second);
			int size;
			std::cout << "Enter the number of pairs to insert:" << std::endl;
			std::cin >> size;
			Pair* values = new Pair[size];
			for (int i = 0; i < size; i++) {
				std::cout << "Enter the first and second elements of pair " << i + 1 << ":" << std::endl;
				std::cin >> first >> second;
				values[i] = Pair(first, second);
			}
			file.insertAfter(pair, values, size);
			std::cout << size << " pairs inserted after " << first << ":" << second << std::endl;
			delete[] values;
			break;
		}
		case 0: {
			std::cout << "Exiting program" << std::endl;
			break;
		}
		default: {
			std::cout << "Invalid option selected" << std::endl;
			break;
		}
		}
	} while (option != 0);
	return 0;
}
