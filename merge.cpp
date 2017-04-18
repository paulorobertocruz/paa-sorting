#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

vector<int> v;

vector<long long int> comparacoes;
vector<long long int> trocas;
vector<float> tempos;
vector<string> labels;

void merge(int, int , int );

void mergesort( int low, int high)
{
    int mid;
    comparacoes[comparacoes.size()-1]++;
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

    comparacoes[comparacoes.size()-1]++;
    while (i <= mid && j <= high)
    {
        comparacoes[comparacoes.size()-1]++;
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

    comparacoes[comparacoes.size()-1]++;
    while (i <= mid)
    {
        c[k] = v[i];
        k++;
        i++;
    }

    comparacoes[comparacoes.size()-1]++;
    while (j <= high)
    {
        c[k] = v[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)
    {
        trocas[trocas.size()-1]++;
        v[i] = c[i];
    }
}


void leituraChamada(string entrada)
{    
    v.clear();
    comparacoes.push_back(0);
    trocas.push_back(0);
    labels.push_back(entrada);

    
    ifstream leitura(entrada.c_str()); // tipo para leitura de arquivo
    
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
    tempos.push_back(tempo);
    
}


int main(int argc, char **argv)
{   
    //comparações e trocas
    leituraChamada("./entradas/crescente/OC-100.txt");
    leituraChamada("./entradas/crescente/OC-1000.txt");
    leituraChamada("./entradas/crescente/OC-10000.txt");
    leituraChamada("./entradas/crescente/OC-50000.txt");
    leituraChamada("./entradas/crescente/OC-100000.txt");

    leituraChamada("./entradas/decrescente/OD-100.txt");
    leituraChamada("./entradas/decrescente/OD-1000.txt");
    leituraChamada("./entradas/decrescente/OD-10000.txt");
    leituraChamada("./entradas/decrescente/OD-50000.txt");
    leituraChamada("./entradas/decrescente/OD-100000.txt");

    leituraChamada("./entradas/desordenados/ODE-100.txt");
    leituraChamada("./entradas/desordenados/ODE-1000.txt");
    leituraChamada("./entradas/desordenados/ODE-10000.txt");
    leituraChamada("./entradas/desordenados/ODE-50000.txt");
    leituraChamada("./entradas/desordenados/ODE-100000.txt");

    ofstream gravarDados("./dados_merge_cmp.txt");
    for(int i = 0; i < comparacoes.size(); i++)
        gravarDados << labels[i] << ": tempo:" << tempos[i] << " comparacoes:"<< comparacoes[i] << " trocas:" << trocas[i] << endl;


    return 0;

}