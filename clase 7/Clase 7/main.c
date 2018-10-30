#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"
#include <string.h>
int main()
{

    char usuario[6];
    getNombre(&usuario[6]);
    /*char clave[9];
    char auxUser[9]= "admin\n";
    char auxClave[9]= "admin\n";
    int auxTamanio;

    fgets(usuario, 16, stdin);
    __fpurge(stdin);
    fgets(clave, 9, stdin);
    __fpurge(stdin);
    auxTamanio = strlen(usuario);
    printf("El tamanio es %d\n", auxTamanio);
    printf("la clave es:  %s\ny el usuario es %s\n", clave, usuario);

    if( (strcmp(usuario,auxUser) && strcmp(clave, auxClave) ) == 0 )
    {

        printf("Ingreso");
    }else
    {
        printf("noooooo");
    }*/


    /*
    char nombre[25];
    char apellido[25];
    char localidad[25];
    int tamanio;
    tamanio = sizeof(nombre);
    printf("el tamanio antes es : %d\n", tamanio);
    printf("Ingrese nombre: \n");
    scanf("%s", nombre);
    printf("el tamanio es : %d\n", tamanio);
    printf("El nombre ingresado es ");
    fgets(nombre,10, stdin);
    __fpurge(stdin);
    fgets(apellido,10, stdin);
    __fpurge(stdin);
    fgets(localidad,10, stdin);
    __fpurge(stdin);
    printf("\n El nombre es: %s\n El apellido ingresado es %s\n y la localidad es: %s\n", nombre, apellido, localidad);
    */
    return 0;
}
