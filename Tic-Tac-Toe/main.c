#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

int main(){
    setlocale(LC_ALL,"");

        char tabuleiro[tam][tam];
        int linha, coluna;
        int jogador = 1;


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



    return 0;
}
