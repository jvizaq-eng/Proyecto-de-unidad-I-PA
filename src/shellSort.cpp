#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;

void shellSort(int A[], int n, long long &comparaciones, long long &intercambios) {
    int k, aux, j;
    k = n + 1;
    while (k > 1) {
        k = int(k / 2);
        for (int i = k; i < n; i++) {
            aux = A[i];
            j = i;
            while (j - k >= 0) {
                comparaciones++;
                if (A[j - k] > aux) {
                    A[j] = A[j - k];
                    intercambios++;
                    j = j - k;
                } else {
                    break;
                }
            }
            A[j] = aux;
        }
    }
}

int main() {
    int tamanos[] = {100, 1000, 5000, 10000};
    
    ofstream archivo("results/resultados.csv", ios::app);
    if (!archivo.is_open()) {
        cout << "Error al abrir el archivo de resultados." << endl;
        return 1;
    }

    for (int n : tamanos) {
        int* A = new int[n];
        
        for (int i = 0; i < n; i++) {
            A[i] = rand() % 10000;
        }

        long long comparaciones = 0;
        long long intercambios = 0;

        auto begin = chrono::steady_clock::now();
        shellSort(A, n, comparaciones, intercambios);
        auto end = chrono::steady_clock::now();

        auto tiempo = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

        archivo << "Shellsort," << n << "," << tiempo << "," 
                << comparaciones << "," << intercambios << "\n";

        cout << "Prueba Shellsort finalizada para N = " << n << endl;
        delete[] A; 
    }

    archivo.close();
    cout << "Resultados de Shellsort guardados con exito!" << endl;
    return 0;
}
