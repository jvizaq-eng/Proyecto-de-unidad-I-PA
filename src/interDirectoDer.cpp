#include <iostream>
#include <chrono>
#include <fstream>
#include <cstdlib>

using namespace std;

void interDirectoDer(int A[], int n, long long &comparaciones, long long &intercambios) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comparaciones++;
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
                intercambios++;
            }
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
        interDirectoDer(A, n, comparaciones, intercambios);
        auto end = chrono::steady_clock::now();

        auto tiempo = chrono::duration_cast<chrono::milliseconds>(end - begin).count();

        archivo << "IntercambioDirecto," << n << "," << tiempo << "," 
                << comparaciones << "," << intercambios << "\n";

        cout << "Prueba finalizada para N = " << n << endl;
        delete[] A; 
    }

    archivo.close();
    cout << "Datos guardados en results/resultados.csv con exito!" << endl;
    return 0;
}
