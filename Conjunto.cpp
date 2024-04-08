/* 
 * TAD conjunto
 */

#include <iostream>
#include <cmath>

using namespace std;

class conjunto {
    private:



    public: 
        // sugest�o de m�todos p�blicos para sua classe conjunto
        void insere(int elemento);
        void remove(int elemento);
        bool membro(int elemento);

        void uniao(conjunto& C1, conjunto& C2);
        void intersecao(conjunto& C1, conjunto& C2);    
        void diferenca(conjunto& C1, conjunto& C2);
        
        unsigned tamanho();

        void imprime();
        void depura();     
};

// fun��o que retorna uma posi��o no vetor para um dado caracter mai�sculo
inline unsigned char2pos(char c) {
    return unsigned(c)- 65;
}


// *** n�o altere a fun��o principal sem antes consultar os professores ***
int main( ) {
    conjunto meusConjuntos[26];
    char operacao;
    // conjuntos s�o representados por letras mai�sculas
    char conjunto1, conjunto2, conjunto3;
    int elemento;
    unsigned pos1, pos2, pos3;

    do {
        cin >> operacao;
        switch (operacao) {
            case 'i': // inserir
                cin >> conjunto1 >> elemento;
                pos1 = char2pos(conjunto1);
                meusConjuntos[pos1].insere(elemento);
                break;
            case 'r': // remover
                cin >> conjunto1 >> elemento;
                pos1 = char2pos(conjunto1);
                meusConjuntos[pos1].remove(elemento);
                break;
            case 'm': // checa pertin�ncia
                cin >> conjunto1 >> elemento;
                pos1 = char2pos(conjunto1);
                cout << meusConjuntos[pos1].membro(elemento) << endl;
                break;
            case '+': // efetua uni�o
                // conjunto1 ter� o resultado da uni�o de conjunto2 com conjunto3
                cin >> conjunto1 >> conjunto2 >> conjunto3;
                pos1 = char2pos(conjunto1);
                pos2 = char2pos(conjunto2);
                pos3 = char2pos(conjunto3);
                meusConjuntos[pos1].uniao(meusConjuntos[pos2],meusConjuntos[pos3]);
                break;
            case '*': // efetua interse��o
                // conjunto1 ter� o resultado da interse��o de conjunto2 com conjunto3
                cin >> conjunto1 >> conjunto2 >> conjunto3;
                pos1 = char2pos(conjunto1);
                pos2 = char2pos(conjunto2);
                pos3 = char2pos(conjunto3);
                meusConjuntos[pos1].intersecao(meusConjuntos[pos2],meusConjuntos[pos3]);
                break;
            case '-': // efetua diferen�a
                // conjunto1 ter� o resultado da diferen�a de conjunto2 para o conjunto3
                cin >> conjunto1 >> conjunto2 >> conjunto3;
                pos1 = char2pos(conjunto1);
                pos2 = char2pos(conjunto2);
                pos3 = char2pos(conjunto3);
                meusConjuntos[pos1].diferenca(meusConjuntos[pos2],meusConjuntos[pos3]);
                break;
            case 't': // tamanho
                cin >> conjunto1;
                pos1 = char2pos(conjunto1);
                cout << meusConjuntos[pos1].tamanho() << endl;
                break;
            case 'd': // mostrar estrutura
                cin >> conjunto1;
                pos1 = char2pos(conjunto1);
                meusConjuntos[pos1].depura();
                break;
            case 'p': // imprimir dados
                cin >> conjunto1;
                pos1 = char2pos(conjunto1);
                meusConjuntos[pos1].imprime();
                break;
            case 's': // sair
                break;
            default:
                cout << "Op��o inv�lida!" << endl;
        }
    } while (operacao != 's');

    return 0; 
}
