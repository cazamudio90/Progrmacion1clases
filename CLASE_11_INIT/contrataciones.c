#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "utn.h"
#include "contrataciones.h"

static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice);
int con_inicializarArray(Contratacion* pBuffer,int limite){
    int i;
    for(i=0;i<limite;i++){
        pBuffer[i].isEmpty=1;
    }
    return 0;
}
int con_borrarPorID(Contratacion* pBuffer,int limite,int id){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==0&& pBuffer[i].ID==id){
            pBuffer[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}
int con_contratarPublicidad(Contratacion* pBuffer,int id,int limite){
    int indice;
    if(con_buscarIndiceVacio(pBuffer,limite,&indice)==0){
        pBuffer[indice].ID=con_obtenerID();
        pBuffer[indice].isEmpty=0;
        pBuffer[indice].idPantalla=id;
        utn_getLetrasYNumeros(pBuffer[indice].video,15,"\nIngrese el nombre del video: ");
        utn_getLetrasYNumeros(pBuffer[indice].cuit,10,"\nIngrese el CUIT: ");
        utn_getEntero(&pBuffer[indice].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
    }
    return 0;
}
int con_obtenerID(){
    static int ID=0;
    return ID++;
}
static int con_buscarIndiceVacio(Contratacion* pBuffer,int limite,int*indice){
    int i;
    int retorno=-1;
    for(i=0;i<limite;i++){
        if(pBuffer[i].isEmpty==1){
            *indice=i;
            retorno=0;
            break;
        }
    }
    return retorno;
}
int con_imprimirPorCuit(Contratacion* pBuffer,int limite,char* cuit){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0&&cuit!=NULL){
        for(i=0;i<limite;i++){
            if(pBuffer[i].isEmpty==0&&strcmp(pBuffer[i].cuit,cuit)==0){
                retorno=0;
                printf("\nID: %d",pBuffer[i].ID);
                printf("\tID Pantalla: %d",pBuffer[i].idPantalla);
                printf("\tDias: %d",pBuffer[i].dias);
                printf("\tVideo: %s",pBuffer[i].video);
            }
        }
    }
    return retorno;
}
int con_modificarPorIdPantalla(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
    if(pBuffer!=NULL&&limite>0){
        for (i=0;i<limite;i++){
            if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                retorno=0;
                utn_getEntero(&pBuffer[i].dias,3,"\nIngrese la cantidad de dias: ","\nError Ingrese una cantidad de dias validos",1,200);
            }
        }
    }
    return retorno;
}
int con_cancelarById(Contratacion* pBuffer,int limite,int idPantalla){
    int i;
    int retorno=-1;
        if(pBuffer!=NULL&&limite>0){
            for(i=0;i<limite;i++){
                if(pBuffer[i].idPantalla==idPantalla&& pBuffer[i].isEmpty==0){
                    retorno=0;
                    pBuffer[i].isEmpty=1;
                }
            }
        }
    return retorno;
}

int con_listarImportePorContratacion(Contratacion* pBufferCon,Pantalla* pBufferPan,int limiteCon,char* cuit,int limitePan)
{
    int retorno=-1;
    int i,j;
    float total = 0;
    if(pBufferCon != NULL && pBufferPan != NULL && limiteCon >0 && cuit != NULL && limitePan > 0)
    {
        for (i = 0; i < limiteCon; i++)
        {
            if(pBufferCon[i].isEmpty == 0 && strcmp(pBufferCon[i].cuit, cuit)== 0)
            {
                for (j= 0; j< limitePan; j++)
                {
                    if(pBufferPan[j].ID == pBufferCon[i].idPantalla)
                    {
                        total = total + pBufferPan[j].precio;
                        break;
                    }

                }
            }
        }
        printf("Debera pagar %f\n", total);
    }
    return retorno;
}

