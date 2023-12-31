#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED
#include <string>

using namespace std;

class Fecha{
private:
    int _dia, _mes, _anio;
    void establecerFechaPorDefecto();
    bool esBisiesto();
    void agregarDia();

public:
    Fecha();
    Fecha(int dia, int mes, int anio);

    int getDia();
    int getMes();
    int getAnio();
    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);
    void Cargar();

    void agregarDias(int cantidadDias);
    string toString(string formatoFecha = "DD/MM/YYYY");

};
#endif // FECHA_H_INCLUDED
