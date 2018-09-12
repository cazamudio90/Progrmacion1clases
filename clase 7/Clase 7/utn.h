#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#include "utn.h"
#include <string.h>
#define DATO_INVALIDO -1
#define false 0
#define true 1


int array_getEntero(int* pEdad,int reintentos,char* msg,char*msgErr,int min, int max);
int arry_calcularMaximoArray(int* pArray, int limite, int* pMaximo);
int array_initArray(int* pArray, int limite, int valor);
int array_mostrarArray(int* pArray, int limite);
int array_ordenar(int* pArray, int limite, int order);
int array_maximoDesde(int* pArray, int limite, int desde, int* pMinimo);
int array_minimoDesde(int* pArray, int limite, int desde, int* pMinimo);
void array_swap (int* elementoA, int* elementoB);
char getNombre(char* pArray);
char getNombreValido(char* pArray);

#endif // UTN_H_INCLUDED
