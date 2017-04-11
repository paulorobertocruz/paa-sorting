#include<stdio.h>
#include<time.h>

typedef struct INFO
{
    int trocas;
    int comparacoes;
} INFO;

void gerar_vector(int *v, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        v[i] = size - i;
    }
 
}

void print_vector(int *vector, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("%d", vector[i]);
        if(i+1 < size)
        {
            printf(",");
        }        
    }

    printf("\n");
}

INFO selectoin_sort( int *vector, int size )
{
    INFO data;
    
    data.trocas = 0;
    data.comparacoes = 0;

    int i, j;
    int maxPosition = 0;
    int temp = 0;

    for(i = size-1; i >= 0; i--)
    {

        maxPosition = 0;

        for(j = 1; j < i + 1; j++)
        {
            data.comparacoes += 1;
            if( vector[j] > vector[maxPosition] )
            {
                maxPosition = j;
            }
        }

        data.comparacoes += 1;
        if (i != maxPosition)
        {
            //troca
            data.trocas += 1;
            temp = vector[i];
            vector[i] = vector[maxPosition];
            vector[maxPosition] = temp;
        }
        

    }

    return data;
}

int main(int argc, char **argv)
{

    if(argc < 2){
        printf("Argumentos faltando!\n");
        return 1;
    }

    // dados da execução do algoritmo
    INFO dados;
    
    int size = 10;
    int v[size];
    int i, j;
    
    FILE *arquivo;

    arquivo = fopen(argv[1], "r");

    clock_t clock_in, clock_out;

    for(i = 0; i < size; i++)
    {
        v[i] = size-i;
        // v[i] = i;
    }

    print_vector(v, size);

    clock_in = clock();
    
    dados = selectoin_sort(v, size);
    
    clock_out = clock();

    print_vector(v, size);
    
    printf("%f\n", (clock_in - clock_out) /CLOCKS_PER_SEC );
    printf("trocas: %d comparacoes: %d", dados.trocas, dados.comparacoes);

}