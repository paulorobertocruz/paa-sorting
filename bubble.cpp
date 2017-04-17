#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

//GLOBAIS -------------------------------------------
vector<int> v;
// int comparacoes;
// int trocas;
//---------------------------------------------------
void bubblesort()
{
  int aux;

  // comparacoes = 0;
  // trocas = 0;

  for(int i = 0; i < v.size()-1; i++)
    for(int j = i+1; j < v.size(); j++)
    {
      //comparacoes++;

      if(v[i] > v[j])
      {
          //trocas++;
          aux = v[i];
          v[i] = v[j];
          v[j] = aux;
      }
    }
}

void leituraChamada(string entrada, string saida)
{
  ifstream leitura(entrada.c_str()); // tipo para leitura de arquivo
  ofstream escrita(saida.c_str()); // tipo para escrita de arquivo
  clock_t inicio, fim;       // para calcular tempo de cpu
  double tempo;
  int aux;

  //Leitura do arquivo ----------------------------------------
  while(leitura >> aux)
    v.push_back(aux); // escrita no vector
  //-----------------------------------------------------------

  inicio = clock(); // início da contagem do tempo de CPU
  bubblesort(); // chamada do método de ordenação
  fim = clock(); // Fim da contagem do tempo de CPU

  tempo = (fim - inicio)/(double)CLOCKS_PER_SEC; //Cálculo do tempo de CPU

  //Escrita no arquivo ---------------------------------------
  escrita << "Tempo: " << tempo << "\n";
  //escrita << "Trocas: " << trocas << "\n";
  //escrita << "Comparacoes" << comparacoes << "\n";

  for(int i = 0; i < v.size(); i++)
  escrita << v[i] << " ";//escrita dos dados ordenados arquivo de saída
  //----------------------------------------------------------
}

//---------------------------------------------------
int main()
{
  leituraChamada("./desordenados/ODE-100.txt", "./saidas/desordenadas/SO-100.txt");
  leituraChamada("./desordenados/ODE-1000.txt", "./saidas/desordenadas/SO-1000.txt");
  leituraChamada("./desordenados/ODE-10000.txt", "./saidas/desordenadas/SO-10000.txt");
  leituraChamada("./desordenados/ODE-50000.txt", "./saidas/desordenadas/SO-50000.txt");
  leituraChamada("./desordenados/ODE-100000.txt", "./saidas/desordenadas/SO-100000.txt");

  return 0;
}
//---------------------------------------------------
