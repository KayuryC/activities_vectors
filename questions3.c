#include <stdio.h>
#include <stdlib.h>

//Definindo valores
    //KayuryC_
#define true 1
#define false 0
#define tamanho_vetor 5

// Função para verificar se um caractere já existe no vetor
int caractere_existe(char vetor[], int tamanho, char caractere) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == caractere) {
            return true;// Caractere encontrado
        }
    }
    return false;//Caso nao encontre caractere 
}

// Funçao pra verificar existencia de no vetor/void
void adicionar_caractere(char vetor[], int *tamanho, char caractere) {
    if (*tamanho < tamanho_vetor && !caractere_existe(vetor, *tamanho, caractere)) {
        vetor[*tamanho] = caractere;
        (*tamanho)++;
        printf("Caractere '%c' adicionado.\n", caractere);
    } 
	else{
        printf("ERRO!ERRO!ERRO!\nCaractere '%c' ja existe ou vetor esta ocupado.\n", caractere);
    }
}

int main() {
	//Declarando Variveis
	    char vetor[tamanho_vetor];
	    int tamanho = 0;
	    char caractere;
	
	//Input do usuario
	    printf("Digite ate %d caracteres, o programa nao aceita valores repetidos!\n", tamanho_vetor);
	    
	//Laço de repeticao para varrer cada vetor
	    while (tamanho < tamanho_vetor) {
	        printf("Digite o proximo caractere: ");
	        scanf(" %c", &caractere);
	
		//Funçao para adicionar caractere no vetor
	        adicionar_caractere(vetor, &tamanho, caractere);
	
	        // se o vetor ja estiver ocupado
	        if (tamanho == tamanho_vetor) {
	            break;
	        }
	
	        // Perguntar ao jovem usuario se deseja adicionar outro caractere
	        char continuar;
	        printf("Deseja adicionar outro caractere? (S/N): ");
	        scanf(" %c", &continuar);
	       //system("cls");
	       
	        if (continuar != 'S' && continuar != 's') {
	            break;
	        }
	    }
	    system("cls");//Limpar CMD
	    
		//Conteudo final do que esta no vetor
	    printf("Conteudo do vetor:");
	    for (int i = 0; i < tamanho; i++) {
	        printf(" %c", vetor[i]);
	    }
	    printf("\n");

    return 0;
}
