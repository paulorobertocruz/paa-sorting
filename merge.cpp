#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

vector<int> v;

int trocas = 0;

int comparacoes = 0;

void merge(int, int , int );

void mergesort( int low, int high)
{
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergesort(low,mid);
        mergesort(mid+1,high);
        merge(low,high,mid);
    }
    return;
}

void merge( int low, int high, int mid)
{
    int i, j, k;
    vector<int> c;
    i = low;
    k = low;
    j = mid + 1;
    
    
    c.resize(v.size());

    while (i <= mid && j <= high)
    {
        if (v[i] < v[j])
        {
            c[k] = v[i];
            k++;
            i++;
        }
        else
        {
            c[k] = v[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        c[k] = v[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        c[k] = v[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        v[i] = c[i];
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
    mergesort(0, v.size()-1); // chamada do método de ordenação
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


int main(int argc, char **argv)
{   
    leituraChamada("./entradas/desordenados/ODE-100.txt", "./saidas/merge/desordenadas/SO-100.txt");
    leituraChamada("./entradas/desordenados/ODE-1000.txt", "./saidas/merge/desordenadas/SO-1000.txt");
    leituraChamada("./entradas/desordenados/ODE-10000.txt", "./saidas/merge/desordenadas/SO-10000.txt");
    leituraChamada("./entradas/desordenados/ODE-50000.txt", "./saidas/merge/desordenadas/SO-50000.txt");
    leituraChamada("./entradas/desordenados/ODE-100000.txt", "./saidas/merge/desordenadas/SO-100000.txt");

}