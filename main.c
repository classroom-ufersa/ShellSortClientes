#include "cliente.h"

// código para rodar no shell
// gcc -c main.c
// gcc -c cliente.c
// gcc -o executavel.exe cliente.o main.o
// ./executavel.exe

int main() {
  FILE *arquivo = fopen("clientes.txt", "at");
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo clientes.txt\n");
    return 1;
  }

  fclose(arquivo);

  int numClientes;
  Cliente *clientes = lerClientes("clientes.txt", &numClientes);

  printf("Clientes antes da ordenação:\n");
  imprimirClientes(clientes, numClientes);

  shellSort(clientes, numClientes);

  printf("\nClientes ordenados:\n");
  imprimirClientes(clientes, numClientes);

  free(clientes);

  return 0;
}
