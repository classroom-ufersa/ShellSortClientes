#include "./tad/cliente.c" // Código de compilação pelo terminal "gcc -o main -c main.c"

int main() {
    FILE *arquivo = fopen("clientes.txt", "at");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo clientes.txt");
        return 1;
    }

    fclose(arquivo);

    int numClientes;
    Cliente *clientes = lerClientes("clientes.txt", &numClientes);

    printf("Clientes antes da ordenacao:\n");
    imprimirClientes(clientes, numClientes);

    shellSort(clientes, numClientes);

    printf("\nClientes ordenados:\n");
    imprimirClientes(clientes, numClientes);

    free(clientes);

    return 0;
}
