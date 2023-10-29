#include <stdio.h>
#include <stdlib.h>

// Função para calcular a soma dos maiores elementos em cada subvetor
long long somaMaioresSubvetores(long long *vetor, int N, int K) {
    long long somaMaiores = 0;
    int *fila = (int *)malloc(N * sizeof(int)); // Aloca memória para uma fila
    int frente = 0, tras = -1;

    for (int i = 0; i < N; i++) {
        // Remove elementos fora do subvetor de tamanho K
        while (frente <= tras && fila[frente] < i - K + 1)
            frente++;

        // Remove elementos menores que o elemento atual
        while (frente <= tras && vetor[i] >= vetor[fila[tras]])
            tras--;

        // Adiciona o índice do elemento atual à fila
        fila[++tras] = i;

        // Adiciona o maior elemento no subvetor atual à soma
        if (i >= K - 1)
            somaMaiores += vetor[fila[frente]];
    }

    free(fila); // Libera a memória alocada para a fila
    return somaMaiores;
}

int main() {
    int T;
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        int N, K;
        long long S;
        scanf("%d %d %lld", &N, &K, &S);

        long long *matriz = (long long *)malloc(N * sizeof(long long)); // Aloca memória para o vetor matriz
        matriz[0] = S;

        // Gera os valores do vetor matriz usando uma fórmula linear congruente
        for (int i = 1; i < N; ++i)
            matriz[i] = (1LL * matriz[i - 1] * 1103515245 + 12345) % 2147483648LL;

        // Chama a função para calcular a soma dos maiores elementos nos subvetores
        long long resultado = somaMaioresSubvetores(matriz, N, K);

        printf("%lld\n", resultado); // Imprime o resultado

        free(matriz); // Libera a memória alocada para o vetor matriz
    }

    return 0;
}
