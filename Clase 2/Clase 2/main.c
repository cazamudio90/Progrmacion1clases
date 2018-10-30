#include <stdio.h>
#include <stdlib.h>

#define LIMITE_ARRAY 3 //ESTO  es para limitar los arrays
int main()
{
    //Varibles
      int numero[LIMITE_ARRAY]; //arrays
      int primerNumero = 9999;
      int segundoNumero;
      int tercerNumero;
      int numeroMaximo;
      int numeroMinimo;
      int i;
      //ejercicio 2 Para achicar el codigo
       for(i=0; i<LIMITE_ARRAY ;i++)
       {
         printf("\nNumero %d: ", i+1);

         while(scanf("%d",&numero[i]) != 1)
         {
            printf("\n Error - Numero %d: ", i+1);
            __fpurge(stdin);
         }
         if (i==0)
         {
         numeroMaximo = numero[i];
         numeroMinimo = numero[i];
         } else if(numero[i] > numeroMaximo)
         {
           numeroMaximo = numero[i];
         }else if (numero[i] < numeroMinimo)
         {
           numeroMinimo = numero[i];
         }
       }
       printf("Max: %d - Min %d", numeroMaximo, numeroMinimo);

       for (i=0; i<LIMITE_ARRAY ; i++)
       {
         if (numero[i] > numeroMinimo && numero[i] < numeroMaximo)
           {
             printf("\nEs el del medio %d", numero[i]);
             break;
           }
       }
      /*
    //Procedimientos para hacer el ejercicio 1
      printf("\nNumero 1: ");

      while(scanf("%d",&primerNumero) != 1)
      {
        printf("\n Error - Numero 1: ");
        __fpurge(stdin);
      }
     printf("%d",primerNumero);
     numeroMaximo = primerNumero;
     numeroMinimo = primerNumero;
     // para el seungo numero
       printf("\nNumero 2: ");
       while(scanf("%d",&segundoNumero) != 1)
      {
        printf("\n Error - Numero 2: ");
        __fpurge(stdin);
      }
      if (segundoNumero > numeroMaximo)
      {
        numeroMaximo = segundoNumero;
      } else if (segundoNumero < numeroMinimo)
      {
        numeroMinimo = segundoNumero;
      }
      printf("%d",segundoNumero);
      //Tercer numero
      printf("\nNumero 3: ");
       while(scanf("%d",&tercerNumero) != 1)
      {
        printf("\n Error - Numero 2: ");
        __fpurge(stdin);
      }
      if (tercerNumero > numeroMaximo)
      {
        numeroMaximo = tercerNumero;
      } else if (tercerNumero < numeroMinimo)
      {
        numeroMinimo = tercerNumero;
      }
      printf("%d",tercerNumero);
      printf("\nMax: %d",numeroMaximo);
      printf("\nMin: %d",numeroMinimo);
      //
      if (primerNumero < numeroMaximo && primerNumero > numeroMinimo)
      {
        printf("\nEs el del medio %d", primerNumero);
      }
      // segundo numero para ver si es el del medio
      if (segundoNumero < numeroMaximo && segundoNumero > numeroMinimo)
      {
        printf("\nEs el del medio %d", segundoNumero);
      }
      // Tercer numero
      if (tercerNumero < numeroMaximo && tercerNumero > numeroMinimo)
      {
        printf("\nEs el del medio %d", tercerNumero);
      }*/
    return 0;
}
