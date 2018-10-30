#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int idCliente;
    char nombres[51];
    char apellido[51];
}clientes;
clientes * cli_newCliente (void);
int cli_getNombre(clientes* this, char * nombre);
int cli_buscarLugarVVacio(clientes* pArray[], int limite);
int cli_initArray(clientes* pArray[], int limite);
int cli_BuscarPorId (clientes * pArray[], int limite, int id);
int cli_deleteClinte (clientes* this);
int cli_getApellido(clientes* this, char * apellido);
int cli_setID(clientes* this, int id);

#endif // CLIENTES_H_INCLUDED
