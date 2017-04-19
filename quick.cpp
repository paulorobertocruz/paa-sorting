#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include <stdio.h>

using namespace std;

vector<long long int> comparacoes;
vector<long long int> trocas;
vector<double> tempos;
vector<string> labels;

int partition(vector<int>& A, int p,int q)
{
    int x= A[p];
    int i=p;
    int j;

    for(j=p+1; j<q; j++)
    {
        comparacoes.back()++;
        if(A[j]<=x)
        {
            i=i+1;
            trocas.back()++;
            swap(A[i],A[j]);
        }

    }

    trocas.back()++;
    swap(A[i],A[p]);
    return i;
}

void quick(vector<int>& A, int p,int q)
{
    int r;
    if(p<q)
    {
        r = partition(A, p,q);
        quick(A,p,r);
        quick(A,r+1,q);
    }
}

void leituraChamada(string entrada, string saida)
{
  labels.push_back(entrada);

  vector<int> v;

  ifstream leitura(entrada.c_str()); // tipo para leitura de arquivo
  ofstream escrita(saida.c_str()); // tipo para escrita de arquivo
  // clock_t inicio, fim;       // para calcular tempo de cpu
  // double tempo;
  int aux;

  //Leitura do arquivo ----------------------------------------
  while(leitura >> aux)
    v.push_back(aux); // escrita no vector
  //-----------------------------------------------------------

  comparacoes.push_back(0);
  trocas.push_back(0);

  //inicio = clock(); // início da contagem do tempo de CPU
  quick(v, 0, (int)v.size()); // chamada do método de ordenação

  //sort(v.begin(), v.end());

  //fim = clock(); // Fim da contagem do tempo de CPU

  // tempo = (fim - inicio)/(double)CLOCKS_PER_SEC; //Cálculo do tempo de CPU
  // tempos.push_back(tempo);

  for(int i = 0; i < v.size(); i++)
    escrita << v[i] << " ";//escrita dos dados ordenados no arquivo de saída
  //----------------------------------------------------------

}

//---------------------------------------------------
int main()
{
  //comparações e trocas
  leituraChamada("./entradas/crescente/OC-100.txt", "./saidas/quick/crescente/OC-100.txt");
  leituraChamada("./entradas/crescente/OC-1000.txt", "./saidas/quick/crescente/OC-1000.txt");
  leituraChamada("./entradas/crescente/OC-10000.txt", "./saidas/quick/crescente/OC-10000.txt");
  leituraChamada("./entradas/crescente/OC-50000.txt", "./saidas/quick/crescente/OC-50000.txt");
  leituraChamada("./entradas/crescente/OC-100000.txt", "./saidas/quick/crescente/OC-100000.txt");

  leituraChamada("./entradas/decrescente/OD-100.txt", "./saidas/quick/decrescente/OD-100.txt");
  leituraChamada("./entradas/decrescente/OD-1000.txt", "./saidas/quick/decrescente/OD-1000.txt");
  leituraChamada("./entradas/decrescente/OD-10000.txt", "./saidas/quick/decrescente/OD-10000.txt");
  leituraChamada("./entradas/decrescente/OD-50000.txt", "./saidas/quick/decrescente/OD-50000.txt");
  leituraChamada("./entradas/decrescente/OD-100000.txt", "./saidas/quick/decrescente/OD-100000.txt");

  leituraChamada("./entradas/desordenados/ODE-100.txt", "./saidas/quick/desordenados/SO-100.txt");
  leituraChamada("./entradas/desordenados/ODE-1000.txt", "./saidas/quick/desordenados/SO-1000.txt");
  leituraChamada("./entradas/desordenados/ODE-10000.txt", "./saidas/quick/desordenados/SO-10000.txt");
  leituraChamada("./entradas/desordenados/ODE-50000.txt", "./saidas/quick/desordenados/SO-50000.txt");
  leituraChamada("./entradas/desordenados/ODE-100000.txt", "./saidas/quick/desordenados/SO-100000.txt");

  ofstream gravarDados("./dados_quick.txt");
  for(int i = 0; i < comparacoes.size(); i++)
      //gravarDados << labels[i]<< ": tempo:" << tempos[i] << " comparacoes:"<< comparacoes[i] << " trocas:" << trocas[i] << endl;

  return 0;
}
