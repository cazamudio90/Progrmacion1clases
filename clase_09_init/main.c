#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

#define CANTIDAD_PRODUCTOS 200

int main()
{

/*1)  Definir un tipo de dato que represente un producto.
    El producto tiene un nombre, una descripcion y un precio*/



/*2)  Definir un array de 200 productos, indicar de alguna manera
    que la info de cada item no esta cargada.*/
     productoDES productos [CANTIDAD_PRODUCTOS];
     //int idProducto;
     for (int i = 0; i <= CANTIDAD_PRODUCTOS; i++)
    {
        productos[i].flag = 0;
        productos[i].indice = 0;
    }
 //pedirIndiceVacio(productos,CANTIDAD_PRODUCTOS);
  mostrarMenu (productos, CANTIDAD_PRODUCTOS);
/*




7)  Agregar una opcion en el menu. "Editar producto" que pida al usuario el ID del
    mismo y le permita cambiar el nombre y el precio.

8)  Agregar una opcion en el menu "Borrar producto" que pida al usuario el ID del
    mismo.*/

    return 0;
}




