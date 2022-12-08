#ifndef CAMINHAO_H
#define CAMINHAO_H
#include <istream>
#include <ostream>
#include <sstream>
#include <vector>
#include <veiculo.h>

using namespace std;

class Caminhao : public Veiculo {
  private:
  string tipo_de_carga; // Comum ou perigosa

  public:
  Caminhao(string marca, int preco, string chassi, int fabricacao, string tipo_de_carga);
  string get_tipo_de_carga(); // Getter
  string impressao_atributo_especifico();
};

#endif