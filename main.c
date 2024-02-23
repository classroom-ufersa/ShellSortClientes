#include "./tad/cliente.h"
#include <stdio.h>
#include <stdlib.h>

// código para rodar no shell
// gcc -c main.c -o main.o
// gcc -c ./tad/cliente.c -o cliente.o
// gcc main.o cliente.o -o main

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
