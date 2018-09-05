#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD 10
int retornarTotal(int listado[],  int tamanio);
int retornarPromedio(int listado[],  int tamanio);
void cargarListado(int* listado, int tamanio);
void mostrarListado(int* listado, int tamanio);
int obtenerMayor(int* listado, int tamanio);
int obtenerMenor(int* listado, int tamanio);
void mostrarInformacionDelArray(int* listado, int tamanio);
int cantidadDePares(int* listado, int tamanio);
int retornarCantidadDeNotas(int* listado, int tamanio, int minimo, int maximo);
int main()
{
    //Variables
    int listadoDeNotas[CANTIDAD];
    int i;
    /*printf("Tamaño de variable %d\n", sizeof(numeroIngresado));
    printf("Tamaño del array %d\n", sizeof(listadoDeNotas));
    printf("Direccion de memoria de la variable: %d\n", &numeroIngresado);
    printf("Direccion de memoria del array: %d\n", listadoDeNotas);*/
    printf("----------------------------\n");
    cargarListado(listadoDeNotas,CANTIDAD);
    mostrarListado(listadoDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas, CANTIDAD);
     return 0;
}

int retornarTotal(int listado[],  int tamanio)
{
   int acumulador = 0;
   int i;
    for (i=0; i< tamanio; i++)
    {
       acumulador = acumulador + listado[i];
    }
    return acumulador;
}
int retornarPromedio(int listado[],  int tamanio)
{
    int suma;
    int promedio;
    suma = retornarTotal(listado, tamanio);
    promedio = suma / tamanio;
    return promedio;
}
void cargarListado(int* listado, int tamanio)
{
    int numeroIngresado;
    int i;
    for (i=0; i< tamanio; i++)
    {
        printf("Ingrese nota: \n");
        scanf("%d", &numeroIngresado);
        listado[i] = numeroIngresado;
    }
}
void mostrarListado(int* listado, int tamanio)
{
    int i;
    for (i=0; i< tamanio; i++)
    {
        printf("La nota es: %d\n", listado[i]);
    }
}
int obtenerMayor(int* listado, int tamanio)
{
    int mayor;
    int i;
    for (i=0; i< tamanio; i++)
    {
      if (i == 0 || listado[i]> mayor)
      {
        mayor = listado[i];
      }
    }
    return mayor;
}
int obtenerMenor(int* listado, int tamanio)
{
    int menor;
    int i;
    for (i=0; i< tamanio; i++)
    {
      if (i == 0 || listado[i]< menor)
      {
        menor = listado[i];
      }
    }
    return menor;
}
void mostrarInformacionDelArray(int* listado, int tamanio)
{
    printf("El mayor es %d\n", obtenerMayor(listado, tamanio));
    printf("El menor es %d\n", obtenerMenor(listado, tamanio));
    printf("El total es %d\n", retornarTotal(listado, tamanio));
    printf("El promedio es %d\n", retornarPromedio(listado, tamanio));
    printf("Cantidad de pares es %d\n", cantidadDePares(listado, tamanio));
    printf("Desaprobaron: %d\n", retornarCantidadDeNotas(listado, tamanio, 1, 3));
    printf("A final van: %d\n", retornarCantidadDeNotas(listado, tamanio, 4, 5));
    printf("Aprobaron: %d\n", retornarCantidadDeNotas(listado, tamanio, 6, 10));
}
int cantidadDePares(int* listado, int tamanio)
{
    int i;
    int cantidadPares = 0;
    for (i=0; i< tamanio; i++)
    {
        if (listado[i]%2 == 0)
        {
            cantidadPares++;
        }
    }
    return cantidadPares;
}
int retornarCantidadDeNotas(int* listado, int tamanio, int minimo, int maximo)
{
    int i;
    int notas = 0;
    for (i=0; i< tamanio; i++)
    {
        if (listado[i] >= minimo && listado[i]<= maximo)
        {
            notas++;
        }
    }
    return notas;
}
