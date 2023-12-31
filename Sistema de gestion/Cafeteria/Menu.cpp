#include <iomanip>
#include "archivo_producto.h"
#include "Archivo_Categoria.h"
#include "Archivo_Cliente.h"
#include "Archivo_Venta.h"
#include "Archivo_Vendedor.h"
#include "Archivo_bkp.h"
#include "rlutil.h"
#include "Menu.h"

using namespace std;

void Menu::menu_Principal()
{
    rlutil::setBackgroundColor(rlutil::WHITE);
    rlutil::setColor(rlutil::BLACK);
    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "* BIENVENIDO VENDEDOR *" << endl << endl;       
        cout << "Menu Principal" << endl;
        cout << "-------------------------" << endl;
        cout << " 1- Productos " << endl;
        cout << " 2- Categorias " << endl;
        cout << " 3- Ventas " << endl;
        cout << " 4- Clientes " << endl;
        cout << " 5- Vendedores " << endl;
        cout << " 6- Stock " << endl;
        cout << " 7- Backup de las ventas " << endl;
        cout << " 8- Informes " << endl;
        cout << "-------------------------" << endl;
        cout << " 0- SALIR" << endl;

        cin >> op;
        while (op < 0 || op>8)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            menu_Productos();
        }
        break;
        case 2:
        {
            menu_Categorias();
        }
        break;
        case 3:
        {
            menu_Ventas();
        }
        break;
        case 4:
        {
            menu_Clientes();
        }
        break;
        case 5:
        {
            menu_Vendedores();
        }
        break;
        case 6:
        {
        system("cls");
        archivo_producto ar;
        int cant = ar.cantidad_de_registros();
        int cantA = ar.get_cantidad_Activa(cant);
        
        if (cantA > 0) {
            cout << "Stock de productos" << endl;
            cout << "-------------------------------" << endl;
            archivo_producto archivo;
            archivo.stock_de_productos();
            cout << "-------------------------------" << endl;
            system("pause");
        }
        else {
            cout << "NO HAY PRODUCTOS CARGADOS" << endl;
            system("pause");
        }

        }break;
        case 7:
        {
            menu_backup();
        }break;
        case 8:
        {
            menu_Informes();
        }break;
        }
    }
}
void Menu::menu_Productos()
{
    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "----Productos----" << endl;
        cout << "-----------------" << endl;
        cout << " 1- Listar" << endl;
        cout << " 2- Agregar" << endl;      
        cout << " 3- Modificar" << endl;
        cout << " 4- Eliminar" << endl;
        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
       

        cin >> op;

        while (op < 0 || op>4)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            bool menu2activo = true;

            while (menu2activo)
            {
                system("cls");
                cout << "Listar Productos" << endl;
                cout << "-------------------------" << endl;
                cout << "1- Todos" << endl;
                cout << "2- Listar por categorias" << endl;
                cout << "3- Por rango de precio " << endl;
                cout << "-------------------------" << endl;
                cout << "0- Volver" << endl;
                cin >> op;

                while (op < 0 || op>3)
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
                    rlutil::setColor(rlutil::BLACK);
                    cin >> op;
                }

                switch (op)
                {

                case 1:
                {
                    system("cls");
                    cout << "Lista de todos los productos" << endl;
                    archivo_producto archivo;
                    int cant = archivo.cantidad_de_registros();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    if (cantActiva == 0)
                    {
                        Producto producto;
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardados Productos Activos" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                        char desicion;
                        cout << "�Desea cargar un producto nuevo? (S/N): ";
                        cin >> desicion;
                        if (desicion == 's' || desicion == 'S')
                        {
                            if (producto.Cargar()) {
                                archivo.guardar(producto);
                                system("cls");
                                cout << "-----------------------------------" << endl;
                                producto.Mostrar();
                                cout << "-----------------------------------" << endl;
                                cout << "Se cargo exitosamente..." << endl;
                            }
                            else { 
                                Menu menu;
                                menu_Productos();
                            }
                        }
                        else if (desicion == 'n' || desicion == 'N')
                        {
                            return;
                        }
                    }
                    else
                    {
                        archivo.listar(cant);
                    }
                    system("pause");
                }
                break;
                case 2:
                {
                    system("cls");
                    cout << "Lista por categoria" << endl;
                    archivo_producto archivo;
                    Archivo_Categoria archivoCat;
                    int cant = archivo.cantidad_de_registros();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    int cantC = archivoCat.cantidad_categorias();
                    int cantActivaCat = archivoCat.get_cantidad_Activa(cantC);
                    if (cantActiva == 0 || cantActivaCat == 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardados Categorias o productos activos" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                    }
                    else
                    {
                        archivo.listaXcategoria();
                    }
                    system("pause");

                }
                break;
                case 3:
                {
                    system("cls");
                    cout << "Lista por rango de precio" << endl << endl;
                    archivo_producto archivo;
                    int cant = archivo.cantidad_de_registros();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    if (cantActiva == 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardados Productos Activos" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                    }
                    else
                    {
                        archivo.listaXrango();
                    }
                    system("pause");
                }
                break;
                case 0:
                {
                    menu2activo = false;
                }
                }

            }
        }break;

        case 2:
        {
            bool menu3activo = true;

            while (menu3activo)
            {
                system("cls");
                cout << "Agregar Productos" << endl;
                cout << "----------------------------" << endl;
                cout << "1- Agregar producto nuevo" << endl;
                cout << "(ACLARACION: Para agregar productos primero debe generar la categoria a la cual pertenece.) " << endl;
                cout << "2- Agregar stock de producto" << endl;
                cout << "----------------------------" << endl;
                cout << "0- Volver" << endl;
                cin >> op;

                while (op < 0 || op>2)
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
                    rlutil::setColor(rlutil::BLACK);
                    cin >> op;
                }

                switch (op)
                {
                case 1:
                {
                    system("cls");
                    Archivo_Categoria archivo;
                    int cant = archivo.cantidad_categorias();
                    int cantActiva = archivo.get_cantidad_Activa(cant);

                    if (cantActiva == 0) {
                        char desicion;
                        Categoria categoria;
                        Archivo_Categoria ar;

                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardadas categorias Activas" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                        cout << "�Desea ingresar una categoria nueva? (S/N): ";
                        cin >> desicion;
                        if (desicion == 's' || desicion == 'S')
                        {
                            categoria.cargar();
                            ar.guardar(categoria);
                            system("cls");
                            categoria.mostrar();
                            cout << "Se cargo exitosamente..." << endl;
                        }
                        else if (desicion == 'n' || desicion == 'N')
                        {
                            menu_Productos();
                        }
                        system("pause");
                    }
                    else {
                        Producto producto;  
                        if (producto.Cargar())
                        {
                            archivo_producto archivo;
                            archivo.guardar(producto);
                            system("cls");
                            cout << "Producto cargado" << endl;
                            cout << "-----------------------------------" << endl;
                            producto.Mostrar();
                            cout << "-----------------------------------" << endl << endl;
                            system("pause");
                            cout << endl;
                        }
                    }
                }

                break;
                case 2:
                {
                    system("cls");
                    cout << "AGREGAR STOCK" << endl;
                    archivo_producto ar;
                    int cant = ar.cantidad_de_registros();
                    int cantA = ar.get_cantidad_Activa(cant);
                    ar.listar(cant);
                    int id;
                    archivo_producto archivo;
                    Producto producto, aux;
                    if (cantA == 0) {
                        system("cls");
                        rlutil::setColor(rlutil::RED);
                        cout << "ERROR, no hay productos cargados" << endl;
                        rlutil::setColor(rlutil::BLACK);
                        system("pause");
                    }
                    else {
                        cout << "Ingrese ID del producto al que desea agregarle stock: ";
                        cin >> id;
                        archivo.Stock(id);
                        system("cls");                    
                    }
                }
                break;
                case 0:
                {
                    menu3activo = false;
                }
                }
                break;
            }
        }
        break;
        case 3:
        {
            system("cls");
            archivo_producto archivo;
            int cant = archivo.cantidad_de_registros();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados Productos Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else {
                system("cls");
                cout << "Modificar producto" << endl;
                archivo_producto archivo;
                archivo.modificar();
                system("pause");
            }
        }
        break;
        case 4:
        {
            system("cls");
            archivo_producto archivo;
            int cant = archivo.cantidad_de_registros();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados Productos Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");

            }
            else {
                cout << "Eliminar producto" << endl;
                archivo_producto archivo;
                archivo.baja_Logica();
                system("pause");
            }
        }
        break;

        }
    }
}

