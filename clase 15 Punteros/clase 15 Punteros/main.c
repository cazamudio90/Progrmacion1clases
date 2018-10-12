#include <stdio.h>
#include <stdlib.h>

int* new_array(int size);
int inicializar_array(int*pArray, int limite, int valor);
int  punterosPrint_array(int*pArray, int limite);
int delete_array(int*pArray);
int reSize_array ( int * arrayInt, int size);
int main()
{
    int * arrayEnteros;
    arrayEnteros = new_array(100);
    inicializar_array(arrayEnteros, 100, 1024);
    punterosPrint_array(arrayEnteros, 100);
    delete_array(arrayEnteros);

    return 0;
}
int* new_array(int size)
{
    int* retorno = NULL;
    int * auxInt;
    if (size > 0)
    {
      auxInt = (int*) malloc (sizeof(int) * size);
         if ( auxInt != NULL)
         {
            retorno = auxInt;
         }
    }
    return retorno;
}
int inicializar_array(int* pArray, int limite, int valor)
{
    int retorno = -1;
    int i;
    if (pArray != NULL && limite > 0)
    {
        for(i=0; i < limite; i++)
        {
            *(pArray+i) = valor;
        }
       retorno = 0;
    }
  return retorno;
}
int punterosPrint_array(int*pArray, int limite)
{
    int retorno = -1;
    int i;
    for(i=0; i < limite; i++)
    {
        printf("%p - [%d] - %d \n", (pArray + i), i ,*(pArray + i) );
    }
    retorno = 0;
return retorno;
}
int delete_array(int* pArray)
{
    int retorno = -1;
    if (pArray != NULL)
    {
        free(pArray);
        retorno = 0;
    }

    return retorno;
}

int reSize_array ( int * arrayInt, int size)
{
    int* retorno = NULL;

    if(arrayInt != NULL && size >0 )
    {
        retorno = realloc(arrayInt, sizeof(int)*size);
    }
    return retorno;
}
