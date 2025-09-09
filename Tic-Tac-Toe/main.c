#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

int linha, coluna;
char tabuleiro[tam][tam];

void imprimirJogo();
void inicializarJogo();
void lerCoordenadas(int jogador);

int ganhouPorLinha(char c);
int atualizarJogador(int jogador);
int salvarCoordenadas(int jogador);

int main(){
    setlocale(LC_ALL,"");


    int opcao;
    int jogador,ganhou,jogadas;

    do{
        jogador = 1;
        ganhou = 0;
        jogadas = 0;

        inicializarJogo();

        do{

            imprimirJogo();

            lerCoordenadas(jogador);

            jogadas += salvarCoordenadas(jogador);

            jogador =atualizarJogador(jogador);

            if(ganhouPorLinha('O') == 1){
                ganhou = 1;
            }
            if(ganhouPorLinha('X') == 1){
                ganhou = 2;
            }

                for(int i = 0; i < tam; i++){
                    if(tabuleiro[0][i] == 'O' && tabuleiro[1][i] == 'O' && tabuleiro[2][i] == 'O')
                        ganhou = 1;
                }

                for(int i = 0; i < tam; i++){
                    if(tabuleiro[0][i] == 'X' && tabuleiro[1][i] == 'X' && tabuleiro[2][i] == 'X')
                        ganhou = 1;
                }

                if(tabuleiro[0][0] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][2] == 'O'){
                    ganhou = 1;
                }

                if(tabuleiro[0][0] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][2] == 'X'){
                    ganhou = 2;
                }

                if(tabuleiro[0][2] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][0] == 'O'){
                    ganhou = 1;
                }

                if(tabuleiro[0][2] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][0] == 'X'){
                    ganhou = 2;
                }

                system("cls");

        }while(ganhou == 0 && jogadas <9);

        system("cls");

        imprimirJogo();

        if(ganhou==1){
            printf("\nParabens jogador 1 voc� ganhou !!!\n");
        }else if(ganhou==2){
            printf("\nParabens jogador 2 voc� ganhou !!!\n");
        }else{
             printf("\nDeu empate !!!\n");
        }

        printf("Digite 1 para jogar novamente:");
            scanf("%d",&opcao);
        system("cls");

    }while(opcao==1);
    return 0;
}

void inicializarJogo(){
    for(int i=0; i < tam; i++){
        for(int j=0; j < tam; j++){
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirJogo(){
    printf(" 0     1     2\n");
    printf("\n");

    for(int i=0; i < tam; i++){
        for(int j=0; j < tam; j++){
            printf(" %c ",tabuleiro[i][j]);
            if(j<2){
                printf(" | ");
            }
            if(j==2){
                printf("  %d ",i);
            }
        }
        if(i<2){
            printf("\n--------------\n");
        }
    }

    printf("\n");
}

void lerCoordenadas(int jogador){
    do{
        printf("\nDigite a posi��o desejada jogador %d\nLinha:",jogador);
            scanf("%d",&linha);
        printf("Coluna: ");
            scanf("%d%*c",&coluna);
        if(linha<0 || linha>2 || coluna<0 || coluna>2){
            printf("Op��o invalida !!!");
            getchar();
        }else if(tabuleiro[linha][coluna] != ' ') {
            printf("Posi��o j� ocupada!\n");
            getchar();
        }
    }while(linha<0 || linha>2 || coluna<0 || coluna>2 || tabuleiro[linha][coluna] != ' ');
}

int salvarCoordenadas(int jogador){

    if(jogador == 1){
        tabuleiro[linha][coluna] = 'O';
    }else{
        tabuleiro[linha][coluna] = 'X';
    }
    return 1;
}

int atualizarJogador(int jogador){

    if(jogador==1){
        jogador = 2;
    }else{
        jogador = 1;
    }
    return jogador;
}

int ganhouPorLinha(char c){

    for(int i = 0; i < tam; i++){
        if(tabuleiro[i][0] == c && tabuleiro[i][1] == c && tabuleiro[i][2] == c)
            return 1;
    }
    return 0;
}
