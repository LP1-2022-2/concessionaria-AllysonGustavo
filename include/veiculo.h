#ifndef VEICULO_H
#define VEICULO_H
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>

using namespace std;

class Veiculo {
  private:
  string marca;
  int preco;
  string chassi;
  int fabricacao; // Ano de fabricação

  public:
  Veiculo(string marca,int preco,string chassi,int fabricacao);
  string get_marca(); // Getter
  int get_preco(); // Getter
  void set_preco(int i);
  string get_chassi(); // Getter
  int get_fabricacao(); // Getter
  string impressao_search_vehicle();
  string impressao_atributo_especifico();
};

#endif