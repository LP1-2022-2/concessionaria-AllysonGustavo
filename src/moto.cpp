#include "moto.h"

using namespace std;

Moto::Moto(string marca, int preco, string chassi, int fabricacao, string tipo_de_motor) : Veiculo(marca,preco,chassi,fabricacao){
  this->modelo = modelo;
}

string Moto::get_modelo(){
  return modelo;
}

string Moto::impressao_atributo_especifico(){
  return "Modelo: " + modelo;
}