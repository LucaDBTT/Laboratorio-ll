#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto
{
private:
    int id_producto;
    int id_categoria;
    char _nombre[30];
    bool estado;
    float precio;
    int stock;
    float precio_compra;

public:
    Producto();
    void setPrecioCompra(float precio_compra);
    void setStock(int nStock);
    void setPrecio(float nPrecio);
    void setNombre(string _nombre);
    void setId_Categoria(int id_categoria);
    void setId_Producto(int id_producto);
    void setEstado(bool nEstado);
    float getPrecioCompra();
    int getStock();
    void AgregarStock(int can);
    string getNombre();
    int getId_Categoria();
    float getPrecio();
    int getId_Producto();
    bool getEstado();
    bool Cargar();
    void CargarCategoria();
    void Mostrar();
    
};

