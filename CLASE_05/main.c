#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD_EMPLEADOS 6
#define DATO_INVALIDO -1
#define false 0
#define true 1

int main()
{
    int edades[CANTIDAD_EMPLEADOS] = { 50, 10 , 30, 50, 1, 22};
   // int i;
/*
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        if(utn_getEntero(&edades[i],2,"\nEdad?","\nEdad fuera de rango",0,200)==-1)
        {
            edades[i] = DATO_INVALIDO;
        }
    }
*/
    //array_mostrarArray(edades,CANTIDAD_EMPLEADOS);
    array_ordenar2(edades,CANTIDAD_EMPLEADOS,0);
    /*int cantidad;
    char nombre[81];
    char bufferNombre[4097];
    scanf("%s", bufferNombre);
    cantidad = strlen(bufferNombre);
    strncpy(nombre, bufferNombre, 81);
    printf("\n ---> %s", nombre);*/
   array_mostrarArray(edades,CANTIDAD_EMPLEADOS);

    return 0;
}



