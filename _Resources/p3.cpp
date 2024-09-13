#include <iostream>
using namespace std;

char** crearTeatro(int filas, int columnas) {
    char** teatro = new char*[filas];
    for (int i = 0; i < filas; i++) {
        teatro[i] = new char[columnas];
    }

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            teatro[i][j] = 'L';
        }
    }
    return teatro;
}

void liberarTeatro(char** teatro, int filas) {
    for (int i = 0; i < filas; i++) {
        delete[] teatro[i];
    }
    delete[] teatro;
}

void reservarAsiento(char** teatro, int filas, int columnas, int fila, int columna) {
    if (0 <= fila && fila < filas && 0 <= columna && columna < columnas) {
        if (teatro[fila][columna] == 'L') {
            teatro[fila][columna] = 'R';
            cout << "El asiento ha sido reservado." << endl;
        } 
        else {
            cout << "ERROR: El asiento ya está reservado." << endl;
        }
    } 
    else {
        cout << "ERROR: El asiento no existe." << endl;
    }
}

void cancelarReserva(char** teatro, int filas, int columnas, int fila, int columna) {
    if (fila >= 0 && fila < filas && 0 <= columna && columna < columnas) {
        if (teatro[fila][columna] == 'R') {
            teatro[fila][columna] = 'L'; 
            cout << "La Reserva ha sido cancelada." << endl;
        } 
        else {
            cout << "ERROR: El asiento no esta reservado." << endl;
        }
    } 
    else {
        cout << "ERROR: El asiento no existe." << endl;
    }
}

void mostrarAsientos(char** teatro, int filas, int columnas) {
    cout << ".:Estado actual de todos los asientos:." << endl;
    cout << "\n  ";
    for (int j = 0; j < columnas; ++j) {
        cout << j + 1 << ' ';
    }
    cout << endl;
    
    for (int i = 0; i < filas; ++i) {
        cout << i + 1 << ' ';
        for (int j = 0; j < columnas; ++j) {
            cout << teatro[i][j] << ' ';
        }
        cout << endl;
    }
}


void mostrarMenu() {
    cout << "\nMenu del teatro Royal:" << endl;
    cout << "1) Mostrar asientos" << endl;
    cout << "2) Reservar asiento" << endl;
    cout << "3) Cancelar reserva" << endl;
    cout << "4) Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int filas = 5;
    int columnas = 6;

    char** teatro = crearTeatro(filas, columnas);
    
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        switch(opcion) {
            case 1:
                mostrarAsientos(teatro, filas, columnas);
                break;
            case 2: {
                int fila, columna;
                cout << "Ingrese la fila del asiento a reservar ([1," << filas <<"]): ";
                cin >> fila;
                cout << "Ingrese la columna del asiento a reservar ([1," << columnas <<"]): ";
                cin >> columna;
                reservarAsiento(teatro, filas, columnas, fila - 1, columna - 1);
                break;
            }
            case 3: {
                int fila, columna;
                cout << "Ingrese la fila del asiento reservado a cancelar ([1," << filas <<"]): ";
                cin >> fila;
                cout << "Ingrese la columna del asiento reservado a cancelar ([1," << columnas <<"]): ";
                cin >> columna;
                cancelarReserva(teatro, filas, columnas, fila - 1, columna - 1);
                break;
            }
            case 4:
                cout << "\n!Gracias por comprar en el teatro Royal!" << endl << endl;
                break;
            default:
                cout << "Opcion inválida. Intente nuevamente." << endl;
        }
    } while(opcion != 4);

    liberarTeatro(teatro, filas);
    return 0;
}
