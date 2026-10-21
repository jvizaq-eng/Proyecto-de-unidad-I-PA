#include <iostream>
#include <chrono>

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
    int A[] = {12, 5, 8, 1, 9, 3, 15, 20, 2};
    int n = 9;
    long long comparaciones = 0;
    long long intercambios = 0;

    auto begin = chrono::steady_clock::now();
    interDirectoDer(A, n, comparaciones, intercambios);
    auto end = chrono::steady_clock::now();

    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios: " << intercambios << endl;
    cout << "Tiempo en ms: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;

    return 0;
}
