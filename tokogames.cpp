#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int leerEntero() {

    int valor;

    while (!(cin >> valor)) {

        cin.clear();
        cin.ignore(10000, '\n');

        cout << "Ingrese un numero valido: ";
    }

    cin.ignore(10000, '\n');

    return valor;
}

struct Proveedor {
    int id;
    char nombre[100];
    char rif[20];
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
};

struct Transaccion {
    int id;
    char tipo[10];
    int idProducto;
    int cantidad;
    float precioUnitario;
    float total;
    char fecha[11];
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

void obtenerFechaActual(char* buffer) {

    time_t t = time(NULL);
    tm* tmPtr = localtime(&t);

    sprintf(buffer, "%04d-%02d-%02d",
        tmPtr->tm_year + 1900,
        tmPtr->tm_mon + 1,
        tmPtr->tm_mday);
}

void redimensionarProductos(Tienda* tienda) {

    int nuevaCapacidad = tienda->capacidadProductos * 2;

    Producto* nuevo = new Producto[nuevaCapacidad];

    for (int i = 0; i < tienda->numProductos; i++)
        nuevo[i] = tienda->productos[i];

    delete[] tienda->productos;

    tienda->productos = nuevo;
    tienda->capacidadProductos = nuevaCapacidad;
}


void redimensionarProveedores(Tienda* tienda) {

    int nuevaCapacidad = tienda->capacidadProveedores * 2;

    Proveedor* nuevo = new Proveedor[nuevaCapacidad];

    for (int i = 0; i < tienda->numProveedores; i++)
        nuevo[i] = tienda->proveedores[i];

    delete[] tienda->proveedores;

    tienda->proveedores = nuevo;
    tienda->capacidadProveedores = nuevaCapacidad;
}


void redimensionarClientes(Tienda* tienda) {

    int nuevaCapacidad = tienda->capacidadClientes * 2;

    Cliente* nuevo = new Cliente[nuevaCapacidad];

    for (int i = 0; i < tienda->numClientes; i++)
        nuevo[i] = tienda->clientes[i];

    delete[] tienda->clientes;

    tienda->clientes = nuevo;
    tienda->capacidadClientes = nuevaCapacidad;
}


void redimensionarTransacciones(Tienda* tienda) {

    int nuevaCapacidad = tienda->capacidadTransacciones * 2;

    Transaccion* nuevo = new Transaccion[nuevaCapacidad];

    for (int i = 0; i < tienda->numTransacciones; i++)
        nuevo[i] = tienda->transacciones[i];

    delete[] tienda->transacciones;

    tienda->transacciones = nuevo;
    tienda->capacidadTransacciones = nuevaCapacidad;
}

void inicializarTienda(Tienda* tienda) {

    strcpy(tienda->nombre, "tokogames");
    strcpy(tienda->rif, "J-00070650-4");

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
}


void crearProveedor(Tienda* tienda) {

    if (tienda->numProveedores >= tienda->capacidadProveedores)
        redimensionarProveedores(tienda);

    Proveedor* p = &tienda->proveedores[tienda->numProveedores];

    p->id = tienda->siguienteIdProveedor++;

    cout << "Nombre proveedor: ";
    cin.getline(p->nombre, 100);

    cout << "RIF: ";
    cin.getline(p->rif, 20);

    tienda->numProveedores++;

    cout << "Proveedor creado correctamente\n";
}

void crearProducto(Tienda* tienda) {

    if (tienda->numProductos >= tienda->capacidadProductos)
        redimensionarProductos(tienda);

    Producto* p = &tienda->productos[tienda->numProductos];

    p->id = tienda->siguienteIdProducto++;

    cout << "Codigo: ";
    cin.getline(p->codigo, 20);

    cout << "Nombre: ";
    cin.getline(p->nombre, 100);

    cout << "Descripcion: ";
    cin.getline(p->descripcion, 200);

    cout << "ID proveedor: ";
    p->idProveedor = leerEntero();

    cout << "Precio: ";
    cin >> p->precio;
    cin.ignore(10000, '\n');

    cout << "Stock: ";
    p->stock = leerEntero();

    obtenerFechaActual(p->fechaRegistro);

    tienda->numProductos++;

    cout << "Producto creado correctamente\n";
}

void crearCliente(Tienda* tienda) {

    if (tienda->numClientes >= tienda->capacidadClientes)
        redimensionarClientes(tienda);

    Cliente* c = &tienda->clientes[tienda->numClientes];

    c->id = tienda->siguienteIdCliente++;

    cout << "Nombre: ";
    cin.getline(c->nombre, 100);

    cout << "Cedula: ";
    cin.getline(c->cedula, 20);

    cout << "Telefono: ";
    cin.getline(c->telefono, 20);

    cout << "Email: ";
    cin.getline(c->email, 100);

    tienda->numClientes++;

    cout << "Cliente creado correctamente\n";
}

void registrarVenta(Tienda* tienda) {

    if (tienda->numTransacciones >= tienda->capacidadTransacciones)
        redimensionarTransacciones(tienda);

    cout << "ID producto: ";
    int idProducto = leerEntero();

    cout << "Cantidad: ";
    int cantidad = leerEntero();

    for (int i = 0; i < tienda->numProductos; i++) {

        Producto& p = tienda->productos[i];

        if (p.id == idProducto) {

            if (p.stock < cantidad) {

                cout << "Stock insuficiente\n";
                return;
            }

            p.stock -= cantidad;

            Transaccion* t =
                &tienda->transacciones[tienda->numTransacciones];

            t->id = tienda->siguienteIdTransaccion++;

            strcpy(t->tipo, "VENTA");

            t->idProducto = idProducto;

            t->cantidad = cantidad;

            t->precioUnitario = p.precio;

            t->total = cantidad * p.precio;

            obtenerFechaActual(t->fecha);

            tienda->numTransacciones++;

            cout << "Venta registrada correctamente\n";

            return;
        }
    }

    cout << "Producto no encontrado\n";
}

void listarProductos(Tienda* tienda) {

    for (int i = 0; i < tienda->numProductos; i++) {

        Producto& p = tienda->productos[i];

        cout << p.id << " - "
             << p.nombre << " - Stock: "
             << p.stock << endl;
    }
}


void listarProveedores(Tienda* tienda) {

    for (int i = 0; i < tienda->numProveedores; i++)
        cout << tienda->proveedores[i].id
             << " - "
             << tienda->proveedores[i].nombre
             << endl;
}


void listarClientes(Tienda* tienda) {

    for (int i = 0; i < tienda->numClientes; i++)
        cout << tienda->clientes[i].id
             << " - "
             << tienda->clientes[i].nombre
             << endl;
}


void listarTransacciones(Tienda* tienda) {

    for (int i = 0; i < tienda->numTransacciones; i++) {

        Transaccion& t = tienda->transacciones[i];

        cout << t.id << " - "
             << t.tipo << " - Total: "
             << t.total << endl;
    }
}


void liberarTienda(Tienda* tienda) {

    delete[] tienda->productos;
    delete[] tienda->proveedores;
    delete[] tienda->clientes;
    delete[] tienda->transacciones;
}

void menu(Tienda* tienda) {

    int opcion;

    do {

        cout << "\n===== TOKOGAMES =====\n";
        cout << "1. Crear proveedor\n";
        cout << "2. Crear producto\n";
        cout << "3. Crear cliente\n";
        cout << "4. Registrar venta\n";
        cout << "5. Listar productos\n";
        cout << "6. Listar proveedores\n";
        cout << "7. Listar clientes\n";
        cout << "8. Listar transacciones\n";
        cout << "0. Salir\n";

        opcion = leerEntero();

        switch (opcion) {

        case 1: crearProveedor(tienda); break;
        case 2: crearProducto(tienda); break;
        case 3: crearCliente(tienda); break;
        case 4: registrarVenta(tienda); break;
        case 5: listarProductos(tienda); break;
        case 6: listarProveedores(tienda); break;
        case 7: listarClientes(tienda); break;
        case 8: listarTransacciones(tienda); break;
        }

    } while (opcion != 0);
}

int main() {

    Tienda tienda;

    inicializarTienda(&tienda);

    menu(&tienda);

    liberarTienda(&tienda);

    return 0;
}
