#include <iostream>
#include <string>
#include <vector>
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

NodoCliente* buscarCliente(NodoCliente* inicio, int cedula);
NodoNegocio* buscarNegocio(NodoNegocio* inicio, int idNegocio);
Producto* buscarProducto(NodoProducto* inicio, std::string nombre);
Ingrediente* buscarIngrediente(vector<Ingrediente>& listaIngredientes, string nombre);

void insertarCliente(NodoCliente*& inicio, Cliente nuevoCliente);
void eliminarCliente(NodoCliente*& inicio, int cedula);
void modificarCliente(NodoCliente* inicio, int cedula, Cliente nuevoDato);
void mostrarClientes(NodoCliente* inicio);

void insertarNegocio(NodoNegocio*& inicio, Negocio nuevoNegocio);
void eliminarNegocio(NodoNegocio*& inicio, int idNegocio);
void modificarNegocio(NodoNegocio* inicio, int idNegocio, Negocio nuevoDato);
void mostrarNegocios(NodoNegocio* inicio);

void insertarProducto(NodoProducto*& inicio, Producto nuevoProducto);
void eliminarProducto(NodoProducto*& inicio, std::string nombre);
void modificarProducto(NodoProducto* inicio, std::string nombre, Producto nuevoDato);
void mostrarProductos(NodoProducto* inicio);

void agregarIngredienteAProducto(NodoProducto*& inicio, Producto prod, Ingrediente ingr, double cantidad, std::string unidad);
void modificarCantidadIngredienteProducto(NodoProducto*& inicio, Producto prod, Ingrediente ingr, double nuevaCantidad);
void modificarCantidadIngredienteGeneral(vector<Ingrediente>& listaIngredientes, Ingrediente ingr, double nuevaCantidad);

void registrarVenta(NodoCliente*& clientes, int cedulaCliente, int idNegocio, Producto prod, double cantidad, std::string fecha);
bool validarInventario(NodoInventario* inventario, Producto prod, double cantidad);
void actualizarInventario(NodoInventario*& inventario, Producto prod, double cantidad);

Cliente obtenerClienteMasNegocios(NodoCliente* inicio);
Cliente obtenerClienteMasInventario(NodoCliente* inicio);
Cliente obtenerClienteMasVentasGeneral(NodoCliente* inicio);
Cliente obtenerClienteMasVentasFecha(NodoCliente* inicio, std::string fecha);

int contarNegocios(NodoNegocio* inicio);
double calcularCantidadInventario(NodoInventario* inicio);
double calcularCantidadVentasGeneral(NodoNegocio* inicio);
double calcularCantidadVentasFecha(NodoNegocio* inicio, std::string fecha);

void cargarDatos(NodoCliente*& clientes, NodoProducto*& productos, std::vector<Ingrediente>& listaIngredientes);

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









/*
***********************************************
*                                             *
*        Menu Principal (abajo)  ↓↓↓↓         *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


void menu_p(){
    cout << " \n############################# Menu Principal #############################\n " << endl;
    cout << "0. Salir" << endl;
    cout << "1. Actualizar informacion." << endl;
    cout << "2. Consultas. " << endl;
    cout << "3. Reportes. " << endl;
}


/*
***********************************************
*                                             *
*   Menu para Actualizar Info (abajo)  ↓↓↓↓   *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


void menu_a(){
    int opa;
    while(true){
        cout << " \n############################# Menu Actualizar Informacion #############################\n " << endl;
        cout << "0. Regresar" << endl;
        cout << "1. Opcion 1." << endl;
        cout << "2. Opcion 2." << endl;
        cout << "3. Opcion 3." << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opa;
        switch(opa){
            case 0:
                return;
            case 1:
                // Llamada de la funcion
                break;
            case 2:
                // Llamada de la funcion
                break;
            case 3:
                // Llamada de la funcion
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }
}

/*
***********************************************
*                                             *
*        Menu de Consultas (abajo)  ↓↓↓↓      *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void menu_c(){
    int opc;
    while(true){
        cout << " \n############################# Menu de Consultas #############################\n " << endl;
        cout << "0. Regresar" << endl;
        cout << "1. Cual es el cliente con mas negocios?"<< endl;
        cout << "2. Cual es el cliente con mas inventario en general?" << endl;
        cout << "3. Cual es el cliente que vende mas en general?" << endl;
        cout << "4. Cual es el cliente que vende mas en general, en una fecha X, de acuerdo con el precio?" << endl;
        cout << "5. Cual es el cliente que vende mas en general un producto X, en una fecha X, de acuerdo con el precio?" << endl;
        cout << "6. Cual es el producto mas vendido en toda la historia?" << endl;
        cout << "7. Cual es el ingrediente que mas se consume, segun el inventario actual de todos los clientes?" << endl;
        cout << "8. Cuales son los 3 ingredientes mas requeridos en cantidad de veces según los productos insertados?" << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opc;
        switch(opc){
            case 0:
                return;
            case 1:
                // Llamada de la funcion
                break;
            case 2:
                // Llamada de la funcion
                break;
            case 3:
                // Llamada de la funcion
                break;
            case 4:
                // Llamada de la funcion
                break;
            case 5:
                // Llamada de la funcion
                break;
            case 6:
                // Llamada de la funcion
                break;
            case 7:
                // Llamada de la funcion
                break;
            case 8:
                // Llamada de la funcion
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }
}

/*
***********************************************
*                                             *
*        Menu de Reportes (abajo)  ↓↓↓↓       *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void menu_r(){
    int opr;
    while(true){
        cout << " \n############################# Menu de Reportes #############################\n " << endl;
        cout << "0. Regresar" << endl;
        cout << "1. Imprimir la lista de clientes en orden ascendente y en orden descendente según el apellido." << endl;
        cout << "2. Imprimir los negocios de un cliente X." << endl;
        cout << "3. Imprimir la lista de ingredientes." << endl;
        cout << "4. Imprimir la lista de productos." << endl;
        cout << "5. Imprimir los ingredientes de un producto X." << endl;
        cout << "6. Imprimir el inventario de un cliente X." << endl;
        cout << "7. Imprimir el inventario vencido a partir de una fecha X." << endl;
        cout << "8. Imprimir las todas ventas de una fecha X, para un cliente Y." << endl;
        cout << "9. Imprimir los inventarios en 0." << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opr;
        switch(opr){
            case 0:
                return;
            case 1:
                // Llamada de la funcion
                break;
            case 2:
                // Llamada de la funcion
                break;
            case 3:
                // Llamada de la funcion
                break;
            case 4:
                // Llamada de la funcion
                break;
            case 5:
                // Llamada de la funcion
                break;
            case 6:
                // Llamada de la funcion
                break;
            case 7:
                // Llamada de la funcion
                break;
            case 8:
                // Llamada de la funcion
                break;
            case 9:
                // Llamada de la funcion
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }
}


/*
***********************************************
*                                             *
*        Main principal (abajo)  ↓↓↓↓         *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


int main(){
    int op;
    while(true){
        menu_p();
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> op;
        switch(op){
            case 0:
                return 0;
            case 1:
                menu_a();
                break;
            case 2:
                menu_c();
                break;
            case 3:
                menu_r();
                break;
            default:
                cout << "Opcion no valida. Intente de nuevo." << endl;
                break;
        }
    }
return 0;
}