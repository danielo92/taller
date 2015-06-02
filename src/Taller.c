/*
 ============================================================================
 Name        : Taller.c
 Author      : Dani
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>

struct Coche { //ESTRUCTURA COCHES OK!

    char matricula[8];
    char marca[30];
    char modelo[30];
    int cv;
};


int buscar(struct Coche taller[], char matricula[]){

    int i = 0;

    do
    {
        if (strcasecmp((matricula), taller[i].matricula) == 0) return i;
    }
    while(++i<10);

    return -1;
}

int insertar(struct Coche coche, struct Coche taller[]){

    if (buscar(taller, coche.matricula) != -1) return 1;
    else {
        int i;
        for (i = 0; i < 10; i++)
        {
            if (strcasecmp(taller[i].matricula, "0") == 0)
            {
                taller[i] = coche;
                return 0;
            }
        }
    }
}

int borrar(struct Coche taller[], char matricula[]){

    int posicion = buscar(taller, matricula);

    if (posicion != -1)
    {
        strcpy(taller[posicion].matricula, "0");
        strcpy(taller[posicion].marca, "0");
        strcpy(taller[posicion].modelo, "0");
        taller[posicion].cv = 0;
        return 0;
    }
    else return 1;
}

void imprimir(struct Coche taller[], char matricula[]){

    int posicion = buscar(taller, matricula);

    if (posicion == -1) printf("1\n\n");
    else
    {
        printf("Matricula\t ");
        printf("%s\n", taller[posicion].matricula);
        printf("Marca    \t ");
        printf("%s\n", taller[posicion].marca);
        printf("Modelo   \t ");
        printf("%s\n", taller[posicion].modelo);
        printf("Caballos \t ");
        printf("%d\n\n", taller[posicion].cv);
    }
}

void ordenar(struct Coche taller[]){

    struct Coche aux;

    int i;
    for (i = 0; i < 9; i++)
    {
        int j;
        for (j = i+1; j < 10; j++)
        {
            if (strcasecmp(taller[i].matricula, taller[j].matricula) > 0)
            {
                aux = taller[i];
                taller[i] = taller[j];
                taller[j] = aux;
            }

        }
    }
}

int main(int argc, char** argv) {

    setbuf(stdout, NULL);

    struct Coche taller[10];
    struct Coche aux;

    int i;
    for (i = 0; i < 10; i++)
    {
       strcpy(taller[i].matricula, "0");
    }

    int opcion = 0;
    char seleccion[30];

    do {

        printf("1. Introducir Coche\ n2. Eliminar Coche\n3. Imprimir Coche\n4. Ordenar Taller\n"
            "5. Salir\n");

        printf("\nSelecciona opcion\n");
        scanf("%d", &opcion);
        setbuf(stdin, NULL);

        switch(opcion)
        {
            case 1:
                printf("\nIntroduce la matricula\n");
                gets(aux.matricula);
                printf("Introduce la marca\n");
                gets(aux.marca);
                printf("Introduce el modelo\n");
                gets(aux.modelo);
                printf("Introduce los cv\n");
                scanf("%d", &aux.cv);
                setbuf(stdin, NULL);
                printf("%d", insertar(aux, taller));
                break;
            case 2:
                printf("Introduce la matricula\n");
                scanf("%s", &seleccion);
                printf("%d", borrar(taller, seleccion));
                break;
            case 3:
                printf("Introduce matricula\n");
                scanf("%s", &seleccion);
                imprimir(taller,seleccion);
                break;
            case 4:
                ordenar(taller);

                for (i = 0; i < 10; i++)
                {
                    printf("%s\n", taller[i].matricula);
                }
                break;
            case 5:
                break;
            default:
                break;
        }

    } while (opcion != 5);

    return (EXIT_SUCCESS);
}
