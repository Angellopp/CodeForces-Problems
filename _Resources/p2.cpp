#include <iostream>
using namespace std;

class ResistenciaElectrica {
    private:
        double valor;

    public:
        // Constructor
        ResistenciaElectrica(double valor){
            this->valor = valor;
        }

        void imprimirValor() {
            cout << valor << " ohmios" << endl;
        }
        // Suma en serie y paralelo
        ResistenciaElectrica sumaSerie(ResistenciaElectrica resis2) {
            return ResistenciaElectrica(valor + resis2.valor);
        };
        ResistenciaElectrica sumaParalelo(ResistenciaElectrica resis2) {
            return ResistenciaElectrica(1 / ((1 / valor) + (1 / resis2.valor)));
        };
};

int main() {
    int valor1, valor2;
    cout << "Ingrese el valor de la primera resistencia (en ohmios): ";
    cin >> valor1;
    cout << "Ingrese el valor de la segunda resistencia (en ohmios): ";
    cin >> valor2;
    ResistenciaElectrica resistencia1(valor1);
    ResistenciaElectrica resistencia2(valor2);
    ResistenciaElectrica enSerie = resistencia1.sumaSerie(resistencia2);
    ResistenciaElectrica enParalelo = resistencia1.sumaParalelo(resistencia2);
    cout << "Resistencia en serie: ";
    enSerie.imprimirValor();
    cout << "Resistencia en paralelo: ";
    enParalelo.imprimirValor();

}

