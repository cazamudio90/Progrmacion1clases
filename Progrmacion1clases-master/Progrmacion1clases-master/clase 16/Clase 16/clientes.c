#include "clientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <string.h>
#include <ctype.h>

static int utn_isValidNombre(char* pBuffer,int limite);
clientes * cli_newCliente (void)
{
   /* clientes* p;
   p = (clientes*) malloc(sizeof (clientes));
   return p; */
   return (clientes*) malloc(sizeof (clientes));

}
int cli_initArray(clientes* pArray[], int limite)
{
    int retorno = -1;
    int i;
    if(pArray != NULL && limite >0)
    {
        for (i= 0; i< limite; i++)
        {
            pArray[i] = NULL;
       }
      retorno = 0;
    }
    return retorno;
}

int cli_setNombre (clientes* this, char* nombre ) //guarda el nombre
{

    int retorno = -1;
    if(this != NULL && nombre != NULL && utn_isValidNombre(nombre, strlen(nombre)))
    {
        strncpy(this->nombres,nombre,sizeof(this->nombres));
        retorno = 0;
    }
    return retorno;
}

static int utn_isValidNombre(char* pBuffer, int limite)
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

int cli_getNombre(clientes* this, char * nombre)
{
  int retorno = -1;
    if (this != NULL && nombre != NULL)
    {
         strncpy(nombre,this->nombres,sizeof(this->nombres));
    }
  return retorno ;
}
/*int cli_getApellido(clientes* this, char * apellido)
{
  int retorno = -1;
    if (this != NULL && apellido != NULL)
    {
         strncpy(apellido,this->apellido,sizeof(this->apellido));
    }
  return retorno ;
}
int cli_setID(clientes* this, int id)
{
  int retorno = -1;
    if (this != NULL && id >= 0)
    {
         //this->id = id;
    }
  return retorno ;
}*/

int cli_buscarLugarVVacio(clientes* pArray[], int limite)
{
    int retorno = -1;
    int i;
    if(pArray != NULL && limite >0)
    {
        for (i=0; i<limite; i++)
        {
            if(pArray[i]== NULL)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int cli_BuscarPorId (clientes * pArray[], int limite, int id)
{
    int retorno = -1;
    int i;
    if (pArray != NULL && limite >0 && id >= 0)
    {
        for( i= 0; i< limite; i++)
        {
            if ( pArray[i] != NULL && pArray[i]->idCliente == id)
            {
                retorno = i;
                break;
            }
        }
    }

    return retorno;
}

int cli_deleteClinte (clientes* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}

/*clientes * cli_newClienteParametros(char*nombre, char * apellido, int id)
{
    clientes* p;
    p = cli_newCliente();
    if(p!= NULL)
    {
        if (cli_setNombre(p,nombre) == 0 && cli_setApellido(p,apellido) == 0 && cli_setID(p,id)==0)
        {
            printf("Se ingreso cliente");
        }else
        {
            cli_deleteClinte(p);
            p = NULL;
        }

    }

}*/
