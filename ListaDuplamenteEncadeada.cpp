#include <iostream>
using namespace std;
typedef int Dado;

class Noh{
    friend class Lista;
    public:
        Noh(Dado d);
    private:
        Dado mDado;
        Noh* mPtAnterior;
        Noh* mPtProximo;
};
Noh::Noh(Dado d) {
    mDado = d;
    mPtAnterior = NULL;
    mPtProximo = NULL;
}
class Lista{
    public:
        Lista();
        ~Lista();
        void InserirNoInicio(const Dado& valor);
        void InserirNoFim(const Dado& valor);
        void InserirNaPosicao(unsigned int pos, const Dado& valor);
        Dado RemoverNoInicio(); 
        Dado RemoverNoFim();
        Dado RemoverNaPosicao(unsigned int pos);
        int Buscar(const Dado& valor);
        void Imprimir();
        void LimparTudo();
        unsigned int Tamanho(){return mTamanho;};
        bool Vazia();
    private:
        Noh* mPtPrimeiro;
        Noh* mPtUltimo;
        unsigned int mTamanho;
};
Lista::Lista() {
    mPtPrimeiro = NULL;
    mPtUltimo = NULL;
    mTamanho = 0;
}
Lista::~Lista() {
    LimparTudo();
}
void  Lista::InserirNoInicio(const Dado& valor) {
    Noh* novo = new Noh(valor);
    if (Vazia()) {
        mPtPrimeiro = novo;
        mPtUltimo = novo;
    }
    else {
        novo->mPtProximo = mPtPrimeiro;
        mPtPrimeiro->mPtAnterior = novo;
        mPtPrimeiro = novo;
    }
    mTamanho++;
}
void Lista::InserirNoFim(const Dado& valor) {
    Noh* novo = new Noh(valor);
    if (Vazia()) {
        mPtPrimeiro = novo;
        mPtUltimo = novo;
    }
    else {
        mPtUltimo->mPtProximo = novo;
        novo->mPtAnterior = mPtUltimo;
        mPtUltimo = novo;
    }
    mTamanho++;
}
void Lista::InserirNaPosicao(unsigned int pos, const Dado& valor) {
     if (pos == 0) {
        InserirNoInicio(valor);
    }
    else if (pos == mTamanho){
        InserirNoFim(valor);
    }
    else {
        Noh* novo = new Noh (valor);
        Noh* ptIterador = mPtPrimeiro;
        unsigned int contador = 0;
        while (contador < pos - 1 and ptIterador != NULL) {
            ptIterador = ptIterador->mPtProximo;
            contador++;
        }
        novo->mPtProximo = ptIterador->mPtProximo;
        ptIterador->mPtProximo->mPtAnterior = novo;
        ptIterador->mPtProximo = novo;
        novo->mPtAnterior = ptIterador;
        mTamanho++;
    }
}
Dado Lista::RemoverNoInicio() {
    if (mTamanho == 1){
        Noh* ptAuxiliar = mPtPrimeiro;
        Dado valor = ptAuxiliar->mDado;
        mPtPrimeiro = NULL;
        mPtUltimo = NULL;
        delete ptAuxiliar;
        mTamanho = 0;
        return valor;
    }
    else {
        Noh* ptAuxiliar = mPtPrimeiro;
        Dado valor = mPtPrimeiro->mDado;
        mPtPrimeiro = mPtPrimeiro->mPtProximo;
        mPtPrimeiro->mPtAnterior = NULL;
        delete ptAuxiliar;
        mTamanho--;
        return valor;
    }
}
Dado Lista::RemoverNoFim() {
    if (mTamanho == 1) {
        Noh* ptAuxiliar = mPtUltimo;
        Dado valor = ptAuxiliar->mDado;
        mPtPrimeiro = NULL;
        mPtUltimo = NULL;
        delete ptAuxiliar;
        mTamanho = 0;
        return valor;
    }
    else {
        Noh* ptAuxiliar = mPtUltimo;
        Dado valor = mPtUltimo->mDado;
        mPtUltimo = mPtUltimo->mPtAnterior;
        mPtUltimo->mPtProximo = NULL;
        delete ptAuxiliar;
        mTamanho--;
        return valor;
    }
}
Dado Lista::RemoverNaPosicao(unsigned int pos) {
    if (pos == 0){
        return RemoverNoInicio();
    }
    else if (mTamanho == 1) {
        return RemoverNoInicio();
    }
    else if (pos == mTamanho - 1){ 
        return RemoverNoFim();
    }
    else {
        Noh* ptIterador = mPtPrimeiro;
        unsigned int contador = 0;
        while (contador < pos and ptIterador != NULL){
            ptIterador = ptIterador->mPtProximo;
            contador++;
        }
        Dado valor = ptIterador->mDado;
        ptIterador->mPtProximo->mPtAnterior = ptIterador->mPtAnterior;
        ptIterador->mPtAnterior->mPtProximo = ptIterador->mPtProximo;
        delete ptIterador;
        mTamanho--;
        return valor;
    }
}
int Lista::Buscar(const Dado& valor) {
    Noh* ptIterador = mPtPrimeiro;
    int contador = 0;
    while (ptIterador != NULL){
        if (ptIterador->mDado == valor){
            return contador;
        }
        ptIterador = ptIterador->mPtProximo;
        contador++;
    }
    return -1;
}
void Lista::Imprimir() {
    Noh* ptIterador = mPtPrimeiro;
    while (ptIterador != NULL){
        cout << ptIterador->mDado << " ";
        ptIterador = ptIterador->mPtProximo;
    }
}
void Lista::LimparTudo() {
    Noh* ptIterador = mPtPrimeiro;
    Noh* ptAuxiliar = NULL;
    while (ptIterador != NULL){
        ptAuxiliar = ptIterador;
        ptIterador = ptIterador->mPtProximo;
        delete ptAuxiliar;
    }
    mPtPrimeiro = NULL;
    mPtUltimo = NULL;
    mTamanho = 0;
}
bool Lista::Vazia() {
    if (mTamanho == 0) {
        return true;
    }
    else {
        return false;
    }
}
int main() {
    Lista listaDupla;
    Dado valor;
    char comando;
    unsigned int posicao;
    do{
        cin >> comando;
        switch (comando){
            case 'e': // Inserir no Inicio;
                cin >> valor;
                listaDupla.InserirNoInicio(valor);
                break;
            case 'w': // Inserir no Fim;
                cin >> valor;
                listaDupla.InserirNoFim(valor);
                break;
            case 'q': //Inserir na Posicao;
                cin >> posicao;
                cin >> valor;
                if (posicao < 0 or posicao > listaDupla.Tamanho()){
                    cerr << "Erro: Posicao Invalida\n";
                }
                else {
                    listaDupla.InserirNaPosicao(posicao,valor);
                }
                break;
            case 'o':// Remover no inicio;
                if (listaDupla.Vazia()){
                    cerr << " Impossivel Remover, Lista Vazia!\n";
                }
                else {
                    cout << listaDupla.RemoverNoInicio();
                }
                break;
            case 'p': // Remover no Fim;
                if (listaDupla.Vazia()){
                    cerr << " Impossivel Remover, Lista Vazia!\n";
                }
                else {
                    cout << listaDupla.RemoverNoFim();
                }
                break;
            case 'r':
                cin >> posicao;
                if (listaDupla.Vazia()) {
                    cerr << "Impossivel Remover, Lista Vazia\n";
                }
                if (posicao < 0 or posicao >= listaDupla.Tamanho()) {
                    cerr << "Erro: Posicao Invalida\n";
                } 
                else {
                    cout << listaDupla.RemoverNaPosicao(posicao);
                }
                break;
            case 'b': // Buscar Valor;
                cin >> valor;
                if (listaDupla.Vazia()){
                    cerr << " Erro: Lista Vazia!\n";
                }
                else {
                    cout << listaDupla.Buscar(valor);
                }
                break;
            case 'i': // Imprimir a Lista;
                listaDupla.Imprimir();
                break;
            case 'l': // Limpa Tudo;
                listaDupla.LimparTudo();
                break;
            case 't': // Consultar o Tamanho;
                cout << listaDupla.Tamanho() << endl;
                break;
            case 'f': // Finalizar;
                //Checado no While;
                break;
            default:
                cout << "Comando Invalido\n";
        }
    } while (comando != 'f');
    return 0;
}