void Menu::menu_Categorias()
{
    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "---Categorias----" << endl << endl;
        cout << " 1- Listar" << endl;
        cout << " 2- Agregar" << endl;
        cout << " 3- Modificar" << endl;
        cout << " 4- Eliminar" << endl;
        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
        cout << "-----------------" << endl;

        cin >> op;

        while (op < 0 || op>4)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            system("cls");
            cout << "Lista de categorias" << endl << endl;
            Archivo_Categoria archivo;
            Categoria categoria;
            int cant = archivo.cantidad_categorias();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardadas categorias Activas" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                char desicion;
                cout << "�Desea cargar una categoria nueva? (S/N): ";
                cin >> desicion;
                if (desicion == 's' || desicion == 'S')
                {
                    categoria.cargar();
                    archivo.guardar(categoria);
                    system("cls");
                    cout << "-----------------------------------" << endl;
                    categoria.mostrar();
                    cout << "-----------------------------------" << endl;
                    cout << "Se cargo exitosamente..." << endl;
                }
                else if (desicion == 'n' || desicion == 'N')
                {
                    menu_Categorias();
                }

            }
            else
            {
                rlutil::setColor(rlutil::BLACK);
                archivo.listar_categorias(cant);
                cout << endl << endl;
                system("pause");
            }
        }
        break;

        case 2:
        {
            cout << "Agregar categoria" << endl;
            Archivo_Categoria ac;
            ac.agregar_categoria();
        }
        break;
        case 3:
        {
            system("cls");
            cout << "Modificar categoria" << endl;
            Archivo_Categoria archivo;
            Categoria cat;
            int cant = archivo.cantidad_categorias();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardadas categorias Activas" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else {
                archivo.modificar_categorias();
            }
        }
        break;
        case 4:
        {
            system("cls");
            cout << "Eliminar categoria" << endl;
            Archivo_Categoria archivo;
            Categoria ca;
            int cant = archivo.cantidad_categorias();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardadas categorias Activas" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");

            }
            else {
                archivo.baja_Logica();
                cout << endl;
                system("pause");
                system("cls");
            }

        }
        break;

        }
    }

}

