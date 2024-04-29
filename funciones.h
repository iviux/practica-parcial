#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "pila.h"
#define DIMENSION 50
#define CANT_PAL 10
#define LONG_PAL 30

int cargarPilaUsuario (Pila *p);
void cargarPilaRandom (Pila *p);
void opcionDeCarga (Pila *p);
int pilaToArray (Pila p, int a[]);
void muestraArreglo (int a[]);
void informeGeneralPromedios (int a[]);
int buscarMayor (int a[]);
int buscarMenor (int a[]);
int informaMayorMenor (int a[], char s[]);
int contarVocalesEnPalabra (char p[]);
int informaString (char s[][LONG_PAL], int val);
void adivinarLaPalabra (char p[][LONG_PAL]);
