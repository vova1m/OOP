#include <iostream>
#include "Pair.h"

using namespace std;

int main() {
    Pair p1, p2;
    cout << "������� ������ ����: ";
    cin >> p1;
    cout << "������� ������ ����: ";
    cin >> p2;

    Pair p3 = p1 - p2;
    cout << "p1 - p2 = " << p3 << endl;

    Pair p4 = p1 + 2;
    cout << "p1 + 2 = " << p4 << endl;

    Pair p5 = p2 + 1.5;
    cout << "p2 + 1.5 = " << p5 << endl;

    cout << "++p1 = " << ++p1 << endl;
    cout << "p1++ = " << p1++ << endl;
    cout << "p1 = " << p1 << endl;

    return 0;
}
