#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define bufferString 4096
#define CANTIDAD_EMPLEADOS 3
struct eEmpleado
{
    char nombre[50];
    char apellido[50];
    float salario;
}

typedef struct eEmpleado Empleado;
typedef struct eEmpleado
{
    char nombre[50];
    char apellido[50];
    float salario;
}Empleado;


void ordernarPorNombre(char* pNombre[][50], char* pApellido[][50], char* pDni[][50], int limite);
int main()
{
    char nombres[CANTIDAD_EMPLEADOS][50] = { "AAA", "CCC", "BBB"};
    char apellidos[CANTIDAD_EMPLEADOS][50] = { "AAA", "CCC", "BBB"};
    char dni[CANTIDAD_EMPLEADOS][50] = { "AAA", "CCC", "BBB"};
    int i;

    /*for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        utn_getNombre(nombres[i],50,"Nombre=?\n", "\nErrosr", 2 );
    }*/
    ordernarPorNombre(nombres, apellidos, dni, CANTIDAD_EMPLEADOS );
    for(i=0;i < CANTIDAD_EMPLEADOS;i++)
    {
        printf("%s %s %s\n", nombres[i], apellidos[i], dni[i]);
    }
    return 0;
}

void ordernarPorNombre(char* pNombre[][50], char* pApellido[][50], char* pDni[][50] ,int limite)
{
    int swap;
    int i;
    char bufferStr[256];
    do
    {
        swap = 0;
        for(i= 0; i< limite -1; i++)
        {
            if(strcmp(&pNombre[i], &pNombre[i+1]) >0 )
            {
                strcpy(bufferStr, pNombre[i]);
                strcpy(pNombre[i], pNombre[i+1]);
                strcpy(pNombre[i+1], bufferStr);

                strcpy(bufferStr, pApellido[i]);
                strcpy(pApellido[i], pNombre[i+1]);
                strcpy(pApellido[i+1], bufferStr);

                strcpy(bufferStr, pDni[i]);
                strcpy(pDni[i], pNombre[i+1]);
                strcpy(pDni[i+1], bufferStr);
            swap =1;
            }
        }

    }while (swap);


}




