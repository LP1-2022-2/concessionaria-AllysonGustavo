#ifndef EXECUTOR_H
#define EXECUTOR_H
#include "sistema.h"
#include <istream>
#include <ostream>
#include <sstream>
#include <queue>

using namespace std;

class Executor {
  private:
  Sistema * sistema;
  stringstream ss;
  bool sair = false;

  public:
  Executor(Sistema &sistema);
  void iniciar(istream &in, ostream &out);
  vector<string> DividirTexto(string resto);
  string processarLinha(string linha);
};

#endif