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

struct Inventario {
    //variables
    int id;
    string nombre;
    string fecha_vencimiento;

    //punteros
    Ingrediente* ingrediente;

    //constructores
    Inventario(int id, string nombre, string fecha_vencimiento, Ingrediente* ingrediente) {
        this->id = id;
        this->nombre = nombre;
        this->fecha_vencimiento = fecha_vencimiento;
        this->ingrediente = ingrediente;
    }
};


struct Cliente {
    //variables
    string nombre;
    string apellido;
    int cedula;
    int edad;
    string direccion;

    //punteros
    Negocio* negocio;
    Inventario* inventario;

    //constructores
    Cliente(string nombre, string apellido, int cedula, int edad, string direccion, Negocio* negocio, Inventario* inventario) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->cedula = cedula;
        this->edad = edad;
        this->direccion = direccion;
        this->negocio = negocio;
        this->inventario = inventario;
    }
};

struct Negocio {
    //variables
    int id;
    string nombre;
    string horario;
    string ubicacion;

    //punteros
    VentasXDia* ventas;
    Negocio* sig;

    //constructores
    Negocio(int id, string nombre, string horario, string ubicacion, VentasXDia* ventas) {
        this->id = id;
        this->nombre = nombre;
        this->horario = horario;
        this->ubicacion = ubicacion;
        this->ventas = ventas;
        this->sig = NULL;
    }
};


struct Cantidad {
    //variables
    int cantidad;
    string unidad;

    //punteros
    Ingrediente* ingrediente;
    Cantidad* sig;

    //constructores
    Cantidad(int cantidad, string unidad, Ingrediente* ingrediente) {
        this->cantidad = cantidad;
        this->unidad = unidad;
        this->ingrediente = ingrediente;
        this->sig = NULL;
    }
};


struct Producto {
    //variables
    std::string nombre;
    double precio;

    //punteros
    Cantidad* cantidad;
    Producto* sig;

    //constructores
    Producto(std::string nombre, double precio, Cantidad* cantidad) {
        this->nombre = nombre;
        this->precio = precio;
        this->cantidad = cantidad;
    }
};


struct VentasXDia {
    //variables
    string fecha;
    int cantidad_productos_vendidos;
    
    //punteros
    Producto* product;
    VentasXDia* sig;

    //constructores
    VentasXDia(string fecha, int cantidad_productos_vendidos, Producto* product) {
        this->fecha = fecha;
        this->cantidad_productos_vendidos = cantidad_productos_vendidos;
        this->product = product;
        this->sig = NULL;
    }
};



struct Ingrediente {
    //variables
    string nombre;
    double cantidad;
    string unidad;

    //punteros
    Ingrediente* sig;

    //constructores
    Ingrediente(string nombre, double cantidad, string unidad) {
        this->nombre = nombre;
        this->cantidad = cantidad;
        this->unidad = unidad;
        this->sig = NULL;
    }
};


