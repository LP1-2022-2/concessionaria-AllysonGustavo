#include "sistema.h"
#include "concessionaria.h"
#include "veiculo.h"
#include "automovel.h"
#include "caminhao.h"
#include "moto.h"

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_concessionaria(const string nome) {
  vector < string > strings;
  istringstream f(nome);
  string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  Concessionaria variavel(strings[0], strings[1], stoi(strings[2]));
  concessionarias.push_back(variavel);
  return "Concessionaria criada com sucesso!";
}

/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */

string Sistema::add_car(const string carro) {
  vector < string > strings;
  istringstream f(carro);
  string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  // Buscar a concessinaria digitada
  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].verify_chassi(strings[3])) { // Verifica se o chassi já existe na concessionária
      return "ERRO - Veículo " + strings[3] + " já adicionado à concessionária " + concessionarias[i].get_nome();
    }
    if (concessionarias[i].get_nome() == strings[0]) { // Verifica se o nome da concessionária é igual ao nome digitado pelo usuario
      Automovel carro(strings[1], stoi(strings[2]), strings[3], stoi(strings[4]), strings[5]);
      concessionarias[i].add_veiculo(carro);
      return "Carro adicionado com sucesso!";
      break;
    }
  }
  return "Erro ao adicionar carro!";
}

string Sistema::add_truck(const string caminhao) {
  vector < string > strings;
  istringstream f(caminhao);
  string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  // Buscar a concessinaria digitada
  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].verify_chassi(strings[3])) { // Verifica se o chassi já existe na concessionária
      return "ERRO - Veículo " + strings[3] + " já adicionado à concessionária " + concessionarias[i].get_nome();
    }
    if (concessionarias[i].get_nome() == strings[0]) {
      Caminhao caminhao(strings[1], stoi(strings[2]), strings[3], stoi(strings[4]), strings[5]);
      concessionarias[i].add_veiculo(caminhao);
      return "Caminhão adicionado com sucesso!";
      break;
    }
  }
  return "Erro ao adicionar caminhão!";
}

string Sistema::add_motorcycle(const string moto) {
  vector < string > strings;
  istringstream f(moto);
  string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  // Buscar a concessinaria digitada
  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].verify_chassi(strings[3])) { // Verifica se o chassi já existe na concessionária
      return "ERRO - Veículo " + strings[3] + " já adicionado à concessionária " + concessionarias[i].get_nome();
    }
    if (concessionarias[i].get_nome() == strings[0]) {
      Moto moto(strings[1], stoi(strings[2]), strings[3], stoi(strings[4]), strings[5]);
      concessionarias[i].add_veiculo(moto);
      return "Moto adicionada com sucesso!";
      break;
    }
  }
  return "Erro ao adicionar moto!";
}

string Sistema::remove_vehicle(const string chassi) {
  bool removeu;
  for (int i = 0; i < concessionarias.size(); i++) {
    removeu = concessionarias[i].remove_vehicle(chassi);
    if (removeu) {
      return "Veículo " + chassi + " removido da concessionária " + concessionarias[i].get_nome();
    }
  }
  return "Erro ao remover veículo";
}

string Sistema::search_vehicle(const string chassi) {
  string encontrou;
  for (int i = 0; i < concessionarias.size(); i++) {
    encontrou = concessionarias[i].search_vehicle(chassi);
    if (encontrou != "erro") {
      return encontrou;
    }
  }
  return "Erro ao encontrar o veículo";
}