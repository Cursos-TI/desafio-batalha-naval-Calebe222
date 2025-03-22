#include <stdio.h>

// Tamano do tabuleiro
#define TAMANHO_TABULEIRO 10


// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Valor para representar água no tabuleiro
#define AGUA 0

// Valor para representar uma parte de um navio no tabuleiro
#define NAVIO 3

// Função para inicializar o tabuleiro com água

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar um navio horizontalmente 
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (coluna + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha][coluna + i] = NAVIO;
        }
    }
}

// Função para posicionar um navio verticalmente
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (linha + i < TAMANHO_TABULEIRO) {
            tabuleiro[linha + i][coluna] = NAVIO;
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) { // Corrigido: estava "i" no loop interno
            printf("%d ", tabuleiro[i][j]); // Adicionado um espaço para melhor visualização
        }
        printf("\n");
    }
}

// Função principal 
int main () {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];


    // inicializa o tabuleiro com água 
    inicializarTabuleiro(tabuleiro);

    // Posiciona o primeiro navio horizontalmente 
    int linhaNavio1 = 2, colunaNavio1 = 3;
    posicionarNavioHorizontal(tabuleiro, linhaNavio1, colunaNavio1);

     // Posiciona o segundo navio verticalmente
     int linhaNavio2 = 5, colunaNavio2 = 7;
     posicionarNavioVertical(tabuleiro, linhaNavio2, colunaNavio2);
 
    // Exibe o tabuleiro com os navios posicionados 
    exibirTabuleiro(tabuleiro);

    return 0;
}