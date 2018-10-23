#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>

using std::string;
using std::getline;
using namespace std;

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
    char regraE[10];
    char regraD[10];
    char palavra[51];
    char simbolo_inicial[5];
    char conjunto_nao_terminais[100], conjunto_terminais[100];
    string triangulo[60][60], simbolo;
    int iterador_terminais, iterador_palavras;

    int cond_parada;

    scanf("%s", simbolo_inicial);
    while(1){
        //ler simboloinicial, conjuntos de terminais e conjunto de não terminais em forma de string
        scanf("%s", conjunto_terminais);
        scanf("%s", conjunto_nao_terminais);
        vector<string> regras_E;
        vector<string> regras_D;
        vector<string> palavras;
        //ler regras enquanto nao encontrar uma regra do tipo '# -> #'
        cond_parada = 1;
        while(cond_parada == 1){
            scanf("%s -> %s", regraE, regraD );
            if( regraE[0] == '#'){ 
                cond_parada = 0;
            } else {
                regras_E.push_back(regraE);
                regras_D.push_back(regraD);
            }
        }
        //ler palavras enquanto nao encontrar uma palavra do tipo '#'
        cond_parada = 1;
        while(cond_parada == 1){
            scanf("%s", palavra);
            if (palavra[0] == '#'){
                cond_parada = 0;
            } else{
                palavras.push_back(palavra);
            }
        }
    
        cout << "Instancia " << iterador << endl;
        //laco de repeticao para percorrer todas as palavras
        for (iterador_palavras=0; iterador_palavras < palavras.size(); iterador_palavras++) {

            //laco de repeticao para percorrer todos os caracteres de uma determinada palavra
            for (iterador_terminais =1; iterador_terminais <= palavras[iterador_palavras].size(); iterador_terminais++){

                //determinado caracter da palavra    
                char simbolo= palavras[iterador_palavras][iterador_terminais-1];

                //pesquisar NAO TERMINAIS que geram o simbolo
                string lista_simbolos = "";
                //laco de repeticao para percorrer todas as regras
                for (int iterador_regras=0; iterador_regras < regras_E.size(); iterador_regras++) {
                    //se um determinado simbolo a direita da regra for igual ao simbolo terminal
                    if(regras_D[iterador_regras][0] == simbolo){
                        //adiciona na lista de simbolos o simbolo a esquerda daquela regra
                        lista_simbolos += regras_E[iterador_regras][0];
                    }
                }
                if(lista_simbolos.size() == 0) {
                    lista_simbolos = "*";
                }
                //Adiciona na primeira linha do triangulo a lista de simbolos encontrados que geram o determinado terminal  
                triangulo[1][iterador_terminais] = lista_simbolos;
            }

            int tamanho_palavra= palavras[iterador_palavras].size();
            string lista_simbolos;

            //laco para percorrer as linha do triangulo
            for(int linha= 2; linha < tamanho_palavra+1; linha++) {
                //laco para percorrer as colunas do triangulo
                for(int coluna= 1; coluna < (tamanho_palavra-linha+2); coluna++){
                    lista_simbolos = "";

                    for( int aux = 1; aux < linha; aux++) {

                        //lacos de repeticao para fazer as combinacoes de simbolos em posicoes do tringulo que possuem mais de um simbolo
                        for (int item1 = 0; item1 < triangulo[linha-aux][coluna].size(); item1++) {
                            for (int item2 = 0; item2 < triangulo[aux][(linha-aux)+coluna].size(); item2++) {
                                //concatena os simbolos de duas posicoes do triangulo
                                simbolo = "";
                                simbolo += triangulo[linha-aux][coluna][item1];
                                simbolo += triangulo[aux][(linha-aux)+coluna][item2];
                                //laco de repeticao para percorrer todas as regras
                                for (int iterador_regras=0; iterador_regras < regras_E.size(); iterador_regras++) {
                                    //se um determinado simbolo a direita da regra for igual ao simbolo gerado 
                                    if(regras_D[iterador_regras] == simbolo){
                                        //adiciona na lista de simbolos o simbolo a esquerda daquela regra
                                        lista_simbolos += regras_E[iterador_regras][0];
                                    }
                                }
                            }
                        }
                    }

                    if(lista_simbolos.size() == 0) {
                        lista_simbolos = "*";
                    } else {
                        //retira as variaveis repetidas da lista de simbolos
                        lista_simbolos = remove_repetidos(lista_simbolos);   
                    }
                    //Adiciona na determinada linha do triangulo a lista de simbolos encontrados
                    triangulo[linha][coluna] = lista_simbolos;
                }
            }
            int pertence = 0;
            //percorre a lista de simbolos da posicao do topo do trinagulo
            for (int item = 0; item < triangulo[tamanho_palavra][1].size(); item++) {
                //se algum dos simbolos da lista de simbolos da posicao do topo do trinagulo for igual ao simbolo inicial a palavra e valida
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
        if(scanf("%s", simbolo_inicial) != EOF){
            cout << endl;
        } else {
            break;
        }
    }
    return 0;
}
