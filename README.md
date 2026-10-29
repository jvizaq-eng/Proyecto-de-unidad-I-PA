# Proyecto-de-unidad-I-PA

Comparación empírica de dos algoritmos de ordenamiento en C++: **Intercambio Directo** (método directo, O(n²)) y **Shellsort** (método subcuadrático, O(n^1.5) esperado). Proyecto de la Unidad 01 (evaluación de producto).

* **Estudiante:** Jennifer Elia Viza Quispe (jvizaq@unjbg.edu.pe) — Universidad Nacional Jorge Basadre Grohmann, Tacna, Perú.
* **Commit final:** main

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
```

---

## Principales resultados y conclusiones

Tiempo medio (ms) con n = 10 000:

| Patrón | Intercambio Directo | Shellsort |
| :--- | :---: | :---: |
| **Aleatorio** | 1 202.78 ms | 5.45 ms |
| **Ascendente** | 371.36 ms | 1.53 ms |
| **Descendente** | 1 268.85 ms | 2.59 ms |

* **Intercambio Directo** crece de forma cuadrática estricta (realiza 49 995 000 comparaciones fijas para n = 10 000 independientemente del patrón).
* **Shellsort** logra un rendimiento subcuadrático drásticamente superior, reduciendo el tiempo de procesamiento en un 99.5% en datos aleatorios (5.45 ms frente a 1 202.78 ms).
* **Estabilidad:** Intercambio Directo es un algoritmo estable; Shellsort es inestable debido a sus intercambios a larga distancia sobre la brecha (gap).

---

## Video de demostración

[Enlace al video de demostración en YouTube](AQUI_VA_TU_ENLACE_DE_YOUTUBE)
