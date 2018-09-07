#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#endif // UTN_H_INCLUDED
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED



#endif // UTN_H_INCLUDED
int utn_getNumero(  int *pResultado,
                    char mensaje[],
                    char  mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos);
int utn_getChar(char *pResultado,
                    char mensaje[],
                    char  mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos);
float utn_getFloat( float *pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int minimo,
                    int maximo,
                    int reintentos);
int utn_getCaracter( int *pResultado,
                        char mensaje[],
                        char  mensajeError[],
                        int minimo,
                        int maximo,
                        int reintentos);

int retornarTotal(int listado[],  int tamanio);
int retornarPromedio(int listado[],  int tamanio);
void cargarListado(int* listado, int tamanio);
void mostrarListado(int* listado, int tamanio);
int obtenerMayor(int* listado, int tamanio);
int obtenerMenor(int* listado, int tamanio);
void mostrarInformacionDelArray(int* listado, int tamanio);
int cantidadDePares(int* listado, int tamanio);
int retornarCantidadDeNotas(int* listado, int tamanio, int minimo, int maximo);
#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED


/**
    utn_getEntero : pide un entero al usuario
    @param pEdad: puntero a edad
    @param reintentos: cantidad de reintentos
    @return : 0 OK, -1 error.
*/
int utn_getEntero(int* pEdad,int reintentos,char* msg,
                          char*msgErr,int min, int max);


#endif // UTN_H_INCLUDED


