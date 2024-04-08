#include <iostream>
using namespace std;

typedef int Dado;

class Noh {
    friend class Fila;
    public:
        Noh(Dado d); // Construtor do Noh;
    private:  // Atributos do Noh;
        Dado mDado;
        Noh* mPtProximo;
};
class Fila {
    public: // Metodos;
        Fila(); // Construtor;
        ~Fila(); // Destrutor;
        void Enfileirar(const Dado& d); // Insere na Fila;
        Dado Desenfileirar(); // Remove da Fila;
        void Imprimir(); // Fins de Depuracao;
        void LimparTudo(); // Remover todos os elementos da Fila;
        Dado Espia(){ return mPtPrimeiro->mDado;}
        unsigned int Tamanho(){ return mTamanho;}
        bool Vazia(); 
    private: // Atributos;
        Noh* mPtPrimeiro;
        Noh* mPtUltimo;
        unsigned int mTamanho;
};

Noh::Noh(Dado d) {
    mDado = d;
    mPtProximo = NULL;
}
Fila::Fila() {
    mPtPrimeiro = NULL;
    mPtUltimo = NULL;
    mTamanho = 0;
}
Fila::~Fila() {
    while (not Vazia()) {
        Desenfileirar();
    }
    mTamanho = 0;
    mPtPrimeiro = NULL;
    mPtUltimo = NULL;
}
void Fila::Enfileirar (const Dado& d) {
    Noh* novo = new Noh(d);
    if (Vazia()) {
        mPtPrimeiro = novo;
    }
    else {
        mPtUltimo->mPtProximo = novo;
    }
    mPtUltimo = novo;
    mTamanho++;
}
Dado Fila::Desenfileirar() {
    Dado removido = mPtPrimeiro->mDado;
    Noh* ptAuxiliar = mPtPrimeiro;
    if (mTamanho == 1) {  // Se não fizer isso o mPtUltimo não é apontado para NULL;
        mPtUltimo = NULL;
    }
    else {
        mPtPrimeiro = mPtPrimeiro->mPtProximo;
    }
    delete ptAuxiliar;
    mTamanho--;
    return removido;
}
void Fila::Imprimir() {
    if (Vazia()) {
        cerr << "Fila Vazia!\n";
    }
    else {
        Noh* ptAuxiliar = mPtPrimeiro;
        while (ptAuxiliar != NULL) {
            cout << ptAuxiliar->mDado << " "    ;
            ptAuxiliar = ptAuxiliar->mPtProximo;
        }
    }
}
void Fila::LimparTudo() {
    if (Vazia()) {
        cerr << "Fila Vazia\n";
    }
    else {
        while (not Vazia()){
            Desenfileirar();
        }
    }
}
bool Fila::Vazia() {
    if (mTamanho == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    Fila fila;
    char comando;
    Dado valor;
    string tipo;
    do {
        cin >> comando;
        switch (comando) {
            case 'e': // Inserir(Enfileirar);
            	cin >> tipo;
                cin >> valor;
                fila.Enfileirar(valor);
                break;
            case 'r': // Revomer(Desenfileirar);
                if (fila.Tamanho() == 0) {
                    cerr << "Fila Vazia!\n";
                }
                else {
                    cout << fila.Desenfileirar() << endl;
                }
                break;
            case 't': // Ver Tamanho da Fila;
                cout << fila.Tamanho();
                break;
            case 'i':
                fila.Imprimir();
                break;
            case 'l': // Limpar Tudo(Remove Todos os Elementos da Fila);
                fila.LimparTudo();
                break;
            case 'f': //Finalizar
                // Checado no While;
                break;
            default:
                cerr << "Comando Invalido!\n";
        }
        
    } while (comando !='f');
    return 0;
}
