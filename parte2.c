#include <stdio.h>

//Estudiante: Frank Wang Wu
//laboratorio 3 parte 2


/*
* metodo que consiste en encontrar el valor minimo
* de un arreglo determinado, este metodo toma como
* variable a comparar el primer elemento del arreglo
* compara con el siguiente elemento del arreglo,
* si este es menor que la tomada como ejemplo, pues
* se intercambian y este pasara a ser el nuevo elemento
* mas pequeno del arreglo, y asi va comparando con
* el resto de los elementos del arreglo. Hasta encontrar
* el valor menor del arreglo.
* */
int encontrarMinimo(int arreglo[], int longitud) {

    int minimo = arreglo[0];

    for (int i=1; i<longitud; i++) {
      if (arreglo[i] < minimo) {
        minimo = arreglo[i];
      }
    }
    return minimo;
}

/*
* metodo que consiste en encontrar el valor maximo
* de un arreglo determinado, este metodo toma como
* variable a comparar el primer elemento del arreglo
* compara con el siguiente elemento del arreglo,
* si este es mayor que la tomada como ejemplo, pues
* se intercambian y este pasara a ser el nuevo elemento
* mas grande del arreglo, y asi va comparando con
* el resto de los elementos del arreglo. Hasta encontrar
* el valor mayor del arreglo.
* */
int encontrarMaximo (int arreglo[], int longitud) {
    int maximo = arreglo[0];

    for (int i=1; i<longitud; i++) {
      if (arreglo[i] > maximo) {
        maximo = arreglo[i];  
      }
    }
    return maximo;
}

/*
* metodo en que se usa punteros, se toma la direccion del arreglo para realizar
* la comparacion, y las de la variable minimo y maximo como lugar destino a guardar
* los valores. Se determina con el mismo metodo que las dos funciones anteriores.
* */
void encontrarMinimoMaximo (int *arreglo, int *minimo, int *maximo, int longitud) {

    *minimo = *maximo = arreglo[0];

    for (int i=1; i<longitud; i++) {
      if (arreglo[i] < *minimo) {
        *minimo = arreglo[i];
      }
      if (arreglo[i] > *maximo) {
        *maximo = arreglo[i];
      }
    }
}



int main() {
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15}; //arreglo establecido desordenado
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]); // calcular el tamano del arreglo

    int minimo = encontrarMinimo(arreglo, longitud); //llamada de funciones
    int maximo = encontrarMaximo(arreglo, longitud); // llamada de funciones

    int min, max;
    encontrarMinimoMaximo (arreglo, &min, &max, longitud); // llamada de funciones

    printf("\nmetodo encontrar minimo: \nvalor: %d", minimo);
    printf("\nmetodo encontrar maximo: \nvalor: %d", maximo);

    printf("\nmetodo encontrar minimo y maximo usando punteros: \nvalor minimo: %d \nvalor maximo: %d\n", min, max);

    return 0;
}

