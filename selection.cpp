#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

vector<int> v;
int trocas = 0;
int comparacoes = 0;

void selectoin_sort()
{    
    
    int size;

    int i, j;
    int maxPosition = 0;
    int temp = 0;
    
    size = v.size();

    for(i = size-1; i >= 0; i--)
    {

        maxPosition = 0;

        for(j = 1; j < i + 1; j++)
        {
            comparacoes += 1;
            if( v[j] > v[maxPosition] )
            {
                maxPosition = j;
            }
        }

        comparacoes += 1;
        if (i != maxPosition)
        {
            //troca
            trocas += 1;
            temp = v[i];
            v[i] = v[maxPosition];
            v[maxPosition] = temp;
        }
        

    }

}


void leituraChamada(string entrada, string saida)
{
    v.clear();
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
    selectoin_sort(); // chamada do método de ordenação
    fim = clock(); // Fim da contagem do tempo de CPU

    tempo = (fim - inicio)/(double)CLOCKS_PER_SEC; //Cálculo do tempo de CPU

    //Escrita no arquivo ---------------------------------------
    escrita << "Tempo: " << tempo << "\n";
    escrita << "Trocas: " << trocas << "\n";
    escrita << "Comparacoes: " << comparacoes << "\n";

    for(int i = 0; i < v.size(); i++)
    escrita << v[i] << " ";//escrita dos dados ordenados arquivo de saída
    //----------------------------------------------------------
}


int main(int argc, char **argv)
{
    //comparações e trocas
    leituraChamada("./entradas/crescente/OC-100.txt", "./saidas/selection/crescente/OC-100.txt");
    leituraChamada("./entradas/crescente/OC-1000.txt", "./saidas/selection/crescente/OC-1000.txt");
    leituraChamada("./entradas/crescente/OC-10000.txt", "./saidas/selection/crescente/OC-10000.txt");
    leituraChamada("./entradas/crescente/OC-50000.txt", "./saidas/selection/crescente/OC-50000.txt");
    leituraChamada("./entradas/crescente/OC-100000.txt", "./saidas/selection/crescente/OC-100000.txt");

    leituraChamada("./entradas/decrescente/OD-100.txt", "./saidas/selection/decrescente/OD-100.txt");
    leituraChamada("./entradas/decrescente/OD-1000.txt", "./saidas/selection/decrescente/OD-1000.txt");
    leituraChamada("./entradas/decrescente/OD-10000.txt", "./saidas/selection/decrescente/OD-10000.txt");
    leituraChamada("./entradas/decrescente/OD-50000.txt", "./saidas/selection/decrescente/OD-50000.txt");
    leituraChamada("./entradas/decrescente/OD-100000.txt", "./saidas/selection/decrescente/OD-100000.txt");

    leituraChamada("./entradas/desordenados/ODE-100.txt", "./saidas/selection/desordenados/SO-100.txt");
    leituraChamada("./entradas/desordenados/ODE-1000.txt", "./saidas/selection/desordenados/SO-1000.txt");
    leituraChamada("./entradas/desordenados/ODE-10000.txt", "./saidas/selection/desordenados/SO-10000.txt");
    leituraChamada("./entradas/desordenados/ODE-50000.txt", "./saidas/selection/desordenados/SO-50000.txt");
    leituraChamada("./entradas/desordenados/ODE-100000.txt", "./saidas/selection/desordenados/SO-100000.txt");
}