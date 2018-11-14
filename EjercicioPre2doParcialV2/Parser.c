#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
int parser_EmployeeFromText(FILE* pFile , LinkedList* listaEmpleados)
{
    int retorno = -1;
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Empleado * pEmpleado;
    int flagOnce = 1;
    if(pFile != NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
                flagOnce = 0;
                fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferNombre,
                        bufferHorasTrabajadas,
                        bufferSueldo);

            }
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",
                        bufferId,
                        bufferNombre,
                        bufferHorasTrabajadas,
                        bufferSueldo);
            pEmpleado = Empleado_newConParametros( bufferId,
                                                   bufferNombre,
                                                   bufferHorasTrabajadas,
                                                   bufferSueldo);
            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(listaEmpleados, pEmpleado);

            }
        }
    }
    return retorno;
}
int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(fileName,"r");
    if(!parser_EmployeeFromText(pArchivo, listaEmpleados))
    {
        retorno = 1;
    }
    fclose(pArchivo);
    return retorno;
}

