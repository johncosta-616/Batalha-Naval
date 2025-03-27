#include <stdio.h>

//PROCEDIMENTO
void sobreporMatriz(int matrizMaior[][15], int linhasMaior, int colunasMaior, int matrizMenor[][5], int linhasMenor, int colunasMenor, int startLinha, int startColuna) {
    for (int i = 0; i < linhasMenor; i++) {
        for (int j = 0; j < colunasMenor; j++) {
            if ((startLinha + i < linhasMaior) && (startColuna + j < colunasMaior)) {
                matrizMaior[startLinha + i][startColuna + j] = matrizMenor[i][j];
            }
        }
    }
}

int main() {

   //VÁRIAVEIS
    int i, j;  // Variáveis para o loop do tabuleiro
    printf("### BATALHA NAVAL ###\n");

    // Matriz do tabuleiro
    int tabuleiro[10][15];

    // 1. Lógica tabuleiro
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 15; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //2.Habilidades:

    int cone[5][5] = { 
        {0, 0, 1, 0, 0},
        {0, 1, 1, 1, 0},
        {0, 1, 1, 1, 0},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };

    int cruz[5][5] = { 
        {0, 0, 7, 0, 0},
        {0, 7, 7, 7, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 7, 0, 0},
        {0, 0, 0, 0, 0},
    };
    
    int octaedro[5][5] = {
        {0, 0, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 4, 4, 4, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 0, 0},
    };

        //ÁREA DOS PARÂMETROS
        sobreporMatriz(tabuleiro, 10, 15, cone, 5, 5, 4, 5); 
        sobreporMatriz(tabuleiro, 10, 15, cruz, 5, 5, 2, 1);
        sobreporMatriz(tabuleiro, 10, 15, octaedro, 5, 5, 6, 10);


    // 3. Imprimir o tabuleiro
    printf("     A  B  C  D  E  F  G  H  I  J  K  L  M  N  O\n"); // Organizar melhor o tabuleiro
    for (i = 0; i < 10; i++) {  // Loop das linhas 
        printf("%2d| ", i + 1);

        for (j = 0; j < 15; j++) {  // Loop das colunas
            printf("%2d ", tabuleiro[i][j]);
        }

        printf("\n");
    }
    return 0;

}
