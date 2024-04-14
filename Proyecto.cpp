#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
***********************************************
*                                             *
*      Structs de las listas (abajo)  ↓↓↓↓    *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

struct Cliente {
    std::string nombre;
    std::string apellido;
    int cedula;
    int edad;
    std::string direccion;
    struct NodoNegocio* negocios;
    struct NodoInventario* inventario;
};

struct Negocio {
    int id;
    std::string nombre;
    std::string horario;
    std::string ubicacion;
    struct NodoVenta* ventas;
};

struct Producto {
    std::string nombre;
    double precio;
    struct NodoIngredienteProducto* ingredientes;
};

struct Ingrediente {
    std::string nombre;
    double cantidad;
    std::string unidad;
};

struct NodoCliente {
    Cliente datos;
    NodoCliente* siguiente;
    NodoCliente* anterior;
};

struct NodoNegocio {
    Negocio datos;
    NodoNegocio* siguiente;
};

struct NodoProducto {
    Producto datos;
    NodoProducto* siguiente;
};

struct NodoIngredienteProducto {
    double cantidad;
    std::string unidad;
    Ingrediente* ingrediente;
    NodoIngredienteProducto* siguiente;
};

struct NodoVenta {
    std::string fecha;
    double cantidad;
    Producto* producto;
    NodoVenta* siguiente;
};

struct NodoInventario {
    double cantidad;
    std::string fechaVencimiento;
    Ingrediente* ingrediente;
    NodoInventario* siguiente;
};


/*
***********************************************
*                                             *
*        Prototipos de las funciones          *
*              (abajo)  ↓↓↓↓                  *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

