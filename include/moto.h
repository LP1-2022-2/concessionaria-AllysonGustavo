#ifndef MOTO_H
#define MOTO_H
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>
#include <veiculo.h>

using namespace std;

class Moto : public Veiculo {
  private:
  string modelo; // Clássico ou esportivo

  public:
  Moto(string marca, int preco, string chassi, int fabricacao, string modelo);
  string get_modelo(); // Getter
  string impressao_atributo_especifico();
};

#endif