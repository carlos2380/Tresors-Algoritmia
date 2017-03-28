#include <iostream>
#include <vector>
#include <queue>
using namespace std;



struct Casilla {
    char tipo;
    bool vist;
    int distancia;
    int fila;
    int colum;
};

typedef vector<vector<Casilla> > Mapa;

void leer_mapa(Mapa &mapa) {
    for(int i = 0; i < mapa.size(); ++i) {
        for(int j = 0; j < mapa[0].size(); ++j){
            cin >> mapa[i][j].tipo;
            mapa[i][j].vist  = false;
            mapa[i][j].fila  = i;
            mapa[i][j].colum  = j;
        }
    }
}

/*void escribir_mapa(Mapa &mapa) {
    for(int i = 0; i < mapa.size(); ++i) {
        for(int j = 0; j < mapa[0].size(); ++j){
            cout << mapa[i][j].tipo << " ";
        }
        cout << endl;
    }
}*/

bool posicion_ok(int fila, int columna, Mapa &mapa) {
     
     if(fila < 0 or fila >= mapa.size() or columna < 0 or columna >= mapa[0].size()) return false;
     if(mapa[fila][columna].vist == true) return false;
     if(mapa[fila][columna].tipo == 'X') return false;
     return true;
    
}

int trobar_tresor(int f_ini, int c_ini, Mapa &mapa)
{
        int distancia = 0;
        bool trobat = false;
        int pasos = -1;
        
        queue<Casilla> q;
        q.push(mapa[f_ini][c_ini]);
       
        while(not q.empty() and trobat == false)
        {
                Casilla c = q.front();
                distancia = c.distancia;
                q.pop();
                mapa[c.fila][c.colum].vist = true;
                if(c.tipo == 't') {
                   trobat = true;
                   pasos = c.distancia;
                   return pasos;
                }
                if(posicion_ok(c.fila -1, c.colum, mapa)) {
                    mapa[c.fila -1][c.colum].distancia = distancia +1;
                    q.push(mapa[c.fila -1][c.colum]);
                }
                if(posicion_ok(c.fila, c.colum -1, mapa)) {
                    mapa[c.fila][c.colum -1].distancia = distancia +1;
                    q.push(mapa[c.fila ][c.colum-1]);
                }
                if(posicion_ok(c.fila +1, c.colum, mapa)) {
                    mapa[c.fila+1][c.colum].distancia = distancia +1;
                    q.push(mapa[c.fila +1][c.colum]);
                }
                if(posicion_ok(c.fila, c.colum +1, mapa)){
                    mapa[c.fila][c.colum +1].distancia = distancia +1;
                    q.push(mapa[c.fila ][c.colum +1]);
                }
        }
        return pasos;
}

int main() {
  int filas, columnas;
  cin >> filas >> columnas;
  
  Mapa mapa (filas, vector<Casilla> (columnas));
  leer_mapa(mapa);
  
  //escribir_mapa(mapa);
  int f_ini, c_ini;
  cin >> f_ini >> c_ini;
  int distancia = trobar_tresor(f_ini - 1, c_ini - 1, mapa);
  
  if (distancia > -1) cout << "distancia minima: " << distancia << endl;
  else cout << "no es pot arribar a cap tresor" << endl;
  
}