#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD_EMPLEADOS 5
#define DATO_INVALIDO -1
#define false 0
#define true 1

static int getInt (int* numeroIngresado)
{
    fflush(stdin);
    return scanf("%d", numeroIngresado);
}
static int getChar (char* caracterIngresado)
{
    fflush(stdin);
    return scanf("%c",caracterIngresado);
}
static  int getString (char* textoIngresado)
{
    fflush(stdin);
    return scanf("%s", textoIngresado);
}

static  int getFloat (float* numeroIngresado)
{
    fflush(stdin);
    return scanf("%f", numeroIngresado);
}
/*
*\ brief solicita un numero al usuario valida y devuelve un resultado.
*\param presultado puntero a la variable resultado.
*\param mensaje es el mensaje a ser mostrado.
*\param mensaje de error.
*\param minimo es el numero minimo aceptado.
*\param maximo es el numero maximo aceptado.
*\param reintentos es la cantida de reintentos permitidos.
*\ return retorna 0 si esta correcto o -º si es incorrecto.
*/

int utn_getNumero(  int *pResultado,
                    char mensaje[],
                    char  mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)

{
    int retorno;
    char letraIngresado;

    while (reintentos>0)
    {
        printf(mensaje);
        fflush(stdin);
        if (scanf("%c",&letraIngresado)==1)
        {
            if (letraIngresado <= minimo && letraIngresado >= maximo)
            {
                break;
            }
        }
            reintentos --;
            printf(mensajeError);

    }

      if(reintentos == 0)
      {
        retorno = -1;
      }else
      {
        retorno = 0;
      }
  *pResultado = letraIngresado;
   printf("la letra ingresada esta dentro de los parametos : %d",letraIngresado);
   return retorno;
}


       /*
    *\ brief solicita un caracter al usuario valida y devuelve un resultado.
    *\param presultado puntero a la variable resultado.
    *\param mensaje es el mensaje a ser mostrado.
    *\param mensaje de error si tiene un error.
    *\param minimo el caracter minimo aceptado
    *\param maximo es el caracter maximo aceptado.
    *\param reintentos es la cantida de reintentos permitidos.
    *\ return retorna 0 si esta correcto o -º si es incorrecto.
    */


       int utn_getChar(char *pResultado,
                    char mensaje[],
                    char  mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)
    {

        int auxiliar;
        printf("%s",mensaje);
        scanf("%d",&auxiliar);
        return auxiliar;


    }

    /*
    *\ brief solicita un numero al usuario valida y devuelve un resultado.
    *\param presultado puntero a la variable resultado.
    *\param mensaje es el mensaje a ser mostrado.
    *\param mensaje de error.
    *\param minimo es el numero minimo aceptado.
    *\param maximo es el numero maximo aceptado.
    *\param reintentos es la cantida de reintentos permitidos.
    *\ return retorna 0 si esta correcto o -º si es incorrecto.
    */

    float utn_getFloat( float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos)
    {

        float auxiliar;
        printf("%s",mensaje);
        scanf("%f",&auxiliar);
        return auxiliar;

    }

    /*
    *\ brief solicita un caracter al usuario valida y devuelve un resultado.
    *\param presultado puntero a la variable resultado.
    *\param mensaje es el mensaje a ser mostrado.
    *\param mensaje de error.
    *\param minimo es el caracter minimo ceptado.
    *\param maximo es el caracter maximo aceptado.
    *\param reintentos es la cantida de reintentos permitidos.
    *\ return retorna 0 si esta correcto o -º si es incorrecto.
    */

    int utn_getCaracter( int *pResultado,
                        char mensaje[],
                        char  mensajeError[],
                        int minimo,
                        int maximo,
                        int reintentos);

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


