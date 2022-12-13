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
      concessionarias[i].add_carro(carro);
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
      concessionarias[i].add_caminhao(caminhao);
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
      concessionarias[i].add_moto(moto);
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

string Sistema::list_concessionaria(const string concessionaria) {
  string saida;
  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].get_nome() == concessionaria) {
      saida =  concessionarias[i].lista_concessionaria();
      return saida;
    }
  }
  return "Erro ao encontrar o veículo";
}

string Sistema::raise_price(const string nome) {
  vector < string > strings;
  istringstream f(nome);
  string s;
  while (getline(f, s, ' ')) {
    strings.push_back(s);
  }
  // Buscar a concessinaria digitada

  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].get_nome() == strings[0]) {
      concessionarias[i].aumentar_preco(stoi(strings[1]));
      return "Aumento de " + strings[1] + "% nos preços de automóveis da Concessionária IMD_SA realizado\n" +
"Aumento de " + to_string(stoi(strings[1]) * 2) +  "% nos preços de motos da Concessionária IMD_SA realizado\n" +
"Aumento de " + to_string(stoi(strings[1]) * 3) +  "% nos preços de caminhões da Concessionária IMD_SA realizado";
    }
  }
  return "Erro ao adicionar moto!";
<<<<<<< HEAD
}

string Sistema::save_concessionaria(string nome) {  
  for (int i = 0; i < concessionarias.size(); i++) {
    if (concessionarias[i].get_nome() == nome && concessionarias[i].salvar_estoque()) {
        return "Arquivo " + concessionarias[i].get_nome() + " criado com sucesso";
    }
  }
  return "Erro ao criar arquivo!";
}

vector <string> Sistema::parse_input(string input) {
  vector < string > vetor;
  istringstream parse(input); // Receber entrada da linha
  string atributo_relativo;
  while (parse) {
    parse >> atributo_relativo;
    if (parse) {
      vetor.push_back(atributo_relativo);
    }
  }
  return vetor;
}

string Sistema::load_concessionaria(string dir_arquivo) {
  ifstream arm_dados;
  vector < string > elementos_veiculos, concessionaria;
  string concessionaria_dados, vehicle_data;
  arm_dados.open(dir_arquivo);

  getline(arm_dados, concessionaria_dados, '\n');
  concessionaria = parse_input(concessionaria_dados);
  create_concessionaria(concessionaria_dados);
  while (!arm_dados.eof()) {
    getline(arm_dados, vehicle_data, '\n');
    if (vehicle_data != "") {

      elementos_veiculos = parse_input(vehicle_data);
      vehicle_data = concessionaria[0] + " " + vehicle_data;
      if (elementos_veiculos[4] == "gasolina" || elementos_veiculos[4] == "elétrico") {
        add_car(vehicle_data);
      } else if (elementos_veiculos[4] == "clássico" || elementos_veiculos[4] == "esportivo") {
        add_motorcycle(vehicle_data);
      } else if (elementos_veiculos[4] == "comum" || elementos_veiculos[4] == "perigosa") {
        add_truck(vehicle_data);
      }
    }
  }
  return "Concessionaria " + concessionaria[0] + " criada com sucesso";
=======
>>>>>>> 5724194041692fffe07ee27e0ca6fd3df12edb5b
}