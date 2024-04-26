#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 10

int main(int argc, char *argv[]) {
	//Declarando variaveis
	//KayuryC_
	int vetor[10];
	int rn;
	int linha, coluna;
	char menu_principal;
	char menu_c;


	srand(time(NULL));//Gera numeros aleatorios

	//Processo de input pro menu
	printf("Escolha uma das opcoes abaixo...\n\n(A) Imprimir o vetor completo no formato GRID.");
	printf("\n(B) Gerar aleatoriamente.\n(C) Alterar valor.\n(D) Sair do programa.\n");
	scanf("%c", &menu_principal);
	system("cls");

	//Menu principal
	if(menu_principal == 'a' || menu_principal == 'A') {
		//Informando em que parte do menu o usuario está
		printf("Dentro de Imprimir o vetor completo no formato GRID>>>\n\n");

		//Input do usuario para 10 valores
		for(int i = 0; i < 10; i++) {
			printf("Digite 10 valores (POSSITIVOS & INTEIROS): ", vetor[i]);
			scanf("%d", &vetor[i]);
		}

		printf("\n");//Pula linha

		//Laço de linha
		for(int i = 0; i < 5; i++) {
			printf("[%d] ", vetor[i]);
		}
		printf("\n");//Pula linha

		//Laço de colunas
		for(int j = 5; j < 10; j++) {
			printf("[%d] ", vetor[j]);
		}
	}
	if(menu_principal == 'b' || menu_principal == 'B') {
		printf("Dentro de Gerar aleatoriamente>>>\n\nDigite um range para o valor aleatorio, lemrando que o vetor parte de 0 sempre: ");
		scanf("%d", &rn);
		//Varrendo vetor e gerando valores aleatorios
		for (int i = 0; i < 5; i++) {
			vetor[i] = rand() % rn;
			printf("[%d] ", vetor[i]);
		}

		printf("\n");//Pula linha

		for (int j = 5; j < 10; j++) {
			vetor[j] = rand() % rn;
			printf("[%d] ", vetor[j]);
		}
	}
	if(menu_principal == 'c' || menu_principal == 'C') {
		//Informando local acessado
		printf("Dentro de Alterar valor>>>\n\nEscolha uma das opcoes...\n(i) Adicionar um valor no vetor\n(j) Remover valor de um vetor.\n");
		scanf("%s", &menu_c);
		system("cls");//Limpar CMD

		switch(menu_c) {
				//Declarando variaveis
				int vetor[TAMANHO_VETOR] = {0}; // Inicializa o vetor com todos os elementos como 0
				int posicao, valor, opcao;

			case 'i'://Caso o usuario informe "i"
				printf("Dentro de Adicionar valor no vetor>>>\n\n");
				//Input para trocar a posição
				printf("Informe a posicao (entre 0 e 9): ");
				scanf("%d", &posicao);

				if (posicao < 0 || posicao >= TAMANHO_VETOR) {
					printf("Posicao invalida.\n");
					return 1;
				}

				if (vetor[posicao] != 0) { // Se a posição já estiver ocupada
					printf("Posicao esta ocupada: %d\n", vetor[posicao]);
					printf("Deseja substituir? (1) Sim / (2) Não\n");
					int opcao;//Variavel para seleção de sim ou não
					scanf("%d", &opcao);

					if (opcao != 1) { // Se a opção não for substituir
						printf("Operacao cancelada.\n");
						return 0;
					}
				}

				//Input valor desejado
				printf("Informe o valor a ser adicionado: ");
				scanf("%d", &valor);

				if (valor % 2 != 0) { // Verifica se o valor é par
					printf("O valor informado nao e par.\n");
					return 1;
				}

				//Informando ao usuario valor eh posicao
				vetor[posicao] = valor;
				printf("Valor %d adicionado com sucesso na posicao %d.\n", valor, posicao);
				break;

			case 'j':
				printf("Dentro de Remover valor de um vetor>>>\n\n");//Informando local ao usuario
				printf("Escolha uma opcao:\n");
				printf("(1) Remover por posicao\n");
				printf("(2) Remover por valor\n");
				scanf("%d", &opcao);
				system("cls");

				switch (opcao) {
					case 1:
						printf("Informe a posicao (entre 0 e 9): ");
						scanf("%d", &posicao);
						if (posicao < 0 || posicao >= TAMANHO_VETOR) {
							printf("Posicao invalida.\n");
							return 1;
						}
						vetor[posicao] = 0;
						printf("Valor removido com sucesso.\n");
						break;
					case 2:
						printf("Informe o valor a ser removido: ");
						scanf("%d", &valor);
						for (int i = 0; i < TAMANHO_VETOR; i++) {
							if (vetor[i] == valor) {
								vetor[i] = 0;
								printf("Valor removido na posicao %d.\n", vetor[i]);
							}
						}
						break;
					default:
						printf("Opcao invalida.\n");
						return 1;
				}
		}
	}
	if(menu_principal == 'd' || menu_principal == 'D') {

		printf("Encerrando programa.\n");
		system("Pause");
	}
	return 0;
}