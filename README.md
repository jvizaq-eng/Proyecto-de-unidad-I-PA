# Proyecto-de-unidad-I-PA
# proyecto_ordenamiento

Comparación empírica de dos algoritmos de ordenamiento en C++: **Intercambio Directo** (método directo, O(n²)) y **Shellsort** (método subcuadrático, O(n^1.5) esperado). Proyecto de la Unidad 01 (evaluación de producto).

* **Estudiante:** Jennifer Elia Viza Quispe (jvizaq@unjbg.edu.pe) — Universidad Nacional Jorge Basadre Grohmann, Tacna, Perú.
* **Commit final:** `main` *(o puedes poner el código hash de 7 caracteres de tu último commit en GitHub)*

---

## Algoritmos seleccionados

* **Intercambio Directo / Burbuja:** Método directo, iterativo, estable.
* **Shellsort:** Método de saltos decrecientes (gap = n/2), iterativo, inestable.

---

## Requisitos

* `g++` con soporte C++11 (probado con g++, MSYS2 / MinGW).
* Para las gráficas y el resumen estadístico: Python 3 con `pandas` y `matplotlib`.

---

## Entorno experimental

| Componente | Valor |
| :--- | :--- |
| **Equipo** | Laptop PC |
| **CPU** | Intel Core i5 / AMD Ryzen |
| **RAM** | 16 GB RAM DDR4 |
| **Almacenamiento** | SSD |
| **SO** | Windows 11 Home 64-bit |
| **Compilador** | `g++` (Estándar C++11) |
| **Flags** | `-O2 -std=c++11 -Iinclude` |
| **Energía** | Equipo conectado a la corriente |
| **Temporizador** | `std::chrono::high_resolution_clock`, sin E/S de disco |

---

## Tamaños, patrones y semillas

* **Tamaños:** n ∈ {100, 1 000, 5 000, 10 000}.
* **Patrones:** Aleatorio, Ascendente y Descendente.
* **30 repeticiones por condición:** (2 algoritmos × 3 patrones × 4 tamaños × 30 repeticiones) = **720 ejecuciones totales**.
* **Semilla de la repetición r:** `1000 + r`, registrada en el CSV. Ambos algoritmos reciben copias idénticas de la misma entrada en memoria.

---

## Descripción de los archivos de resultados

* **`results/resultados.csv`:** Archivo plano con la bitácora de las 720 ejecuciones. Contiene los campos: `algoritmo`, `n`, `patron`, `repeticion`, `tiempo_ms`, `comparaciones`, `intercambios`, `profundidad`, `semilla` y `commit`.

---

## Cómo reproducir los experimentos

```bash
# 1. Compilar el programa principal
g++ -O2 -std=c++11 src/main.cpp -o experimento

# 2. Correr el experimento y generar la bitácora de datos
./experimento

# 3. Generar gráficas estadísticas
python src/graficar.py
