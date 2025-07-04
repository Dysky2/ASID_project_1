#include <iostream>
#include <time.h>
#include <fstream>
using namespace std;

int plik_dane()
{
    ofstream file("dane.txt");

    srand(time(NULL));
    for (int i = 0; i < 90000; i++) {
        file << ((rand() % 201) - 100) << endl;
    }

    file.close();
    return  0;
}
