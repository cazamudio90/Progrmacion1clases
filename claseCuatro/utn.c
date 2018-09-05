#include <stdio.h>
#include <stdlib.h>
#include "../claseCuatro/utn.h"
static  int getInt (int* numeroIngresado)
{
    fflush(stdin);
    return scanf("%d",numeroIngresado);
}
static int getChar (char* caracterIngresado)
{
    fflush(stdin);
    return scanf("%c",caracterIngresado);
}
static  int getString (char* textoIngresado[])
{
    fflush(stdin);
    return scanf("%s",textoIngresado);
}

static  int getFloat (float* numeroIngresado)
{
    fflush(stdin);
    return scanf("%f",numeroIngresado);
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
        if (scanf("%c",&numeroIngresado)==1)
        {
            if (letraIngresado <='a' && letraIngresado >='z' )
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
        scanf("%d",auxiliar);
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

        int auxiliar;
        printf("%s",mensaje);
        scanf("%f",auxiliar);
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

    {





    }



