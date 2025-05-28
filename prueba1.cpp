#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

int main() {

    srand(time(0)); // Semilla para aleatoriedad
    cout << fixed << setprecision(2); // Mostrar dinero con dos decimales

    // Arrays con datos del juego
    string pilotos[5] = {"Hamilton", "Verstappen", "Leclerc", "Sainz", "Perez"};
    string circuitos[3] = {"Monza", "Monaco", "Silverstone"};
    float probabilidades[5] = {0.3, 0.25, 0.2, 0.15, 0.1};
    
    // Variables del juego
    int opcion, carrera_apuesta, piloto_apuesta;
    float saldo = 1000, apuesta;
    char continuar;
    
    cout << "BIENVENIDO AL JUEGO DE APUESTAS DE FORMULA 1\n";
    
    do {
        // Menú principal con switch
        cout << "\n--- MENU PRINCIPAL ---\n";
        cout << "1. Ver pilotos\n";
        cout << "2. Ver circuitos\n";
        cout << "3. Hacer apuesta\n";
        cout << "4. Ver saldo\n";
        cout << "5. Salir\n";
        cout << "Elige una opcion: ";
        cin >> opcion;
        
        switch(opcion) {
            case 1:
                // Mostrar pilotos con for
                cout << "\n--- PILOTOS ---\n";
                for(int i = 0; i < 5; i++) {
                    cout << i+1 << ". " << pilotos[i] 
                         << " (Prob: " << probabilidades[i]*100 << "%)\n";
                }
                break;
                
            case 2:{
                // Mostrar circuitos con while
                cout << "\n--- CIRCUITOS ---\n";
                int j = 0;
                while(j < 3) {
                    cout << j+1 << ". " << circuitos[j] << "\n";
                    j++;
                }
                break;
            }    
            case 3:
                if (saldo <= 0) {
                 cout << "\nTu saldo es 0. ¿Deseas recargar saldo para seguir jugando? (s/n): ";
                    char recargar;
                    cin >> recargar;
                if (recargar == 's' || recargar == 'S') {
                    cout << "¿Cuánto deseas recargar? $";
                    float recarga;
                     cin >> recarga;
                if (recarga > 0) {
                     saldo += recarga;
                    cout << "Saldo recargado exitosamente. Nuevo saldo: $" << saldo << "\n";
                    } else {
                     cout << "Cantidad no válida. Fin del juego.\n";
                     break;
                    }
                    } else {
                        cout << "Gracias por jugar!\n";
                break;
                }   
                }
                // Sistema de apuestas
                cout << "\n--- HACER APUESTA ---\n";
                
                // Elegir carrera
                cout << "Circuitos disponibles:\n";
                for(int i = 0; i < 3; i++) {
                    cout << i+1 << ". " << circuitos[i] << "\n";
                }
                cout << "Elige un circuito (1-3): ";
                cin >> carrera_apuesta;
                
                // Validación con if-else
                if(carrera_apuesta < 1 || carrera_apuesta > 3) {
                    cout << "Opcion invalida!\n";
                    break;
                }
                
                // Elegir piloto
                cout << "\nPilotos disponibles:\n";
                for(int i = 0; i < 5; i++) {
                    cout << i+1 << ". " << pilotos[i] << "\n";
                }
                cout << "Elige un piloto (1-5): ";
                cin >> piloto_apuesta;
                
                if(piloto_apuesta < 1 || piloto_apuesta > 5) {
                    cout << "Opcion invalida!\n";
                    break;
                }
                
                // Monto de apuesta
                cout << "\nTu saldo es: $" << saldo << "\n";
                cout << "Cuanto quieres apostar? $";
                cin >> apuesta;
                
                if(apuesta > saldo) {
                    cout << "No tienes suficiente saldo!\n";
                } else {
                    // Simular resultado aleatorio
                    int ganador = rand() % 5;
                    
                    cout << "\nRESULTADO DE LA CARRERA:\n";
                    cout << "El ganador es: " << pilotos[ganador] << "\n";
                    
                    if(ganador == piloto_apuesta-1) {
                        float ganancia = apuesta * (1/probabilidades[ganador]);
                        cout << "GANASTE! $" << ganancia << "\n";
                        saldo += ganancia;
                    } else {
                        cout << "Perdiste tu apuesta\n";
                        saldo -= apuesta;
                    }
                }
                break;
                
            case 4:
                cout << "\nTu saldo actual es: $" << saldo << "\n";
                break;
                
            case 5:
                cout << "Gracias por jugar!\n";
                return 0;
                
            default:
                cout << "Opcion no valida!\n";
        }
        
        // Preguntar si quiere continuar
        cout << "\nQuieres continuar? (s/n): ";
        cin >> continuar;
        
    } while(continuar == 's' || continuar == 'S');
    
    cout << "Tu saldo final es: $" << saldo << "\n";
    cout << "Hasta pronto!\n";
    
    return 0;
}