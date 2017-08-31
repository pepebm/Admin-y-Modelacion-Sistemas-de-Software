#include <iostream>
#include <string>
#include <map>

using namespace std;

template <class T, class Func>
class Command {
public:
  virtual T exec(T*, int, Func) = 0;
};

template <class T, class Func>
class Sum : public Command<T, Func> {
  T exec(T* arr, int size, Func f)
  {
    T acum = 0;
    for (int i = 0; i < size; i++) {
      acum += arr[i];
    }
    return acum;
  }
};

template <class T, class Func>
class Res : public Command<T, Func> {
  T exec(T* arr, int size, Func f)
  {
    T acum = 0;
    for (int i = 0; i < size; i++) {
      acum -= arr[i];
    }
    return acum;
  }
};

template <class T, class Func>
class Operaciones {
  std::map<std::string, Command<T, Func>* > operaciones;
  map<string, Func> operacionesConApuntadores;
public:
  Operaciones(){
    operaciones.insert(make_pair("suma", new Sum<T, Func>()));
    operaciones.insert(make_pair("resta", new Res<T, Func>()));
  }

void insert(string s, Func f)
{
  operacionesConApuntadores.insert(make_pair(s, f));
}

Func getOpFunc(string op)
{
  typename map<string, Command<T, Func>*>::iterator it;
  it = operacionesConApuntadores.find(op);
  if (it != operacionesConApuntadores.end())
  {
    return it->second;
  }
  return NULL;
  }
}

Command<T, Func>* getOp(std::string op){
  typename map<string, Command<T, Func>*>::iterator it;
  it = operaciones.find(op);
  if (it != operaciones.end())
  {
    return it->second;
  }
  return NULL;
  }
};

int main() {
  Operaciones<double, int> op;
  double* arrD = new double[5]{2.1, 3.5, 2.3, 4.3, 1.4};
  Command<double, int>* c = op.getOp("suma");
  cout <<"Suma: " <<c->exec(arrD, 5, 0)<<endl;
  c = op.getOp("resta");
  cout <<"Resta: " <<c->exec(arrD, 5, 0)<<endl;
  cout << "-------------------" << endl;

  return 0;
}
