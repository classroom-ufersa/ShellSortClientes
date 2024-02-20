#include "cliente.h"

Cliente *lerClientes(char *nomeArquivo, int *numClientes) {
    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
        exit(1);
    }

    // Contar o número de clientes no arquivo
    int contador = 0;
    char linha[100];
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        contador++;
    }
    rewind(arquivo);

    // Aloca memória para o array de clientes
    Cliente *clientes = (Cliente *)malloc(contador * sizeof(Cliente));
    if (clientes == NULL) {
        printf("Erro ao alocar memória\n");
        exit(1);
    }

    // Ler os clientes do arquivo e armazenar no array
    for (int i = 0; i < contador; i++) {
        fscanf(arquivo, "%d %[^\n]", &clientes[i].id, clientes[i].nome);
    }

    fclose(arquivo);
    *numClientes = contador;
    return clientes;
}

void shellSort(Cliente arr[], int n) {
    for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
        for (int i = intervalo; i < n; i += 1) {
            Cliente temp = arr[i];
            int j;
            for (j = i; j >= intervalo && arr[j - intervalo].id > temp.id; j -= intervalo) {
                arr[j] = arr[j - intervalo];
            }
            arr[j] = temp;
        }
    }
}

void imprimirClientes(Cliente *clientes, int numClientes) {
    for (int i = 0; i < numClientes; i++) {
        printf("ID: %d, Nome: %s\n", clientes[i].id, clientes[i].nome);

    }
}

void Dados_Clientes(Cliente * cliente){
printf("Insira seu nome: ");
scanf(" %[^\n]", estudante->nome);
printf("Informe seu endereço: ");
scanf(" %[^\n]", cliente->endereço);
    
}

void Menu(Cliente * cliente){
printf("-------- SISTEMA SHELL SORT --------");
printf("Oque deseja fazer:");
printf("(1)-Casdastrar Clientes \n (2)-Mostrar Ordenação");
if(){
    
    }
}






