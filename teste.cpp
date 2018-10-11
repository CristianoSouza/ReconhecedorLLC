#include <iostream>
#include <cstdio>
#include <cstdlib>
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
    string simbolo_inicial[500], conjunto_nao_terminais, conjunto_terminais, regra, palavra;
    string triangulo[500][500], simbolo;
    int iterador_terminais, iterador_palavras;

    int cond_parada = 1;
    ios_base::sync_with_stdio(false);
    vector<string> regras_E[500];
    vector<string> regras_D[500];
    vector<string> palavras[500];

    while (!cin.eof() ){
        //cin >> simbolo_inicial){
        getline(cin, simbolo_inicial[iterador] );
        getline(cin, conjunto_terminais);
        getline(cin, conjunto_nao_terminais);

        
        cond_parada = 1;
        while(cond_parada == 1){
            getline(cin, regra);
            if (regra == "# -> #"){
                cond_parada = 0;
            } else{
                //vector<string> str_split;
                //split(str_split,regra,is_any_of(" "));
                //regras_E.push_back(str_split[0].c_str());
                //regras_D.push_back(str_split[2].c_str());
                std::size_t pos = regra.find(" -> ");
                regras_E[iterador].push_back(regra.substr(0,pos));
                regras_D[iterador].push_back(regra.substr(5));
            }
        }

        cond_parada = 1;
        while(cond_parada == 1){
            getline(cin, palavra);
            if (palavra == "#"){
                cond_parada = 0;
            } else{
                palavras[iterador].push_back(palavra);
            }
        }


        //cout << "Dados: " << endl;
        //cout << "Simbolo_inicial: " << simbolo_inicial << endl;
        //cout << "Conjunto_terminais: " << conjunto_terminais << endl;
        //cout << "Conjunto_nao_terminais: " << conjunto_nao_terminais << endl;
        //cout << "REGRAS: " << endl;

        //for ( int i=0; i< regras_E.size(); i++) {
        //    cout << regras_E[i] << ", " << regras_D[i]<< endl;
        //}

        //cout << "Palavras: " << endl;
        cout << endl;
        cout << "Instancia " << iterador << endl;
        for (iterador_palavras=0; iterador_palavras < palavras[iterador].size(); iterador_palavras++) {

            //cout << palavras[iterador_palavras] << endl;

            //for dos terminais
            //cout << "PALAVRAS SIXE: " << palavras[iterador_palavras].size() << endl;
            for (iterador_terminais =1; iterador_terminais <= palavras[iterador][iterador_palavras].size(); iterador_terminais++){

                char simbolo= palavras[iterador][iterador_palavras][iterador_terminais-1];
                //cout << "Simbolo: " << simbolo << endl;
                //cout << "iterador_terminais: " << iterador_terminais << endl;

                //pesquisar NAO TERMINAIS que geram o simbolo
                string lista_simbolos = "";
                for (int iterador_regras=0; iterador_regras < regras_E[iterador].size(); iterador_regras++) {
                    if(regras_D[iterador][iterador_regras][0] == simbolo){
                        //cout << "Encontrado: " << regras_E[iterador_regras][0] << " ---> " << simbolo << endl;
                        lista_simbolos += regras_E[iterador][iterador_regras][0];
                    }
                }
                if(lista_simbolos.size() == 0) {
                    lista_simbolos = "*";
                } else {
                    lista_simbolos = remove_repetidos(lista_simbolos);   
                }
                triangulo[1][iterador_terminais] = lista_simbolos;
                //cout << triangulo[1][iterador_terminais] << endl;
                //cout << "Lista obtida para o terminal " << simbolo << ": " << endl;
                //for ( int k=0; k< 5; k++) {
                   //cout << triangulo[1][iterador_terminais][k] << endl;
                //}
            }


            int tamanho_palavra= palavras[iterador][iterador_palavras].size();
            string lista_simbolos;
            for(int linha= 2; linha < tamanho_palavra+1; linha++) {
                for(int coluna= 1; coluna < (tamanho_palavra-linha+2); coluna++){
                    lista_simbolos = "";

                    for( int aux = 1; aux < linha; aux++) {
                        //cout << "V" << linha << coluna << " = V" << linha-aux << coluna << " + V" << aux << linha-aux+coluna << endl;
                        //cout << "V" << linha-aux << coluna<<  "= "<< triangulo[linha-aux][coluna][0] << endl;
                        //cout << "V" << aux << linha-aux+coluna << "= " << triangulo[aux][(linha-aux)+coluna][0] << endl;
                        //cout << "tamanho: " << triangulo[aux][(linha-aux)+coluna].size() << endl;

                        for (int item1 = 0; item1 < triangulo[linha-aux][coluna].size(); item1++) {
                            for (int item2 = 0; item2 < triangulo[aux][(linha-aux)+coluna].size(); item2++) {
                                //cout << "item_a: " << triangulo[linha-aux][coluna][item1] << " -- itemb: " << triangulo[aux][(linha-aux)+coluna][item2]<< endl;
                                simbolo = "";
                                simbolo += triangulo[linha-aux][coluna][item1];
                                simbolo += triangulo[aux][(linha-aux)+coluna][item2];
                                //cout << "Simbolo: " << simbolo << endl;


                                for (int iterador_regras=0; iterador_regras < regras_E[iterador].size(); iterador_regras++) {
                                    if(regras_D[iterador][iterador_regras] == simbolo){
                                        //cout << "Encontrado: " << regras_E[iterador_regras][0] << " ---> " << simbolo << endl;
                                        lista_simbolos += regras_E[iterador][iterador_regras][0];
                                    }
                                }


                                //lista = getSimbolo(simbolo, regras)
                                //lista_simbolos = lista_simbolos + lista
                                //print('Lista obtida para ' + simbolo + ': ')
                                //print(lista_simbolos)


                                //print('------------------')
                                //print( str(triangulo[0][0]))
                                //print( str(simbolo_inicial))
                                //print(str(triangulo[0][0]) == str(simbolo_inicial))
                                //print('------------------')
                            }
                        }
                    }
                    //if not lista_simbolos:
                    //  lista_simbolos.append('*')

                    //lista_simbolos = remove_repetidos(lista_simbolos)
                    //print('Lista adicionada ao triangulo')
                    //print(lista_simbolos)
                    //triangulo[linha].append(lista_simbolos)
                    //cout << "lista simbolos: " << lista_simbolos << endl;
                    if(lista_simbolos.size() == 0) {
                        lista_simbolos = "*";
                    } else {
                        lista_simbolos = remove_repetidos(lista_simbolos);   
                    }
                    //cout << "lista simbolos ADC: " << lista_simbolos << endl;
                    triangulo[linha][coluna] = lista_simbolos;
                    //cout << "triangulo[" << linha << "][" << coluna << "]: " << triangulo[linha][coluna]  << endl;
                }
            }
            int pertence = 0;
            //for item in triangulo[tamanho_palavra][1]:
            //cout << "triangulo[" << tamanho_palavra << "][" << 1 << "]: " << triangulo[tamanho_palavra][1]  << endl;
            for (int item = 0; item < triangulo[tamanho_palavra][1].size(); item++) {
                //cout << "Simbolo_inicial: " << simbolo_inicial << endl;
                //cout << "Item: " << triangulo[tamanho_palavra][1][item] << endl;
                if(triangulo[tamanho_palavra][1][item] == simbolo_inicial[iterador][0]){
                    pertence = 1;
                }
            }
            if (pertence == 1){
                cout <<  palavras[iterador][iterador_palavras] <<  " e uma palavra valida" << endl;
            }else{
                cout << palavras[iterador][iterador_palavras] << " nao e uma palavra valida" << endl;
            }
        }
        iterador++;
    }
    return 0;
}
