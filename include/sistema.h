#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include <concessionaria.h>

// Sistema deve concentrar todas as operações
class Sistema {
  private:
		std::vector<Concessionaria> concessionarias; //um vetor com todos as concessionarias
  public:

		/*Encerra o funcionamento do programa.
			@return uma string com a mensagem "Saindo.."
		*/
		std::string quit();

		/* Cria uma concessionaria e retorna uma string de erro/sucesso 
			@param nome o nome da concessionaria
			@return uma string contendo uma mensagem de erro ou "Concessionaria Criada"
		*/
		std::string create_concessionaria (const std::string nome);

    std::string add_car (const string carro);
    std::string add_truck (const string caminhao);
    std::string add_motorcycle (const string moto);
		std::string remove_vehicle(const string chassi);
    std::string search_vehicle(const string chassi);
    std::string list_concessionaria(const string concessionaria);
    std::string raise_price(const string nome);
<<<<<<< HEAD
<<<<<<< HEAD
    std::string save_concessionaria(string nome);
    std::vector <string> parse_input(string input);
    std::string load_concessionaria(string dir_arquivo);
=======
>>>>>>> 5724194041692fffe07ee27e0ca6fd3df12edb5b
=======
>>>>>>> 5724194041692fffe07ee27e0ca6fd3df12edb5b
};

#endif