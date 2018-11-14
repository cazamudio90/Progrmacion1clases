
#include "Empleado.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    return this;
}

void Empleado_delete(Empleado* this)
{
    free(this);
}

Empleado* Empleado_newConParametros(int id,char* nombre,int horasTrabajadas,int sueldo)
{
    Empleado* this;
    this=Empleado_new();

    if(
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setId(this,id)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
    !Empleado_setSueldo(this,sueldo))
        return this;

    Empleado_delete(this);
    return NULL;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setId(Empleado* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int em_calcularSueldo(Empleado* this)
{
    int returnAux = -1;
    int bufferHoras;
    char nombre[128];
    int total;
    if (this != NULL)
    {
        Empleado_getNombre(this,nombre);
        Empleado_getHorasTrabajadas(this,&bufferHoras);
        if(bufferHoras <= 120)
        {
            total = bufferHoras * 180;

        }else if(bufferHoras > 120 && bufferHoras <= 160)
        {
            total = bufferHoras - 120;
            total = (total * 240) + (120 * 180);

        }else if (bufferHoras >160 && bufferHoras <= 240)
        {
          total = bufferHoras - 160;
          total = (total * 350) + (40 * 240)+ (120 * 180);
        }
        returnAux = 0;
        printf("%s - %d\n", nombre, total);
    }
    return returnAux;
}

