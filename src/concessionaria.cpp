#include "concessionaria.h"
#include "automovel.h"
#include "caminhao.h"
#include "moto.h"


using namespace std;

Concessionaria::Concessionaria(){ // Concessionaria padrão, serve para teste
  estoque = 0;
  nome = "nome";
  cnpj = "123B";
}

Concessionaria::Concessionaria(string nome, string cnpj, int estoque){
  this->nome = nome;
  this->cnpj = cnpj;
  this->estoque = estoque;
}

// Getters
string Concessionaria::get_nome(){
  return nome;
}

string Concessionaria::get_cnpj(){
  return cnpj;
}

int Concessionaria::get_estoque(){
  return estoque;
}

// Adicionar veículo
void Concessionaria::add_veiculo(Veiculo veiculo){
  veiculos.push_back(veiculo);
}

// Verificar se o chassi já existe
bool Concessionaria::verify_chassi(string chassi){
  for(int i = 0;i < veiculos.size();i++){
    if(chassi == veiculos[i].get_chassi()){
      return true;
    }
  }
  return false;
}

// Remover veiculo da concessionaria
bool Concessionaria::remove_vehicle(string chassi){
  for(int i = 0;i < veiculos.size();i++){
    if(chassi == veiculos[i].get_chassi()){ // Encontrou o chassi
      veiculos.erase(veiculos.begin() + i);
      return true; // Encontrou o chassi e removeu
    }
  }
  return false; // Não encontrou o chassi então, não removeu
}

// Procurar se o chassi está cadastrado
string Concessionaria::search_vehicle(string chassi){
  for(int i = 0;i < veiculos.size();i++){
    if(chassi == veiculos[i].get_chassi()){ // Encontrou o chassi
      return "Concessionaria: " + nome + "\n" + veiculos[i].impressao_search_vehicle(); // Encontrou o chassi
    }
  }
  return "Erro ao encontrar o chassi"; // Não encontrou o chassi
}