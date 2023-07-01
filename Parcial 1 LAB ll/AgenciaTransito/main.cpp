#include <iostream>
using namespace std;
#include "Parcial.h"

int main(){

Parcial reg;
int opcion;

  do
  {
    cout << "------ PARCIAL ------"<<endl;
    cout << "---------------------"<<endl;
    cout << "1- PUNTO 1" << endl;
    cout << "2- PUNTO 2" << endl;
    cout << "3- PUNTO 3" << endl;
    cout << "4- PUNTO 4" << endl;
    cout << "---------------------"<<endl;
    cout << "0- SALIR" << endl;
    cout << "---------------------"<<endl;
    cout << "INGRESE UNA OPCION: ";
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        system("cls");
        reg.Punto1();
        system("pause");
        system("cls");
      break;
    case 2:
        system("cls");
        reg.Punto2();
        system("pause");
        system("cls");
      break;
    case 3:
        system("cls");
        reg.Punto3();
        system("pause");
        system("cls");
      break;
    case 4:
        system("cls");
        reg.Punto4();
        system("pause");
        system("cls");
      break;
    case 0:

      break;
    default:

      break;
    }
  } while (opcion != 0);

  return 0;
}
