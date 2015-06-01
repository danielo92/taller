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

struct Coche {

	char matricula[7];
	char marca[30];
	char modelo[30];
	int cv;

};

int size(struct Coche taller[]) {

	return sizeof(taller) / sizeof(taller[0]);
}


int buscar(struct Coche taller[], char matricula[]) {
	int i = 0;
	do {
		if (strcasecmp(matricula, taller[i].matricula) == 0) {
			return i;
		}
	} while (++i < size(taller));
	return -1;
}

void ordenar(struct Coche taller[]) {
    int i, j;
    for (i = 0; i < size(taller); ++i) {
        for (j = i + 1; j < size(taller); ++j) {
            if (strcasecmp(taller[i].matricula, taller[j].matricula)==1) {
                struct Coche aux = taller[i];
                taller[i] = taller[j];
                taller[j] = aux;
            }
        }
    }

}



int main(void) {

	return EXIT_SUCCESS;
}
