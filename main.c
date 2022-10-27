#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
char tabuleiro[4][4];
int jogador=1, ocupado[4][4], jogoterminado;
void tabu(){
    int x, y;
    printf("    1   2   3    x\n  -------------");
    for(y=1;y<4;y++){
        printf("\n%d |", y);
        for(x=1;x<4;x++){
            printf(" %c |", tabuleiro[x][y]);
        }
        printf("\n  -------------");
    }
    printf("\ny\n");
}
void pvp(){
    int x,y;

        printf("\n-------%dº Jogador-------\n", jogador);
        printf("Escolha a posição\nx=");
        scanf("%d", &x);
        printf("y=");
        scanf("%d", &y);
        while(x<=0 || x>=4 || y<=0 || y>=4){
            printf("Coordenadas invalidas, tente outra vez:");
            printf("\nx=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
        }
        while(ocupado[x][y]==1){
            printf("Lugar ocupado pelo outro jogador, escolha uma posição diferente");
            printf("\nx=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
            while(x<=0 || x>=4 || y<=0 || y>=4){
                printf("Coordenadas invalidas, tente outra vez:");
                printf("\nx=");
                scanf("%d", &x);
                printf("y=");
                scanf("%d", &y);
            }
        }
        if (ocupado[x][y]==0){
            ocupado[x][y]=1;
        }
        if(jogador==1){
            tabuleiro[x][y]='X';
            jogador++;
        }
        else{
            tabuleiro[x][y]='O';
            jogador--;
        }
}
void validar(){

    int x,y, empate;
    empate=0;
    for(y=1;y<4;y++){
        if(tabuleiro[1][y] == tabuleiro[2][y] && tabuleiro[1][y]==tabuleiro[3][y]){
            if(tabuleiro[1][y]=='X'){
                printf("O jogador 1 ganhou\n");
                jogoterminado=1;
            }
            if(tabuleiro[1][y]=='O'){
                printf("O jogador 2 ganhou\n");
                jogoterminado=1;
            }
        }
    }
    for(x=1;x<4;x++){
        if(tabuleiro[x][1] == tabuleiro[x][2] && tabuleiro[x][1]==tabuleiro[x][3]){
            if(tabuleiro[x][1]=='X'){
                printf("O jogador 1 ganhou\n");
                jogoterminado=1;
            }
            if(tabuleiro[x][1]=='O'){
                printf("O jogador 2 ganhou\n");
                jogoterminado=1;
            }
        }
    }
    if(tabuleiro[1][1]==tabuleiro[2][2] && tabuleiro[1][1]==tabuleiro[3][3]){
        if(tabuleiro[1][1]=='X'){
            printf("O jogador 1 ganhou\n");
            jogoterminado=1;
        }
        if(tabuleiro[1][1]=='O'){
            printf("O jogador 2 ganhou\n");
            jogoterminado=1;
        }
    }
    if(tabuleiro[3][1]==tabuleiro[2][2] && tabuleiro[3][1]==tabuleiro[1][3]){
        if(tabuleiro[3][1]=='X'){
            printf("O jogador 1 ganhou\n");
            jogoterminado=1;
        }
        if(tabuleiro[3][1]=='O'){
            printf("O jogador 2 ganhou\n");
            jogoterminado=1;
        }
    }
    for(y=1;y<4;y++){
        for(x=1;x<4;x++){
            if(ocupado[x][y]==1){
                empate++;
            }
        }
    }
    if(empate==9){
        printf("\nJogo empatado\n");
        jogoterminado=1;
    }
}
void pvcd(){
    int x,y,limitador;
    if(jogador==1){
        limitador=0;
        printf("Escolha a posição\nx=");
        scanf("%d", &x);
        printf("y=");
        scanf("%d", &y);
        while(ocupado[x][y]==1){
            printf("Lugar ocupado pelo outro jogador, escolha uma posição diferente");
            printf("\nx=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
        }
        if (ocupado[x][y]==0){
            ocupado[x][y]=1;
        }
        tabuleiro[x][y]='X';
        jogador++;
    }
    else{
        limitador=0;
        jogador--;
        srand(time(NULL));
        for(y=1;y<4;y++){
           if(tabuleiro[1][y]==tabuleiro[2][y] && ocupado[3][y]==0 && limitador==0){
                if(tabuleiro[1][y]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[3][y]='O';
                    ocupado[3][y]=1;
                }
            }
            if(tabuleiro[1][y]==tabuleiro[3][y] && ocupado[2][y]==0 && limitador==0){
                if(tabuleiro[1][y]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[2][y]='O';
                    ocupado[2][y]=1;
                }
            }
            if(tabuleiro[2][y]==tabuleiro[3][y] && ocupado[1][y]==0 && limitador==0){
                if(tabuleiro[2][y]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[1][y]='O';
                    ocupado[1][y]=1;
                }
            }

        }
        for(x=1;x<4;x++){
           if(tabuleiro[x][1]==tabuleiro[x][2] && ocupado[x][3]==0 && limitador==0){
                if(tabuleiro[x][1]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[x][3]='O';
                    ocupado[x][3]=1;
                }
            }
           if(tabuleiro[x][1]==tabuleiro[x][3] && ocupado[x][2]==0 && limitador==0){
                if(tabuleiro[x][1]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[x][2]='O';
                    ocupado[x][2]=1;
                }
            }
           if(tabuleiro[x][2]==tabuleiro[x][3] && ocupado[x][1]==0 && limitador==0){
                if(tabuleiro[x][2]=='O' || tabuleiro[3][1]=='X'){
                    limitador=1;
                    tabuleiro[x][1]='O';
                    ocupado[x][1]=1;
                }
            }
        }
        if(tabuleiro[1][1]==tabuleiro[2][2] && ocupado[3][3]==0 && limitador==0){ // diagonal esquerda para a direita
            if(tabuleiro[1][1]=='O' || tabuleiro[3][1]=='X'){
                limitador=1;
                tabuleiro[3][3]='O';
                ocupado[3][3]=1;
            }
        }
        if(tabuleiro[1][1]==tabuleiro[3][3] && ocupado[2][2]==0 && limitador==0){
            if(tabuleiro[1][1]=='O' || tabuleiro[1][1]=='X'){
                limitador=1;
                tabuleiro[2][2]='O';
                ocupado[2][2]=1;
            }
        }
        if(tabuleiro[2][2]==tabuleiro[3][3] && ocupado[1][1]==0 && limitador==0){
            if(tabuleiro[2][2]=='O' || tabuleiro[3][1]=='X'){
                limitador=1;
                tabuleiro[1][1]='O';
                ocupado[1][1]=1;
            }
        }
        if(tabuleiro[3][1]==tabuleiro[1][3] && ocupado[2][2]==0 && limitador==0){ // diagonal direita para a esquerda
            if(tabuleiro[3][1]=='O' || tabuleiro[3][1]=='X'){
                limitador=1;
                tabuleiro[2][2]='O';
                ocupado[2][2]=1;
            }
        }
        if(tabuleiro[2][2]==tabuleiro[1][3] && ocupado[3][1]==0 && limitador==0){
            if(tabuleiro[2][2]=='O' || tabuleiro[2][2]=='X'){
                limitador=1;
                tabuleiro[3][1]='O';
                ocupado[3][1]=1;
            }
        }
        if(tabuleiro[2][2]==tabuleiro[3][1] && ocupado[1][3]==0 && limitador==0){
            if(tabuleiro[2][2]=='O' || tabuleiro[2][2]=='X'){
                limitador=1;
                tabuleiro[1][3]='O';
                ocupado[1][3]=1;
            }
        }
        x= rand()%4;
        y= rand()%4;
        while(x==0 || y==0){
            x= rand()%4;
            y= rand()%4;
        }
        while(ocupado[x][y]==1){
            x= rand()%4;
            y= rand()%4;
            while(x==0 || y==0){
                x= rand()%4;
                y= rand()%4;
            }
        }
        if (ocupado[x][y]==0 && limitador==0){
            ocupado[x][y]=1;
            tabuleiro[x][y]='O';
        }

    }
}
void pvcf(){
    int x,y;
    if(jogador==1){
        printf("Escolha a posição\nx=");
        scanf("%d", &x);
        printf("y=");
        scanf("%d", &y);
        while(ocupado[x][y]==1){
            printf("Lugar ocupado pelo outro jogador, escolha uma posição diferente");
            printf("\nx=");
            scanf("%d", &x);
            printf("y=");
            scanf("%d", &y);
        }
        if (ocupado[x][y]==0){
            ocupado[x][y]=1;
        }
        tabuleiro[x][y]='X';
        jogador++;
    }
    else{
        jogador--;
        srand(time(NULL));
        x= rand()%4;
        y= rand()%4;
        while(x==0 || y==0){
            x= rand()%4;
            y= rand()%4;
        }
        while(ocupado[x][y]==1){
            x= rand()%4;
            y= rand()%4;
            while(x==0 || y==0){
                x= rand()%4;
                y= rand()%4;
            }
        }
        if (ocupado[x][y]==0){
            ocupado[x][y]=1;
            tabuleiro[x][y]='O';
        }
    }


}
void instrucoes(){
    printf("O objetivo do jogo é fazer uma sequência de três símbolos iguais, seja em linha vertical, horizontal ou diagonal,\nenquanto tenta impedir que seu adversário faça o mesmo; Quando um dos participantes faz uma linha, ganha o jogo;\nComeça do início, normalmente trocando os símbolos escolhidos.\n\n");
}
void menu(){
    printf("I- Instruções\n");
    printf("P- Jogar contra outra pessoa\n");
    printf("C- Jogar contra Computador\n");
    printf("S- Sair\n");
}
int main(){
    char opc;
    int x, y, dif;
    setlocale(LC_ALL, "Portuguese");
    for(x=0;x<4;x++){
        for(y=0;y<4;y++){
            ocupado[x][y]=0;
        }
    }
    do{
        jogador=1;
        menu();
        scanf(" %c", &opc);
        while(opc != 'I' && opc != 'P' && opc != 'C' && opc != 'S' && opc != 'i' && opc != 'p' && opc != 'c' && opc != 's'){
            printf("[%c] não é um operador válido\n", opc);
            scanf(" %c", &opc);
        }
        if (opc <= 122 && opc >= 97){
            opc= opc - 32;
        }
        if(opc=='I'){
            instrucoes();
        }
        if(opc=='P'){
            while(jogoterminado==0){
                tabu();
                pvp();
                validar();
            }
            tabu();
            jogoterminado=0;
            for(y=1;y<4;y++){
                for(x=1;x<4;x++){
                    tabuleiro[x][y]=' ';
                }
            }
            for(x=0;x<4;x++){
                for(y=0;y<4;y++){
                    ocupado[x][y]=0;
                }
            }
        }
        if(opc=='C'){
            printf("\nEscolha a dificuldade:\n1-Fácil\n2-Difícil\n3-Voltar\n");
            scanf("%d", &dif);
            while(dif<=0||dif>=4){
                printf("Opção inválida, tente outra vez: ");
                scanf("%d", &dif);
            }
            srand(time(NULL));
            jogador= rand()%3;
            while(jogador==0){
                jogador=rand()%3;
            }
            if(dif==1){
                while(jogoterminado==0){
                    tabu();
                    pvcf();
                    validar();
                }
                tabu();
                jogoterminado=0;
                for(y=1;y<4;y++){
                    for(x=1;x<4;x++){
                        tabuleiro[x][y]=' ';
                    }
                }
                for(x=0;x<4;x++){
                    for(y=0;y<4;y++){
                        ocupado[x][y]=0;
                    }
                }
            }
            if(dif==2){
                while(jogoterminado==0){
                    tabu();
                    pvcd();
                    validar();
                }
                jogoterminado=0;
                for(y=1;y<4;y++){
                    for(x=1;x<4;x++){
                        tabuleiro[x][y]=' ';
                    }
                }
                for(x=0;x<4;x++){
                    for(y=0;y<4;y++){
                        ocupado[x][y]=0;
                    }
                }
            }
        }
    }
    while(opc!='S');
}
