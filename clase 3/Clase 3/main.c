#include <stdio.h>
#include <stdlib.h>
int pedirEdad();
int validarEdad(int edad, int max, int min);
int main()
{
   // Punteros

  /* int edad;
     int* pEdad;
     edad = 5;
     pEdad = &edad;
     pEdad = 8;
     printf("%d",edad);
     printf("%%d", *pEdad);

  */
    int edad;

    edad = pedirEdad2();
    printf("\nLa edad es de %d",edad);
}
 int pedirEdad()
 {
   int edad;
   int esValidadLaEdad;
   do
   {
     printf("Poner una edad valida: ");
     scanf("%d",&edad);
     esValidadLaEdad = validarEdad(edad, 1, 100);
   }while(esValidadLaEdad != 1);
   return edad;
 }
 int validarEdad(int edad, int min, int max)
 {
   if (edad >= min && edad <= max)
   {
     return 1;
   }else
   {
     return 0;
   }
 }
//Segunda Forma de hacerlo
   /* int pedirEdad2()
      {
       int edad;
       printf("Poner una edad valida: ");
       scanf("%d",&edad);
       edad = ValidarEdad2(edad, 1, 100);
      }
    int ValidarEdad2(int edad, int maximo, int minimo)
     {
       int contador;
       contador = 0;
       while (edad < minimo || edad > maximo
       {
        contador++;
        if (contador == 3)
       {
         break;
       }
        printf("Ingrese su edad nuevamente");
        scanf("%d",&edad);
       }

       return edad;
     }*/
