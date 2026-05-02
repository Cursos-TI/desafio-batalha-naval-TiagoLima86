#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    int vertical = 10;
    int horizontal = 10;

    int tabuleiro [10][10];
    char *cabecalho[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J"};

    int tabuleiro2 [10][10];



    //Imprimindo cabeçalho
    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%s ", cabecalho[i]);
        
    }
    printf("\n");

    // Definindo tabuleiro com 0

    for (int i = 0; i < vertical; i++){
        for (int j = 0; j < horizontal; j++){
            tabuleiro[i][j] = 0;
        }
    }

    // posicionando o navio na horizontal

    int hzn = 1;

    for (int j = 2; j <= 4; j++) {
        if (tabuleiro[2][j] != 0) {
            hzn = 0;
            break;
            }
        }

    if (hzn) {
        for (int j = 2; j <= 4; j++) {
            tabuleiro[2][j] = 3;
            }
    } else {
        printf("Sobrepondo navio existente!!\n");
    }
 

    // Posicionando navio na vertical
    int vrt = 1;
    for (int i = 2; i <5; i++){
        if (tabuleiro[i][6] != 0){
            vrt = 0;
            break;
        }
    }

    if (vrt){
        for (int i = 2; i <5; i++){
            tabuleiro[i][6] = 3;
        }
    } else {
        printf("Sobrepondo navio existente!!\n");
    }

   

    //Teste de navio na diagonal

    int dgn1 = 1;

    for (int i = 5, j = 5; i < 8 && j < 8; i++, j++) {
        if (tabuleiro[i][j] != 0) {
            dgn1 = 0;
            break;
        }
    }
    
    if (dgn1){
        for (int i =5 , j = 5; i < 8 && j < 8; i++, j++){
            if (tabuleiro[i][j] == 0){
            tabuleiro[i][j] = 3;
            } 
        }
    }else {
            printf("Sobrepondo navio existente!!\n");
        
    }

    //segundo navio na diagonal
    int dgn2 = 1;
    for (int i = 4, j = 3; i < 7 && j >= 0; i++, j++){
        if (tabuleiro[i][j] != 0){
            dgn2 = 0;
            break;
        }
        
        
    }
    if (dgn2){
        for (int i = 4, j = 3; i < 7 && j >= 0; i++, j--) {
            if (tabuleiro[i][j] == 0){
                 tabuleiro[i][j] = 3;
            }
        }
    } else {
        printf("Sobrepondo navio existente!!\n");
    }
    

    // Imprimindo Tabuleiro

    for (int i = 0; i < vertical; i++) {
        printf("%d ", i + 1); // número da linha

        for (int j = 0; j < horizontal; j++) {
            printf("%2d", tabuleiro[i][j]);
        }

        printf("\n");
    }
    // Tabulheiro de habilidades
    printf("\n");
    printf("\n");
    printf("\n");
    printf("TABULEIRO DE HABILIDADES");
    printf("\n");
    printf("\n");
    printf("\n");

    //Iniciando com 0
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 10; j++){
            tabuleiro2[i][j] = 0;
        }
    }

    //Colocando o  triângulo
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {

            
            if (i >= 5 && i <= 7 && j >= (3 - (i - 5)) && j <= (3 + (i - 5))) {
                tabuleiro2[i][j] = 1;
            } else {
                tabuleiro2[i][j] = 0;
            }
        }
    }

    //Colocando a Cruz
    for (int i = 0; i <10; i++){
        for (int j = 0; j < 10; j++){
            if ((j == 3 && i >= 0 && i <= 4) ||   // coluna vertical
                (i == 2 && j >= 1 && j <= 5)      // barra horizontal
                ) {
                tabuleiro2[i][j] = 3;
                }

        }
    }

    //Colocando o octaedro

    for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {

        // parte de baixo (sua)
        if ((i == 5 && j >= 5 && j <= 9) ||
            (i == 6 && j >= 6 && j <= 8) ||
            (i == 7 && j == 7)) {

            tabuleiro2[i][j] = 2;
        }

        // parte de cima (completa o losango)
        else if ((i == 4 && j >= 6 && j <= 8) || (i == 3 && j == 7)) {
            tabuleiro2[i][j] = 2;
        }



    }
}


    
   


    printf("   ");
    for (int i = 0; i < 10; i++){
        printf("%s ", cabecalho[i]);
        
    }
    printf("\n");

    for (int i = 0; i < vertical; i++) {
        printf("%d ", i + 1); // número da linha

        for (int j = 0; j < horizontal; j++) {
            printf("%2d", tabuleiro2[i][j]);
        }

        printf("\n");
    }

    return 0;
}
