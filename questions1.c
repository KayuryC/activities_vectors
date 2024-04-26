#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	//Declarando Variáveis  
		//KayuryC_
        int idade[3];
        idade[0] = 18;
	        
    //Input do Usuario
		for(int i = 1; i < 3; i++){ 
     	    printf("-----------------\n%d Idade inicial", idade[0]);//Informar idade inicial
	      	printf("\nDigite as proximas idades\n(Sendo que todas tem que ser maior que a idade inicial): ");
	      	scanf("%d", &idade[i]);//Ler idade de input
	      	
	    	if(idade[i] < idade[0]){
	      		printf("\nAdicione uma idade maior que %d da proxima\n\n", idade[0]);
	      		break;
			}
			system("cls");//Apagar CMD
	  }   	
	  
		  	printf("As idades sao...\n");//Informando idade
		  	
	//Varrendo vetor
		for (int i = 0; i < 3; i++){
	      	printf("[%d]\t", idade[i]);
	      
	    }	
	
	return 0;
}