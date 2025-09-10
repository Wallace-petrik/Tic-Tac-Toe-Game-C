#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 3

int linha, coluna;
char tabuleiro[tam][tam];

void imprimirJogo();
void inicializarJogo();
void lerCoordenadas(int jogador);

int ganhouPorLinhas();
int ganhouPorColunas();
int ganhouPorLinha(char c);
int ganhadorDiagPrincipal();
int ganhouPorColuna(char c);
int ganhadorDiagSecundaria();
int ganhouDiagPrincipal(char c);
int ganhouDiagSecundaria(char c);
int atualizarJogador(int jogador);
int salvarCoordenadas(int jogador);
int jogar(int jogadas, int jogador, int ganhou);

int main(){
    setlocale(LC_ALL,"");


    int opcao;
    int jogador,ganhou,jogadas;

    do{
        jogador = 1;
        ganhou = 0;
        jogadas = 0;

        inicializarJogo();

        ganhou = jogar(jogadas,jogador,ganhou);

        system("cls");

        imprimirJogo();

        if(ganhou==1){
            printf("\nParabens jogador 1 você ganhou !!!\n");
        }else if(ganhou==2){
            printf("\nParabens jogador 2 você ganhou !!!\n");
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
        printf("\nDigite a posição desejada jogador %d\nLinha:",jogador);
            scanf("%d",&linha);
        printf("Coluna: ");
            scanf("%d%*c",&coluna);
        if(linha<0 || linha>2 || coluna<0 || coluna>2){
            printf("Opção invalida !!!");
            getchar();
        }else if(tabuleiro[linha][coluna] != ' ') {
            printf("Posição já ocupada!\n");
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

int ganhouPorLinhas(){
    if(ganhouPorLinha('O') == 1){
        return 1;
    }
    if(ganhouPorLinha('X') == 1){
        return 2;
    }
    return 0;
}

int ganhouPorColuna(char c){

    for(int i = 0; i < tam; i++){
        if(tabuleiro[0][i] == c && tabuleiro[1][i] == c && tabuleiro[2][i] == c)
            return 1;
    }
    return 0;
}

int ganhouPorColunas(){
    if(ganhouPorColuna('O') == 1){
        return 1;
    }
    if(ganhouPorColuna('X') == 1){
        return 2;
    }
    return 0;
}

int ganhouDiagPrincipal(char c){

    if(tabuleiro[0][0] == c && tabuleiro[1][1] == c && tabuleiro[2][2] == c){
        return 1;
    }
    return 0;
}

int ganhadorDiagPrincipal(){
    if(ganhouDiagPrincipal('O') == 1){
        return 1;
    }
    if(ganhouDiagPrincipal('X') == 1){
        return 2;
    }
    return 0;
}

int ganhouDiagSecundaria(char c){

    if(tabuleiro[0][2] == c && tabuleiro[1][1] == c && tabuleiro[2][0] == c){
        return 1;
    }
    return 0;
}

int ganhadorDiagSecundaria(){
    if(ganhouDiagSecundaria('O') == 1){
        return 1;
    }
    if(ganhouDiagSecundaria('X') == 1){
        return 2;
    }
    return 0;
}

int jogar(int jogadas, int jogador, int ganhou){

    do{

        imprimirJogo();

        lerCoordenadas(jogador);

        jogadas += salvarCoordenadas(jogador);

        jogador =atualizarJogador(jogador);

        ganhou += ganhouPorLinhas();

        ganhou += ganhouPorColunas();

        ganhou += ganhadorDiagPrincipal();

        ganhou += ganhadorDiagSecundaria();

        system("cls");

    }while(ganhou == 0 && jogadas <9);
    return ganhou;
}
