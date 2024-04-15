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
    int cantidad;
    string fecha_vencimiento;

    //punteros
    Ingrediente* ingrediente;
    Inventario* sig;

    //constructores
    Inventario(int id, int cantidad, string fecha_vencimiento, Ingrediente* ingrediente) {
        this->id = id;
        this->cantidad = cantidad;
        this->fecha_vencimiento = fecha_vencimiento;
        this->ingrediente = ingrediente;
        this->sig = NULL;
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
    Cliente* sig;

    //constructores
    Cliente(string nombre, string apellido, int cedula, int edad, string direccion, Negocio* negocio, Inventario* inventario) {
        this->nombre = nombre;
        this->apellido = apellido;
        this->cedula = cedula;
        this->edad = edad;
        this->direccion = direccion;
        this->negocio = negocio;
        this->inventario = inventario;
        this->sig = NULL;
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

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *           El Sabor del Bosque               *
    *             (abajo)  ↓↓↓↓                   *
    *                                             *
    ***********************************************
    */


    //ventas
    VentasXDia* ventas_1 = new VentasXDia("01/01/2021", 10, producto_2);
    VentasXDia* ventas_2 = new VentasXDia("01/01/2021", 20, producto_3);
    VentasXDia* ventas_3 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_1->sig = ventas_2;
    ventas_2->sig = ventas_3;
    ventas_3->sig = NULL;

    //negocio
    Negocio* negocio_1 = new Negocio(132, "El Sabor del Bosque", "8:00am - 8:00pm", "San Jose", ventas_1);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *           La Cantina del Mar                *
    *            (abajo)  ↓↓↓↓                    *
    *                                             *
    ***********************************************
    */  

    //ventas
    VentasXDia* ventas_4 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_5 = new VentasXDia("01/01/2021", 20, producto_4);
    VentasXDia* ventas_6 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_4->sig = ventas_5;
    ventas_5->sig = ventas_6;
    ventas_6->sig = NULL;

    //negocio
    Negocio* negocio_2 = new Negocio(295, "La Cantina del Mar", "9:00am - 10:00pm", "Heredia", ventas_4);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *          La Casa de la Pizza                *
    *           (abajo)  ↓↓↓↓                     *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_7 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_8 = new VentasXDia("01/01/2021", 20, producto_3);
    VentasXDia* ventas_9 = new VentasXDia("01/01/2021", 30, producto_4);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_7->sig = ventas_8;
    ventas_8->sig = ventas_9;
    ventas_9->sig = NULL;

    //negocio
    Negocio* negocio_3 = new Negocio(295, "La Casa de la Pizza", "11:00am - 10:00pm", "Alajuela", ventas_7);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *         El Sabor de la Montaña              *
    *          (abajo)  ↓↓↓↓                      *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_10 = new VentasXDia("01/01/2021", 10, producto_4);
    VentasXDia* ventas_11 = new VentasXDia("01/01/2021", 20, producto_5);
    VentasXDia* ventas_12 = new VentasXDia("01/01/2021", 30, producto_1);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_10->sig = ventas_11;
    ventas_11->sig = ventas_12;
    ventas_12->sig = NULL;


    //negocio
    Negocio* negocio_4 = new Negocio(295, "El Sabor de la Montaña", "10:00am - 10:00pm", "Cartago", ventas_10);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *        El Sabor de la Montaña               *
    *         (abajo)  ↓↓↓↓                       *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_13 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_14 = new VentasXDia("01/01/2021", 20, producto_5);
    VentasXDia* ventas_15 = new VentasXDia("01/01/2021", 30, producto_3);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_13->sig = ventas_14;
    ventas_14->sig = ventas_15;
    ventas_15->sig = NULL;

    //negocio
    Negocio* negocio_5 = new Negocio(295, "El Sabor de la Montaña", "10:00am - 10:00pm", "Limon", ventas_13);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *           El Rincón del Chef                *
    *           (abajo)  ↓↓↓↓                     *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_16 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_17 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_18 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_16->sig = ventas_17;
    ventas_17->sig = ventas_18;
    ventas_18->sig = NULL;

    //negocio
    Negocio* negocio_6 = new Negocio(295, "El Rincón del Chef", "10:00am - 10:00pm", "Guanacaste", ventas_16);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *          Sabores del Mundo                  *
    *          (abajo)  ↓↓↓↓                      *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_19 = new VentasXDia("01/01/2021", 10, producto_3);
    VentasXDia* ventas_20 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_21 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_19->sig = ventas_20;
    ventas_20->sig = ventas_21;
    ventas_21->sig = NULL;

    //negocio
    Negocio* negocio_7 = new Negocio(295, "Sabores del Mundo", "10:00am - 10:00pm", "Puntarenas", ventas_19);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *         El Jardín Secreto                   *
    *         (abajo)  ↓↓↓↓                       *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_22 = new VentasXDia("01/01/2021", 10, producto_4);
    VentasXDia* ventas_23 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_24 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_22->sig = ventas_23;
    ventas_23->sig = ventas_24;
    ventas_24->sig = NULL;

    //negocio
    Negocio* negocio_8 = new Negocio(295, "El Jardín Secreto", "10:00am - 10:00pm", "Guanacaste", ventas_22);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *        La Parrilla del Valle                *
    *        (abajo)  ↓↓↓↓                        *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_25 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_26 = new VentasXDia("01/01/2021", 20, producto_4);
    VentasXDia* ventas_27 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_25->sig = ventas_26;
    ventas_26->sig = ventas_27;
    ventas_27->sig = NULL;

    //negocio
    Negocio* negocio_9 = new Negocio(295, "La Parrilla del Valle", "10:00am - 10:00pm", "San Jose", ventas_25);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *       La Taberna del Duende                 *
    *      (abajo)  ↓↓↓↓                          *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_28 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_29 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_30 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_28->sig = ventas_29;
    ventas_29->sig = ventas_30;
    ventas_30->sig = NULL;

    //negocio
    Negocio* negocio_10 = new Negocio(295, "La Taberna del Duende", "10:00am - 10:00pm", "San Carlos", ventas_28);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *      Rincón Gastronómico                    *
    *     (abajo)  ↓↓↓↓                           *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_31 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_32 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_33 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_31->sig = ventas_32;
    ventas_32->sig = ventas_33;
    ventas_33->sig = NULL;

    //negocio
    Negocio* negocio_11 = new Negocio(295, "La Cabaña del Chef", "10:00am - 10:00pm", "San Ramon", ventas_31);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *     Delicias del Sur                        *
    *   (abajo)  ↓↓↓↓                             *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_34 = new VentasXDia("01/01/2021", 10, producto_3);
    VentasXDia* ventas_35 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_36 = new VentasXDia("01/01/2021", 30, producto_4);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_34->sig = ventas_35;
    ventas_35->sig = ventas_36;
    ventas_36->sig = NULL;

    //negocio
    Negocio* negocio_12 = new Negocio(295, "Delicias del Sur", "10:00am - 10:00pm", "San Isidro", ventas_34);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *    Bocado Celestial                         *
    *   (abajo)  ↓↓↓↓                             *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_37 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_38 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_39 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_37->sig = ventas_38;
    ventas_38->sig = ventas_39;
    ventas_39->sig = NULL;

    //negocio
    Negocio* negocio_13 = new Negocio(295, "Bocado Celestial", "10:00am - 10:00pm", "San Isidro", ventas_37);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *   Cocina de Autor                           *
    *   (abajo)  ↓↓↓↓                             *
    *                                             *
    ***********************************************
    */  

    //ventas
    VentasXDia* ventas_40 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_41 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_42 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_40->sig = ventas_41;
    ventas_41->sig = ventas_42;
    ventas_42->sig = NULL;

    //negocio
    Negocio* negocio_14 = new Negocio(295, "Cocina de Autor", "10:00am - 10:00pm", "San Isidro", ventas_40);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*  
    ***********************************************
    *                                             *
    *  El Fogón del Pueblo                        *
    * (abajo)  ↓↓↓↓                               *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_43 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_44 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_45 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_43->sig = ventas_44;
    ventas_44->sig = ventas_45;
    ventas_45->sig = NULL;

    //negocio
    Negocio* negocio_15 = new Negocio(295, "La Cabaña del Chef", "10:00am - 10:00pm", "San Isidro", ventas_43);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    * Café de la Plaza                            *
    * (abajo)  ↓↓↓↓                               *
    *                                             *
    ***********************************************
    */
   
    //ventas    
    VentasXDia* ventas_46 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_47 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_48 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_46->sig = ventas_47;
    ventas_47->sig = ventas_48;
    ventas_48->sig = NULL;

    //negocio
    Negocio* negocio_16 = new Negocio(295, "Café de la Plaza", "10:00am - 10:00pm", "San Isidro", ventas_46);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *  La Esquina Deliciosa                       *
    * (abajo)  ↓↓↓↓                               *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_49 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_50 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_51 = new VentasXDia("01/01/2021", 30, producto_5);


    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto
    ventas_49->sig = ventas_50;
    ventas_50->sig = ventas_51;
    ventas_51->sig = NULL;

    //negocio
    Negocio* negocio_17 = new Negocio(295, "La Esquina Deliciosa", "10:00am - 10:00pm", "San Isidro", ventas_49);

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*
    ***********************************************
    *                                             *
    *  El Rincón de los Sabores                   *
    * (abajo)  ↓↓↓↓                               *
    *                                             *
    ***********************************************
    */

    //ventas
    VentasXDia* ventas_52 = new VentasXDia("01/01/2021", 10, producto_1);
    VentasXDia* ventas_53 = new VentasXDia("01/01/2021", 20, producto_2);
    VentasXDia* ventas_54 = new VentasXDia("01/01/2021", 30, producto_5);

    //relaciones entre nodos de las cantidades de cada una de las cantidades que requiere este producto 
    ventas_52->sig = ventas_53;
    ventas_53->sig = ventas_54;
    ventas_54->sig = NULL;

    //negocio
    Negocio* negocio_18 = new Negocio(295, "El Rincón de los Sabores", "10:00am - 10:00pm", "San Isidro", ventas_52);


    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //relaciones de los nodos de los negocios

    negocio_1->sig = negocio_2;
    negocio_2->sig = negocio_3;

    negocio_4->sig = negocio_5;
    negocio_5->sig = negocio_6;

    negocio_7->sig = negocio_8;
    negocio_8->sig = negocio_9;

    negocio_10->sig = negocio_11;
    negocio_11->sig = negocio_12;

    negocio_13->sig = negocio_14;
    negocio_14->sig = negocio_15;

    negocio_16->sig = negocio_17;
    negocio_17->sig = negocio_18;

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    //inventario cliente 1
    Inventario* inventario_1 = new Inventario(1, 2000, "01/01/2021", ingrediente_1);
    Inventario* inventario_2 = new Inventario(2, 1000, "01/01/2021", ingrediente_2);
    Inventario* inventario_3 = new Inventario(3, 500, "01/01/2021", ingrediente_3);
    Inventario* inventario_4 = new Inventario(4, 200, "01/01/2021", ingrediente_4);

    //relaciones entre nodos de los inventarios
    inventario_1->sig = inventario_2;
    inventario_2->sig = inventario_3;
    inventario_3->sig = inventario_4;
    inventario_4->sig = NULL;


    //inventario cliente 2
    Inventario* inventario_5 = new Inventario(5, 439, "01/01/2021", ingrediente_5);
    Inventario* inventario_6 = new Inventario(6, 384, "01/01/2021", ingrediente_6);
    Inventario* inventario_7 = new Inventario(7, 123, "01/01/2021", ingrediente_7);

    //relaciones entre nodos de los inventarios
    inventario_5->sig = inventario_6;
    inventario_6->sig = inventario_7;
    inventario_7->sig = NULL;


    //inventario cliente 3
    Inventario* inventario_8 = new Inventario(8, 20, "01/01/2021", ingrediente_8);
    Inventario* inventario_9 = new Inventario(9, 40, "01/01/2021", ingrediente_9);
    Inventario* inventario_10 = new Inventario(10, 56, "01/01/2021", ingrediente_10);

    //relaciones entre nodos de los inventarios
    inventario_8->sig = inventario_9;
    inventario_9->sig = inventario_10;
    inventario_10->sig = NULL;


    //inventario cliente 4
    Inventario* inventario_11 = new Inventario(11, 405, "01/01/2021", ingrediente_11);
    Inventario* inventario_12 = new Inventario(12, 344, "01/01/2021", ingrediente_12);
    Inventario* inventario_13 = new Inventario(13, 50, "01/01/2021", ingrediente_13);

    //relaciones entre nodos de los inventarios
    inventario_11->sig = inventario_12;
    inventario_12->sig = inventario_13;
    inventario_13->sig = NULL;


    //inventario cliente 5
    Inventario* inventario_14 = new Inventario(14, 123, "01/01/2021", ingrediente_14);
    Inventario* inventario_15 = new Inventario(15, 432, "01/01/2021", ingrediente_15);
    Inventario* inventario_16 = new Inventario(16, 23, "01/01/2021", ingrediente_16);

    //relaciones entre nodos de los inventarios
    inventario_14->sig = inventario_15;
    inventario_15->sig = inventario_16;
    inventario_16->sig = NULL;

    //clientes
    Cliente* cliente_1 = new Cliente("Armando", "Perez", 123456789, 25, "San Jose", negocio_1, inventario_1);
    Cliente* cliente_2 = new Cliente("Juanpa", "Gonzalez", 987654321, 30, "Heredia", negocio_2, inventario_5);
    Cliente* cliente_3 = new Cliente("Yank", "Jimenez", 123456789, 25, "San Jose", negocio_3, inventario_8);
    Cliente* cliente_4 = new Cliente("Emma", "Gutierrez", 987654321, 30, "Heredia", negocio_4, inventario_11);
    Cliente* cliente_5 = new Cliente("Dylan", "Jimenez", 123456789, 25, "San Jose", negocio_5, inventario_14);


    //relaciones entre nodos de los clientes
    cliente_1->sig = cliente_2;
    cliente_2->sig = cliente_3;
    cliente_3->sig = cliente_4;
    cliente_4->sig = cliente_5;
    cliente_5->sig = cliente_4;
    cliente_4->sig = cliente_3;
    cliente_3->sig = cliente_2;
    cliente_2->sig = cliente_1;
}

    /*
    ***********************************************
    *                                             *
    *  Funciones de Reportes                      *
    * (abajo)  ↓↓↓↓                               *
    *                                             *
    ***********************************************
    */