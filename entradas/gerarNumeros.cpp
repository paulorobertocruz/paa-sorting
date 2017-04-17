#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

// Geração dos números de forma desordenada -----------------------------------
void gerarNumerosDE(int tamanho)
{
  ofstream saida("./folder/a.txt"); //Cria o arquivo
  unsigned int aux1, aux2, aux;
  vector<int> v; // Vetor para geração dos números

  srand( time(NULL) ); // seta a função rand() com um número realmente randomico a cada execução

  // Preenchimento do vetor de forma crescente
  for(int i = 0; i < tamanho; i++)
    v.push_back(i);

  // Randomização do vetor por trocas
  for(int i = 0; i < 2*tamanho; i++)
  {
    aux1 = rand() % tamanho; // posição randomica no vetor
    aux2 = rand() % tamanho; // posição randomica no vetor

    //troca entre os elementos de forma randomica ----------------------------
    aux = v[aux1];
    v[aux1] = v[aux2];
    v[aux2] = aux;
    //------------------------------------------------------------------------
  }

  //escrita no arquivo
  for(int i = 0; i < tamanho; i++)
    saida << v[i] << " ";
}
//----------------------------------------------------------------------------

// Geração dos números de forma ordenada crescente ---------------------------
void gerarNumeros(string caminho, int tamanho)
{
  ofstream saida(caminho.c_str());

  for(int i = 0; i < tamanho; i++)
  {
    saida << i << " ";
  }
}
//----------------------------------------------------------------------------
int main()
{
  gerarNumerosDE(100);
  // gerarNumerosDE("ODE-1000.txt", 1000);
  // gerarNumerosDE("ODE-10000.txt", 10000);
  // gerarNumerosDE("ODE-50000.txt", 50000);
  // gerarNumerosDE("ODE-100000.txt", 100000);

  return 0;
}
