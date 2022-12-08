#ifndef CONCESSIONARIA_H
#define CONCESSIONARIA_H
#include <veiculo.h>
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>
#include <queue>

using namespace std;

class Concessionaria {
  private:
  vector<Veiculo> veiculos;
  int estoque;
  string nome;
  string cnpj;

  public:
  Concessionaria();
  Concessionaria(string nome, string cnpj, int estoque);
  string get_nome(); // Getter
  string get_cnpj(); // Getter
  int get_estoque(); // Getter
  void add_veiculo(Veiculo veiculo);
  bool verify_chassi(string chassi);
  bool remove_vehicle(string chassi);
  string search_vehicle(string chassi);
};

#endif