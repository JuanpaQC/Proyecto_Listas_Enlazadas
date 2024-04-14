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
*        Funciones de Gestion de info         *
*              (abajo)  ↓↓↓↓                  *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void gestionClientes(NodoCliente*& listaClientes) {
    int opcion;
    while (true) {
        cout << " \n############################# Gestion de Clientes #############################\n " << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "1. Insertar cliente." << endl;
        cout << "2. Eliminar cliente." << endl;
        cout << "3. Modificar cliente." << endl;
        cout << "4. Mostrar clientes." << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opcion;
        switch (opcion) {
        case 0:
            cout << "Regresando al menu principal..." << endl;
            return;
        case 1: {
            Cliente nuevoCliente;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nuevoCliente.nombre;
            cout << "Ingrese el apellido del cliente: ";
            cin >> nuevoCliente.apellido;
            cout << "Ingrese la cedula del cliente: ";
            cin >> nuevoCliente.cedula;
            cout << "Ingrese la edad del cliente: ";
            cin >> nuevoCliente.edad;
            cout << "Ingrese la direccion del cliente: ";
            cin >> nuevoCliente.direccion;

            insertarCliente(listaClientes, nuevoCliente);
            break;
        }
        case 2: {
            int cedula;
            cout << "Ingrese la cedula del cliente que desea eliminar: ";
            cin >> cedula;
            eliminarCliente(listaClientes, cedula);
            break;
        }
        case 3: {
            int cedula;
            cout << "Ingrese la cedula del cliente que desea modificar: ";
            cin >> cedula;
            Cliente nuevoDato;
            cout << "Ingrese el nombre del cliente: ";
            cin >> nuevoDato.nombre;
            cout << "Ingrese el apellido del cliente: ";
            cin >> nuevoDato.apellido;
            cout << "Ingrese la cedula del cliente: ";
            cin >> nuevoDato.cedula;
            cout << "Ingrese la edad del cliente: ";
            cin >> nuevoDato.edad;
            cout << "Ingrese la direccion del cliente: ";
            cin >> nuevoDato.direccion;

            modificarCliente(listaClientes, cedula, nuevoDato);
            break;
        }
        case 4: {
            mostrarClientes(listaClientes);
            break;
        }
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}

void gestionNegocios(NodoNegocio*& negocios) {
    int opcion;
    while (true) {
        cout << " \n############################# Gestion de Negocios #############################\n " << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "1. Insertar negocio." << endl;
        cout << "2. Eliminar negocio." << endl;
        cout << "3. Modificar negocio." << endl;
        cout << "4. Mostrar negocios." << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opcion;
        switch (opcion) {
        case 0:
            cout << "Regresando al menu principal..." << endl;
            return;
        case 1: {
            Negocio nuevoNegocio;
            cout << "Ingrese el id del negocio: ";
            cin >> nuevoNegocio.id;
            cout << "Ingrese el nombre del negocio: ";
            cin >> nuevoNegocio.nombre;
            cout << "Ingrese el horario del negocio: ";
            cin >> nuevoNegocio.horario;
            cout << "Ingrese la ubicacion del negocio: ";
            cin >> nuevoNegocio.ubicacion;

            insertarNegocio(negocios, nuevoNegocio);
            break;
        }
        case 2: {
            int idNegocio;
            cout << "Ingrese el id del negocio que desea eliminar: ";
            cin >> idNegocio;
            eliminarNegocio(negocios, idNegocio);
            break;
        }
        case 3: {
            int idNegocio;
            cout << "Ingrese el id del negocio que desea modificar: ";
            cin >> idNegocio;
            Negocio nuevoDato;
            cout << "Ingrese el nombre del negocio: ";
            cin >> nuevoDato.nombre;
            cout << "Ingrese el horario del negocio: ";
            cin >> nuevoDato.horario;
            cout << "Ingrese la ubicacion del negocio: ";
            cin >> nuevoDato.ubicacion;

            modificarNegocio(negocios, idNegocio, nuevoDato);
            break;
        }
        case 4: {
            mostrarNegocios(negocios);
            break;
        }
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}

void gestionProductos(NodoProducto*& productos, vector<Ingrediente>& listaIngredientes) {
    int opcion;
    while (true) {
        cout << " \n############################# Gestion de Productos #############################\n " << endl;
        cout << "0. Regresar al menu principal" << endl;
        cout << "1. Insertar producto." << endl;
        cout << "2. Eliminar producto." << endl;
        cout << "3. Modificar producto." << endl;
        cout << "4. Mostrar productos." << endl;
        cout << "Ingrese la opcion que desea elegir: ";
        cin >> opcion;
        switch (opcion) {
        case 0:
            cout << "Regresando al menu principal..." << endl;
            return;
        case 1: {
            Producto nuevoProducto;
            cout << "Ingrese el nombre del producto: ";
            cin >> nuevoProducto.nombre;
            cout << "Ingrese el precio del producto: ";
            cin >> nuevoProducto.precio;

            insertarProducto(productos, nuevoProducto);
            break;
        }
        case 2: {
            std::string nombre;
            cout << "Ingrese el nombre del producto que desea eliminar: ";
            cin >> nombre;
            eliminarProducto(productos, nombre);
            break;
        }
        case 3: {
            std::string nombre;
            cout << "Ingrese el nombre del producto que desea modificar: ";
            cin >> nombre;
            Producto nuevoDato;
            cout << "Ingrese el nombre del producto: ";
            cin >> nuevoDato.nombre;
            cout << "Ingrese el precio del producto: ";
            cin >> nuevoDato.precio;

            modificarProducto(productos, nombre, nuevoDato);
            break;
        }
        case 4: {
            mostrarProductos(productos);
            break;
        }
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}

void gestionIngredientes(std::vector<Ingrediente>& listaIngredientes) {
    int opcion;
    do {
        std::cout << "\n===== GESTIÓN DE INGREDIENTES =====" << std::endl;
        std::cout << "1. Insertar ingrediente" << std::endl;
        std::cout << "2. Eliminar ingrediente" << std::endl;
        std::cout << "3. Modificar cantidad de ingrediente" << std::endl;
        std::cout << "4. Mostrar ingredientes" << std::endl;
        std::cout << "0. Regresar al menú principal" << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                Ingrediente nuevoIngrediente;
                std::cout << "Ingrese el nombre del ingrediente: ";
                std::cin >> nuevoIngrediente.nombre;
                std::cout << "Ingrese la cantidad del ingrediente: ";
                std::cin >> nuevoIngrediente.cantidad;

                listaIngredientes.push_back(nuevoIngrediente);
                break;
            }
            case 2: {
                std::string nombreIngrediente;
                std::cout << "Ingrese el nombre del ingrediente a eliminar: ";
                std::cin >> nombreIngrediente;
                auto it = std::find_if(listaIngredientes.begin(), listaIngredientes.end(), [nombreIngrediente](Ingrediente& i) {
                    return i.nombre == nombreIngrediente;
                });
                if (it != listaIngredientes.end()) {
                    listaIngredientes.erase(it);
                } else {
                    std::cout << "El ingrediente no existe." << std::endl;
                }
                break;
            }
            case 3: {
                std::string nombreIngrediente;
                double nuevaCantidad;
                std::cout << "Ingrese el nombre del ingrediente a modificar: ";
                std::cin >> nombreIngrediente;
                std::cout << "Ingrese la nueva cantidad del ingrediente: ";
                std::cin >> nuevaCantidad;

                Ingrediente* ingr = buscarIngrediente(listaIngredientes, nombreIngrediente);
                if (ingr != nullptr) {
                    modificarCantidadIngredienteGeneral(listaIngredientes, *ingr, nuevaCantidad);
                } else {
                    std::cout << "El ingrediente no existe." << std::endl;
                }
                break;
            }
            case 4:
                for (auto& i : listaIngredientes) {
                    std::cout << "Nombre: " << i.nombre << std::endl;
                    std::cout << "Cantidad: " << i.cantidad << std::endl;
                    std::cout << "------------------------" << std::endl;
                }
                break;
            case 0:
                std::cout << "Regresando al menú principal..." << std::endl;
                break;
            default:
                std::cout << "Opción inválida. Intente nuevamente." << std::endl;
                break;
        }
    } while (opcion != 0);
}

void registroVentas(NodoCliente*& clientes, NodoNegocio*& negocios, NodoProducto*& productos) {
    int cedulaCliente, idNegocio;
    std::string nombreProducto, fecha;
    double cantidad;
    std::cout << "Ingrese la cédula del cliente: ";
    std::cin >> cedulaCliente;
    std::cout << "Ingrese el id del negocio: ";
    std::cin >> idNegocio;
    std::cout << "Ingrese el nombre del producto: ";
    NodoCliente* cliente = buscarCliente(clientes, cedulaCliente);
    NodoNegocio* negocio = buscarNegocio(negocios, idNegocio);
    Producto* producto = buscarProducto(productos, nombreProducto);

    if (cliente != nullptr && negocio != nullptr && producto != nullptr) {
        registrarVenta(clientes, cedulaCliente, idNegocio, *producto, cantidad, fecha);
    } else {
        std::cout << "Cliente, negocio o producto no encontrado." << std::endl;
    }
}




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
    int opcion;
    cout << " \n############################# Menu Principal #############################\n " << endl;
    cout << "1. Gestion de Clientes" << endl;
    cout << "2. Gestion de Negocios" << endl;
    cout << "3. Gestion de Productos" << endl;
    cout << "4. Gestion de Ingredientes" << endl;
    cout << "5. Registro de Ventas" << endl;
    cout << "6. Actualizar informacion." << endl;
    cout << "7. Consultas. " << endl;
    cout << "8. Reportes. " << endl;
    cout << "0. Salir" << endl;
    cout << "Ingrese la opcion que desea elegir: ";
    cin >> opcion;

    switch(opcion){
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