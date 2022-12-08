#include "caminhao.h"

using namespace std;

Caminhao::Caminhao(string marca, int preco, string chassi, int fabricacao, string tipo_de_motor) : Veiculo(marca,preco,chassi,fabricacao){
  this->tipo_de_carga = tipo_de_carga;
}

string Caminhao::get_tipo_de_carga(){
  return tipo_de_carga;
}

string Caminhao::impressao_atributo_especifico(){
  return "Tipo de carga: " + tipo_de_carga;
}