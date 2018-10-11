#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp> 

using std::string;
using std::getline;
using namespace std;
using namespace boost;


vector<string> getSimbolo (string simbolo, vector<string> regras_E, vector<string> regras_D) {
    cout << "Simbolo: " << simbolo << endl;
    vector<string> lista_simbolos;
    for (int i=0; i < regras_E.size(); i++) {
        if(regras_D[i] == simbolo){
            lista_simbolos.push_back(regras_E[i]);
            cout << "Encontrado: " << regras_E[i] << " ---> " << simbolo << endl;
        }
    }
    return lista_simbolos;
}

int main() {
    int iterador= 0;
    string simbolo_inicial, conjunto_nao_terminais, conjunto_terminais, regra, palavra;
    vector<string> regras_E;
    vector<string> regras_D;
    vector<string> palavras;
    
    int cond_parada = 1;
    ios_base::sync_with_stdio(false);
    
    while (getline(cin,simbolo_inicial )) {
        getline(cin, conjunto_terminais);
        getline(cin, conjunto_nao_terminais);

        cond_parada = 1;
        while(cond_parada == 1){
            getline(cin, regra);
            if (regra == "# -> #"){
                cond_parada = 0;
            } else{
                vector<string> str_split; 
                split(str_split,regra,is_any_of(" ")); 
                regras_E.push_back(str_split[0].c_str());
                regras_D.push_back(str_split[2].c_str());
            }
        }

        cond_parada = 1;
        while(cond_parada == 1){
            getline(cin, palavra);
            if (palavra == "#"){
                cond_parada = 0;
            } else{
                palavras.push_back(palavra);
            }
        }
        cout << "Dados: " << endl;
        cout << "simbolo_inicial: " << simbolo_inicial << endl;
        cout << "conjunto_terminais: " << conjunto_terminais << endl;
        cout << "conjunto_nao_terminais: " << conjunto_nao_terminais << endl;
        cout << "REGRAS: " << endl;

        for ( int i=0; i< regras_E.size(); i++) {
            cout << regras_E[i] << ", " << regras_D[i]<< endl;
        }
        
        cout << "Palavras: " << endl;
        for ( int j=0; j < palavras.size(); j++) {
            cout << palavras[j] << endl;
            
            //triangulo = []
            //triangulo.append('X')
            //triangulo.append([])

            //triangulo[1].append('X')
            for (int i =0; i < palavras[j].size(); i++ ){
                //lista = getSimbolo(palavra[i-1],regras)
                cout << "Lista obtida para o terminal " << palavras[j][i] << ": " << endl;
                //print(lista)
                //if not lista:
                //      lista.append('*')
                //triangulo[1].append(lista)
            }
        }
        
        
    }
    return 0;
}