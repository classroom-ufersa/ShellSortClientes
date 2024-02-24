#include "cliente.h"
#include <stdlib.h>

typedef struct clientes Cliente;

Cliente *lerClientes(char *nomeArquivo, int *numClientes) {
  FILE *arquivo = fopen(nomeArquivo, "r");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo %s\n", nomeArquivo);
    exit(1);
  }

  // Contar o número de clientes no arquivo.
  int contador = 0;
  char linha[150];
  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    contador++;
  }
  rewind(arquivo);
  contador /= 2;

  // Aloca memória para o array de clientes.
  Cliente *clientes = (Cliente *)calloc(contador,sizeof(Cliente));
  if (clientes == NULL) {
    printf("Erro ao alocar memória\n");
    exit(1);
  }

  // Ler os clientes do arquivo e armazenar no array.
  for (int i = 0; i < contador; i++) {
    if (fscanf(arquivo, "%d %49[^\n] %99[^\n]", &clientes[i].ID,
               clientes[i].nome, clientes[i].endereco) != 3) {
    }
  }

  fclose(arquivo);
  *numClientes = contador;
  return clientes;
}

void shellSort(Cliente *arr, int n) {
  for (int intervalo = n / 2; intervalo > 0; intervalo /= 2) {
    for (int i = intervalo; i < n; i += 1) {
      Cliente temp = arr[i];
      int j;
      for (j = i; j >= intervalo && arr[j - intervalo].ID > temp.ID;
           j -= intervalo) {
        arr[j] = arr[j - intervalo];
      }
      arr[j] = temp;
    }
  }
}

void imprimirClientes(Cliente *clientes, int numClientes) {
  for (int i = 0; i < numClientes; i++) {
    printf("ID: %d, Nome: %s, Endereco: %s\n", clientes[i].ID, clientes[i].nome,
           clientes[i].endereco);
  }
}

void Menu(Cliente *clientes, int *opc) {
  system("clear");
  printf("-------- SISTEMA SHELL SORT --------\n");
  printf("O que deseja fazer:\n");
  printf("(1) - Cadastrar Clientes \n(2) - Mostrar Ordenação\n(3) - Sair\n");
  scanf("%d", opc);
}

void Dados_Clientes(Cliente *clientes, int numClientes){
  printf("Insira seu nome: ");
  scanf(" %[^\n]", clientes[numClientes].nome);
  printf("Informe seu endereço: ");
  scanf(" %[^\n]", clientes[numClientes].endereco);

    // Verificar se o há outro ID igual.
    int novoID;
    printf("Informe o seu ID: ");
    scanf("%d", &novoID);

    for (int i = 0; i < numClientes; i++) {
      if (clientes[i].ID == novoID) {
        printf("ID já existe. Por favor, insira um novo ID: ");
        scanf("%d", &novoID);
        i = -1;
      }
    }
    clientes[numClientes].ID = novoID;
}
