#include <stdio.h>


char jogo[3][3];
char jogador1[50], jogador2[50];


void inicializarMatriz() {
   int Linha,Coluna;
    for(Linha = 0; Linha < 3; Linha++) {
        for(Coluna = 0; Coluna < 3; Coluna++) {
            jogo[Linha][Coluna] = ' ';
        }
    }
}

int eValido(char letra) {
    if(letra == 'x' || letra == '0')
        return 1;
    else
        return 0;
}

int coordenadaEhValida(int x, int y) {
    if(x >= 0 && x < 3) {
        if(y >= 0 && y < 3)
            return 1;
    }
    return 0;
}

int posicaVazia(int x, int y) {
    if(jogo[x][y] != 'x' && jogo[x][y] != '0')
        return 1;
    return 0;
}

int ganhouLinhas() {
    int linha, coluna, igual = 1;
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 2; coluna++) {
            if(eValido(jogo[linha][coluna]) && jogo[linha][coluna] == jogo[linha][coluna+1])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int ganhouColunas() {
    int linha, coluna, igual = 1;
    for(linha = 0; linha < 3; linha++) {
        for(coluna = 0; coluna < 2; coluna++) {
            if(eValido(jogo[coluna][linha]) && jogo[coluna][linha] == jogo[coluna+1][linha])
                igual++;
        }
        if(igual == 3)
            return 1;
        igual = 1;
    }
    return 0;
}

int ganhouDiagonalPrincipal() {
    int linha, igual = 1;
    for(linha = 0; linha < 2; linha++) {
        if(eValido(jogo[linha][linha]) && jogo[linha][linha] == jogo[linha+1][linha+1])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

int ganhouDiagonalSecundaria() {
    int diagonal, igual = 1;
    for(diagonal = 0; diagonal < 2; diagonal++) {
        if(eValido(jogo[diagonal][3-diagonal-1]) && jogo[diagonal][3-diagonal-1] == jogo[diagonal+1][3-diagonal-2])
            igual++;
    }
    if(igual == 3)
        return 1;
    else
        return 0;
}

void imprimir() {
    int lin, col;

    printf("\n\t    0  1  2\n");
    for(lin = 0; lin < 3; lin++) {
        printf("\t%d ", lin);
        for(col = 0; col < 3; col++) {
            if(col < 2)
                printf(" %c |", jogo[lin][col]);
            else
                printf(" %c ", jogo[lin][col]);
        }
        if(lin < 2)
            printf("\n\t   ---------\n");
    }
}

void jogar() {
    int x, y, valida, jogadas = 0, ganhou = 0, ordem = 1;

    do {
        do {
            imprimir();
            printf("\n\nDigite a coordenada que deseja jogar: ");
            scanf("%d%d", &x, &y);
            valida = coordenadaEhValida(x, y);
            if(valida == 1)
                valida += posicaVazia(x, y);
        } while(valida != 2);
        if(ordem == 1)
            jogo[x][y] = 'x';
        else
            jogo[x][y] = '0';
        jogadas++;
        ordem++;
        if(ordem == 3)
            ordem = 1;
        ganhou += ganhouLinhas();
        ganhou += ganhouColunas();
        ganhou += ganhouDiagonalPrincipal();
        ganhou += ganhouDiagonalSecundaria();
    } while(ganhou == 0 && jogadas < 9);

    if(ganhou != 0) {
        imprimir();
        if(ordem - 1 == 1)
            printf("\nParabens. Voce venceu %s\n", jogador1);
        else
            printf("\nParabens. Voce venceu %s\n", jogador2);
    } else
        printf("\nQue feio. Ninguem venceu!\n\n");
}

int main() {

    int novamente;

    printf("Jogar 1 digite seu nome: ");
    scanf("%s", jogador1);
    printf("Jogar 2 digite seu nome: ");
    scanf("%s", jogador2);
    printf("\n*********J O G O D A V E L H A*********");
    printf("\nBoa sorte jogadores %s e %s!\n",jogador1 ,jogador2);
 

    do {
        inicializarMatriz();
        jogar();
        printf("Deseja jogar novamente?\n1 - Sim\n2 - Nao\n");
        scanf("%d", &novamente);
    } while(novamente == 1);

    return 0;
}
