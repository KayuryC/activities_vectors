#include <stdio.h>

char tabuleiro[3][3]; // Tabuleiro do jogo

//Função para inicializar o tabuleiro com espaços em branco
void inicializar_tabuleiro() {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

//Função para imprimir o tabuleiro atual
void imprimir_tabuleiro() {
    printf("\n");
    printf(" %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
    printf("\n");
}

//Função para verificar se alguém ganhou
char verificar_vitoria() {
    //Verificar linhas
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2]) {
            return tabuleiro[i][0];
        }
    }

    //Verificar colunas
    for(int i = 0; i < 3; i++) {
        if(tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i]) {
            return tabuleiro[0][i];
        }
    }

    //Verificar diagonais
    if(tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }
    if(tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    //Verificar se deu velha
    int empate = 1;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(tabuleiro[i][j] == ' ') {
                empate = 0;
                break;
            }
        }
    }
    if(empate) {
        return 'E';//Empate
    }

    return ' ';//Jogo continua
}

//Função principal
int main() {
    int linha, coluna;
    char jogador_atual = 'X';
    char vencedor = ' ';

    inicializar_tabuleiro();

    printf("Bem-vindo ao Jogo da Velha!\n");

    while(vencedor == ' ') {
        imprimir_tabuleiro();

        printf("Jogador %c, digite a linha e coluna para sua jogada (ex: 1 1): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a posição está disponível
        if(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || tabuleiro[linha-1][coluna-1] != ' ') {
            printf("Jogada invalida! Tente novamente.\n");
            continue;
        }
		system("cls");//Limpar CMD
		
        tabuleiro[linha-1][coluna-1] = jogador_atual;

        vencedor = verificar_vitoria();

        // Trocar de jogador
        if(jogador_atual == 'X') {
            jogador_atual = 'O';
        } else {
            jogador_atual = 'X';
        }
    }

    imprimir_tabuleiro();

    if(vencedor == 'E') {
        printf("Empate!\n");
    } else {
        printf("Parabens, jogador %c! Voce ganhou!\n", vencedor);
    }

    return 0;
}
