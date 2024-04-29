#include "funciones.h"


int cargarPilaUsuario (Pila *p)
{
    system("cls");

    int val = 0, cal = 0;
    char op;

    do
    {
        printf("Ingrese la calificacion %d: ", val+1);
        scanf("%d", &cal);
        apilar(p, cal);
        val++;

        printf("Presione una tecla para continuar, 'esc' para salir.");
        fflush(stdin);
        op = getch();
        system("cls");

    } while (val < 50 && op != 27);

    return val;
}

void cargarPilaRandom (Pila *p)
{
    system("cls");

    srand(time(NULL));
    int val = 0;

    printf("Cuantos valores desea agregar a la pila: ");
    scanf("%d", &val);

    for (int i = 0; i < val; i++)
    {
        apilar(p, rand() % 10 + 1);
    }
}

void opcionDeCarga (Pila *p)
{
    char op;

    do
    {
        printf("Como desea cargar la pila: Manual (m) / Automatico (a)");
        fflush(stdin);
        op = getch();

        switch(op)
        {
            case 'm':
            {
                cargarPilaUsuario(p);
                break;
            }
            case 'a':
            {
                cargarPilaRandom(p);
                break;
            }
            default:
            {
                system("cls");

                printf("La opcion ingresada es incorrecta. ");
                system("pause");
            }

        }
    }while (op != 'a' && op != 'm');
}

int pilaToArray (Pila p, int a[])
{
    int inpar = 1, par = 0, val = 0;
    Pila aux;
    inicpila(&aux);

    while (!pilavacia(&p))
    {
        apilar(&aux, desapilar(&p));
    }

    while (!pilavacia(&aux))
    {
        if (tope(&aux) % 2 == 0)
        {
            a[par] = desapilar(&aux);
            par = par + 2;
        }
        else
        {
            a[inpar] = desapilar(&aux);
            inpar = inpar + 2;
        }
        val ++;
    }

    return val;
}

void muestraArreglo (int a[])
{
    int i = 0;

    while (i < DIMENSION)
    {
        if (a[i] != 0)
        {
            printf("%2d |", a[i]);
            i++;
        }
        else
        {
            i++;
        }
    }
    printf("\n\n");
}

void informeGeneralPromedios (int a[])
{
    int suma = 0, val = 0, bajos = 0, altos = 0;

    for (int i = 0; i < DIMENSION; i++)
    {
        if (a[i] != 0)
        {
            suma+= a[i];
            val ++;
        }
    }

    float promedio = (float) suma / val;

    for (int i = 0; i < DIMENSION; i++)
    {
        if (a[i] != 0 && a[i] < promedio)
        {
            bajos++;
        }
        else if (a[i] != 0 && a[i] > promedio)
        {
            altos++;
        }
    }


    printf("El promedio de la clase es %.2f\n", promedio);
    printf("Hay %d alumnos debajo del promedio y %d por encima\n\n", bajos, altos);
}

int buscarMayor (int a[])
{
    int mayor = 0;

    for (int i = 0; i < DIMENSION; i++)
    {
        if (a[i] != 0 && a[i] > mayor)
        {
            mayor = a[i];
        }
    }
    return mayor;
}

int buscarMenor (int a[])
{
    int menor = 11;

    for (int i = 0; i < DIMENSION; i++)
    {
        if (a[i] != 0 && a[i] < menor)
        {
            menor = a[i];
        }
    }
    return menor;
}

int informaMayorMenor (int a[], char s[])
{
    int r = 0;

    if (strcmpi(s, "mayor") == 0)
    {
        r = buscarMayor(a);
    }
    else if (strcmpi(s, "menor") == 0)
    {
        r = buscarMenor(a);
    }
    else
    {
        system("cls");
        return 0;
    }

    return r;
}

int contarVocalesEnPalabra (char p[])
{
    int i = 0, v = 0;

    while (p[i] != 0)
    {
        if(p[i] == 'a' || p[i] == 'e' || p[i] == 'i' || p[i] == 'o' || p[i] == 'u')
        {
            v++;
        }

        i++;
    }

    return v;
}

int informaString (char s[][LONG_PAL], int val)
{
    int pos = 0, mayor = 0;

    for (int i = 0; i < val; i++)
    {
        if (contarVocalesEnPalabra(s[i]) > mayor)
        {
            mayor = contarVocalesEnPalabra(s[i]);
            pos = i;
        }
    }

    printf("La palabra con mas vocales es %s\n", s[pos]);
    printf("%s tiene %d vocales.\n\n", s[pos], mayor);

    return pos;
}

void adivinarLaPalabra (char p[][LONG_PAL])
{
    srand(time(NULL));
    int np = rand() % CANT_PAL;

    int i = 0, cont = 0, flag = 0;
    char letra;
    char aux[LONG_PAL];

    while (p[np][i] != 0)
    {
        p[np][i] = toupper(p[np][i]);
        aux[i] = '_';
        cont++;
        i++;
    }
    aux[i] = 0;

    do
    {
        flag = 0;
        system("cls");

        printf("La palabra oculta tiene %d letras: ", cont);
        printf("%s \n\n", aux);
        printf("Ingrese la letra que desea adivinar: ");
        fflush(stdin);
        scanf("%c", &letra);
        letra = toupper(letra);

        for (i = 0; i < cont; i++)
        {
            if(p[np][i] == letra)
            {
                aux[i] = letra;
                flag = 1;
            }
        }

        if (flag == 1)
        {
            printf("La letra se encuentra en la palabra.\n");
        }
        else
        {
            printf("La letra no se encuentra en la palabra.\n");
        }

        system("pause");
    }while (strcmpi(p[np], aux) != 0);

    system("cls");
    printf("La palabra oculta era: %s\n\n", aux);
}
