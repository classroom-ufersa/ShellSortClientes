#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
} Cliente;

// Função para entrada de dados
void Menu(Cliente *clientes);

// Função para ler e armazenar os dados cadastrados em um arquivo de texto.
Cliente *lerClientes(char *nomeArquivo, int *numClientes);

// Função para ordenar os dados.
void shellSort(Cliente arr[], int n);

// Função que irá imprimir os dados dos clientes na tela.
void imprimirClientes(Cliente *clientes, int numClientes);

// Função para verificar se os dados de um cliente são válidos.
int verificarDadosCliente(Cliente *clientes); 