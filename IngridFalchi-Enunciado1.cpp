/* Classe pilha, um pilha (LIFO) implementada usando encadeamento
 *
 * by Joukim, 2017, Estruturas de Dados
 *
 */

#include <iostream>

using namespace std;

class noh {
friend class pilha;
private:
    int dado; // poderia ser outro tipo de variÃ¡vel
    noh* prox;
};

// pilha dinamicamente encadeada
class pilha {
private:
    noh* topo;
    int tamanho;

public:
    pilha();
    ~pilha();
    void push(int d) { empilha(d); }
    void empilha(int d);
    int pop() { return desempilha(); }
    int desempilha(); // retorna o topo da pilha
    int espia(); // espia o topo da pilha
    bool vazia();
    void limpaPilha(); //limpa a pilha
};

/* implementar os métodos da pilha */


//  Implementar aqui
int acessaElemento(pilha& p1, int elemento){
//  Implementar aqui
}

int main() {
    pilha p1;
    int n, numero, elemento;
    cin >> n;

    while (n > 0) {
        cin >> numero;
        p1.empilha(numero);
        n--;
    }

    cin >> elemento;
    cout << acessaElemento(p1,elemento) << endl;

    while (not p1.vazia()) {
        cout << p1.desempilha() << " ";
    }

    cout << endl;

    return 0;
}
