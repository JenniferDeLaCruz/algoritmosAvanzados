# include <iostream>
# include <vector> 
# include <random>
# include <algorithm>

using namespace std;

// Problema 1: Suma máxima con programación dinámica.

class algoritmos{
    public:

        // Problema 1: Suma máxima. 

        void sumaMaxima(vector<int> a){
            bool flag = true;
            int resultado = 0; 
            int mayor = a[0];

            // Si el arreglo dado es de menos dos elementos, 
            // no es posible hacer una suma. 
            if (a.size() <= 2){
                return;
            }        

            // Ciclo iterativo. Empieza a 
            for(int i=3; i <= a.size(); i++){
                int suma = 0;

                if (a[i-1] <= mayor && flag ){
                    flag = false;
                }

                else{
                    flag = true;
                    for (int j = i-1; j>=0; j -= 2){
                        suma += a[j];
                    }
                }

                if (a[i-1] > mayor)
                    mayor = a[i-1];

                if ( resultado < suma && suma > 0)
                    resultado = suma;

                if ( suma < 0 )
                    resultado = suma;
            }

            cout << "La suma mas grande posible era : " << resultado;
            
        }

        // Función auxiliar que valida y establece en una matriz los movimientos que 
        // realizará el caballo en el tablero. 

        bool caballoAux(vector<vector<int>>& tablero, int n, int x, int y, int c){

            // Movimientos válidos por el caballo (coordenadas x,y).
            vector<int> cx = {1, 2, 2, 1, -1, -2, -2, -1};
            vector<int> cy = {2, 1, -1, -2, -2, -1, 1, 2};

            // Condición de escape de la función. 
            if (c == n*n)
                return true;

            // Ciclo que valida la posición del caballo. Puede probar entre 8 posiciones. 
            // Basado en backtracking. 
            for (int i=0; i<8; i++){
                int movx = x + cx[i];
                int movy = y + cy[i];
                if (movx >= 0 && movy >= 0 && movx < n && movy < n && tablero[movx][movy] == -1) {
                    tablero[movx][movy] = c;
                    if (caballoAux(tablero, n, movx, movy, c+1)) {
                        return true;
                    }
                    tablero[movx][movy] = -1;
                }

            }

            return false;
        
        }

        void caballoTablero(){
            int n;
            cout << "A continuacion se muestra el recorrido que realizara el caballo en un tablero de ajedrez. \nIndique de cuanto por cuanto es el tablero : ";
            cin >> n;

            vector<vector<int>> tablero(n, vector<int>(n, -1));
            tablero[0][0] = 0;

            if(caballoAux(tablero, n, 0, 0, 1)){

                for(int i = 0; i < n; i++){

                    for(int j = 0; j < n; j++)
                        cout << tablero[i][j] << " ";

                    cout <<endl;
                }  
                
            }else  
                cout << "No se encontro un recorrido valido." <<endl;

        }

       /*
            */

        int adivinarMaq (int n, int m){
            int op = -1;
            int cuenta = 1;
            int mom = 2;
            int num = 0;

            cout << "Piensa un numero del "<< n << " al " << m << ". La computadora intentara adivinarlo. \nEs " << num << " tu numero? (SI [1] / NO [2]) ";
            cin >> op;
            
            if(op == 2){
                cout << "El numero es mayor [1] o menor [2]? ";
                cin >> mom;
                if (mom == 1){
                    num = round(m/2);
                    m = m/2;
                    while(op !=1 ){
                        cout << "\nEs " << num << " tu numero? (SI [1] / NO [2]) "; 
                        cin >> op;
                        if (op == 2){
                            cout << "El numero es mayor [1] o menor [2]? ";
                            cin >> mom;
                            if ( mom == 1 ){
                                num = num + ceil(m/2);
                                m = m/2;
                                cuenta ++;
                                cout << "Ronda " << cuenta << ", M es : " << m << " y num es : " << num <<endl;

                                if (m == 1){
                                    m = 4;
                                }
                            }else{
                                num = num - ceil(m/2);
                                m = m/2;
                                cuenta ++;
                                cout << "Ronda " << cuenta << ", M es : " << m << " y num es : " << num <<endl;

                                if (m == 1){
                                    m = 4;
                                }
                            }
                        }
                    }
                    cout << "La maquina ha ganado en " << cuenta << " turnos." <<endl;
                }else{
                    num = round(n/2);
                    n = n/2;
                    while(op !=1 ){
                        cout << "\nEs " << num << " tu numero? (SI [1] / NO [2]) "; 
                        cin >> op;
                        if (op == 2){
                            cout << "El numero es mayor [1] o menor [2]? ";
                            cin >> mom;
                            if ( mom == 1 ){
                                num = num - ceil(n/2);
                                n = n/2;
                                cuenta ++;

                                if (n == -1){
                                    n = -4;
                                }
                                cout << "Ronda " << cuenta << ", N es : " << n << " y num es : " << num <<endl;
                                
                            }else{
                                num = num + ceil(n/2);
                                n = n/2;
                                cuenta ++;

                                if (n == -1 ){
                                    n = -4;
                                }
                                cout << "Ronda " << cuenta << ", N es : " << n << " y num es : " << num <<endl;
                            }
                        }
                    }
                    cout << "La maquina ha ganado en " << cuenta << " turnos." <<endl;
                }
            }else{
                cout << "La maquina ha ganado en 1 turno.";
            }
        }