int con_imprimirContrataciones(Contratacion* pBuffer,int limite)
{
    int i;
    if (pBuffer != NULL && limite >0  )
    {
        for (i = 0; i< limite; i++)
        {
            if (pBuffer[i].isEmpty == 0)
            {
                printf("ID %d\n", pBuffer[i].ID);
                printf("Video %s\n", pBuffer[i].video);
                printf("Cuit %s\n", pBuffer[i].cuit);
                printf("Dias %d\n", pBuffer[i].dias);
                printf("ID Pantalla %d\n", pBuffer[i].idPantalla);
                printf("---------------------------------\n");
            }
        }
    }

    return 0;
}
int con_ordenarByCuit(Contratacion* pBuffer,int limite,int upOrDonw)
{
  int i, j;
  char auxCuit[4096];
  if (pBuffer != NULL && limite > 0 )
    {
        for(i = 0; i < limite; i++)
        {
           for(j = 0; j < limite- 1; j++)
           {
                if(pBuffer[i].isEmpty == 0 && upOrDonw == 1 && strcmp(pBuffer[i].cuit,pBuffer[j+1].cuit) > 0)
                {
                    strncpy(auxCuit,pBuffer[j+1].cuit, 4096);
                    strncpy(pBuffer[j+1].cuit,pBuffer[i].cuit, 4096);
                    strncpy(pBuffer[i].cuit,auxCuit, 4096);
                }else if (pBuffer[i].isEmpty == 0 && upOrDonw == 0 && strcmp(pBuffer[i].cuit,pBuffer[j+1].cuit) < 0)
                {
                    strncpy(auxCuit,pBuffer[i].cuit,4096);
                    strncpy(pBuffer[j+1].cuit, pBuffer[i].cuit,4096);
                    strncpy(pBuffer[j+1].cuit,auxCuit,4096);
                }

           }
        }
    }
    return 1;
}
int con_intercambiarPocionEstructura(Contratacion* pBuffer,int indiceDestino,int indiceOrigen){
    return 0;
}

int con_agruparPosiciones(Contratacion* pBuffer,int limite){

    return 1;
}

int con_ingresoForzado(Contratacion* pBuffer,int limite,char* video,char* cuit,int dias,int idPantalla){
    int aux;
    con_buscarIndiceVacio(pBuffer,limite,&aux);
    strcpy(pBuffer[aux].video,video);
    strcpy(pBuffer[aux].cuit,cuit);
    pBuffer[aux].dias=dias;
    pBuffer[aux].idPantalla=idPantalla;
    pBuffer[aux].isEmpty=0;
    pBuffer[aux].ID=con_obtenerID();
    return 0;
}
int con_listarClientesEImportes(Contratacion * pBufferCon,Pantalla* pbufferPan,int limiteCon,int limitePan)
{
    int i, j, y;
    CuitUnico listaCuit[4096];

    for (i=0; i < limiteCon; i++)
    {
        for (j= 0; j<limiteCon -1; i++)
        {
           for (y = 0; y < limiteCon-1; y++)
           {
               if (pBufferCon[i].isEmpty ==0&& listaCuit[y].isEmpty ==0 && i == 0 )
                {
                     strncpy(listaCuit[y].cuit, pBufferCon[i].cuit, 4096);
                     listaCuit[y].ID = y;
                     listaCuit[y].idPantalla = pBufferCon[i].idPantalla;
                     listaCuit[y].isEmpty = 1;
                }
                if ((pBufferCon[i].isEmpty ==0 && strcmp(pBufferCon[i].cuit, pBufferCon[j+1].cuit)!= 0))
                {
                     strncpy(listaCuit[y].cuit,pBufferCon[j+1].cuit,4096);
                     listaCuit[y].ID = y;
                     listaCuit[y].idPantalla = pBufferCon[j+1].idPantalla;
                     listaCuit[y].isEmpty = 1;
                }else
                {
                    continue;
                }
            }
        }
    }

    return 1;
}
