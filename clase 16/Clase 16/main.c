#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"
#include <string.h>
#define CANTIDAD_ARRAY 100
int main()
{
    //clientes * clientes = (cliente) malloc (100*sizeof);
    clientes * clientesArray [CANTIDAD_ARRAY];
    char * auxNombre[64];
    int i;
    clientes* aux;
    cli_initArray(clientesArray, CANTIDAD_ARRAY);
    aux = cli_newCliente();
    if(aux != NULL)
    {
        //strncpy(aux->nombres,"camela",sizeof(aux->nombres));
        cli_setNombre(aux, "Juan");
        clientesArray[0] = aux;
        cli_getNombre(aux,auxNombre);
        printf("%s", auxNombre);
    }
    return 0;
}
