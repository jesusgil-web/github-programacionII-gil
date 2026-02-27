#include <iostream>
#include <cstring>
using namespace std;
struct Producto {

    int id;
    char codigo[20];
    char nombre[100];
    char descripcion[200];
    int idProveedor;
    float precio;
    int stock;
    char fechaRegistro[11];
};
struct Producto {
    int id;
    char codigo[20];
    char nombre[100];
    char descripcion[200];
    int idProveedor;
    float precio;
    int stock;
    char fechaRegistro[11];
};
struct Cliente {
    int id;
    char nombre[100];
    char cedula[20];
    char telefono[20];
    char email[100];
    char direccion[200];
    char fechaRegistro[11];
};
struct Transaccion {
    int id;
    char tipo[10];
    int idProducto;
    int idRelacionado;
    int cantidad;
    float precioUnitario;
    float total;
    char fecha[11];
    char descripcion[200];
};
struct Tienda {

    char nombre[100];
    char rif[20];

    Producto* productos;
    int numProductos;
    int capacidadProductos;

    Proveedor* proveedores;
    int numProveedores;
    int capacidadProveedores;

    Cliente* clientes;
    int numClientes;
    int capacidadClientes;

    Transaccion* transacciones;
    int numTransacciones;
    int capacidadTransacciones;

    int siguienteIdProducto;
    int siguienteIdProveedor;
    int siguienteIdCliente;
    int siguienteIdTransaccion;
};
void inicializarTienda(Tienda* tienda, const char* nombre, const char* rif)
    std::string(tienda->nombre, nombre);
    std::string(tienda->rif, rif);
    tienda->capacidadProductos = 5;
    tienda->capacidadProveedores = 5;
    tienda->capacidadClientes = 5;
    tienda->capacidadTransacciones = 5;
    tienda->numProductos = 0;
    tienda->numProveedores = 0;
    tienda->numClientes = 0;
    tienda->numTransacciones = 0;

    tienda->productos = new Producto[5];
    tienda->proveedores = new Proveedor[5];
    tienda->clientes = new Cliente[5];
    tienda->transacciones = new Transaccion[5];

    tienda->siguienteIdProducto = 1;
    tienda->siguienteIdProveedor = 1;
    tienda->siguienteIdCliente = 1;
    tienda->siguienteIdTransaccion = 1;

    void liberarTienda(Tienda* tienda) {
    delete[] tienda->productos;
    delete[] tienda->proveedores;
    delete[] tienda->clientes;
    delete[] tienda->transacciones;
};

int main() {

    Tienda tienda;
};

inicializarTienda(&tienda, "GameZone", "J-00070650-4");

        cout << "=========================\n";
    cout << " TIENDA GAMEZONE 🎮\n";
    cout << " Sistema iniciado\n";
    cout << "=========================\n";

    cout << "Capacidad Productos: " << tienda.capacidadProductos << endl;
    cout << "Capacidad Proveedores: " << tienda.capacidadProveedores << endl;
    cout << "Capacidad Clientes: " << tienda.capacidadClientes << endl;
    cout << "Capacidad Transacciones: " << tienda.capacidadTransacciones << endl;

{   liberarTienda(&tienda);
    return 0;
};