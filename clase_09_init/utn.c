#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096
static int isValidFloat(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (((pBuffer[0] == '-' || pBuffer[0] == '+') && pBuffer[1] != '.') ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
static int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 ) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1;i < limite && pBuffer[i] != '\0';i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}
/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if(tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
    utn_getNombre :
    @param
    @param
    @return
*/
static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}


/**
    utn_getNombre :
    @param
    @param
    @return
*/
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}
int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferFloat[4096];
    if( pFloat != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferFloat, limite) == 0 &&
                isValidFloat(bufferFloat, limite))
            {
                *pFloat = atof(bufferFloat);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}

int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferEntero[4096];
    if( pEntero != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(bufferEntero, limite) == 0 &&
                isValidEntero(bufferEntero, limite))
            {
                *pEntero = atoi(bufferEntero);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }while(reintentos>=0);
    }
    return retorno;
}
/*3)  Realizar una funcion que reciba el array, un indice, y le
    permita al usuario cargar los datos en el item de la posicion especificada por el indice.
    int getCharArray(productoDes* pArray, int indice) tAMBIE SE LE AGREGA EL TAMAÑO DEL INDICE*/
int utn_getProducto(productoDES* pArray, int len, int idProducto)
    {
        int retorno = -1;
        char bufferNombre[50];
        char bufferDescripcion[150];
        float bufferPrecio;
        int bufferEntero;
        if(pArray != NULL && len > 0 && idProducto < len)
        {
            if (pArray[idProducto].flag == 0)
            {
                if ((utn_getNombre(bufferNombre, 50, "Ingrese Producto\n", "No es un nombre valido\n", 2)==0 )&&
                 (utn_getNombre(bufferDescripcion, 150, "Ingrese Descripcion Producto\n", "No es un desc valido\n", 2)==0)
                && utn_getFloat(&bufferPrecio,20, "Ingrese Precio\n", "No es un precio valido\n",2 )== 0
                && utn_getEntero(&bufferEntero,20, "Ingrese id", "No es un id Valido", 2)== 0)
                {
                 strncpy(pArray[idProducto].nombre, bufferNombre, 50);
                 strncpy(pArray[idProducto].descripcion, bufferDescripcion, 150);
                 pArray[idProducto].precio =  bufferPrecio;
                 pArray[idProducto].indice = bufferEntero;
                 pArray[idProducto].flag =  1;
                retorno = 0;
                }
            }
        }

        return retorno;
    }


/*4)  Realizar una funcion que reciba el array y un indice e imprima
    los datos del item de la posicion especificada por el indice.*/
void printProducto(productoDES* pArray, int len)
{
      if (pArray != NULL && len > 0)
      for(int i = 0; i < len ; i++ )
      {
           if (pArray[i].flag == 1)
           {
                printf("Producto %s\n", pArray[i].nombre);
                printf("Descripcion %s\n", pArray[i].descripcion);
                printf("Precio %f\n", pArray[i].precio);
                printf("Indice %d\n", pArray[i].indice);
           }

       }

}

//5)  Realizar una funcion que me devuelva el indice de un item vacio (sin cargar).
int pedirIndiceVacio(productoDES* pArray, int len, int * indice)
{
    int retorno = -1;
     for (int i = 0; i <= len; i++)
     {
       if (pArray[i].flag == 0)
       {
         *indice = i;
         retorno = 0;
         break;
       }
     }
     printf("Indice vacio %d\n", *indice);

     return retorno;
}

/*
3) Realizar un programa con un menu de dos opciones:
    a) Cargar un producto
    b) Imprimir lista productos
*/
void mostrarMenu (productoDES* pArray, int len)
{
  char resp;
  int idProducto;
  int id;
  int subIndice;
  do
  {
      printf("a- Cargar Producto\n");
      printf("b- Imprimir lista de productos\n");
      printf("c- Editar producto por id\n");
      printf("d- Borrar producto por id\n" );
      printf("g- Salir\n");
      __fpurge(stdin);
      scanf("%c", &resp);
      switch(resp)
      {
        case 'a':
         if (pedirIndiceVacio(pArray, len, &idProducto) == 0)
              {

                utn_getProducto(pArray,len, idProducto);
                //printProducto(productos, idProducto);
              }
              break;
         case 'b':
         printProducto(pArray, len);
         break;
         case 'c':
         if (utn_getEntero(&id,20, "Ingrese id", "No es un id Valido", 2)== 0)
         {
            if (getArrayConId (pArray, len, &subIndice, id) == 0)
            {
                utn_getProductoModificar( pArray, len, subIndice);
            }
         }
         case 'd':
         if (utn_getEntero(&id,20, "Ingrese id", "No es un id Valido", 2)== 0)
         {
            if (getArrayConId (pArray, len, &subIndice, id) == 0)
            {
                if (utn_getProductoBorrar(pArray, len, subIndice) == 0)
                {
                    printf("Producto borrado");
                }else
                {
                    printf("no se encontro Producto");
                }
            }
         }
         case 'g':
         printf("salio");
         break;
         default:
         printf("No es una opcion valida\n");
         break;
      }
    }while(resp != 'g');
}

/*5)  Realizar una funcion que reciba el array y un ID, y me devuelva el indice
    del item con dicho ID.*/

int getArrayConId (productoDES* pArray, int len, int * indice, int id)
{
   int retorno = -1;
    if (pArray != NULL && len >0)
    {
        for (int i = 0; i < len; i++)
        {
            if ( id == pArray[i].indice)
            {
                printf("El indice es %d" ,i);
                *indice = i;
                retorno = 0;
                break;
            }
        }
        if (retorno == -1)
        {
            printf("No se encontro id");
        }
    }
    return retorno;
}
int utn_getProductoModificar(productoDES* pArray, int len, int idProducto)
    {
        int retorno = -1;
        char bufferNombre[50];
        float bufferPrecio;
        if(pArray != NULL && len > 0 && idProducto < len)
        {
            if (pArray[idProducto].flag == 1)
            {
                if ((utn_getNombre(bufferNombre, 50, "Modifique Producto\n", "No es un nombre valido\n", 2)==0 )
                && utn_getFloat(&bufferPrecio,20, "Modifique Precio\n", "No es un precio valido\n",2 )== 0)
                {
                 strncpy(pArray[idProducto].nombre, bufferNombre, 50);
                 pArray[idProducto].precio =  bufferPrecio;
                retorno = 0;
                }
            }
        }

        return retorno;
    }
int utn_getProductoBorrar(productoDES* pArray, int len, int idProducto)
{
    int retorno = -1;
    if(pArray != NULL && len > 0 && idProducto < len)
    {
        if (pArray[idProducto].flag == 1)
        {
            pArray[idProducto].flag =  0;
            retorno = 0;
        }
    }
    return retorno;
}

/*6)  Realizar una funcion que reciba el array, un indice, y le permita al usuario
    modificar los campos nombre y precio del item del array en la posicion especificada por el indice.*/





