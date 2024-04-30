#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma oferta
typedef struct {
    int posicao;
    double valor;
    int quantidade;
} Oferta;

// Função para processar as notificações e gerar o resultado
void processarNotificacoes(int numNotificacoes, Oferta ofertas[]) {
    for (int i = 0; i < numNotificacoes; i++) {
        int posicao, acao;
        double valor;
        int quantidade;
        printf("Digite a notificação %d (posição, ação, valor, quantidade): ", i + 1);
        scanf("%d,%d,%lf,%d", &posicao, &acao, &valor, &quantidade);

        // Atualizar a oferta na posição especificada
        if (acao == 0) { // INSERIR ou MODIFICAR
            ofertas[posicao - 1].posicao = posicao;
            ofertas[posicao - 1].valor = valor;
            ofertas[posicao - 1].quantidade = quantidade;
        } else if (acao == 2) { // DELETAR
            ofertas[posicao - 1].quantidade = 0;
        }
    }

    // Imprimir o resultado
    for (int i = 0; i < numNotificacoes; i++) {
        if (ofertas[i].quantidade > 0) {
            
            printf("%d,%.2lf,%d\n", ofertas[i].posicao -1, ofertas[i].valor, ofertas[i].quantidade);
        }
    }
}

int main() {
    int numNotificacoes;
    printf("Digite o número de notificações: ");
    scanf("%d", &numNotificacoes);

    // Inicializar o array de ofertas
    Oferta ofertas[numNotificacoes];
    for (int i = 0; i < numNotificacoes; i++) {
        ofertas[i].quantidade = 0; // Inicialmente, todas as quantidades são zero
        
    }