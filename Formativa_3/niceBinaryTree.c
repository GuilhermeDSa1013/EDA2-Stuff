#include <stdio.h>

#define MAX_SIZE 1000

int find_tree_depth(char *preorder) {
    char stack[MAX_SIZE];
    int top = -1;
    int depth = 0;

    for (int i = 0; preorder[i] != '\0'; i++) {
        if (preorder[i] == 'n') {
            stack[++top] = 'n';
        } else if (preorder[i] == 'l') {
            // Encontrou uma folha, calcula a profundidade com base na pilha atual
            depth = (top + 1 > depth) ? (top + 1) : depth;
            // Desempilha todos os 'n' até o último 'n'
            while (top >= 0 && stack[top] == 'n') {
                top--;
            }
        }
    }

    return depth;
}

// Função principal
int main() {
    int T;
    scanf("%d", &T);

    // Limpar buffer após a leitura do número de testes
    while (getchar() != '\n');

    for (int t = 0; t < T; t++) {
        char preorder[MAX_SIZE];
        fgets(preorder, sizeof(preorder), stdin);

        int depth = find_tree_depth(preorder);
        printf("%d\n", depth);
    }

    return 0;
}
