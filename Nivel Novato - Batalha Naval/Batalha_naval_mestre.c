#include <stdio.h>

// Tamanho do tabuleiro
#define TAMANHO_TABULEIRO 10

// Tamanho dos navios
#define TAMANHO_NAVIO 3

// Tamanho das matrizes de habilidade (5x5)
#define TAMANHO_HABILIDADE 5

// Valores para representar elementos no tabuleiro
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

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

// Função para criar a matriz de habilidade em forma de cone
void criarMatrizCone(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (j >= i && j < TAMANHO_HABILIDADE - i) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de cruz
void criarMatrizCruz(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (i == centro || j == centro) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para criar a matriz de habilidade em forma de octaedro (losango)
void criarMatrizOctaedro(int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE]) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            if (abs(i - centro) + abs(j - centro) <= centro) {
                matriz[i][j] = 1; // Área afetada
            } else {
                matriz[i][j] = 0; // Área não afetada
            }
        }
    }
}

// Função para sobrepor uma habilidade ao tabuleiro
void sobreporHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int habilidade[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE], int linha, int coluna) {
    int centro = TAMANHO_HABILIDADE / 2; // Centro da matriz de habilidade
    for (int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int linhaTabuleiro = linha + (i - centro);
            int colunaTabuleiro = coluna + (j - centro);
            if (linhaTabuleiro >= 0 && linhaTabuleiro < TAMANHO_TABULEIRO && colunaTabuleiro >= 0 && colunaTabuleiro < TAMANHO_TABULEIRO) {
                if (habilidade[i][j] == 1) {
                    tabuleiro[linhaTabuleiro][colunaTabuleiro] = AREA_AFETADA;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Função principal
int main() {
    // Declaração do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa o tabuleiro com água
    inicializarTabuleiro(tabuleiro);

    // Posiciona o primeiro navio horizontalmente
    int linhaNavio1 = 2, colunaNavio1 = 3;
    posicionarNavioHorizontal(tabuleiro, linhaNavio1, colunaNavio1);

    // Posiciona o segundo navio verticalmente
    int linhaNavio2 = 5, colunaNavio2 = 7;
    posicionarNavioVertical(tabuleiro, linhaNavio2, colunaNavio2);

    // Cria as matrizes de habilidade
    int cone[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int cruz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    int octaedro[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];

    criarMatrizCone(cone);
    criarMatrizCruz(cruz);
    criarMatrizOctaedro(octaedro);

    // Define os pontos de origem das habilidades
    int linhaCone = 1, colunaCone = 1;
    int linhaCruz = 4, colunaCruz = 4;
    int linhaOctaedro = 7, colunaOctaedro = 7;

    // Sobrepõe as habilidades ao tabuleiro
    sobreporHabilidade(tabuleiro, cone, linhaCone, colunaCone);
    sobreporHabilidade(tabuleiro, cruz, linhaCruz, colunaCruz);
    sobreporHabilidade(tabuleiro, octaedro, linhaOctaedro, colunaOctaedro);

    // Exibe o tabuleiro com os navios e as áreas de efeito das habilidades
    exibirTabuleiro(tabuleiro);

    return 0;
}