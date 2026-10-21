#include <iostream>
using namespace std;

void shellSort(int A[], int n) {
	int k, aux, j, i;
	k = n + 1;
	while (k > 1) {
		k = int(k/2);
		for (int i = k; i < n; i++) {
			aux = A[i];
			j = i;
			while (j-k >= 0 && A[j-k] > aux) {
				A[j] = A[j-k];
				j = j-k;
			}
			A[j] = aux;
		}
	}
}

int main () {
	int n;
	cout << "Ingrese la cantidad de elementos: ";
	cin >> n;
	
	int A[n];
	cout << "Ingresa los " << n << " numeros:" << endl;
	for(int i = 0; i < n; i++) {
		cout << "Elemento [" << i << "]: ";
		cin >> A[i];
	}
	
	shellSort(A, n);
	
	cout << "\nArreglo ordenado: " << endl;
	for (int i = 0; i < n; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	return 0;
}
