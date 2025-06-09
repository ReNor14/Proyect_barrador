#include <iostream>
#include <stdlib.h>
using namespace std;

//Carro de F1
//Dibujo del carro

//Funcion de dibujo 
Void drawF1Car(){
    cout << "      __" << endl;
    cout << "     / __ \\" << endl;
    cout << "    | |  | |" << endl;
    cout << "   ||_|_|" << endl;
    cout << " /_\\ /_\\" << endl;
    cout << "| (o) | (o) |" << endl;
    cout << " \\_/ \\_/" << endl;
    cout << "   /\\_/\\" << endl;
    cout << "  |____|" << endl;
    cout << "   \\__/" << endl;
    return 0;
}

int main(){
    drawF1Car(); //Llamar a la funcion para dibujar

    return 0;
}