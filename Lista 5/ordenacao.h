/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <chrono>
#include <vector>

using namespace std;

//A STL oferece uma sunção swap() que troca elementos; ela pode ser usada abaixo

// Funções Utilitárias

// Valida um array (isto é, se está ordenado ou não)
template<class T>
int validate(vector<T> &array) {
	for (int i = 0; i < array.size() - 1; i++) {
		if (array[i] > array[i + 1]) return 0;
	}
	return 1;
}

// Exibe um array na tela
template<class T>
void print(vector<T> &array) {
	for (int i = 0; i < array.size(); i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class T>
void bubblesort(vector<T> &array) {
	//cout << "Bubble sort" << endl;
	cout << "Antes: ";
	validate(array) ? cout << "Ordenado" << " " : cout << "Nao Ordenado" << endl;

	int last = array.size() - 1;
	bool change;
	do{
		change = false;
		for (int i = 0; i < last; i++) {
			if (array[i] > array[i + 1]) {
				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				change = true;
			}
		}
	} while (change);

	//print(array);
	cout << "Depois: ";
	validate(array) ? cout << "Ordenado" << endl  : cout << "Nao Ordenado" << endl;
}

template<class T>
void selectionsort(vector<T> &array) {
	cout << "Antes: ";
	validate(array) ? cout << "Ordenado" << " " : cout << "Nao Ordenado" << endl;

	int last = array.size();
	for (int i = 0; i < last; i++) {
		int min = i;
		for (int j = i + 1; j < last; j++) {
			if (array[min] > array[j]) {
				min = j;
			}
		}
		int temp = array[min];
		array[min] = array[i];
		array[i] = temp;
	}
	print(array);
	cout << "Depois: ";
	validate(array) ? cout << "Ordenado" << endl  : cout << "Nao Ordenado" << endl;
}

template<class T>
void insertionsort(vector<T> &array) {

	cout << "Antes: ";
	validate(array) ? cout << "Ordenado" << " " : cout << "Nao Ordenado" << endl;

	int last = array.size();
	for (int i=0; i<last; i++) {
		int temp = array[i];
		int j = i - 1;
		while (array[j] > temp && j>=0) {
			array[j+1] = array[j];
			j--;
		}
		array[j+1] = temp;
	}
	print(array);
	cout << "Depois: ";
	validate(array) ? cout << "Ordenado" << endl  : cout << "Nao Ordenado" << endl;
}

// Faz o merge dos subarrays em aux para array, isto é, array[...] = aux[...]
template<class T>
void merge(vector<T> &array, vector<T> &aux, int start, int mid, int finish) {
	int left = start;
	int right = mid;

	for (int i = start; i <= finish; i++) {
		if (left>=mid) {
			array[i] = aux[right];
			right++;
		} else if (right>finish) {
			array[i] = aux[left];
			left++;
		} else if (aux[left] <= aux[right]) {
			array[i] = aux[left];
			left++;
		} else {
			array[i] = aux[right];
			right++;
		}
	}


}

// Array: array que vai conter o resultado ordenado
// Aux: array auxiliar usado para ordenar as duas metades, esquerda e direita
// Repare que na chamada recursiva de mergesorte, array e aux se alternam
// Isto é, uma hora um é o principal e o outro é o auxiliar, depois invertem
template<class T>
void mergesort(vector<T> &array, vector<T> &aux, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(aux, array, start, mid);
	mergesort(aux, array, mid + 1, finish);

	merge(array, aux, start, mid + 1, finish);
}

// Função chamada inicialmente;
// Chama a função mergesorte() acima com os limites start e finish, e o clone do array (aux).
template<class T>
void mergesort(vector<T> &array) {

	cout << "Antes: ";
	validate(array) ? cout << "Ordenado" << " " : cout << "Nao Ordenado" << endl;

    vector<T> aux = array;
	mergesort(array, aux, 0, array.size() - 1);

	print(array);
	cout << "Depois: ";
	validate(array) ? cout << "Ordenado" << endl  : cout << "Nao Ordenado" << endl;
}

// Partição do QuickSort
template<class T>
int partition(vector<T> &array, int start, int finish) {
	int pivo = array[finish];
	int p = start-1;
	for (int i = start; i < finish; i++) {
		if (array[i] <= pivo) {
			p++;
			int temp = array[p];
			array[p] = array[i];
			array[i] = temp;
		}
	}
	int temp = array[finish];
	array[finish] = array[p+1];
	array[p+1] = temp;

	return p+1;
}

template<class T>
void quicksort(vector<T> &array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

// Semelhante ao que ocorre com o MergeSort.
template<class T>
void quicksort(vector<T> &array) {

	cout << "Antes: ";
	validate(array) ? cout << "Ordenado" << " " : cout << "Nao Ordenado" << endl;

	quicksort(array, 0, array.size() - 1);

	print(array);
	cout << "Depois: ";
	validate(array) ? cout << "Ordenado" << endl  : cout << "Nao Ordenado" << endl;
}


// Testa um algoritmo passado como parâmetro.
template<class T>
void test(vector<T> &array, const char * name, void function(vector<T> &array), bool printFlag) {
    vector<T> &copy = array;
	auto start = std::chrono::high_resolution_clock::now();

	function(copy);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy); else cout << endl;
}








