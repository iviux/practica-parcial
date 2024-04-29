#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int o = 0;
    Pila p;
    inicpila(&p);

    int vectorNotas[DIMENSION] = {0};
    char palabras[CANT_PAL][LONG_PAL] = {"Hola", "Mundo", "martes", "mate", "agua", "computadora", "sobrino", "camion", "sal", "tractor"};

    do
    {
        system("cls");

        printf("Elija una opcion del menu: \n\n");
        printf("0) Salir.\n");
        printf("1) Cargar calificaciones.\n");
        printf("2) Pila a arreglo.\n");
        printf("3) Promedio.\n");
        printf("4) Mostrar mayor o menor.\n");
        printf("5) Mayor string.\n");
        printf("6) Adivinar palabra.\n");


        scanf("%d", &o);

        switch (o)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                system("cls");

                printf("Cargar calificaciones.\n\n");

                opcionDeCarga(&p);

                mostrar(&p);

                system("pause");

                break;
            }
            case 2:
            {
                system("cls");

                printf("Pila a arreglo.\n\n");

                pilaToArray(p, vectorNotas);
                muestraArreglo(vectorNotas);

                system("pause");

                break;
            }
            case 3:
            {
                system("cls");

                printf("Promedio.\n\n");

                muestraArreglo(vectorNotas);

                informeGeneralPromedios (vectorNotas);

                system("pause");

                break;
            }
            case 4:
            {
                system("cls");

                printf("Mostrar mayor o menor.\n\n");

                char mm[DIMENSION];
                int r = 0;

                do
                {
                    printf("Ingrese la nota que desea buscar: (mayor/menor)\n");
                    fflush(stdin);
                    scanf("%s", mm);

                    r = informaMayorMenor (vectorNotas, mm);

                } while (r == 0);

                printf("\nLa %s nota es: %d\n\n", mm, r);

                system("pause");

                break;
            }
            case 5:
            {
                system("cls");

                printf("Mayor string.\n\n");

                informaString(palabras, CANT_PAL);

                system("pause");

                break;
            }
            case 6:
            {
                system("cls");

                printf("Adivinar palabra.\n\n");

                adivinarLaPalabra(palabras);

                system("pause");

                break;
            }
        }

    } while (o != 0);



    return 0;
}
