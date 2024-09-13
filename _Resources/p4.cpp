#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


struct Empleado {
    public:
        string nombre;
        int edad;
        float salario;
};
vector<Empleado> Empleados;
void agregarEmpleado();
void mostrarEmpleados();
void buscarEmpleado();
void actualizarSalarioEmpleado();
void leerEmpleados();
void imprimirEmpleado(Empleado);

void imprimirEmpleado(Empleado emp) {
    cout << "Nombre: " << emp.nombre << ", Edad: " << emp.edad << ", Salario: " << emp.salario << endl;
}

void mostrarMenu() {
    cout << "\nMenu:" << endl;
    cout << "1. Agregar empleado" << endl;
    cout << "2. Mostrar empleados" << endl;
    cout << "3. Buscar empleado por nombre" << endl;
    cout << "4. Actualizar salario de un empleado" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    leerEmpleados();
    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;
        cin.ignore();

        switch(opcion) {
            case 1:
                agregarEmpleado();
                break;
            case 2:
                mostrarEmpleados();
                break;
            case 3:
                buscarEmpleado();
                break;
            case 4:
                actualizarSalarioEmpleado();
                break;
            case 5:
                cout << "Saliendo del programa...." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente nuevamente." << endl;
        }
    } while(opcion != 5);
    return 0;
}

void agregarEmpleado() {
    Empleado emp;
    cout << "Ingrese nombre del empleado: ";
    getline(cin, emp.nombre);
    cout << "Ingrese edad del empleado: ";
    cin >> emp.edad;
    cout << "Ingrese salario del empleado: ";
    cin >> emp.salario;
    cin.ignore();
    Empleados.push_back(emp);
    ofstream file("empleados.txt", ios::app);
    if (file.is_open()) {
        file << '\n' << emp.nombre << ' ';
        file << emp.edad << ' ';
        file << emp.salario << ' ';
        file.close();
        cout << "Empleado agregado correctmente." << endl;
    } 
    else {
        cout << "No se pudo abrir el archivo: empleados.txt." << endl;
    }
}

void mostrarEmpleados() {
    cout << "Listado de empleados: " << endl;
    for (Empleado emp : Empleados) {
        imprimirEmpleado(emp);
    }
}
void leerEmpleados() {
    ifstream file("empleados.txt");
    if (file.is_open()) {
        string linea;
        while (getline(file, linea)) {
            size_t pos = 0;
            Empleado emp;
            pos = linea.find(' ');
            if (pos != string::npos) {
                emp.nombre = linea.substr(0, pos);
                linea.erase(0, pos + 1);
            }
            pos = linea.find(' ');
            if (pos != string::npos) {
                emp.edad = stoi(linea.substr(0, pos));
                linea.erase(0, pos + 1);
            }
            emp.salario = stof(linea);
            Empleados.push_back(emp);
            // cout << "Nombre: " << emp.nombre << ", Edad: " << emp.edad << ", Salario: " << emp.salario << endl;
        }
        file.close();
    } else {
        cout << "No se pudo abrir el archivo: empleados.txt." << endl;
    }
}

void buscarEmpleado() {
    string nombre;
    cout << "Ingrese el nombre del empleado a buscar: ";
    getline(cin, nombre);
    for(Empleado emp : Empleados) {
        if(emp.nombre == nombre) {
            cout << "Empleado encontrado: \n";
            imprimirEmpleado(emp);
            break;
        }
    }
}

void actualizarSalarioEmpleado() {
    string nombre;
    cout << "Ingrese el nombre del empleado para actualizar salario: ";
    getline(cin, nombre);
    float nuevoSalario;
    cout << "Ingrese el nuevo salario: ";
    cin >> nuevoSalario;
    cin.ignore();

    // ifstream file("empleados.txt");
    ofstream tempFile("temp.txt");
    bool actualizado = false;
    if (tempFile.is_open()) {
        for (Empleado emp : Empleados) {
            tempFile << emp.nombre << ' ';
            tempFile << emp.edad << ' ';
            if(emp.nombre == nombre) {
                tempFile << nuevoSalario << ' ' << '\n';
                actualizado = true;
            }
            else {
                tempFile << emp.salario << ' ' << '\n';
            }
        }
        tempFile.close();

        remove("empleados.txt");
        rename("temp.txt", "empleados.txt");
        Empleados.clear();
        leerEmpleados();

        if (actualizado) {
            cout << "Salario actualizado correctamente para el empleado '" << nombre << "'." << endl;
        } 
        else {
            cout << "Empleado no encontrado." << endl;
        }
    } 
    else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void mostrarEmpleados(string filename, const vector<Empleado>& empleados) {
    ofstream file(filename);
    if (file.is_open()) {
        for (Empleado emp : empleados) {
            file << emp.nombre << endl;
            file << emp.edad << endl;
            file << emp.salario << endl;
        }
        file.close();
    }
}
