# ShellSortClientes
Ordenação de clientes com Shell Sort
---
### Desenvolvedores
* [Carlos Henrique Duarte Abrantes](https://github.com/CarlosH6)
* [Otavio Martins](https://github.com/OtavioMartins08)
* [Pedro Henrique Filgueira Carlos](https://github.com/PedrohfCarlos)
* [Rômulo Levy de Castro Oliveira](https://github.com/Romulolevy)
##
### Objetivo

Implemente um algoritmo que manipula um tipo estruturado
Clientes e mantém os clientes ordenados por código em um arquivo.

##
### O que é Shell Sort ?
O Shell Sort é um algoritmo de ordenação por comparação criado por Donald Shell em 1959. O algoritmo é baseado no algoritmo Ordenação por Inserção (Insertion Sort) e funciona da seguinte forma.

##
### Como funciona o Shell Sort
Inicialmente, a coleção é dividida em vários subgrupos, de forma que todos os elementos de um subgrupo estejam a um mesmo intervalo h entre si. Em seguida, cada subgrupo é reordenado, usando o algoritmo de Ordenação por Inserção. Por fim, o valor do intervalo h é reduzido, novos subgrupos são criados e o processo repetido até que o tamanho do intervalo h seja de 1.

![shellsortB](https://github.com/PedrohfCarlos/Segunda-unidade/assets/128182599/67995057-2ac1-4858-abde-2d9806a91217)

[link imagem](https://www.google.com/imgres?imgurl=https%3A%2F%2Fpanda.ime.usp.br%2Fpanda%2Fstatic%2Fpythonds_pt%2F_images%2FshellsortB.png&tbnid=ulw10mXnZayOxM&vet=12ahUKEwiUjYTwxc6EAxVdELkGHVyzD_sQMygAegQIARBQ..i&imgrefurl=https%3A%2F%2Fpanda.ime.usp.br%2Fpanda%2Fstatic%2Fpythonds_pt%2F05-OrdenacaoBusca%2FOShellSort.html&docid=XnXEcL2W8ILWEM&w=465&h=262&q=shell%20sort&ved=2ahUKEwiUjYTwxc6EAxVdELkGHVyzD_sQMygAegQIARBQ)
##
### Quando usar o Shell Sort?

O Shell Sort é indicado para ordenar coleções pequenas.

O Shell Sort é indicado para ordenar coleções que estejam parcialmente ordenadas.

O Shell Sort pode ser usado quando o espaço de memória auxiliar é inexistente ou limitado.

O Shell Sort pode ser usado quando uma ordenação estável é necessária.
### Função Shell Sort
```
Função Shell Sort
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
```
## 
### Complexidade Pior e Melhor Caso
 Melhor Caso  quando os elementos do vetor já estão ordenados, a complexidade do algoritmo é O(n). 
 Pior Caso quando os elementos do vetor estão na ordem reversa, a melhor complexidade conhecida é: O(n log² n).
##
