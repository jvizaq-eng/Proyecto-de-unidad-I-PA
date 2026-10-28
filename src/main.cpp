#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;
using namespace std::chrono;

void intercambioDirecto(vector<int> a, long long& comps, long long& swaps, double& tiempo_ms) {
    comps = 0; swaps = 0;
    int n = a.size();
    auto t1 = high_resolution_clock::now();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            comps++;
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                swaps++;
            }
        }
    }
    auto t2 = high_resolution_clock::now();
    tiempo_ms = duration<double, milli>(t2 - t1).count();
}

void shellSort(vector<int> a, long long& comps, long long& swaps, double& tiempo_ms) {
    comps = 0; swaps = 0;
    int n = a.size();
    auto t1 = high_resolution_clock::now();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = a[i];
            int j = i;
            while (j >= gap) {
                comps++;
                if (a[j - gap] > temp) {
                    a[j] = a[j - gap];
                    swaps++;
                    j -= gap;
                } else {
                    break;
                }
            }
            a[j] = temp;
        }
    }
    auto t2 = high_resolution_clock::now();
    tiempo_ms = duration<double, milli>(t2 - t1).count();
}

vector<int> generarInstancia(int n, const string& patron, int semilla) {
    vector<int> v(n);
    if (patron == "Ascendente") {
        for (int i = 0; i < n; i++) v[i] = i + 1;
    } else if (patron == "Descendente") {
        for (int i = 0; i < n; i++) v[i] = n - i;
    } else { 
        mt19937 rng(semilla);
        uniform_int_distribution<int> dist(1, 100000);
        for (int i = 0; i < n; i++) v[i] = dist(rng);
    }
    return v;
}

int main() {
    vector<int> tamanos = {100, 1000, 5000, 10000};
    vector<string> patrones = {"Aleatorio", "Ascendente", "Descendente"};
    string commit_hash = "a1b2c3d";

    ofstream csv("results/resultados.csv");
    csv << "algoritmo,n,patron,repeticion,tiempo_ms,comparaciones,intercambios,profundidad_recursion,semilla,commit_hash\n";
    cout << "Ejecutando experimentos..." << endl;

    for (int n : tamanos) {
        for (const string& patron : patrones) {
            for (int r = 1; r <= 30; r++) {
                int semilla = 1000 + r;
                vector<int> datos_orig = generarInstancia(n, patron, semilla);

                vector<int> datos_id = datos_orig;
                long long c1 = 0, s1 = 0;
                double t1 = 0;
                intercambioDirecto(datos_id, c1, s1, t1);
                csv << "Intercambio Directo," << n << "," << patron << "," << r << "," 
                    << fixed << setprecision(4) << t1 << "," << c1 << "," << s1 << ",0," 
                    << semilla << "," << commit_hash << "\n";

                vector<int> datos_shell = datos_orig;
                long long c2 = 0, s2 = 0;
                double t2 = 0;
                shellSort(datos_shell, c2, s2, t2);
                csv << "Shellsort," << n << "," << patron << "," << r << "," 
                    << fixed << setprecision(4) << t2 << "," << c2 << "," << s2 << ",0," 
                    << semilla << "," << commit_hash << "\n";
            }
        }
    }

    csv.close();
    cout << "Finalizado con exito. Archivo guardado en results/resultados.csv" << endl;
    return 0;
}
