#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "array.h"
#define CANTIDAD_EMPLEADOS 6
#define DATO_INVALIDO -1
#define false 0
#define true 1


static int getInt(int* pResultado);


int array_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max)
{
    int retorno = -1;
    int auxiliarEdad;

    for(;reintentos > 0;reintentos--)
    {
        printf(msg);
        if(getInt(&auxiliarEdad) == 0)
        {
            if(auxiliarEdad >= min && auxiliarEdad < max)
            {
                *pEdad = auxiliarEdad;
                retorno = 0;
                break;
            }
            else
            {
                printf(msgErr);
            }
        }
        else
        {
            printf(msgErr);
            __fpurge(stdin);
        }
    }
    return retorno;
}

static int getInt(int* pResultado)
{
    if(scanf("%d",pResultado) == 1)
        return 0;
    return -1;
}

int arry_calcularMaximoArray(int* pArray, int limite, int* pMaximo)
{
    int retorno=-1;
    int i;

    int maximo;
    int flagPrimerMaximo = false;

    if(pArray != NULL && limite > 0)
    {

        for(i=0;i<limite;i++)
        {
            if(pArray[i] != DATO_INVALIDO)
            {
                if(flagPrimerMaximo == false)
                {
                    maximo = pArray[i];
                    flagPrimerMaximo = true;
                }
                else if(pArray[i] > maximo)
                {
                    maximo = pArray[i];
                }
            }
        }

        if(flagPrimerMaximo == 0)
        {
            retorno = -2;
        }
        else
        {
            retorno = 0;
        }
    }
    return retorno;
}
int array_initArray(int* pArray, int limite, int valor)
{
    int retorno=-1;
    int i;
    if(pArray != NULL && limite > 0)
    {
        for(i=0;i<limite;i++)
        {
            pArray[i] = valor;
        }
        retorno = 0;
    }
    return retorno;
}
int array_mostrarArray(int* pArray, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        printf("\nIndex:%d - Value:%d - Add: %p",i,pArray[i],&pArray[i]);

    }
    return 0;
}
int array_ordenar(int* pArray, int limite, int order)
{
    int retorno= -1;
    int j;
    int primerIndice;
    if(pArray != NULL && limite > 0)
    {
        for(j=0;j<limite;j++)
        {
            array_minimoDesde(pArray,limite, j, &primerIndice);
            array_swap(&pArray[j], &pArray[primerIndice]);
        }
    }
    return retorno;
}

int array_minimoDesde(int* pArray, int limite, int desde, int* pMinimo)
{
    int retorno=-1;
    int i;
    int auxuliarValorMinimo;
    int auxuliarIndiceMinimo;
    if(pArray != NULL && limite >= desde && pMinimo != NULL)
    {
        for(i=desde; i<limite ; i++)
        {
            if (i == 0|| pArray[i] < auxuliarValorMinimo)
            {
                auxuliarValorMinimo = pArray[i];
                auxuliarIndiceMinimo = i;
            }
        }
        retorno = 0;
        *pMinimo = auxuliarIndiceMinimo;
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
int array_ordenar2(int* pArray, int limite, int order)
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
