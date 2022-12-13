#include "automovel.h"

using namespace std;

Automovel::Automovel(string marca, int preco, string chassi, int fabricacao, string tipo_de_motor) : Veiculo(marca,preco,chassi,fabricacao){
  this->tipo_de_motor = tipo_de_motor;
}

string Automovel::get_tipo_de_motor(){
  return tipo_de_motor;
}

string Automovel::impressao_atributo_especifico(){
  return "Tipo de Motor: " + tipo_de_motor;
}