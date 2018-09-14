#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFERSTRING 4096
/**
    utn_isValidNombre :
    @param
    @param
    @return
*/

static int utn_isValidNombre(char* pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if (pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for (i=0; i < limite && pBuffer[i] != '\0'; i++ )
        {
            if (tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
               retorno = 0;
                break;
            }
        }
    }

    return retorno;
}

/**
    utn_getString :
    @param
    @param
    @return
*/
static int utn_getString(char* pBuffer, int limite)
{
    int retorno = -1;
    int auxLen;
    char buffer[BUFFERSTRING];
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(buffer, limite, stdin);
        auxLen = strlen(buffer);
        if(auxLen != (limite - 1) || buffer[limite-2] == '\n' )
        {
            buffer[auxLen -1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer, buffer, limite);
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre,int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFERSTRING];
    if(pNombre != NULL && limite > 0 && msg != NULL && msgErr != NULL && reintentos >= 0 )
    {
      do
      {
         reintentos--;
         printf("%s", msg);
         if (utn_getString(bufferNombre, limite) == 0 && utn_isValidNombre(bufferNombre, limite))
         {
            strncpy(pNombre, bufferNombre, limite);
            retorno = 0;
            break;
         }else
         {
            printf("%s", msgErr);
         }


      }while(reintentos>=0);
    }
    return retorno;
}

void array_swap (int* elementoA, int* elementoB)
{
    int auxiliar;
    auxiliar = *elementoA;
    *elementoA = *elementoB;
    *elementoB = auxiliar;
}
char array_ordenarString(char* pArray, int limite, int order)
{
    int retorno= -1;
    int j;
    int flagSwap = 0;
    if(pArray != NULL && limite > 0)
    {
        do
        {
            for(j=0;j<limite-1;j++)
            {
                if (order == 0 && pArray[j] < pArray[j+1] || (order == 1 && pArray[j] < pArray[j+1]))
                {
                    flagSwap = 1;
                    array_swap(&pArray[j], &pArray[j+1]);
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



















