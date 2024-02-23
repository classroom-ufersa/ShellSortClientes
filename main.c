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

  int opc, continua = 1;
  while (continua) {
    // Menu para receber a opção do usuário
    Menu(clientes, &opc);

    switch (opc) {
    case 1:
      // Receber os dados do novo cliente
      printf("Digite os dados do novo cliente:\n");
      Dados_Clientes(&clientes[numClientes]);
      numClientes++;
      break;
    case 2:
      // Ordenar os clientes
      shellSort(clientes, numClientes);

      // Imprimir clientes após a ordenação
      printf("\nClientes ordenados:\n");
      imprimirClientes(clientes, numClientes);

      continua = 0; // Finaliza o loop
      break;
    default:
      printf("Opção inválida!\n");
    }
  }

  free(clientes);

  return 0;
}