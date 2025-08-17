#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

int main(){
    setlocale(LC_ALL,"");

        char tabuleiro[tam][tam];

        for(int i=0; i < tam; i++){
            for(int j=0; j < tam; j++){
                tabuleiro[i][j] = 'x';
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
    return 0;
}
