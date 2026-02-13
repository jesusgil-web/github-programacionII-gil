/*
 * EJERCICIO CLASE 1 - PUNTEROS Y MEMORIA DINÁMICA
 * ================================================
 * 
 * ENUNCIADO:
 * Implementar un programa que permita:
 * 1. Crear un arreglo dinámico de números enteros
 * 2. Llenar el arreglo con valores ingresados por el usuario
 * 3. Mostrar todos los números del arreglo
 * 4. Encontrar el número mayor en el arreglo
 * 5. Calcular el promedio de todos los números
 * 6. Liberar la memoria correctamente
 * 
 * REQUISITOS:
 * - Usar punteros y memoria dinámica (new/delete)
 * - Usar paso por referencia donde sea apropiado
 * - Validar entrada del usuario (tamaño del arreglo)
 * - Liberar toda la memoria asignada
 * - Asignar nullptr después de delete
 * 
 * FUNCIONES QUE DEBE IMPLEMENTAR:
 * 1. int* crearArreglo(int tamanio)
 * 2. void llenarArreglo(int* arreglo, int tamanio)
 * 3. void mostrarArreglo(int* arreglo, int tamanio)
 * 4. int encontrarMayor(int* arreglo, int tamanio)
 * 5. float calcularPromedio(int* arreglo, int tamanio)
 * 6. void liberarArreglo(int*& arreglo)
 * 
 * MENÚ SIMPLE:
 * 1. Crear y llenar arreglo
 * 2. Mostrar arreglo
 * 3. Encontrar número mayor
 * 4. Calcular promedio
 * 5. Salir
 * 
 * NOTAS IMPORTANTES:
 * - Validar que el tamaño del arreglo sea positivo
 * - Verificar que new no retorne nullptr
 * - Usar buenas prácticas de programación
 * - Comentar el código apropiadamente
 * 
 * CRITERIOS DE EVALUACIÓN:
 * - Correcta implementación de punteros (50%)
 * - Manejo correcto de memoria (30%)
 * - Funcionalidad del programa (20%)
 * 
 * TIEMPO ESTIMADO: 1-2 horas
 * DIFICULTAD: Básica-Medio
 */

#include <iostream>
#include <locale>
#include <iomanip>
using namespace std;


// Función para crear un arreglo dinámico
int* crearArreglo(int tamanio) {
    if (tamanio <= 0) {
        cout << "El tamanio debe ser mayor que cero." << endl;
        return nullptr;
    }

    int* nuevo = new int[tamanio];

    if (!nuevo) {
        cout << "No se pudo asignar memoria." << endl;
        return nullptr;
    }

    return nuevo;
}

// Función para llenar el arreglo con valores del usuario
void llenarArreglo(int* arreglo, int tamanio) {
    if (arreglo == nullptr) {
        cout << "El arreglo no es valido." << endl;
        return;
    }

    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el valor [" << i << "]: ";
        cin >> *(arreglo + i);
    }
}

// Función para mostrar todos los elementos del arreglo
void mostrarArreglo(int* arreglo, int tamanio) {
    if (arreglo == nullptr || tamanio <= 0) {
        cout << "Arreglo vacio." << endl;
        return;
    }

    cout << "Elementos del arreglo: ";
    for (int i = 0; i < tamanio; i++) {
        cout << *(arreglo + i) << " ";
    }
    cout << endl;
}

// Función para encontrar el número mayor
int encontrarMayor(int* arreglo, int tamanio) {
    if (arreglo == nullptr || tamanio <= 0) {
        cout << "No es posible encontrar el mayor." << endl;
        return 0;
    }

    int mayor = arreglo[0];

    for (int i = 1; i < tamanio; i++) {
        if (*(arreglo + i) > mayor) {
            mayor = *(arreglo + i);
        }
    }

    return mayor;
}

// Función para calcular el promedio
float calcularPromedio(int* arreglo, int tamanio) {
    if (arreglo == nullptr || tamanio <= 0) {
        cout << "No se puede calcular el promedio." << endl;
        return 0.0f;
    }

    int suma = 0;

    for (int i = 0; i < tamanio; i++) {
        suma += arreglo[i];
    }

    return static_cast<float>(suma) / tamanio;
}

// Función para liberar la memoria del arreglo
void liberarArreglo(int*& arreglo) {
    if (arreglo != nullptr) {
        delete[] arreglo;
        arreglo = nullptr;
    }
}

// Función para mostrar el menú
void mostrarMenu() {
    cout << "\n=== GESTION DE ARREGLOS DINAMICOS ===" << endl;
    cout << "1. Crear y llenar arreglo" << endl;
    cout << "2. Mostrar arreglo" << endl;
    cout << "3. Encontrar numero mayor" << endl;
    cout << "4. Calcular promedio" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    setlocale(LC_ALL, "spanish");

    int* arreglo = nullptr;
    int tamanio = 0;

    cout << "=== GESTION DE ARREGLOS DINAMICOS ===" << endl;

    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1: {
                cout << "Ingrese el tamanio del arreglo: ";
                cin >> tamanio;

                liberarArreglo(arreglo);
                arreglo = crearArreglo(tamanio);

                if (arreglo != nullptr) {
                    llenarArreglo(arreglo, tamanio);
                    cout << "Arreglo creado correctamente." << endl;
                }
                break;
            }

            case 2: {
                if (arreglo != nullptr) {
                    mostrarArreglo(arreglo, tamanio);
                } else {
                    cout << "Primero cree el arreglo." << endl;
                }
                break;
            }

            case 3: {
                if (arreglo != nullptr && tamanio > 0) {
                    cout << "El numero mayor es: "
                         << encontrarMayor(arreglo, tamanio) << endl;
                } else {
                    cout << "Arreglo no disponible." << endl;
                }
                break;
            }

            case 4: {
                if (arreglo != nullptr && tamanio > 0) {
                    cout << "El promedio es: "
                         << fixed << setprecision(2)
                         << calcularPromedio(arreglo, tamanio) << endl;
                } else {
                    cout << "Arreglo no disponible." << endl;
                }
                break;
            }

            case 5:
                cout << "Saliendo del programa..." << endl;
                break;

            default:
                cout << "Opcion invalida." << endl;
        }

    } while (opcion != 5);

    liberarArreglo(arreglo);

    cout << "Programa finalizado. Memoria liberada." << endl;
    return 0;
}
