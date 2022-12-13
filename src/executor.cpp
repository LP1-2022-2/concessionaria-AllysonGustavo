#include "executor.h"

using namespace std;

// Função de apoio que recebe um istringstream e
// le todo texto restante até o fim da linha
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

// Separar a string 

vector<string> Executor::DividirTexto(string resto) {
  vector<string> strings;
    istringstream f(resto);
    string s;
    while (getline(f, s, ' ')) {
        cout << s << endl;
        strings.push_back(s);
    }
  return strings;
}

// Construtor. Recebe uma referência ao sistema que vai operar
// Guarda o seu endereço para executar as operações.
Executor::Executor(Sistema &sistema) {
  this->sair = false;
  this->sistema = &sistema;
}

// Inicia o processamento dos comentarios.
// Esse método recebe por exemplo o "cin" e o "cout" no main
// Dessa forma ele faz o necessário para ler 1 comando por linha e
// o processar corretamente, colocando no stream de saída o resultado de cada um.
void Executor::iniciar(istream &inputStream, ostream &outputStream) {
  string linha, saida;
  this->sair = false;
  while (! this->sair)
  {
    if (std::getline(inputStream, linha)) {
      saida = processarLinha(linha);
      outputStream << saida << endl;
    }
  }
}

// Método responsável por processar cada linha, capturando o nome do comando
// e seus parâmetros em variáveis e executar o método correspondente no sistema
string Executor::processarLinha(string linha) {
  istringstream buf(linha);
  string nomeComando;
  buf >> nomeComando;

  if (nomeComando.empty()) {
    return "Comando Inválido <vazio>";
  }

  if (nomeComando == "quit" ) {
    this->sair = true;
    return sistema->quit();
  }
  else if (nomeComando == "create-concessionaria") {
    string nome;    
    nome = restoDe(buf);
    return sistema->create_concessionaria(nome);
  }
  else if(nomeComando == "add-car"){
    string nome;
    nome = restoDe(buf);
    return sistema->add_car(nome);
  }
  else if(nomeComando == "add-truck"){
    string nome;
    nome = restoDe(buf);
    return sistema->add_truck(nome);
  }
  else if(nomeComando == "add-motorcycle"){
    string nome;
    nome = restoDe(buf);
    return sistema->add_motorcycle(nome);
  }
  else if(nomeComando == "remove-vehicle"){
    string nome;
    nome = restoDe(buf);
    return sistema->remove_vehicle(nome);
  }
  else if(nomeComando == "search-vehicle"){
    string nome;
    nome = restoDe(buf);
    return sistema->search_vehicle(nome);
  }
  else if(nomeComando == "save-concessionaria"){
    string nome;
    nome = restoDe(buf);
    return sistema->save_concessionaria(nome);
  }
  else if(nomeComando == "load-concessionaria"){
    string nome;
    nome = restoDe(buf);
    return sistema->load_concessionaria(nome);
  }
  else if(nomeComando == "list-concessionaria"){
    string nome;
    nome = restoDe(buf);
    return sistema->list_concessionaria(nome);
  }
  else if(nomeComando == "raise-price"){
    string nome;
    nome = restoDe(buf);
    return sistema->raise_price(nome);
  }

  return "Erro";	
}