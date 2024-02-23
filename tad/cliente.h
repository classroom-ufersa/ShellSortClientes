#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct clientes {
  char nome[50];
  char endereco[100];
  int ID;
} Cliente;

// Função para entrada de dados
void Menu(Cliente *clientes);

// Função para ler e armazenar os dados cadastrados em um arquivo de texto.
Cliente *lerClientes(char *nomeArquivo, int *numClientes);

// Função para ordenar os dados.
void shellSort(Cliente arr[], int n);

// Função que irá imprimir os dados dos clientes na tela.
void imprimirClientes(Cliente *clientes, int numClientes);

#endif
