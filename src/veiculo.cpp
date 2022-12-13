#include "veiculo.h"

using namespace std;

Veiculo::Veiculo(string marca,int preco,string chassi,int fabricacao){
  this->marca = marca;
  this->preco = preco;
  this->chassi = chassi;
  this->fabricacao = fabricacao;
}

// Getters
string Veiculo::get_marca(){
  return marca;
}

int Veiculo::get_preco(){
  return preco;
}
void Veiculo::set_preco(int i){
  preco = i;
}

string Veiculo::get_chassi(){
  return chassi;
}

int Veiculo::get_fabricacao(){
  return fabricacao;
}

string Veiculo::impressao_search_vehicle(){
  return "Marca: " + marca + "\n" + "Preço: " +  to_string(preco) + "\n" + "Chassi: " +  chassi + "\n" + "Ano: " +  to_string(fabricacao) + "\n";
}

/*string Veiculo::impressao_atributo_especifico(){
  return "erro";
}*/