void Menu::menu_Ventas()
{
    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "---Ventas----" << endl;
        cout << " 1- Listar" << endl;
        cout << " 2- Agregar" << endl;
        cout << "(ACLARACION: Para generar una venta, primero debe haber cargado cliente, vendedor y producto)" << endl;
        cout << " 3- Modificar" << endl;
        cout << " 4- Eliminar" << endl;

        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
        cout << "-----------------" << endl;
        cin >> op;
        while (op < 0 || op>4)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion" << endl;
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;

        case 1:
        {
            bool menu2activo = true;

            while (menu2activo)
            {
                system("cls");
                cout << "Listar Ventas" << endl;
                cout << "-----------------------" << endl;
                cout << "1- Todos" << endl;
                cout << "2- Listar por Cliente" << endl;
                cout << "3- Listar por Fecha" << endl;
                cout << "-----------------------" << endl;
                cout << "0- volver" << endl;
                cout << "-----------------------" << endl;
                cin >> op;

                while (op < 0 || op>3)
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "opcion incorrecta, vuelva a ingresar una opcion" << endl;
                    rlutil::setColor(rlutil::BLACK);
                    cin >> op;
                }

                switch (op)
                {
                case 0:
                {
                    menu2activo = false;
                }
                break;
                case 1:
                {

                    system("cls");
                    cout << "Lista de ventas" << endl;
                    Archivo_Venta archivo;


                    int cant = archivo.cantidad_ventas();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    if (cantActiva == 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardadas ventas Activas" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                        system("pause");
                    }
                    else
                    {
                        system("cls");
                        cout << "        ******** VENTAS ********" << endl;
                        archivo.listar_ventas(cant);
                        cout << "*********************" << endl;
                        system("pause");
                    }
                }
                break;
                case 2:
                {
                    system("cls");
                    cout << "Lista de ventas por cliente" << endl << endl;
                    Archivo_Venta archivo;
                    Archivo_Cliente cliente;
                    int cant = archivo.cantidad_ventas();
                    int cantClientes = cliente.cantidad_clientes();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    if (cantActiva == 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardadas ventas Activas" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                        system("pause");
                    }

                    else
                    {
                        archivo.listar_x_cliente();
                        cout << endl << endl;
                        system("pause");
                    }
                }
                break;
                case 3:
                {
                    system("cls");
                    cout << "Lista de ventas por fecha" << endl;

                    Archivo_Venta archivo;
                    int cant = archivo.cantidad_ventas();
                    int cantActiva = archivo.get_cantidad_Activa(cant);
                    if (cantActiva == 0)
                    {
                        rlutil::setColor(rlutil::RED);
                        cout << "No se encuentran guardadas ventas Activas" << endl << endl;
                        rlutil::setColor(rlutil::BLACK);
                        system("pause");
                    }
                    else
                    {
                        archivo.listar_x_fecha();
                        cout << endl << endl;
                    }
                }
                break;
                }
            }
        }
        break;
        case 2:
        {
            system("cls");
            archivo_producto ap;
            int cant = ap.cantidad_de_registros();
            int stock = ap.Stock_total();
            Archivo_Vendedor av;
            int cantV = av.Cantidad_vendedores();
            Archivo_Cliente ac;
            int cantC = ac.cantidad_clientes();
            Archivo_Categoria acat;
            int cantCat = acat.cantidad_categorias();

            if (cant == 0 || stock <= 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay productos cargados o falta stock" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }

            if (cantV == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay vendedores cargados" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }

            if (cantC == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay clientes cargados" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }

            if (cantCat == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay categorias cargadas" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }
            if (cant != 0 && cantV != 0 && cantC != 0 && cantCat != 0 && stock > 0) {
                cout << "Agregar venta" << endl;
                Archivo_Venta aventas;
                Venta venta;

                venta.cargar();
                system("cls");
                cout << "Se cargo la venta exitosamente..." << endl;
                system("pause");
                system("cls");
                venta.mostrar();
                system("pause");
                aventas.guardar(venta);
            }
            else { return; }
        }
        break;
        case 3:
        {
            system("cls");
            archivo_producto ap;
            int cant = ap.cantidad_de_registros();
            int stock = ap.Stock_total();
            Archivo_Vendedor av;
            int cantV = av.Cantidad_vendedores();
            Archivo_Cliente ac;
            int cantC = ac.cantidad_clientes();
            Archivo_Categoria acat;
            int cantCat = acat.cantidad_categorias();
            Archivo_Venta archivo;
            int cantVen = archivo.cantidad_ventas();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardadas ventas activas" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }else if (cant == 0 || stock <= 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay productos cargados o falta stock" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }else if (cantV == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay vendedores cargados" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }else if (cantC == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay clientes cargados" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }else if (cantCat == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No hay categorias cargadas" << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
                return;
            }else if (cantActiva != 0 && cantV != 0 && cantC != 0 && cantCat != 0 && stock > 0) {
                system("cls");
                cout << "Modificar venta" << endl;
                int pro = archivo.Modificar_Venta();
                system("pause");
                system("cls");
                Venta aux = archivo.leer_ventas(pro - 1);
                cout << "----------------------------------------" << endl;
                aux.mostrar();
                cout << "----------------------------------------" << endl << endl;
                system("pause");
            }
        }
        break;
        case 4:
        {
            system("cls");
            cout << "Eliminar venta" << endl;
            Archivo_Venta venta;
            int cant = venta.cantidad_ventas();
            int cantActiva = venta.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran ventas cargadas" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");

            }
            else {
                venta.BajaLogica();
                system("cls");
            }
        }
        break;

        }
    }
}

