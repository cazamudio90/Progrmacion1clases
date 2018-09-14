#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED

int utn_getNombre(  char* pNombre,int limite, char* msg,
                    char* msgErr, int reintentos);

char array_ordenarString(char* pArray, int limite, int order);
void array_swap (int* elementoA, int* elementoB);
#endif // UTN_H_INCLUDED
