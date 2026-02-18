#include <iostream>
#include <climits>
using namespace std;

int costoMinimo(int arr[], int n, int pos) {
    // Caso base
    if (pos == n) {
        return 0;
    }

    // Caso recursivo
    int min = INT_MAX;
    int producto = 1;

    for (int i = pos; i < n; ++i) {
        producto *= arr[i];
        // Hacer las llamadas recursivas
        int costo = producto + costoMinimo(arr, n, i + 1);

        if (costo < min) {
            min = costo;
        }
    }

    return min;
}

// Graficar el arbol de llamadas recursivas
// para [1,2,3]

int main() {
    int arr[] = {1, 2, 3};
    int n = 3;

    cout <<"el costo minimo es: "<<costoMinimo(arr, n, 0) << endl;

    return 0;
}