void Menu::menu_Clientes()
{

    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "---Clientes----" << endl << endl;
        cout << " 1- Listar" << endl;
        cout << " 2- Agregar" << endl;
        cout << " 3- Modificar" << endl;
        cout << " 4- Eliminar" << endl;
        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
        cout << "-----------------" << endl;
        cin >> op;
        while (op < 0 || op>4)
        {
            cout << "opcion incorrecta, vuelva a ingresar una opcion" << endl;
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            system("cls");
            Archivo_Cliente archivo;
            Cliente cliente;
            int cant = archivo.cantidad_clientes();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            cout << "Lista de clientes" << endl;
            if (cantActiva == 0)
            {
                char desicion;
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados clientes Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                cout << "�Desea ingresar un cliente nuevo? (S/N): ";
                cin >> desicion;
                if (desicion == 's' || desicion == 'S')
                {
                    cliente.Cargar();
                    archivo.guardar(cliente);
                }
                else if (desicion == 'n' || desicion == 'N')
                {
                    menu_Clientes();
                }
                else
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "Opcion incorrecta" << endl << endl;
                    rlutil::setColor(rlutil::BLACK);
                    system("pause");
                }
                system("pause");

            }
            else
            {
                archivo.listar_clientes(cant);
                cout << endl;
                system("pause");
            }
        }
        break;
        case 2:
        {
            Archivo_Cliente archivo;
            Cliente cliente;
            system("cls");
            cout << "Agregar cliente" << endl << endl;
            cliente.Cargar();
            system("cls");
            cout << "Se cargo el cliente exitosamente..." << endl << endl;
            system("pause");
            system("cls");
            cliente.Mostrar();
            system("pause");
            archivo.guardar(cliente);
        }
        break;
        case 3:
        {
            Archivo_Cliente archivo;
            Cliente cliente;
            system("cls");
            cout << "Modificar cliente" << endl;
            int cant = archivo.cantidad_clientes();
            int cantActiva = archivo.get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados clientes Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else
            {
                archivo.modificar_cliente();
                system("pause");
            }
        }
        break;
        case 4:
        {
            system("cls");
            cout << "Eliminar cliente" << endl;
            Archivo_Cliente cliente;  
            int cant = cliente.cantidad_clientes();
            int cantAct = cliente.get_cantidad_Activa(cant);
            if (cantAct == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran clientes cargados" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else
            {
            cliente.baja_Logica();
            system("pause");   
            }
        }
        break;
        }
    }
}

