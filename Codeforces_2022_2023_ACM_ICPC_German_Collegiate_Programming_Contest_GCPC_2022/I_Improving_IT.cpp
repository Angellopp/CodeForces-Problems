#include <iostream>
#include <tuple>
using namespace std;

// Función para el Algoritmo de Euclides Extendido
tuple<int, int, int> gcdExtended(int a, int b) {
    if (a == 0)
        return make_tuple(b, 0, 1);
    int g, x1, y1;
    tie(g, x1, y1) = gcdExtended(b % a, a);
    int x = y1 - (b / a) * x1;
    int y = x1;
    return make_tuple(g, x, y);
}

// Función para resolver la ecuación diofántica ax + by = c
pair<int, int> solveDiophantine(int a, int b, int c) {
    int g, x, y;
    tie(g, x, y) = gcdExtended(a, b);
    if (c % g != 0)
        return make_pair(0, 0); // No hay solución
    x *= (c / g);
    y *= (c / g);

    // Ajustar signos según los signos de a y b originales
    if (a < 0) x = -x;
    if (b < 0) y = -y;

    return make_pair(x, y);
}

int main() {
    int a = 4; // Valores de ejemplo
    int b = -6; // Valores de ejemplo
    int c = 2;

    int g = get<0>(gcdExtended(a, b));
    if (abs(g) != 2) {
        cout << "No existe una solución ya que gcd(a, b) != 2" << endl;
    } else {
        int a1 = a / 2;
        int b1 = b / 2;
        pair<int, int> solution = solveDiophantine(a1, b1, 1);
        if (solution != make_pair(0, 0)) {
            int x = solution.first;
            int y = solution.second;
            cout << "La solución a " << a << "x + " << b << "y = " << c << " es x = " << 2 * x << ", y = " << 2 * y << endl;
        } else {
            cout << "No existe una solución" << endl;
        }
    }
    return 0;
}
