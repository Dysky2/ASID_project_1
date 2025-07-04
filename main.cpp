#pragma warning(disable: 4996)
#include "algorytmy.hpp"
#include <iostream>
#include <ctime>
#include <fstream>

using namespace std;

extern int plik_dane();

int main()
{
    plik_dane();
    clock_t start, end;
    double duration;
    int n;
    cout << "n=";
    cin >> n;

    int* tab = new int[n];
    cout << "Wybierz sortowanie:\n1.Insert_sort\n2.Selection_sort\n3.Bubble_sort\n4.Quick_sort\n5.shell_sort\n6.Heap_sort\n7.Zakoncz dzialanie programu\n";
    int sort;
    cin >> sort;
    switch (sort) {
    case 1: {
        // insert_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        insert_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania insert_sort TEST 1: " << duration << "[s]" << endl;

        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        insert_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania insert_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        quick_sort(tab, 0, n - 1);

        start = clock();
        insert_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania insert_sort TEST 3: " << duration << "[s]" << endl;
        break;
    }
    case 2: {
        //selection_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        selection_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania selection_sort TEST 1: " << duration << "[s]" << endl;

        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        selection_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania selection_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        quick_sort(tab, 0, n - 1);

        start = clock();
        selection_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania selection_sort TEST 3: " << duration << "[s]" << endl;
        break;
    }
    case 3: {
        // bubble_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        bubble_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania bubble_sort TEST 1: " << duration << "[s]" << endl;

        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        bubble_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania bubble_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        quick_sort(tab, 0, n - 1);

        start = clock();
        bubble_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania bubble_sort TEST 3: " << duration << "[s]" << endl;

        break;
    }
    case 4: {
        // quick_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        quick_sort(tab,0, n-1);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania quick_sort TEST 1: " << duration << "[s]" << endl;
      
        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        quick_sort(tab,0, n-1);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania quick_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        quick_sort(tab, 0, n - 1);

        start = clock();
        quick_sort(tab,0, n-1);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania quick_sort TEST 3: " << duration << "[s]" << endl;

        break;
    }
    case 5: {
        // shell_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        shell_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania shell_sort TEST 1: " << duration << "[s]" << endl;

        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        shell_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania shell_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        insert_sort(tab, n);

        start = clock();
        shell_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania shell_sort TEST 3: " << duration << "[s]" << endl;

        break;
    }
    case 6: {
        // heap_sort
        // TEST 1
        fill_tab(tab, n);

        start = clock();
        heap_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania heap_sort TEST 1: " << duration << "[s]" << endl;

        // TEST 2
        fill_tab(tab, n);
        reverse_sort(tab, n);

        start = clock();
        heap_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania heap_sort TEST 2: " << duration << "[s]" << endl;

        // TEST 3
        fill_tab(tab, n);
        quick_sort(tab, 0, n - 1);

        start = clock();
        heap_sort(tab, n);
        end = clock();

        duration = double(end - start) / CLOCKS_PER_SEC;
        cout << "Czas wykonania heap_sort TEST 3: " << duration << "[s]" << endl;

        break;
    }
    default:
        break;
    }
    delete[] tab;
    return 0;
}