/*
***********************************************
*                                             *
*        Funcion de Cargar Datos              *
*              (abajo)  ↓↓↓↓                  *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

Cliente* cliente_1;
Producto* producto_1;
Ingrediente* ingrediente_1;


void Cargar_Datos(){

    /*
    ***********************************************
    *                                             *
    *               Hamburguesas                  *
    *              (abajo)  ↓↓↓↓                  *
    *                                             *
    ***********************************************
    */

    //ingredientes
    Ingrediente* ingrediente_1 = new Ingrediente("Pan", 10, "unidades");
    Ingrediente* ingrediente_2 = new Ingrediente("Queso Amarillo", 50, "tajadas");
    Ingrediente* ingrediente_3 = new Ingrediente("Lechuga", 15, "hojas");
    Ingrediente* ingrediente_4 = new Ingrediente("Tortas de Carne", 10, "unidades");

    //cantidad (sublista de ingredientes)
    Cantidad* cantidad_H1 = new Cantidad(1, "unidad", ingrediente_1);
    Cantidad* cantidad_H2 = new Cantidad(1, "tajadas", ingrediente_2);
    Cantidad* cantidad_H3 = new Cantidad(2, "hojas", ingrediente_3);
    Cantidad* cantidad_H4 = new Cantidad(1, "unidad", ingrediente_4);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    cantidad_H1->sig = cantidad_H2;
    cantidad_H2->sig = cantidad_H3;
    cantidad_H3->sig = cantidad_H4;
    cantidad_H4->sig = NULL;

    /*
    ***********************************************
    *                                             *
    *             Cafe con leche                  *
    *              (abajo)  ↓↓↓↓                  *
    *                                             *
    ***********************************************
    */

    //ingredientes
    Ingrediente* ingrediente_5 = new Ingrediente("Azucar", 50, "paquetes");
    Ingrediente* ingrediente_6 = new Ingrediente("Cafe Molido", 500, "gramos");
    Ingrediente* ingrediente_7 = new Ingrediente("Leche", 300, "militros");

    //cantidad
    Cantidad* cantidad_CL1 = new Cantidad(2, "paquete", ingrediente_5);
    Cantidad* cantidad_CL2 = new Cantidad(20, "gramos", ingrediente_6);
    Cantidad* cantidad_CL3 = new Cantidad(100, "militros", ingrediente_7);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    cantidad_CL1->sig = cantidad_CL2;
    cantidad_CL2->sig = cantidad_CL3;
    cantidad_CL3->sig = NULL;



    /*
    ***********************************************
    *                                             *
    *                 Ceviche                     *
    *              (abajo)  ↓↓↓↓                  *
    *                                             *
    ***********************************************
    */    

    //ingredientes
    Ingrediente* ingrediente_8 = new Ingrediente("Pescado", 20, "unidades");
    Ingrediente* ingrediente_9 = new Ingrediente("Limones", 15, "unidades");
    Ingrediente* ingrediente_10 = new Ingrediente("Cebolla", 10, "unidades");

    //cantidad
    Cantidad* cantidad_CE1 = new Cantidad(1, "unidad", ingrediente_8);
    Cantidad* cantidad_CE2 = new Cantidad(2, "unidades", ingrediente_9);
    Cantidad* cantidad_CE3 = new Cantidad(1, "unidad", ingrediente_10);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    cantidad_CE1->sig = cantidad_CE2;
    cantidad_CE2->sig = cantidad_CE3;
    cantidad_CE3->sig = NULL;


    /*
    ***********************************************
    *                                             *
    *               Gallo Pinto                   *
    *              (abajo)  ↓↓↓↓                  *
    *                                             *
    ***********************************************
    */   

    //ingredientes
    Ingrediente* ingrediente_11 = new Ingrediente("Arroz", 3000, "gramos");
    Ingrediente* ingrediente_12 = new Ingrediente("Frijoles", 3000, "gramos");
    Ingrediente* ingrediente_13 = new Ingrediente("Huevos", 15, "unidades");

    //cantidad
    Cantidad* cantidad_GP1 = new Cantidad(200, "gramos", ingrediente_11);
    Cantidad* cantidad_GP2 = new Cantidad(200, "gramos", ingrediente_12);
    Cantidad* cantidad_GP3 = new Cantidad(1, "unidad", ingrediente_13);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    cantidad_GP1->sig = cantidad_GP2;
    cantidad_GP2->sig = cantidad_GP3;
    cantidad_GP3->sig = NULL;


    /*
    ***********************************************
    *                                             *
    *              Pizza                          *
    *             (abajo)  ↓↓↓↓                   *
    *                                             *
    ***********************************************
    */

    //ingredientes
    Ingrediente* ingrediente_14 = new Ingrediente("Harina", 1000, "gramos");
    Ingrediente* ingrediente_15 = new Ingrediente("Queso Mozarella", 900, "gramos");
    Ingrediente* ingrediente_16 = new Ingrediente("Salsa de Tomate", 10, "unidades");

    //cantidad
    Cantidad* cantidad_PI1 = new Cantidad(200, "gramos", ingrediente_14);
    Cantidad* cantidad_PI2 = new Cantidad(200, "gramos", ingrediente_15);
    Cantidad* cantidad_PI3 = new Cantidad(1, "unidad", ingrediente_16);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    cantidad_PI1->sig = cantidad_PI2;
    cantidad_PI2->sig = cantidad_PI3;
    cantidad_PI3->sig = NULL;


    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //relacion de ingredientes
    ingrediente_1->sig = ingrediente_2;
    ingrediente_2->sig = ingrediente_3;
    ingrediente_3->sig = ingrediente_4;

    ingrediente_5->sig = ingrediente_6;
    ingrediente_6->sig = ingrediente_7;

    ingrediente_8->sig = ingrediente_9;
    ingrediente_9->sig = ingrediente_10;

    ingrediente_11->sig = ingrediente_12;
    ingrediente_12->sig = ingrediente_13;

    ingrediente_14->sig = ingrediente_15;
    ingrediente_15->sig = ingrediente_16;



    //productos
    Producto* producto_1 = new Producto("Hamburguesa", 3000, cantidad_H1);
    Producto* producto_2 = new Producto("Cafe con Leche", 600, cantidad_CL1);
    Producto* producto_3 = new Producto("Ceviche", 2000, cantidad_CE1);
    Producto* producto_4 = new Producto("Gallo Pinto", 1500, cantidad_GP1);
    Producto* producto_5 = new Producto("Pizza", 7500, cantidad_PI1);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    producto_1->sig = producto_2;
    producto_2->sig = producto_3;
    producto_3->sig = producto_4;
    producto_4->sig = producto_5;
    producto_5->sig = producto_1;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //negocios 







}