    // Función auxiliar. Verifica si se ha recorrido todo el tablero
    bool reTab(vector<vector<int>>& tablero,int n) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (tablero[i][j] == -1)
                    return false;
        return true;
    }

    // Empieza la función de backtracking para recorrer el tablero
    bool recorrido(vector<vector<int>>& tablero,int x, int y, int movCuenta, int n) {
        
        // Verifica si la casilla existe y aún no ha sido visitada
        if  (!(x >= 0 && x < n && y >= 0 && y < n && tablero[x][y] == -1))
            return false;

        tablero[x][y] = movCuenta;

        if (reTab(tablero, n))
            return true;

        // Movimientos válidos del rey. 
        int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
        int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};

        for (int i = 0; i < 8; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (recorrido(tablero, newX, newY, movCuenta + 1, n))
                return true;
        }

        // Si no se pudo encontrar una solución, retrocede
        tablero[x][y] = -1;
        return false;
    }

    void rey() {
        
        int n;
        cout << "A continuacion se muestra el recorrido que realizara el rey en un tablero de ajedrez. \nIndique de cuanto por cuanto es el tablero : ";
        cin >> n;

        vector<vector<int>> tablero(n, vector<int>(n, -1));
        tablero[0][0] = 0;

        // Inicializa el tablero
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                tablero[i][j] = -1;

        int inicioX, inicioY;
        cout << "Ingrese las coordenadas iniciales del rey (x y): ";
        cin >> inicioX >> inicioY;

        if (recorrido(tablero, inicioX, inicioY, 0, n)) {
            cout << "Recorrido exitoso : " <<endl;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << tablero[i][j] << " ";
                }
                cout << endl;
            }
        } else {
            cout << "No se encontro un recorrido valido." <<endl;
        }
    }

    void dragonesCaballeros() {
        int n, m;
        cout << "Ingrese el numero de dragones: ";
        cin >> n;
        cout << "Ingrese el numero de caballeros: ";
        cin >> m;
        
        vector<int> dragonCabeza(n);
        vector<int> caballeroAlt(m);
        
        cout << "Ingrese los diametros de las cabezas de dragon: ";
        for (int i = 0; i < n; i++) {
            cin >> dragonCabeza[i];
        }
        
        cout << "Ingrese las alturas de los caballeros: ";
        for (int i = 0; i < m; i++) {
            cin >> caballeroAlt[i];
        }
        
        sort(dragonCabeza.begin(), dragonCabeza.end());
        sort(caballeroAlt.begin(), caballeroAlt.end());
        
        int dragonIndex = 0;
        int knightIndex = 0;
        while (dragonIndex < n && knightIndex < m) {
            if (dragonCabeza[dragonIndex] <= caballeroAlt[knightIndex]) {
                dragonIndex++;
            }
            knightIndex++;
        }
        
        if (dragonIndex == n) 
            cout << "Si es posible cortar todas las cabezas de dragon." << endl;
        else
            cout << "No es posible cortar todas las cabezas de dragon." << endl;        
    }
     

};

int main(){
    algoritmos a;
    vector<int> ap = {5,4,7,8,10,12,24,32,62,17,20};
    vector<int> ap2 = {1,2,3,4};
    vector<int> ap3 = {2,120,64,3,9,100,37,62};
    vector<int> ap4 = {-17,-28,-32,-5,-1,0,-41};
    vector<int> ap5 = {4,3,-20,120,83,-42};
    vector<int> ap6 = {-23,-17,-82,-5,-92};
    
    //a.sumaMaxima(ap6);
    // a.adivinarMaq(-10000, 10000);
    // a.caballoTablero();
    // a.rey();
    a.dragonesCaballeros();
    return 0;
}