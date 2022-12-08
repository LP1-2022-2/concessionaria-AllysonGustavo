#ifndef AUTOMOVEL_H
#define AUTOMOVEL_H
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>
#include <string>
#include <veiculo.h>

using namespace std;

class Automovel : public Veiculo {
  private:
  string tipo_de_motor; // Gasolina ou elétrico

  public:
  Automovel(string marca, int preco, string chassi, int fabricacao, string tipo_de_motor);
  string get_tipo_de_motor(); // Getter
  string impressao_atributo_especifico();
};

#endif