void Menu::menu_Vendedores()
{
    int op;
    bool menu_activo = true;
    while (menu_activo)
    {
        system("cls");
        cout << "---Vendedores----" << endl << endl;
        cout << " 1- Listar" << endl;
        cout << " 2- Agregar" << endl;
        cout << " 3- Modificar" << endl;
        cout << " 4- Eliminar" << endl;
        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
        cout << "-----------------" << endl;
        cin >> op;
        while (op < 0 || op>4)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion" << endl;
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            Archivo_Vendedor archivo;
            Vendedor vendedor;
            int cant = archivo.Cantidad_vendedores();
            int cantActiva = archivo.Get_cantidad_Activa(cant);
            system("cls");
            cout << "Lista de Vendedores" << endl;
            if (cantActiva == 0)
            {
                char desicion;
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados vendedores Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                cout << "�Desea ingresar un vendedor nuevo? (S/N): ";
                cin >> desicion;
                if (desicion == 's' || desicion == 'S')
                {
                    vendedor.Cargar();
                    archivo.Guardar(vendedor);
                }
                else if (desicion == 'n' || desicion == 'N')
                {
                    menu_Vendedores();
                }
                else
                {
                    rlutil::setColor(rlutil::RED);
                    cout << "Opcion incorrecta" << endl << endl;
                    rlutil::setColor(rlutil::BLACK);
                    system("pause");
                }
                system("pause");

            }
            else
            {
                archivo.Listar_Vendedor(cant);
                cout << endl;
                system("pause");
            }
        }break;
        case 2:
        {
            Archivo_Vendedor archivo;
            Vendedor vendedor;
            system("cls");
            cout << "Agregar Vendedor" << endl << endl;
            vendedor.Cargar();
            system("cls");
            cout << "Se cargo el cliente exitosamente..." << endl << endl;
            system("pause");
            system("cls");
            vendedor.Mostrar();
            system("pause");
            archivo.Guardar(vendedor);
        }
        break;
        case 3:
        {
            Archivo_Vendedor archivo;
            Vendedor vendedor;
            int cant = archivo.Cantidad_vendedores();
            int cantActiva = archivo.Get_cantidad_Activa(cant);
            system("cls");
            cout << "Modificar Vendedor" << endl;

            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados vendedores Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else
            {
                archivo.Modificar_Vendedor();
                system("pause");
            }

        }
        break;
        case 4:
        {
            Archivo_Vendedor archivo;
            Vendedor vendedor;
            system("cls");
            cout << "Eliminar Vendedor" << endl;
            int cant = archivo.Cantidad_vendedores();
            int cantActiva = archivo.Get_cantidad_Activa(cant);
            if (cantActiva == 0)
            {
                rlutil::setColor(rlutil::RED);
                cout << "No se encuentran guardados vendedores Activos" << endl << endl;
                rlutil::setColor(rlutil::BLACK);
                system("pause");
            }
            else
            {
            archivo.Baja_Logica();
            system("pause"); }     
            }
        break;
        }
    }
}

