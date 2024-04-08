#include <iostream>   // Pode usar varias coisas prontas
#include <vector>     // mas e' preciso completar a classe
#include <limits>     // classe Heap. E' permitido fazer
#include <string>     // alteracoes na classe Heap.
#include <stdexcept>

class Atividade {
    public:
        int nota;
        int tentativas;
};

class Aluno {
    public:
        Aluno();
        Aluno(unsigned matr, const std::string& n);
        ~Aluno();
        void InserirAtividade(const Atividade& a);
        std::string Nome() const { return nome; }
        unsigned Matricula() { return matricula; }
        float Media() const;
        int Tentativas() const;
    protected:
        unsigned matricula;
        std::string nome;
        std::vector<Atividade> vetAtividades;
};

Aluno::Aluno()
    : matricula(0), nome(), vetAtividades() {
}

Aluno::Aluno(unsigned matr, const std::string& n)
    : matricula(matr), nome(n), vetAtividades() {
}

Aluno::~Aluno() {
	matricula = 0;
	nome = " ";
}

void Aluno::InserirAtividade(const Atividade& a) {
    vetAtividades.push_back(a);
}

float Aluno::Media() const {
    float soma = 0.0f;
    unsigned nroAtividades = unsigned(vetAtividades.size());
    for (unsigned i = 0; i < nroAtividades; ++i)
        soma += float(vetAtividades.at(i).nota);
    return soma / float(nroAtividades);
}

int Aluno::Tentativas() const {
    int tentativas = 0;
    unsigned nroAtividades = unsigned(vetAtividades.size());
    for (unsigned i = 0; i < nroAtividades; ++i)
        tentativas += vetAtividades[i].tentativas;
    return tentativas;
}

bool operator>(const Aluno& a1, const Aluno& a2) {
}

typedef Aluno TDado;

class Heap {
    // classe Heap (max-heap, o maior fica na raiz/inicio)
    public:
        // Criar heap sem dados e com capacidade informada
        Heap(int cap);
        // Destruttor
        ~Heap();
        // Inserir um dado na heap
        void Inserir(const TDado& d);
        // Consulta a raiz
        TDado Raiz();
        // Retira e retorna a raiz
        TDado Retirar();
        // Verifica se a heap est� vazia
        bool Vazia();
    protected:
        void ArrumarDescendo(int i);
        void ArrumarSubindo(int i);
        inline int Direito(int i);
        inline int Esquerdo(int i);
        inline int Pai(int i);
        int mCapacidade;
        int mTamanho;
        int mRaiz;
        TDado* mVetDados;
};

using namespace std;

Heap::Heap(int cap) {
	mCapacidade = cap;
    mVetDados = new TDado[mCapacidade];
    mRaiz = 0;
    mTamanho = 0;
}

Heap::~Heap() {
	delete [] mVetDados;
}

void Heap::ArrumarDescendo(int i) {
    // Arruma as posicoes de i para baixo.
    int esq = Esquerdo(i);
    int dir = Direito(i);
    int maior = i;  // testar se nao e' posicao invalida;
    if ((esq < mTamanho) and (mVetDados[esq].Tentativas() > mVetDados[i].Tentativas())) {
        maior = i;
    }
    if ((dir < mTamanho) and (mVetDados[dir].Tentativas() > mVetDados[maior].Tentativas())) {
        maior = i;
    }
    if (maior != i) { // se maior não for a posicao do parametro;
        swap(mVetDados[i],mVetDados[maior]); // troca;
        ArrumarDescendo(maior); // chama novamente o método;
    }
}

void Heap::ArrumarSubindo(int i) {
    // Arruma as posicoes de i para cima.
    int pai = Pai(i); // calcula pai do parametro recebido;
    if ((i != mRaiz) and (mVetDados[i].Tentativas() > mVetDados[pai].Tentativas())) { // posicao nao pode ser orfao, tem q ter pai. Caso tenha pai, testa se é maior e troca;
        swap(mVetDados[i],mVetDados[pai]);
        ArrumarSubindo(i);
    }
}

int Heap::Pai(int i) {
	return ((i-1) / 2);
}

int Heap::Esquerdo(int i) {
	return ((i*2) + 1);
}

int Heap::Direito(int i) {
	return ((i*2) + 2);
}

TDado Heap::Raiz() {
    if (mTamanho == 0) {
        cerr << "Heap vazia nao tem raiz." << endl;
        return TDado();
    }
    else {
    	return mVetDados[mRaiz];
    }
}

TDado Heap::Retirar() {
    if (mTamanho == 0) {
        cerr << "Impossivel retirar de heap vazia." << endl;
        return TDado();
    }
    else {
        TDado retirado = mVetDados[mRaiz];
        swap(mVetDados[mRaiz], mVetDados[mTamanho - 1]);
        mTamanho--;
        ArrumarDescendo(mRaiz);
        return retirado;
    }
}

bool Heap::Vazia() {
	if (mTamanho == 0) {
        return true;
    }
    else {
        return false;
    }
}

void Heap::Inserir(const TDado& d){
    if (mTamanho < mCapacidade) {
        mVetDados[mTamanho] = d;
        mTamanho++;
        ArrumarSubindo(mTamanho - 1);
    }
    else {
        cerr << "Impossivel inserir em heap cheio.\n";
    }
}

int main() {
    unsigned qtdeAlunos;
    cin >> qtdeAlunos;
    unsigned qtdeAtividades;
    cin >> qtdeAtividades;
    Heap heap(qtdeAlunos);
    Atividade atividade;
    string nome;
    unsigned matricula;
    for (unsigned i = 0; i < qtdeAlunos; ++i) {
        cin >> matricula >> nome;
        Aluno aluno(matricula, nome);
        for (unsigned i = 0; i < qtdeAtividades; ++i) {
            cin >> atividade.nota >> atividade.tentativas;
            aluno.InserirAtividade(atividade);
        }
        heap.Inserir(aluno);
    }
    Aluno alunoDestaque(heap.Retirar());
    cout << '[' << alunoDestaque.Matricula() << "] " << alunoDestaque.Nome() << endl;
    return 0;
}
