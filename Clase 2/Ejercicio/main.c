#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Varibles
    float numeros[5];
    float contador = 0;
    float promedio;
    int i;

    for (i=0; i<5 ; i++)
    {
      printf("\nNumero %d: ", i+1);
      while(scanf("%f",&numeros[i]) != 1)
      {
        printf("\n Error - Numero %f: ", i+1);
        __fpurge(stdin);
      }
       contador = contador + numeros[i];
    }
     promedio = contador / 5;
     printf("El promedio es %f", promedio);

    return 0;
}
