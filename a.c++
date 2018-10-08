#include <iostream>
#include <string>
 
using namespace std;
 
void trocar (int &a, int &b) {
    int aux = a;
    a = b;
    b = aux;
}

int main() {
    int iterador= 0;
    char simbolo_inicial;
    char conjunto_nao_terminais [100],conjunto_terminais[100],regra[100], palavra[50];
    int cond_parada = 1;
    ios_base::sync_with_stdio(false);
    
    while (cin >> simbolo_inicial) {
        cin.get(conjunto_nao_terminais, 100);
        cin.get(conjunto_terminais, 100);
        
        cond_parada = 1
        while(cond_parada == 1){
            cin.get(regra, 100);
            if (regra == '# -> #'){
                cond_parada = 0
            } else{
                //regras.append([regra[0], regra.split("-> ")[1]])
            }
        }

        cond_parada = 1
        while(cond_parada == 1){
            cin.get(palavra, 100);
            if (palavra == '# -> #'){
                cond_parada = 0
            } else{
                //regras.append([regra[0], regra.split("-> ")[1]])
            }
        }
        cout << simbolo_inicial
        cout << conjunto_terminais
        cout << conjunto_nao_terminais
    }
    return 0;
}