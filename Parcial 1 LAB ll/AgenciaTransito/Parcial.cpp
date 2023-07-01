#include<iostream>

using namespace std;
#include "Parcial.h"
#include "MultaArchivo.h"
#include "AgenteArchivo.h"

//RESOLUCION DEL PARCIAL


void Parcial::Punto1()
{

    MultaArchivo Amulta;
    Multa multa;

    int cantidadMultas = Amulta.getCantidadRegistros();
    bool multasEn2021[10] = {false};
    bool multasEn2022[10] = {false};

        for(int i=0; i< cantidadMultas;i++){

            multa = Amulta.leer(i);

            if((multa.getFechaMulta().getAnio() == 2022) && (!multa.getEliminado())){
            multasEn2022[multa.getTipoInfraccion()-1] = true;
            }else if((multa.getFechaMulta().getAnio() == 2021) && (!multa.getEliminado())){
            multasEn2021[multa.getTipoInfraccion()-1] = true;
            }
        }

        cout<<"LOS NUMEROS DE TIPO DE INFRACCION QUE REGISTRARON MULTAS EN 2022 PERO NO EN 2021 FUERON O ES: "<<endl;

        for(int i =0; i<10;i++){
            if(multasEn2022[i] && !multasEn2021[i]){
             cout<<"TIPO: "<<i+1<<endl;
            }
        }
}


void Parcial::Punto2()
{
    MultaArchivo Amulta;
    Multa multa;

    AgenteArchivo Aagente;
    Agente agente;

    int cantidadMultas = Amulta.getCantidadRegistros();
    int cantidadAgentes = Aagente.getCantidadRegistros();

    float importe = 0;
    int id ;

    for(int i=0;i<cantidadMultas;i++){

        multa = Amulta.leer(i);

        if((multa.getMonto() > importe) && (!multa.getEliminado()) && (multa.getPagada())){
            importe = multa.getMonto();
            id = multa.getIDAgente();
        }
    }

    for(int i=0; i< cantidadAgentes;i++){
        agente = Aagente.leer(i);

        if(agente.getIdAgente() == id){

         cout<<"LA MAYOR MULTA FUE DE: $"<<importe<<", Y FUE HECHA POR: "<<agente.getApellidos()<<" "<<agente.getNombres()<<endl;
        }
    }
}


void Parcial::Punto3()
{
    MultaArchivo Amulta;
    Multa multa;

    AgenteArchivo Aagente;
    Agente agente;

    int cantidadMultas = Amulta.getCantidadRegistros();
    int cantidadAgentes = Aagente.getCantidadRegistros();
    int *contadorAgentes = new int [cantidadAgentes];

    if(contadorAgentes == nullptr){
        cout<<"ERROR CON LA MEMORIA"<<endl;
        return;
    }

    for(int i=0;i<cantidadAgentes;i++){
    contadorAgentes[i] = 0;
    agente = Aagente.leer(i);

        for(int j=0;j<cantidadMultas;j++){

            multa = Amulta.leer(j);

            if((!multa.getEliminado()) && (agente.getIdAgente() == multa.getIDAgente()) && (multa.getMonto() > 25000)){
            contadorAgentes[i]++;
            }
        }
    }

    cout<<"LA CANTIDAD DE AGENTES QUE REALIZARON AL MENOS UNA MULTA CON UN MONTO MAYOR A $25000 FUERON: ";

    int cantidad = 0;
    for(int i=0;i<cantidadAgentes;i++){

        if(contadorAgentes[i] >= 1){
            cantidad++;
        }
    }

    cout<<cantidad<<endl;

delete[] contadorAgentes;
}


void Parcial::Punto4(){

    MultaArchivo Amulta;
    Multa multa;

    AgenteArchivo Aagente;
    Agente agente;

    int cantidadMultas = Amulta.getCantidadRegistros();
    int cantidadAgentes = Aagente.getCantidadRegistros();

    for(int i=0; i<cantidadAgentes;i++){

    int tiposMulta[10]={0};
    agente = Aagente.leer(i);

        for(int j=0;j<cantidadMultas;j++){

            multa = Amulta.leer(j);

            if((!multa.getEliminado() &&  (agente.getIdAgente() == multa.getIDAgente()) && (multa.getFechaMulta().getAnio() == 2022))){
            tiposMulta[multa.getTipoInfraccion()-1] ++;
            }
        }

        bool realizo = false;
        for(int x = 0; x<10;x++){
            if(tiposMulta[x] > 1){
            realizo = true;
            }
        }
        if(realizo == true){
           cout<<"ID AGENTE: "<<agente.getIdAgente()<<", APELLIDO Y NOMBRE: "<<agente.getApellidos()<<" "<<agente.getNombres()<<endl;
        }
    }
}
