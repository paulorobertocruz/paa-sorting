#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void contarElementos(string caminho)
{
  ifstream leitura(caminho.c_str());
  unsigned aux, cont = 0;

  while(leitura >> aux)
    cont++;

  cout << cont << endl;
}

int main()
{
  contarElementos("./ODE-100.txt");
  contarElementos("./ODE-1000.txt");
  contarElementos("./ODE-10000.txt");
  contarElementos("./ODE-50000.txt");
  contarElementos("./ODE-100000.txt");

  return 0;
}
