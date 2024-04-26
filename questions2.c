#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) {
    //Declarando variaveis
        //KayuryC_
        int num[20];

    srand(time(NULL));//Gera numeros aleatorios

    //Varrendo vetor e gerando valores aleatorios de 1 a 6
    for (int i = 0; i < 20; i++){
        num[i] = rand() % 6;
    	printf("-[%d]\n", num[i]);
    }
    
	return 0;
}