void Menu::menu_Informes()
{
    int op;
    bool menu_activo = true;
    system("cls");
    while (menu_activo)
    {
        cout << "****INFORMES****" << endl;
        cout << "-----------------------------------" << endl;
        cout << "1- Recaudacion anual por vendedor" << endl;
        cout << "2- Recaudacion anual por Productos" << endl;
        cout << "3- Recaudacion anual por Categorias" << endl;
        cout << "4- Ganancia neta mensual por anio" << endl;
        cout << "-----------------------------------" << endl;
        cout << "0- SALIR" << endl;

        cin >> op;
        while (op < 0 || op>5)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            Archivo_Venta archivo;
            system("cls");
            cout << "RECAUDACION ANUAL POR VENDEDOR: " << endl;
            archivo.recaudacion_x_vendedor();
            system("cls");
        }
        break;
        case 2:
        {
            Archivo_Venta archivo;
            system("cls");
            cout << "RECAUDACION ANUAL POR PRODUCTO: " << endl;
            archivo.recaudacion_x_producto();
            system("cls");
        }
        break;
        case 3:
        {
            Archivo_Venta archivo;
            system("cls");
            cout << "RECAUDACION ANUAL POR CATEGORIA: " << endl;
            archivo.recaudacion_x_categoria();
            system("cls");
        }
        break;
        case 4:
        {
            Archivo_Venta archivo;
            system("cls");
            cout << "GANANCIA MENSUAL POR ANIO: " << endl;
            archivo.ganancia_x_mes_Anual();
            system("cls");
        }
        break;

        }
    }
}

void Menu::menu_backup()
{
    int op;
    bool menu_activo = true;
    system("cls");
    while (menu_activo)
    {
        system("cls");
        cout << "****BACKUP****" << endl;
        cout << " 1- Hacer copia de Seguridad" << endl;
        cout << " 2- Restaurar copia de Seguridad" << endl;
        cout << "-----------------" << endl;
        cout << " 0- SALIR" << endl;
        cin >> op;
        while (op < 0 || op>2)
        {
            rlutil::setColor(rlutil::RED);
            cout << "opcion incorrecta, vuelva a ingresar una opcion: ";
            rlutil::setColor(rlutil::BLACK);
            cin >> op;
        }
        switch (op)
        {
        case 0:
        {
            menu_activo = false;
        }
        break;
        case 1:
        {
            system("cls");
            Archivo_Venta ar;
            int cant = ar.cantidad_ventas();
            int cantA = ar.get_cantidad_Activa(cant);
            if (cantA > 0) {
                cout << "Hacer copia de seguridad" << endl;
                Archivo_bkp Backup;
                Backup.HacerCopiaDeSeguridad();
                cout << "Se realizo la copia de seguridad exitosamente..." << endl;
                system("pause");
            }
            else {
                cout << "NO HAY VENTAS PARA REALIZAR EL BACKUP" << endl;
                system("pause");
            }
        }
        break;
        case 2:
        {
            system("cls");
            Archivo_Venta ar;
            int cant = ar.cantidad_ventas();
            int cantA = ar.get_cantidad_Activa(cant);
            
                cout << "Restaurar copia de seguridad" << endl;
                Archivo_bkp Backup;
                if (Backup.getCantidadRegistros() > 0) {
                    Backup.RestaurarCopiaDeSeguridad();
                    cout << "Se restauro la copia de seguridad exitosamente..." << endl;
                }
                else {
                    cout << "No hay registros para restaurar" << endl;
                system("pause");
                }
            
            
            system("pause");
            }
        }
        break;
        }
    }
