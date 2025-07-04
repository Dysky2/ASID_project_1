#include <iostream>
#include <algorithm>
#include "algorytmy.hpp"
#include <fstream>

using namespace std;

void fill_tab(int*& tab, int n) {
    ifstream file("dane.txt");

    if (tab != nullptr) {
        delete[] tab; 
    }

    tab = new int[n];

    for (int i = 0; i < n; i++) {
        if (!(file >> tab[i])) {
            cout << "blad przypisania do pliku" << endl;
        }
    }

    file.close();
}

void show_data(int* tab, int n) {
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
    }
    cout << endl;
}

void insert_sort(int* tab, int n) {
    bool sorted = true;

    for (int i = 1; i < n; i++) {
        if (tab[i] < tab[i - 1]) {
            sorted = false;
            break;
        }
    }

    if (sorted) return;

    for (int i = 1;i < n;i++) {
        int temp = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > temp) {
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = temp;
    }
}

void selection_sort(int* tab, int n) {

    for (int j = 0; j < n; j++) {
        int min = tab[j];
        int pozycja = j;
        for (int i = j; i < n; i++) {
            if (tab[i] < min) {
                min = tab[i];
                pozycja = i;
            }
        }
        if (j != pozycja) {
            int temp = tab[j];
            tab[j] = tab[pozycja];
            tab[pozycja] = temp;
        }
    }

}

void bubble_sort(int* tab, int n) {
    bool is_sorted = false;
    int count = 0;
    while (is_sorted != true) {
        count = 0;
        for (int j = 1; j < n; j++) {
            if (tab[j - 1] > tab[j]) {
                swap(tab[j - 1], tab[j]);
                count++;
            }
        }

        if (count == 0) {
            is_sorted = true;
        }
    }
}

void quick_sort(int* tab, int left, int right) {
    int pivot = tab[(left+right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (tab[i] < pivot) {
            i++;
        }
        while (tab[j] > pivot) {
            j--;
        }

        if (i <= j) {
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }

    if (j > left)
        quick_sort(tab, left, j);
    if (i < right)
        quick_sort(tab, i, right);
}

void shell_sort(int* tab, int n) {
    int h = n / 2;
    while (h > 0) {
        for (int i = h;i < n;i++) {
            int temp = tab[i];
            int j = i;
            while (j >= h && tab[j - h] > temp) {
                tab[j] = tab[j - h];
                j -= h;
            }
            tab[j] = temp;
        }
        h = h / 2;
    }
}

void heapify(int* tab, int n, int i) {
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    if (n <= 0) {
        cout << "Przekrocznie dolnej granicy ";
        return;
    }

    if (left < n && tab[left] > tab[largest])
        largest = left;

    if (right < n && tab[right] > tab[largest])
        largest = right;

    if (largest != i) {
        swap(tab[i], tab[largest]);
        heapify(tab, n, largest);
    }
}

void heap_sort(int* tab, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(tab, n, i);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(tab[0], tab[i]);
        heapify(tab, i, 0);
    }

}

void reverse_sort(int* tab, int n) {
    sort(tab, tab + n, [](int a, int b) {
        return a > b;
    });
}
