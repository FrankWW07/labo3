#include <stdio.h>
/*
* Estudiante: Frank Wang Wu
* laboratorio 3 parte 1
*/

/*
* metodo para hacer una busqueda lineal de un valor dentro de un array,
* recorriendo casilla por casilla del arreglo
* si encuentra el valor, retorna la posicion en donde la encontro
* si no retorna un valor predeterminado, la que indica que no se encontro ningun valor dentro
* del arreglo.
* */
int buscarEnArregloLineal (int arreglo[], int valor, int longitud) {

  for(int i=0; i<longitud; i++) {
    if (arreglo[i] == valor) {
      return i;
    }
  }
  return -1;
}

/*
* metodo para encontrar con un metodo binario de un valor dentro de un array,
* el metodo consiste en realizar la busqueda empezando por la mitad del array,
* si la primera mitad se encuentra posiblemente el valor, entonces va avanzando
* por esa mitad, y va partiendo el arreglo en mitades hasta encontrar el valor que se quiere,
* como el arreglo esta ordenado en orden entonces dependiendo del valor ingresado
* se mueve hacia una posicion inferior o mayor del arreglo.
* Y una vez encontrado, retorna el valor ingresado por el usuario o imprime que
* no se encontro.
* */
int buscarEnArregloBinario (int arreglo[], int valor, int longitud) {

  int izquierda = 0;
  int derecha = longitud-1;

  while (izquierda <= derecha) {
    int medio = izquierda+(derecha-izquierda)/2;

    if (arreglo[medio] == valor) {
      return medio;
    }

    if (arreglo[medio] < valor) {
      izquierda = medio+1;
    }
    else {
      derecha = medio-1;
    }
  }
    return -1;
}

/*
* este metodo utiliza el mismo algoritmo del metodo de busqueda binaria establecida
* en la funcion anterior, solo que implementa con la manera recursiva, tomando como
* condicion de parada si el lado derecho es mayor o igual que el lado izquierdo, esto quiere
* decir que a medida vaya desplazandose hacia tanto a la izquierda como a la derecha,
* y si no se ha llegado la condicion parada, termina la funcion cuando:
* el valor izquierdo es igual o mayor derecha, y que encuentre el valor o,
* si no pasa ninguno de los dos casos, se sale de la funcion retornando un valor -1
* */

int buscarEnArregloBinRecursiva (int arreglo[], int valor, int izquierda, int derecha) {

  if (izquierda <= derecha) {
    int medio = izquierda + (derecha - izquierda)/2 ; // el valor medio == el centro del arreglo

    if (arreglo[medio] == valor) {
      return medio;
    }

    if (arreglo[medio] < valor) {
      return buscarEnArregloBinRecursiva(arreglo, valor, medio+1, derecha);
    }
    else {
      return buscarEnArregloBinRecursiva(arreglo, valor, izquierda, medio-1);
    }
  }
  return -1;
}


int main() {

    int arreglo[] = {2, 4, 6, 23, 56, 79}; // arreglo establecido
    int longitud = sizeof(arreglo)/sizeof(arreglo[0]);
/*
* calculando la longitud del arreglo usando el sizeof (este da el tamano del arreglo
* en bits, por lo que se divide el tamano total del arreglo por el tamano individual
* asi obteniendo la longitud de ella)
* */
    int valor = 0;

    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);

    int posicionLineal = buscarEnArregloLineal(arreglo, valor, longitud);
    int posicionBinaria = buscarEnArregloBinario(arreglo, valor, longitud);

    int izquierda = 0;
    int derecha = longitud-1;
    int posicionBinRecursiva = buscarEnArregloBinRecursiva(arreglo, valor, izquierda, derecha);

    printf("\nPor medio del metodo de busqueda lineal del arreglo: \n");
    if (posicionLineal != -1) {
      printf("valor: %d \nposicion: %d\n", valor, posicionLineal);
    }
    else {
      printf("El valor %d no fue encontrado en el arreglo. \n", valor);
    }


    printf("\nPor medio del metodo de busqueda binaria del arreglo: \n");
    if (posicionBinaria != -1) {
      printf("valor: %d \nposicion: %d\n", valor, posicionBinaria);
    }
    else {
      printf("El valor %d no fue encontrado en el arreglo. \n", valor);
    }


    printf("\nPor medio del metodo de busqueda binaria recursiva del arreglo: \n");
    if (posicionBinRecursiva != -1) {
      printf("valor: %d \nposicion: %d\n", valor, posicionBinRecursiva);
    }
    else {
      printf("El valor %d no fue encontrado en el arreglo. \n", valor);
    }
    return 0;
}
