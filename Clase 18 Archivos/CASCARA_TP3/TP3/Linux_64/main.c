#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
        printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
        printf("3. Alta de empleado\n");
        printf("4. Modificar datos de empleado\n");
        printf("5. Baja de empleado\n");
        printf("6. Listar empleados\n");
        printf("7. Ordenar empleados\n");
        printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
        printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
        printf("10. Salir\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
            printf("\nSize de la lista %d", ll_len(listaEmpleados));
            controller_loadFromText("data.csv",listaEmpleados);
            printf("\nSize de la lista %d\n", ll_len(listaEmpleados));
            break;
            case 2:
            controller_loadFromBinary("data.bin",listaEmpleados);
            break;
            case 3:
            if (controller_addEmployee(listaEmpleados)== 0)
            {
                printf("Empleado Agregado\n");
            }
            break;
            case 4:
            if(controller_editEmployee(listaEmpleados)==0)
            {
                printf("Empleado modificado\n");
            }else
            {
                printf("No existe ID");
            }
            break;
            case 5:
            if (controller_removeEmployee(listaEmpleados)== 0)
            {
                printf("Empleado Borrado\n");
                break;
            }
            case 6:
            controller_ListEmployee(listaEmpleados);
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            controller_saveAsBinary("data.bin", listaEmpleados);
            break;
            case 10:
            printf("salio\n");
            break;
            default:
            printf("Opcion no valida\n");
            break;
        }
    }while(option != 10);
    return 0;
}
