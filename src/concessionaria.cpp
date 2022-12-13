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

void Concessionaria::add_carro(Automovel veiculo){
  carros.push_back(veiculo);
}

void Concessionaria::add_moto(Moto veiculo){
  motos.push_back(veiculo);
}

void Concessionaria::add_caminhao(Caminhao veiculo){
  caminhaos.push_back(veiculo);
}

// Verificar se o chassi já existe
bool Concessionaria::verify_chassi(string chassi){
  for(int i = 0;i < carros.size();i++){
    if(chassi == carros[i].get_chassi()){
      return true;
    }
  }

  for(int i = 0;i < motos.size();i++){
    if(chassi == motos[i].get_chassi()){
      return true;
    }
  }

  for(int i = 0;i < caminhaos.size();i++){
    if(chassi == caminhaos[i].get_chassi()){
      return true;
    }
  }
  return false;
}

// Remover veiculo da concessionaria
bool Concessionaria::remove_vehicle(string chassi){

  for(int i = 0;i < carros.size();i++){
    if(chassi == carros[i].get_chassi()){ // Encontrou o chassi
      carros.erase(carros.begin() + i);
      return true; // Encontrou o chassi e removeu
    }
  }

  for(int i = 0;i < motos.size();i++){
    if(chassi == motos[i].get_chassi()){ // Encontrou o chassi
      motos.erase(motos.begin() + i);
      return true; // Encontrou o chassi e removeu
    }
  }

  for(int i = 0;i < caminhaos.size();i++){
    if(chassi == caminhaos[i].get_chassi()){ // Encontrou o chassi
      caminhaos.erase(caminhaos.begin() + i);
      return true; // Encontrou o chassi e removeu
    }
  }
  return false; // Não encontrou o chassi então, não removeu
}

// Procurar se o chassi está cadastrado
string Concessionaria::search_vehicle(string chassi){

  for(int i = 0;i < carros.size();i++){
    if(chassi == carros[i].get_chassi()){ // Encontrou o chassi
      return "Concessionaria: " + nome + "\n" + carros[i].impressao_search_vehicle() +     carros[i].impressao_atributo_especifico(); // Encontrou o chassi
    }
  }

  for(int i = 0;i < motos.size();i++){
    if(chassi == motos[i].get_chassi()){ // Encontrou o chassi
      return "Concessionaria: " + nome + "\n" + motos[i].impressao_search_vehicle() + motos[i].impressao_atributo_especifico(); // Encontrou o chassi
    }
  }

  for(int i = 0;i < caminhaos.size();i++){
    if(chassi == caminhaos[i].get_chassi()){ // Encontrou o chassi
      return "Concessionaria: " + nome + "\n" + caminhaos[i].impressao_search_vehicle() + caminhaos[i].impressao_atributo_especifico(); // Encontrou o chassi
    }
  }
  return "Erro ao encontrar o chassi"; // Não encontrou o chassi
}

string Concessionaria::lista_concessionaria(){
  string saida = "Concessionaria:" + nome + "\n";
  int preco1 = 0, preco2 = 0 , preco3 = 0;
  for(int c; c < carros.size(); c++){
    preco1 += carros[c].get_preco();
  }
  for(int c; c < motos.size(); c++){
    preco2 += motos[c].get_preco();
  }
  for(int c; c < caminhaos.size(); c++){
    preco3 += caminhaos[c].get_preco();
  }
  saida += "Total de Automóveis: " + to_string(carros.size()) + "; Valor total: R$ " + to_string(preco1) + "\n";
  saida += "Total de Motos: " + to_string(motos.size()) + "; Valor total: R$ " + to_string(preco2) + "\n";
  saida += "Total de Caminhões: " + to_string(caminhaos.size()) + "; Valor total: R$ " + to_string(preco3) + "\n";
  saida += "Valor Total da frota: R$ " + to_string(preco1 + preco2 + preco3);
  return saida;
}

void Concessionaria::aumentar_preco(int i){
  double p = i;
  int atual;
  for(int c; c < carros.size(); c++){
    atual = carros[c].get_preco();
    carros[c].set_preco(atual * (i + 100) / 100);
  }
  for(int c; c < motos.size(); c++){
    atual = motos[c].get_preco();
    motos[c].set_preco(atual * (i + 100) / 100);
  }
  for(int c; c < caminhaos.size(); c++){
    atual = caminhaos[c].get_preco();
    caminhaos[c].set_preco(atual * (i + 100) / 100);
  }
}