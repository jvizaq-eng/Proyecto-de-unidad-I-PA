#include <iostream>
#include <chrono>

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
    int A[] = {12, 5, 8, 1, 9, 3, 15, 20, 2};
    int n = 9;
    long long comparaciones = 0;
    long long intercambios = 0;

    auto begin = chrono::steady_clock::now();
    shellSort(A, n, comparaciones, intercambios);
    auto end = chrono::steady_clock::now();

    cout << "Comparaciones: " << comparaciones << endl;
    cout << "Intercambios: " << intercambios << endl;
    cout << "Tiempo en ms: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;

    return 0;
}
