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
                auto it = find_if(listaIngredientes.begin(), listaIngredientes.end(), [nombreIngrediente](Ingrediente& i) { // Modify the lambda function to capture 'nombreIngrediente' by value
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
*           Funciones Auxiliares              *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

NodoCliente* buscarCliente(NodoCliente* inicio, int cedula) {
    NodoCliente* aux = inicio;
    while (aux != nullptr && aux->datos.cedula != cedula) {
        aux = aux->siguiente;
    }
    return aux;
}

NodoNegocio* buscarNegocio(NodoNegocio* inicio, int idNegocio) {
    NodoNegocio* aux = inicio;
    while (aux != nullptr && aux->datos.id != idNegocio) {
        aux = aux->siguiente;
    }
    return aux;
}

Producto* buscarProducto(NodoProducto* inicio, std::string nombre) {
    NodoProducto* aux = inicio;
    while (aux != nullptr && aux->datos.nombre != nombre) {
        aux = aux->siguiente;
    }
    if (aux != nullptr) {
        return &(aux->datos);
    }
    return nullptr;
}

Ingrediente* buscarIngrediente(vector<Ingrediente>& listaIngredientes, string nombre) {
    for (auto& i : listaIngredientes) {
        if (i.nombre == nombre) {
            return &i;
        }
    }
    return nullptr;
}

/*
***********************************************
*                                             *
*           Funciones de Cliente              *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void insertarCliente(NodoCliente*& inicio, Cliente nuevoCliente) {
    NodoCliente* nuevo = new NodoCliente;
    nuevo->datos = nuevoCliente;
    nuevo->siguiente = nullptr;
    nuevo->anterior = nullptr;

    if (inicio == nullptr) {
        inicio = nuevo;
    } 
    inicio = nuevo;
}

void eliminarCliente(NodoCliente*& inicio, int cedula) {

    if (inicio == nullptr) {
        return;
    }

    if (inicio->datos.cedula == cedula) {
        NodoCliente* aux = inicio;
        inicio = inicio->siguiente;
        if (inicio != nullptr) {
            inicio->anterior = nullptr;
        }
        delete aux;
        cout << "Cliente eliminado." << endl;
        return;
    }

    NodoCliente* aux = inicio;
    while (aux->siguiente != nullptr && aux->siguiente->datos.cedula != cedula) {
        aux = aux->siguiente;
    }

    if (aux->siguiente == nullptr) {
        cout << "Cliente no encontrado." << endl;
        return;
    }

    NodoCliente* temp = aux->siguiente;
    aux->siguiente = temp->siguiente;
    if (temp->siguiente != nullptr) {
        temp->siguiente->anterior = aux;
    }
    delete temp;
    cout << "Cliente eliminado." << endl;
}

void modificarCliente(NodoCliente* inicio, int cedula, Cliente nuevoDato) {
    
    if(inicio == nullptr){
        cout << "No hay clientes registrados." << endl;
        return;
    }

    NodoCliente* aux = inicio;
    while (aux != nullptr && aux->datos.cedula != cedula) {
        aux = aux->siguiente;
    }

    if (aux == nullptr) {
        cout << "Cliente no encontrado." << endl;
        return;
    }

    aux->datos = nuevoDato;
    cout << "Cliente modificado." << endl;
}

void mostrarClientes(NodoCliente* inicio) {

    if (inicio == nullptr)
    {
        cout << "No hay clientes registrados." << endl;
        return;
    }

    NodoCliente* aux = inicio;
    while (aux != nullptr) {
        cout << "Nombre: " << aux->datos.nombre << endl;
        cout << "Apellido: " << aux->datos.apellido << endl;
        cout << "Cedula: " << aux->datos.cedula << endl;
        cout << "Edad: " << aux->datos.edad << endl;
        cout << "Direccion: " << aux->datos.direccion << endl;
        cout << "------------------------" << endl;
        aux = aux->siguiente;
    }
}

/*
***********************************************
*                                             *
*           Funciones de Negocio              *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


void insertarNegocio(NodoNegocio*& inicio, Negocio nuevoNegocio) {

    NodoNegocio* nuevoNodo = new NodoNegocio;
    nuevoNodo->datos = nuevoNegocio;
    nuevoNodo->siguiente = nullptr;


    if (inicio == nullptr) {
        inicio = nuevoNodo;
        cout << "Negocio insertado." <<endl;
        return;
    }


    nuevoNodo->siguiente = inicio;
    inicio = nuevoNodo;
    cout << "Negocio insertado al principio de la lista." <<endl;
}


void eliminarNegocio(NodoNegocio*& inicio, int idNegocio) {

    if (inicio == nullptr) {
        cout << "La lista de negocios está vacía." <<endl;
        return;
    }


    if (inicio->datos.id == idNegocio) {
        NodoNegocio* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        cout << "Negocio eliminado." <<endl;
        return;
    }


    NodoNegocio* temp = inicio;
    while (temp->siguiente != nullptr && temp->siguiente->datos.id != idNegocio) {
        temp = temp->siguiente;
    }


    if (temp->siguiente == nullptr) {
        cout << "Negocio no encontrado." <<endl;
        return;
    }


    NodoNegocio* nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente;
    delete nodoAEliminar;
    cout << "Negocio eliminado." <<endl;
}


void modificarNegocio(NodoNegocio* inicio, int idNegocio, Negocio nuevoDato) {

    if (inicio == nullptr) {
        cout << "La lista de negocios está vacía." <<endl;
        return;
    }


    NodoNegocio* temp = inicio;
    while (temp != nullptr && temp->datos.id != idNegocio) {
        temp = temp->siguiente;
    }


    if (temp == nullptr) {
        std::cout << "Negocio no encontrado." << std::endl;
        return;
    }

    temp->datos = nuevoDato;
    cout << "Negocio modificado." <<endl;
}

void mostrarNegocios(NodoNegocio* inicio) {

    if (inicio == nullptr) {
        cout << "La lista de negocios está vacía." <<endl;
        return;
    }


    NodoNegocio* temp = inicio;
    while (temp != nullptr) {
        cout << "ID: " << temp->datos.id <<endl;
        cout << "Nombre: " << temp->datos.nombre <<endl;
        cout << "Horario: " << temp->datos.horario <<endl;
        cout << "Ubicación: " << temp->datos.ubicacion <<endl;
        cout << "------------------------" <<endl;
        temp = temp->siguiente;
    }
}

/*
***********************************************
*                                             *
*           Funciones de Producto             *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


void insertarProducto(NodoProducto*& inicio, Producto nuevoProducto) {

    NodoProducto* nuevoNodo = new NodoProducto;
    nuevoNodo->datos = nuevoProducto;
    nuevoNodo->siguiente = nullptr;


    if (inicio == nullptr) {
        inicio = nuevoNodo;
        cout << "Producto insertado." <<endl;
        return;
    }


    nuevoNodo->siguiente = inicio;
    inicio = nuevoNodo;
    cout << "Producto insertado al principio de la lista." <<endl;
}


void eliminarProducto(NodoProducto*& inicio, std::string nombre) {

    if (inicio == nullptr) {
        cout << "La lista de productos está vacía." <<endl;
        return;
    }


    if (inicio->datos.nombre == nombre) {
        NodoProducto* temp = inicio;
        inicio = inicio->siguiente;
        delete temp;
        cout << "Producto eliminado." <<endl;
        return;
    }


    NodoProducto* temp = inicio;
    while (temp->siguiente != nullptr && temp->siguiente->datos.nombre != nombre) {
        temp = temp->siguiente;
    }

    if (temp->siguiente == nullptr) {
        cout << "Producto no encontrado." <<endl;
        return;
    }


    NodoProducto* nodoAEliminar = temp->siguiente;
    temp->siguiente = nodoAEliminar->siguiente;
    delete nodoAEliminar;
    cout << "Producto eliminado." <<endl;
}

void modificarProducto(NodoProducto* inicio, string nombre, Producto nuevoDato) {

    if (inicio == nullptr) {
        cout << "La lista de productos está vacía." <<endl;
        return;
    }


    NodoProducto* temp = inicio;
    while (temp != nullptr && temp->datos.nombre != nombre) {
        temp = temp->siguiente;
    }


    if (temp == nullptr) {
        cout << "Producto no encontrado." <<endl;
        return;
    }


    temp->datos = nuevoDato;
    cout << "Producto modificado." <<endl;
}

void mostrarProductos(NodoProducto* inicio) {

    if (inicio == nullptr) {
        cout << "La lista de productos está vacía." <<endl;
        return;
    }


    NodoProducto* temp = inicio;
    while (temp != nullptr) {
        cout << "Nombre: " << temp->datos.nombre <<endl;
        cout << "Precio: " << temp->datos.precio <<endl;
        cout << "Ingredientes:" <<endl;
        NodoIngredienteProducto* ingredientes = temp->datos.ingredientes;
        while (ingredientes != nullptr) {
            cout << "  - " << ingredientes->cantidad << " " << ingredientes->unidad << " de " << ingredientes->ingrediente->nombre <<endl;
            ingredientes = ingredientes->siguiente;
        }
        cout << "------------------------" <<endl;
        temp = temp->siguiente;
    }
}

/*
***********************************************
*                                             *
*      Funciones de agregar Ingrediente       *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void agregarIngredienteAProducto(NodoProducto*& inicio, Producto prod, Ingrediente ingr, double cantidad, std::string unidad) {
    NodoProducto* temp = inicio;
    while (temp != nullptr && temp->datos.nombre != prod.nombre) {
        temp = temp->siguiente;
    }

    if (temp != nullptr) {
        NodoIngredienteProducto* nuevoNodo = new NodoIngredienteProducto{cantidad, unidad, &ingr, nullptr};

        if (temp->datos.ingredientes == nullptr) {
            temp->datos.ingredientes = nuevoNodo;
        } else {
            NodoIngredienteProducto* curr = temp->datos.ingredientes;
            while (curr->siguiente != nullptr) {
                curr = curr->siguiente;
            }
            curr->siguiente = nuevoNodo;
        }
    }
}

void modificarCantidadIngredienteProducto(NodoProducto*& inicio, Producto prod, Ingrediente ingr, double nuevaCantidad) {
    NodoProducto* temp = inicio;
    while (temp != nullptr && temp->datos.nombre != prod.nombre) {
        temp = temp->siguiente;
    }

    if (temp != nullptr) {
        NodoIngredienteProducto* curr = temp->datos.ingredientes;
        while (curr != nullptr && curr->ingrediente != &ingr) {
            curr = curr->siguiente;
        }

        if (curr != nullptr) {
            curr->cantidad = nuevaCantidad;
        }
    }
}

void modificarCantidadIngredienteGeneral(std::vector<Ingrediente>& listaIngredientes, Ingrediente ingr, double nuevaCantidad) {
    for (auto& i : listaIngredientes) {
        if (i.nombre == ingr.nombre) {
            i.cantidad = nuevaCantidad;
            break;
        }
    }
}

/*
***********************************************
*                                             *
*         Funciones de agregar Ventas         *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

void registrarVenta(NodoCliente*& clientes, int cedulaCliente, int idNegocio, Producto prod, double cantidad, string fecha) {
    NodoCliente* cliente = buscarCliente(clientes, cedulaCliente);
    if (cliente != nullptr) {
        NodoNegocio* negocio = buscarNegocio(cliente->datos.negocios, idNegocio);
        if (negocio != nullptr) {
            if (validarInventario(cliente->datos.inventario, prod, cantidad)) {
                NodoVenta* nuevoNodo = new NodoVenta{fecha, cantidad, &prod, nullptr};

                if (negocio->datos.ventas == nullptr) {
                    negocio->datos.ventas = nuevoNodo;
                } else {
                    NodoVenta* curr = negocio->datos.ventas;
                    while (curr->siguiente != nullptr) {
                        curr = curr->siguiente;
                    }
                    curr->siguiente = nuevoNodo;
                }

                actualizarInventario(cliente->datos.inventario, prod, cantidad);
            } else {
                cout << "No hay suficiente inventario para realizar la venta." <<endl;
            }
        } else {
            cout << "El negocio no existe para este cliente." <<endl;
        }
    } else {
        cout << "El cliente no existe." <<endl;
    }
}

/*
***********************************************
*                                             *
*         Funciones de Inventario             *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

bool validarInventario(NodoInventario* inventario, Producto prod, double cantidad) {
    NodoIngredienteProducto* ingredientes = prod.ingredientes;
    while (ingredientes != nullptr) {
        NodoInventario* temp = inventario;
        double cantidadDisponible = 0;
        while (temp != nullptr && temp->ingrediente != ingredientes->ingrediente) {
            temp = temp->siguiente;
        }

        if (temp != nullptr) {
            cantidadDisponible = temp->cantidad;
        }

        if (cantidadDisponible < ingredientes->cantidad * cantidad) {
            return false;
        }

        ingredientes = ingredientes->siguiente;
    }

    return true;
}

void actualizarInventario(NodoInventario*& inventario, Producto prod, double cantidad) {
    NodoIngredienteProducto* ingredientes = prod.ingredientes;
    while (ingredientes != nullptr) {
        NodoInventario* temp = inventario;
        while (temp != nullptr && temp->ingrediente != ingredientes->ingrediente) {
            temp = temp->siguiente;
        }

        if (temp != nullptr) {
            temp->cantidad -= ingredientes->cantidad * cantidad;
        }

        ingredientes = ingredientes->siguiente;
    }
}

/*
***********************************************
*                                             *
*         Funciones de Consultas              *
*               (abajo)  ↓↓↓↓                 *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/

Cliente obtenerClienteMasNegocios(NodoCliente* inicio) {
    if (inicio == nullptr) {
        Cliente cliente = {"", "", 0, 0, ""};
        return cliente;
    }

    NodoCliente* temp = inicio;
    int maxNegocios = 0;
    Cliente clienteMasNegocios;

    while (temp != nullptr) {
        int cantidadNegocios = contarNegocios(temp->datos.negocios);
        if (cantidadNegocios > maxNegocios) {
            maxNegocios = cantidadNegocios;
            clienteMasNegocios = temp->datos;
        }
        temp = temp->siguiente;
    }

    return clienteMasNegocios;
}

Cliente obtenerClienteMasInventario(NodoCliente* inicio) {
    if (inicio == nullptr) {
        Cliente cliente = {"", "", 0, 0, ""};
        return cliente;
    }

    NodoCliente* temp = inicio;
    double maxInventario = 0;
    Cliente clienteMasInventario;

    while (temp != nullptr) {
        double cantidadInventario = calcularCantidadInventario(temp->datos.inventario);
        if (cantidadInventario > maxInventario) {
            maxInventario = cantidadInventario;
            clienteMasInventario = temp->datos;
        }
        temp = temp->siguiente;
    }

    return clienteMasInventario;
}

Cliente obtenerClienteMasVentasGeneral(NodoCliente* inicio) {
    if (inicio == nullptr) {
        Cliente cliente = {"", "", 0, 0, ""};
        return cliente;
    }

    NodoCliente* temp = inicio;
    double maxVentas = 0;
    Cliente clienteMasVentas;

    while (temp != nullptr) {
        double cantidadVentas = calcularCantidadVentasGeneral(temp->datos.negocios);
        if (cantidadVentas > maxVentas) {
            maxVentas = cantidadVentas;
            clienteMasVentas = temp->datos;
        }
        temp = temp->siguiente;
    }

    return clienteMasVentas;
}

Cliente obtenerClienteMasVentasFecha(NodoCliente* inicio, std::string fecha) {
    if (inicio == nullptr) {
        Cliente cliente = {"", "", 0, 0, ""};
        return cliente;
    }

    NodoCliente* temp = inicio;
    double maxVentas = 0;
    Cliente clienteMasVentas;

    while (temp != nullptr) {
        double cantidadVentas = calcularCantidadVentasFecha(temp->datos.negocios, fecha); // Add a semicolon at the end of the line
        if (cantidadVentas > maxVentas) {
            maxVentas = cantidadVentas;
            clienteMasVentas = temp->datos;
        }
        temp = temp->siguiente;
    }

    return clienteMasVentas;
}

int contarNegocios(NodoNegocio* inicio) {
    int contador = 0;
    NodoNegocio* temp = inicio;
    while (temp != nullptr) {
        contador++;
        temp = temp->siguiente;
    }
    return contador;
}

double calcularCantidadInventario(NodoInventario* inicio) {
    double cantidadTotal = 0;
    NodoInventario* temp = inicio;
    while (temp != nullptr) {
        cantidadTotal += temp->cantidad;
        temp = temp->siguiente;
    }
    return cantidadTotal;
}

double calcularCantidadVentasGeneral(NodoNegocio* inicio) {
    double cantidadTotal = 0;
    NodoNegocio* tempNegocio = inicio;
    while (tempNegocio != nullptr) {
        NodoVenta* tempVenta = tempNegocio->datos.ventas;
        while (tempVenta != nullptr) {
            cantidadTotal += tempVenta->cantidad * tempVenta->producto->precio;
            tempVenta = tempVenta->siguiente;
        }
        tempNegocio = tempNegocio->siguiente;
    }
    return cantidadTotal;
}

double calcularCantidadVentasFecha(NodoNegocio* inicio, std::string fecha) {
    double cantidadTotal = 0;
    NodoNegocio* tempNegocio = inicio;
    while (tempNegocio != nullptr) {
        NodoVenta* tempVenta = tempNegocio->datos.ventas;
        while (tempVenta != nullptr) {
            if (tempVenta->fecha == fecha) {
                cantidadTotal += tempVenta->cantidad * tempVenta->producto->precio;
            }
            tempVenta = tempVenta->siguiente;
        }
        tempNegocio = tempNegocio->siguiente;
    }
    return cantidadTotal;
}

//funcion para saber Cual es el cliente que vende mas en general un producto X, en una fecha X, de acuerdo con el precio?
Cliente obtenerClienteMasVentasProductoFecha(NodoCliente* inicio, std::string fecha, std::string nombreProducto) {
    if (inicio == nullptr) {
        Cliente cliente = {"", "", 0, 0, ""};
        return cliente;
    }

    double calcularCantidadVentasProductoFecha(NodoNegocio* inicio, string fecha, string nombreProducto); // Add the missing function declaration

    NodoCliente* temp = inicio;
    double maxVentas = 0;
    Cliente clienteMasVentas;

    while (temp != nullptr) {
        double cantidadVentas = calcularCantidadVentasProductoFecha(temp->datos.negocios, fecha, nombreProducto);
        if (cantidadVentas > maxVentas) {
            maxVentas = cantidadVentas;
            clienteMasVentas = temp->datos;
        }
        temp = temp->siguiente;
    }

    return clienteMasVentas;
}

//funcion para saber Cual es el producto mas vendido en toda la historia?
Producto obtenerProductoMasVendido(NodoProducto* inicio) {
    if (inicio == nullptr) {
        Producto producto = {"", 0, nullptr};
        return producto;
    }

    double calcularCantidadVentasProducto(string nombreProducto); // Declare the missing function

    NodoProducto* temp = inicio;
    double maxVentas = 0;
    Producto productoMasVendido;

    while (temp != nullptr) {
        double cantidadVentas = calcularCantidadVentasProducto(temp->datos.nombre);
        if (cantidadVentas > maxVentas) {
            maxVentas = cantidadVentas;
            productoMasVendido = temp->datos;
        }
        temp = temp->siguiente;
    }

    return productoMasVendido;
}

//funcion para saber Cual es el ingrediente que mas se consume, segun el inventario actual de todos los clientes?

Ingrediente obtenerIngredienteMasConsumido(vector<Ingrediente>& listaIngredientes) {
    if (listaIngredientes.empty()) {
        Ingrediente ingrediente = {"", 0};
        return ingrediente;
    }

    double maxConsumo = 0;
    Ingrediente ingredienteMasConsumido;

    for (auto& i : listaIngredientes) {
        if (i.cantidad > maxConsumo) {
            maxConsumo = i.cantidad;
            ingredienteMasConsumido = i;
        }
    }

    return ingredienteMasConsumido;
}

//funcion para saber Cuales son los 3 ingredientes mas requeridos en cantidad de veces según los productos insertados?
vector<Ingrediente> obtenerIngredientesMasRequeridos(vector<Ingrediente>& listaIngredientes, NodoProducto* productos) {
    vector<Ingrediente> ingredientesMasRequeridos;

    for (auto& i : listaIngredientes) {
        int cantidad = 0;
        NodoProducto* temp = productos;
        while (temp != nullptr) {
            NodoIngredienteProducto* ingredientes = temp->datos.ingredientes;
            while (ingredientes != nullptr) {
                if (ingredientes->ingrediente->nombre == i.nombre) {
                    cantidad++;
                }
                ingredientes = ingredientes->siguiente;
            }
            temp = temp->siguiente;
        }
        i.cantidad = cantidad;
        ingredientesMasRequeridos.push_back(i);
    }



    sort(ingredientesMasRequeridos.begin(), ingredientesMasRequeridos.end(), [](Ingrediente& a, Ingrediente& b) {
        return a.cantidad > b.cantidad;
    });

    return ingredientesMasRequeridos;
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

void menu_c(NodoCliente *clientes){
    // Declare and initialize the "productos" variable
    // Assuming it is of type "NodoProducto*"
    NodoProducto* productos = nullptr;
    vector<Ingrediente> listaIngredientes = obtenerListaIngredientes();
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
            case 1: {
                Cliente cliente = obtenerClienteMasNegocios(clientes);
                cout << "Cliente con mas negocios: " << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Apellido: " << cliente.apellido << endl;
                cout << "Cedula: " << cliente.cedula << endl;
                cout << "Edad: " << cliente.edad << endl;
                cout << "Direccion: " << cliente.direccion << endl;
                break;
            }
            case 2: {
                Cliente cliente = obtenerClienteMasInventario(clientes);
                cout << "Cliente con mas inventario en general: " << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Apellido: " << cliente.apellido << endl;
                cout << "Cedula: " << cliente.cedula << endl;
                cout << "Edad: " << cliente.edad << endl;
                cout << "Direccion: " << cliente.direccion << endl;
                break;
            }
            case 3: {
                Cliente cliente = obtenerClienteMasVentasGeneral(clientes);
                cout << "Cliente que vende mas en general: " << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Apellido: " << cliente.apellido << endl;
                cout << "Cedula: " << cliente.cedula << endl;
                cout << "Edad: " << cliente.edad << endl;
                cout << "Direccion: " << cliente.direccion << endl;
                break;
            }
            case 4: {
                string fecha;
                cout << "Ingrese la fecha: ";
                cin >> fecha;
                Cliente cliente = obtenerClienteMasVentasFecha(clientes, fecha);
                cout << "Cliente que vende mas en general en la fecha " << fecha << ": " << endl;
                cout << "Nombre: " << cliente.nombre << endl;
                cout << "Apellido: " << cliente.apellido << endl;
                cout << "Cedula: " << cliente.cedula << endl;
                cout << "Edad: " << cliente.edad << endl;
                cout << "Direccion: " << cliente.direccion << endl;
                break;
            }
            case 5:{ 
                string fecha, nombreProducto;
                cout << "Ingrese la fecha: ";
                cin >> fecha;
                cout << "Ingrese el nombre del producto: ";
                cin >> nombreProducto;
                Cliente cliente = obtenerClienteMasVentasProductoFecha(clientes, fecha, nombreProducto);
                cout << "Cliente que vende mas en general el producto " << nombreProducto << " en la fecha " << fecha << ": " << endl;
                break;
            }

            case 6: {
                Producto producto = obtenerProductoMasVendido(productos);
                cout << "Producto mas vendido en toda la historia: " << endl;
                cout << "Nombre: " << producto.nombre << endl;
                cout << "Precio: " << producto.precio << endl;
                break;
            }
            case 7: {
                Ingrediente ingrediente = obtenerIngredienteMasConsumido(listaIngredientes);
                cout << "Ingrediente mas consumido: " << endl;
                cout << "Nombre: " << ingrediente.nombre << endl;
                cout << "Cantidad: " << ingrediente.cantidad << endl;
                break;
            }
            case 8: {
                vector<Ingrediente> ingredientes = obtenerIngredientesMasRequeridos(listaIngredientes, productos);
                cout << "Los 3 ingredientes mas requeridos en cantidad de veces: " << endl;
                for (int i = 0; i < 3; i++) {
                    cout << "Nombre: " << ingredientes[i].nombre << endl;
                    cout << "Cantidad: " << ingredientes[i].cantidad << endl;
                }
                break;
            }
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
*        ARMANDOOOOOOOOOOOOOOOOOOOOO          *
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
                void imprimirClientesAscendente(NodoCliente* inicio) {
                    if (inicio == nullptr) {
                        return;
                    }
                    imprimirClientesAscendente(inicio->siguiente);
                    cout << "Nombre: " << inicio->dato.nombre << " Apellido: " << inicio->dato.apellido << endl;
                }

                void imprimirClientesDescendente(NodoCliente* inicio) {
                    if (inicio == nullptr) {
                        return;
                    }
                    cout << "Nombre: " << inicio->dato.nombre << " Apellido: " << inicio->dato.apellido << endl;
                    imprimirClientesDescendente(inicio->siguiente);
                }
                case 1:
                    cout << "Clientes en orden ascendente según el apellido:" << endl;
                    imprimirClientesAscendente(clientes);
                    cout << "Clientes en orden descendente según el apellido:" << endl;
                    imprimirClientesDescendente(clientes);
                    break;

                break;
            case 2:
                void imprimirNegociosCliente(NodoCliente* inicio, std::string nombreCliente) {
                    if (inicio == nullptr) {
                        return;
                    }
                    if (inicio->dato.nombre == nombreCliente) {
                        NodoNegocio* negocioActual = inicio->dato.negocios;
                        while (negocioActual != nullptr) {
                            std::cout << "Negocio: " << negocioActual->dato.nombre << std::endl;
                            negocioActual = negocioActual->siguiente;
                        }
                    }
                    imprimirNegociosCliente(inicio->siguiente, nombreCliente);
                }
                break;
            case 3:
                void imprimirIngredientes(std::vector<Ingrediente>& listaIngredientes) {
                    for (auto& i : listaIngredientes) {
                        cout << "Nombre: " << i.nombre << endl;
                        cout << "Cantidad: " << i.cantidad << endl;
                        cout << "------------------------" << endl;
                    }
                }
                break;
            case 4:
                void imprimirProductos(NodoProducto* inicio) {
                    if (inicio == nullptr) {
                        return;
                    }
                    NodoProducto* temp = inicio;
                    while (temp != nullptr) {
                        cout << "Nombre: " << temp->datos.nombre << endl;
                        cout << "Precio: " << temp->datos.precio << endl;
                        cout << "Ingredientes:" << endl;
                        NodoIngredienteProducto* ingredientes = temp->datos.ingredientes;
                        while (ingredientes != nullptr) {
                            cout << "  - " << ingredientes->cantidad << " " << ingredientes->unidad << " de " << ingredientes->ingrediente->nombre << endl;
                            ingredientes = ingredientes->siguiente;
                        }
                        cout << "------------------------" << endl;
                        temp = temp->siguiente;
                    }
                }
                break;
            case 5:
                void imprimirIngredientesProducto(NodoProducto* inicio, std::string nombreProducto) {
                    NodoProducto* temp = inicio;
                    while (temp != nullptr && temp->datos.nombre != nombreProducto) {
                        temp = temp->siguiente;
                    }

                    if (temp != nullptr) {
                        cout << "Ingredientes del producto " << nombreProducto << ":" << endl;
                        NodoIngredienteProducto* ingredientes = temp->datos.ingredientes;
                        while (ingredientes != nullptr) {
                            cout << "  - " << ingredientes->cantidad << " " << ingredientes->unidad << " de " << ingredientes->ingrediente->nombre << endl;
                            ingredientes = ingredientes->siguiente;
                        }
                    }
                }
                break;
            case 6:
                void imprimirInventarioCliente(NodoCliente* inicio, std::string nombreCliente) {
                    if (inicio == nullptr) {
                        return;
                    }
                    if (inicio->dato.nombre == nombreCliente) {
                        NodoInventario* inventarioActual = inicio->dato.inventario;
                        while (inventarioActual != nullptr) {
                            cout << "Ingrediente: " << inventarioActual->ingrediente->nombre << endl;
                            cout << "Cantidad: " << inventarioActual->cantidad << endl;
                            inventarioActual = inventarioActual->siguiente;
                        }
                    }
                    imprimirInventarioCliente(inicio->siguiente, nombreCliente);
                }
                break;
            case 7:
                void imprimirInventarioVencido(NodoInventario* inicio, std::string fecha) {
                    if (inicio == nullptr) {
                        return;
                    }
                    NodoInventario* temp = inicio;
                    while (temp != nullptr) {
                        if (temp->ingrediente->fechaVencimiento == fecha) {
                            cout << "Ingrediente: " << temp->ingrediente->nombre << endl;
                            cout << "Cantidad: " << temp->cantidad << endl;
                        }
                        temp = temp->siguiente;
                    }
                }
                break;
            case 8:
                void imprimirVentasFechaCliente(NodoCliente* inicio, std::string nombreCliente, std::string fecha) {
                    if (inicio == nullptr) {
                        return;
                    }
                    if (inicio->dato.nombre == nombreCliente) {
                        NodoNegocio* negocioActual = inicio->dato.negocios;
                        while (negocioActual != nullptr) {
                            NodoVenta* ventaActual = negocioActual->dato.ventas;
                            while (ventaActual != nullptr) {
                                if (ventaActual->fecha == fecha) {
                                    cout << "Negocio: " << negocioActual->dato.nombre << endl;
                                    cout << "Producto: " << ventaActual->producto->nombre << endl;
                                    cout << "Cantidad: " << ventaActual->cantidad << endl;
                                }
                                ventaActual = ventaActual->siguiente;
                            }
                            negocioActual = negocioActual->siguiente;
                        }
                    }
                    imprimirVentasFechaCliente(inicio->siguiente, nombreCliente, fecha);
                }
                break;
            case 9:
                void imprimirInventarioCero(NodoInventario* inicio) {
                    if (inicio == nullptr) {
                        return;
                    }
                    NodoInventario* temp = inicio;
                    while (temp != nullptr) {
                        if (temp->cantidad == 0) {
                            cout << "Ingrediente: " << temp->ingrediente->nombre << endl;
                        }
                        temp = temp->siguiente;
                    }
                }
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
*        Menu Principal (abajo)  ↓↓↓↓         *
*                                             *
*                                             *
*                                             *
*                                             *
*                                             *
***********************************************
*/


void menu_p(){
    NodoCliente* listaClientes = nullptr; 
    NodoNegocio* listaNegocios = nullptr;
    NodoProducto* listaProductos = nullptr;
    vector<Ingrediente> listaIngredientes;

    cargarDatos(listaClientes, listaProductos, listaIngredientes);


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
            gestionClientes(listaClientes);
            break;
        case 2:
            gestionNegocios(listaNegocios);
            break;
        case 3:
            gestionProductos(listaProductos, listaIngredientes);
            break;
        case 4:
            gestionIngredientes(listaIngredientes);
            break;
        case 5:
            registroVentas(listaClientes, listaNegocios, listaProductos);
            break;
        case 6:
            menu_a();
            break;
        case 7:
            menu_c(listaClientes);
            break;
        case 8:
            menu_r();
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
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
    menu_p();
    return 0;
}












