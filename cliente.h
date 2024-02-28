#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct clientes {
    char nome[50];
    char endereco[100];
    int ID;
} Cliente;

// Função para entrada de dados
void Menu(Cliente *clientes, int *opc);

// Função para ler e armazenar os dados cadastrados em um arquivo de texto.
Cliente *lerClientes(char *nomeArquivo, int *numClientes);

// Função para ordenar os dados.
void shellSort(Cliente *arr, int n);

// Função que irá imprimir os dados dos clientes na tela.
void imprimirClientes(Cliente *clientes, int numClientes);

// Função para receber os dados de um novo cliente e armazená-los na estrutura Cliente.
void Dados_Clientes(Cliente *clientes, int numClientes);

// Função para verificar se o nome tem apenas letras.
int verificarDados(const char *str);

// Função para escrever os dados dos clientes em um arquivo de texto.
void escreverClientes(Cliente *clientes, int numClientes);
