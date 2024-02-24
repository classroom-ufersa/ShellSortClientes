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
      // Imprimir clientes antes da ordenação
      printf("\nClientes antes da ordenação:\n");
      imprimirClientes(clientes, numClientes);

      // Ordenar os clientes
      shellSort(clientes, numClientes);

      // Imprimir clientes depois da ordenação
      printf("\nClientes ordenados:\n");
      imprimirClientes(clientes, numClientes);
      printf("\nDigite algo para continuar...\n");
      char digite;
      scanf("%*c%s", &digite);

      break;
    case 3:
      printf("Saindo...\n");
      return 0;
    default:
      printf("Opção inválida!\n");
    }
  }

  free(clientes);

  return 0;
}
