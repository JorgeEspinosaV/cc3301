#include <stdio.h>
#include <stdlib.h>

// Inicializamos funcion swap para utilizarla en quicksort
void swap(double v[], int i, int j);


// Función quicksort
// recibe como variable double a[] (array de doubles (reales)),
// int left y int right para recorrer el array y hacer los swap 
void quicksort(double a[], int left, int right) {
    // si caso base se cumple retornamos a main
    // donde el indicador que parte desde i = 0 iguala o supera a
    // j = n-1
    if (left >= right)
        return;

    // hacemos un swap de a[i] con a[prom(i, j)]
    swap(a, left, (left + right)/2);

    // inicializamos cual fue el ultimo valor de i
    int last = left;

    // recorremos a, desde i + 1 hasta j
    for (int i = left + 1; i <= right; ++i) {
        // si a[k] < a[i] los intercambiamos 
        if (a[i] < a[left])
            swap(a, ++last, i);
    }
    swap(a, left, last);
    quicksort(a, left, last - 1);
    quicksort(a, last + 1, right);
}

void swap(double v[], int i, int j) {
    double tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

// funcion main, toma como parametros un array de double en la linea de comandos
int main (int argc, char *argv[]) {
    // lenght del array que crearemos para los argumentos dados
    int n = argc - 1;

    // inicializamos el n array
    double a[n];

    // llenamos el array con los args
    for (int i = 0; i<n; i++) 
        a[i] = atof(argv[i+1]);

    // ejecutamos quicksort
    quicksort(a, 0, n-1);

    // print el array ordenado
    for (int i = 0; i < n; i++)
        printf("%g ", a[i]);
    printf("\n");

    return 0;
}