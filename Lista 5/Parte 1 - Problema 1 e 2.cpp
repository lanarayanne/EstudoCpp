#include <iostream>
#include <chrono>

#include "ordenacao.h"

int main() {
    int size = 20;
    bool print = false;

    vector<int> array(size);

    for (int i = 0; i < size; i++) {
        array[i] = rand() % (size * 2);
        cout << array[i] << " ";
    }

    cout << endl;
    // test(array, "BubbleSort   ", bubblesort, print); //ok
    // test(array, "SelectionSort", selectionsort, print); //ok
    // test(array, "InsertionSort", insertionsort, print); //ok
    // test(array, "MergeSort    ", mergesort, print); //ok
    test(array, "QuickSort    ", quicksort, print);
}