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



