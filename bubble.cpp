#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

// ESTE CÓDIGO É UM ATENTADO AS BOAS PRÁTICAS DE PROGRAMAÇÃO

using namespace std;

//GLOBAIS -------------------------------------------
vector<long long int> comparacoes;
vector<long long int> trocas;
// vector<double> tempos;
//---------------------------------------------------
void bubblesort(vector<int> &v)
{
  int aux;

  comparacoes.push_back(0);
  trocas.push_back(0);

  for(int i = 0; i < v.size()-1; i++)
    for(int j = i+1; j < v.size(); j++)
    {
      comparacoes[comparacoes.size()-1]++;

      if(v[i] > v[j])
      {
          trocas[trocas.size()-1]++;
          aux = v[i];
          v[i] = v[j];
          v[j] = aux;
      }
    }
}
//---------------------------------------------------
void leituraChamada(string entrada, string saida)
{
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

  //inicio = clock(); // início da contagem do tempo de CPU
  bubblesort(v); // chamada do método de ordenação
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
  // ofstream gravarTempos("./tempos.txt");
  ofstream gravarDados("./dados.txt");

  leituraChamada("./entradas/crescente/OC-100.txt", "./saidas/crescente/OC-100.txt");
  leituraChamada("./entradas/crescente/OC-1000.txt", "./saidas/crescente/OC-1000.txt");
  leituraChamada("./entradas/crescente/OC-10000.txt", "./saidas/crescente/OC-10000.txt");
  leituraChamada("./entradas/crescente/OC-50000.txt", "./saidas/crescente/OC-50000.txt");
  leituraChamada("./entradas/crescente/OC-100000.txt", "./saidas/crescente/OC-100000.txt");
  
  leituraChamada("./entradas/decrescente/OD-100.txt", "./saidas/decrescente/OD-100.txt");
  leituraChamada("./entradas/decrescente/OD-1000.txt", "./saidas/decrescente/OD-1000.txt");
  leituraChamada("./entradas/decrescente/OD-10000.txt", "./saidas/decrescente/OD-10000.txt");
  leituraChamada("./entradas/decrescente/OD-50000.txt", "./saidas/decrescente/OD-50000.txt");
  leituraChamada("./entradas/decrescente/OD-100000.txt", "./saidas/decrescente/OD-100000.txt");

  leituraChamada("./entradas/desordenados/ODE-100.txt", "./saidas/desordenados/ODE-100.txt");
  leituraChamada("./entradas/desordenados/ODE-1000.txt", "./saidas/desordenados/ODE-1000.txt");
  leituraChamada("./entradas/desordenados/ODE-10000.txt", "./saidas/desordenados/ODE-10000.txt");
  leituraChamada("./entradas/desordenados/ODE-50000.txt", "./saidas/desordenados/ODE-50000.txt");
  leituraChamada("./entradas/desordenados/ODE-100000.txt", "./saidas/desordenados/ODE-100000.txt");

  // for(int i = 0; i < tempos.size(); i++)
  //   gravarTempos << tempos[i] << endl;

  for(int i = 0; i < comparacoes.size(); i++)
    gravarDados << comparacoes[i] << " " << trocas[i] << endl;


  return 0;
}
//---------------------------------------------------
