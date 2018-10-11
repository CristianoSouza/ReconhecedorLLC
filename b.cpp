#include <iostream>
#include <string>
#include <vector>
//#include <boost/algorithm/string.hpp>
// g++ -o b b.cpp

using std::string;
using std::getline;
using namespace std;
//using namespace boost;

string remove_repetidos(string lista_simbolos){
    string lista_sem_repetidos = "";

    for (int i =0; i < lista_simbolos.size(); i++){
        if (lista_sem_repetidos.find(lista_simbolos[i]) == -1){
            lista_sem_repetidos += lista_simbolos[i];
        }
    }
    return lista_sem_repetidos;
}

int main() {

    int iterador= 1;
    string simbolo_inicial, conjunto_nao_terminais, conjunto_terminais, regra, palavra;
    string triangulo[500][500], simbolo;
    int iterador_terminais, iterador_palavras;

    int cond_parada = 1;
    ios_base::sync_with_stdio(false);

    while (!cin.eof() ){
        getline(cin,simbolo_inicial );
        getline(cin, conjunto_terminais);
        getline(cin, conjunto_nao_terminais);

        vector<string> regras_E;
        vector<string> regras_D;
        vector<string> palavras;
        cond_parada = 1;
        while(cond_parada == 1){
            getline(cin, regra);
            if (regra == "# -> #"){
                cond_parada = 0;
            } else{
                std::size_t pos = regra.find(" -> ");
                regras_E.push_back(regra.substr(0,pos));
                regras_D.push_back(regra.substr(5));
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


        cout << "Instancia " << iterador << endl;
        for (iterador_palavras=0; iterador_palavras < palavras.size(); iterador_palavras++) {

            //for dos terminais
            for (iterador_terminais =1; iterador_terminais <= palavras[iterador_palavras].size(); iterador_terminais++){

                char simbolo= palavras[iterador_palavras][iterador_terminais-1];

                //pesquisar NAO TERMINAIS que geram o simbolo
                string lista_simbolos = "";
                for (int iterador_regras=0; iterador_regras < regras_E.size(); iterador_regras++) {
                    if(regras_D[iterador_regras][0] == simbolo){
                        lista_simbolos += regras_E[iterador_regras][0];
                    }
                }
                if(lista_simbolos.size() == 0) {
                    lista_simbolos = "*";
                } 
                triangulo[1][iterador_terminais] = lista_simbolos;
            }

            int tamanho_palavra= palavras[iterador_palavras].size();
            string lista_simbolos;
            for(int linha= 2; linha < tamanho_palavra+1; linha++) {
                for(int coluna= 1; coluna < (tamanho_palavra-linha+2); coluna++){
                    lista_simbolos = "";

                    for( int aux = 1; aux < linha; aux++) {

                        for (int item1 = 0; item1 < triangulo[linha-aux][coluna].size(); item1++) {
                            for (int item2 = 0; item2 < triangulo[aux][(linha-aux)+coluna].size(); item2++) {
                                simbolo = "";
                                simbolo += triangulo[linha-aux][coluna][item1];
                                simbolo += triangulo[aux][(linha-aux)+coluna][item2];

                                for (int iterador_regras=0; iterador_regras < regras_E.size(); iterador_regras++) {
                                    if(regras_D[iterador_regras] == simbolo){
                                        lista_simbolos += regras_E[iterador_regras][0];
                                    }
                                }
                            }
                        }
                    }

                    if(lista_simbolos.size() == 0) {
                        lista_simbolos = "*";
                    } else {
                        lista_simbolos = remove_repetidos(lista_simbolos);   
                    }
                    triangulo[linha][coluna] = lista_simbolos;
                }
            }
            int pertence = 0;
            for (int item = 0; item < triangulo[tamanho_palavra][1].size(); item++) {
                if(triangulo[tamanho_palavra][1][item] == simbolo_inicial[0]){
                    pertence = 1;
                }
            }
            if (pertence == 1){
                cout <<  palavras[iterador_palavras] <<  " e uma palavra valida" << endl;
            }else{
                cout << palavras[iterador_palavras] << " nao e uma palavra valida" << endl;
            }
        }
        iterador++;
        cout << endl;
    }
    return 0;
}
