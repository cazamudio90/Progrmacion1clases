#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
typedef struct producto
{
    char nombre[50];
    char descripcion[150];
    float precio;
    int flag;
    int indice;
    //char errrMsg;
}productoDES;
int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos);

int utn_getFloat(   float *pFloat, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getEntero(  int *pEntero, int limite, char *mensaje,
                    char *mensajeError, int reintentos);
int utn_getProducto(productoDES* pArray, int len, int idProducto);
void recorrerEstructura( productoDES pArray ,int limite);
void printProducto(productoDES* pArray, int len);
int pedirIndiceVacio(productoDES* pArray, int len, int * indice);
void mostrarMenu (productoDES* pArray, int len);
int getArrayConId (productoDES* pArray, int len, int * indice, int id);
int utn_getProductoModificar(productoDES* pArray, int len, int idProducto);
int utn_getProductoBorrar(productoDES* pArray, int len, int idProducto);
#endif // UTN_H_INCLUDED
