#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

int main(){
    setlocale(LC_ALL,"");

    char tabuleiro[tam][tam];
    int linha, coluna;
    int jogador = 1;
    int ganhou = 0;

    for(int i=0; i < tam; i++){
        for(int j=0; j < tam; j++){
            tabuleiro[i][j] = ' ';
        }
    }


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

        do{
            printf("\nDigite a posição desejada\nLInha:");
                scanf("%d",&linha);
            printf("Coluna: ");
                scanf("%d",&coluna);
            if(linha<0 || linha>2 || coluna<0 || coluna>2){
                printf("Opção invalida !!!");
            }else if(tabuleiro[linha][coluna] != ' ') {
                printf("Posição já ocupada!\n");
            }
        }while(linha<0 || linha>2 || coluna<0 || coluna>2 || tabuleiro[linha][coluna] != ' ');

        if(jogador == 1){
            tabuleiro[linha][coluna] = 'O';
            jogador++;
        }else{
            tabuleiro[linha][coluna] = 'X';
            jogador = 1;
        }

        for(int i = 0; i < tam; i++){
            if(tabuleiro[i][0] == 'O' & tabuleiro[i][1] == 'O' & tabuleiro[i][2] == 'O');
                ganhou = 1;
        }

        for(int i = 0; i < tam; i++){
            if(tabuleiro[i][0] == 'X' & tabuleiro[i][1] == 'X' & tabuleiro[i][2] == 'X');
                ganhou = 1;
        }

        for(int i = 0; i < tam; i++){
            if(tabuleiro[0][i] == 'O' & tabuleiro[1][i] == 'O' & tabuleiro[2][i] == 'O');
                ganhou = 1;
        }

        for(int i = 0; i < tam; i++){
            if(tabuleiro[0][i] == 'X' & tabuleiro[1][i] == 'X' & tabuleiro[2][i] == 'X');
                ganhou = 1;
        }

        if(tabuleiro[0][0] == 'O' & tabuleiro[1][1] == 'O' & tabuleiro[2][2] == 'O'){
            ganhou = 1;
        }

        if(tabuleiro[0][0] == 'X' & tabuleiro[1][1] == 'X' & tabuleiro[2][2] == 'X'){
            ganhou = 2;
        }

        if(tabuleiro[0][2] == 'O' & tabuleiro[1][1] == 'O' & tabuleiro[2][0] == 'O'){
            ganhou = 1;
        }

        if(tabuleiro[0][2] == 'X' & tabuleiro[1][1] == 'X' & tabuleiro[2][0] == 'X'){
            ganhou = 2;
        }



    return 0;
}
