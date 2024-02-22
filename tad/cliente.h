#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clientes{
    char nome[50];
    char endereco[100];
    int ID;
}Cliente;

// Função para ler e armazenar os dados cadastrados em um arquivo de texto. 
Cliente* lerClientes(char *nomeArquivo, int *numClientes);

// Função que ira imprimir os dados dos clientes na tela.
void imprimirClientes(Cliente *clientes, int numClientes);

// Função para ordenar os dados.
void shellSort(Cliente arr[], int n);

// Função para comparar os dados.
int compararClientes(const void *a, const void *b);

// Função para entrada de dados
void Menu(Cliente * clientes);

// teste
