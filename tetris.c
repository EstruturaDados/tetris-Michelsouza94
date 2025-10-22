#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da struct Peca
// Cada peça tem um nome (tipo: 'I', 'O', 'T', 'L') e um id único incremental.
typedef struct {
    char nome;  // Tipo da peça
    int id;     // Identificador único
} Peca;

// Constantes para a fila
#define MAX_FILA 10  // Capacidade máxima da fila
#define INICIAL 5    // Número inicial de peças

// Variáveis globais para a fila
Peca fila[MAX_FILA];  // Array para armazenar as peças
int frente = 0;       // Índice da frente da fila
int tras = 0;         // Índice do final da fila
int idGlobal = 0;     // Contador global para ids únicos

// Função para gerar uma nova peça automaticamente
// Escolhe um tipo aleatório entre 'I', 'O', 'T', 'L' e atribui um id incremental.
Peca gerarPeca() {
    Peca nova;
    char tipos[4] = {'I', 'O', 'T', 'L'};
    nova.nome = tipos[rand() % 4];  // Seleciona tipo aleatório
    nova.id = idGlobal++;           // Atribui id único e incrementa
    return nova;
}

// Função para inicializar a fila com 5 peças
// Gera peças automaticamente e as adiciona à fila.
void inicializarFila() {
    for (int i = 0; i < INICIAL; i++) {
        fila[tras++] = gerarPeca();
    }
}

// Função para exibir o estado atual da fila
// Mostra cada peça no formato [Tipo ID], ou indica se vazia.
void exibirFila() {
    printf("\nFila de pecas\n");
    if (frente == tras) {
        printf("(vazia)\n");
        return;
    }
    for (int i = frente; i < tras; i++) {
        printf("[%c %d] ", fila[i].nome, fila[i].id);
    }
    printf("\n");
}

// Função para jogar uma peça (dequeue)
// Remove a peça da frente da fila, se houver.
void jogarPeca() {
    if (frente == tras) {
        printf("Fila vazia! Nao ha pecas para jogar.\n");
        return;
    }
    Peca removida = fila[frente++];
    printf("Peca jogada: [%c %d]\n", removida.nome, removida.id);
}

// Função para inserir uma nova peça (enqueue)
// Adiciona uma peça gerada automaticamente ao final da fila, se houver espaço.
void inserirPeca() {
    if (tras >= MAX_FILA) {
        printf("Fila cheia! Nao e possivel inserir nova peca.\n");
        return;
    }
    Peca nova = gerarPeca();
    fila[tras++] = nova;
    printf("Nova peca inserida: [%c %d]\n", nova.nome, nova.id);
}

int main() {
    srand(time(NULL));  // Inicializa o gerador de números aleatórios
    inicializarFila();  // Inicializa a fila com 5 peças

    int opcao;
    do {
        exibirFila();  // Exibe a fila atual

        printf("\nOpcoes de acao:\n");
        printf("1) Jogar peca (dequeue)\n");
        printf("2) Inserir nova peca (enqueue)\n");
        printf("0) Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                jogarPeca();
                break;
            case 2:
                inserirPeca();
                break;
            case 0:
                printf("Saindo do jogo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}