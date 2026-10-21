#include <iostream>
#include <chrono>

using namespace std;

void interDirectoDer(int A[], int n) {
    int aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (A[j] > A[j + 1]) {
                aux = A[j];
                A[j] = A[j + 1];
                A[j + 1] = aux;
            }
        }
    }
}

int main() {
    int A[] = {12, 5, 8, 1, 9, 3, 15, 20, 2};
    int n = 9;

    auto begin = chrono::steady_clock::now();
    interDirectoDer(A, n);
    auto end = chrono::steady_clock::now();

    cout << "Tiempo en ms: " << chrono::duration_cast<chrono::milliseconds>(end - begin).count() << " ms" << endl;

    return 0;
}
