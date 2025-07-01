#include <iostream>
#include <string>
#include <vector>

#include "full_hashtable.h"
#include "simple_hashtable.h"

using namespace std;

struct CPF {
    string valor;
    CPF(const char * s) : valor(s) {
        if (valor.empty()) throw runtime_error("CPF vazio!");
    }
    bool operator== (const CPF& cpf) const {
        return valor == cpf.valor;
    }

};

ostream &operator<< (ostream &out, const CPF& cpf) {
    return out << cpf.valor;
}

// Calcula o hash para chaves do tipo int
template <>
long hash_function<int>(int x) {
    if (x<0) {
        x=x*-1;
    }
    return x*11;
}

// long hash_function<int, int>(int x, int tamanho) {
//
//     return x * x;
// }

// Calcula o hash para chaves do tipo string
template<>
long hash_function<string>(string key) {
    long hash = 1;
    for (auto c : key) {
        hash = c*hash;
    }
    if (hash<0) {
        return hash*-1;
    }
    return hash;
}

template <>
long hash_function<CPF>(CPF cpf) {
    long hash = 1;
    for (auto c : cpf.valor) {
        if (c == '.' || c=='-' || c=='0') continue;
        hash = hash * (c-48) + hash % (c-48);
    }
    return hash;
}

// NAO MEXER
template <class T_chave, class T_valor>
bool testar_hashtable (const vector<pair<T_chave, T_valor>> &dados_criacao,
                       const vector<pair<T_chave, T_valor>> &dados_teste,
                       T_valor not_found) {

    full_hashtable<T_chave, T_valor> tabela(10, not_found);

    try {
        for (auto &[k, v] : dados_criacao) {
            tabela.insert(k, v);
        }
    } catch (std::runtime_error &e) {
        cout << "Erro na insercao: " << e.what() << endl;
        return -1;
    }

    cout << "TABELA CRIADA: " << endl;
    tabela.show();
    cout << endl;

    cout << "TESTANDO BUSCA E REMOCAO: "  << endl;

    for (auto &a: dados_teste) {
        cout << "Buscando " << a.first << " = ";

        T_valor n = tabela.search(a.first);
        if (n != a.second) {
            cout << "ERRO ";
            cout << " esperado = " << a.second;
            cout << " encontrado = " << n;
            return false;
        }  else {
            if (a.second == not_found) cout << "Nao encontrado [OK]";
            else cout << a.second;
        }

        if (a.second == not_found) {
            cout << endl;
            continue; // n�o testa remo��o aqui
        } else {
            cout << " ... removendo...";
        }

        tabela.remove(a.first);
        T_valor n2 = tabela.search(a.first);
        if (n2 == not_found) {
            cout << "OK!" << endl;
        } else {
            cout << "ERRO!" << endl;
            return false;
        }
    }

    return true;
}



int main() {

    cout << endl << "*** Testando Funcoes de Espalhamento *** " << endl;

    cout << "Hash de " << 100 << " = " << hash_function(100) << endl;
    cout << "Hash de " << 72365 << " = " << hash_function(72365) << endl;
    cout << "Hash de " << 51536 << " = " << hash_function(51536) << endl;
    cout << "Hash de " << -101 << " = " << hash_function(-101) << endl;
    cout << "Hash de " << -100 << " = " << hash_function(-100) << endl;
    cout << "Hash de " << 11241 << " = " << hash_function(11241) << endl;
    cout << "Hash de " << -123 << " = " << hash_function(-123) << endl;

    cout << "Hash de " << "Maria" << " = " << hash_function(string("Maria")) << endl;
    cout << "Hash de " << "Joao" << " = " << hash_function(string("Joao")) << endl;
    cout << "Hash de " << "StringGrande" << " = " << hash_function(string("StringGrande")) << endl;
    cout << "Hash de " << "StringGrandeDeTeste" << " = " << hash_function(string("StringGrandeDeTeste")) << endl;
    cout << "Hash de " << "OutraStringGrandeDeTeste" << " = " << hash_function(string("OutraStringGrandeDeTeste")) << endl;

    cout << "Hash do CPF " << "123.456.789-00" << " = " << hash_function(CPF("123.456.789-00")) << endl;
    cout << "Hash do CPF " << "111.222.333-44" << " = " << hash_function(CPF("111.222.333-44")) << endl;
    cout << "Hash do CPF " << "987.654.321-00" << " = " << hash_function(CPF("987.654.321-00")) << endl;

    try {
        /* Tabela de alunos por matricula: mat = aluno */
        cout << endl << "*** Tabela de Alunos *** " << endl;
        simple_hashtable<int, string> alunos(10, -1, string("NOT_FOUND"));

        alunos.insert(12312, "Marcos");
        alunos.insert(23523, "Flavia");
        alunos.insert(98787, "Victor");
        alunos.insert(72365, "Pedro");
        alunos.insert(51535, "Esmeralda");

        cout << "TABELA CRIADA: " << endl;

       alunos.show();
        cout << endl;

        cout << "TESTANDO BUSCA: "  << endl;

        cout << 12312 << " : " << alunos.search(12312) << endl; // Marcos
        cout << 99999 << " : " << alunos.search(99999) << endl; // NOT_FOUND
        cout << 23523 << " : " << alunos[23523] << endl; // Flavia, equivalente a search()
        cout << 66666 << " : " << alunos[66666] << endl; // NOT_FOUND
        cout << 72365 << " : " << alunos[72365] << endl; // Pedro

        cout << endl <<  "TESTANDO REMOCAO: "  << endl;

        alunos.remove(12312); // Marcos
        alunos.remove(99999); // NOT_FOUND, sem efeito
        alunos.remove(23523); // Flavia
        alunos.remove(66666); // NOT_FOUND, sem efeito
        alunos.remove(72365); // Pedro

        cout << 12312 << " : " << alunos[12312] << endl; // NOT_FOUND
        cout << 99999 << " : " << alunos[99999] << endl; // NOT_FOUND
        cout << 23523 << " : " << alunos[23523] << endl; // NOT_FOUND
        cout << 66666 << " : " << alunos[66666] << endl; // NOT_FOUND
        cout << 72365 << " : " << alunos[72365] << endl; // NOT_FOUND

    } catch (std::runtime_error &e) {
        cout << "ERRO: " << e.what() << endl;
        return -1;
    }

    cout << endl << "*** Testando Lista Encadeada *** " << endl;

    linkedlist<string> lista_nomes;
    lista_nomes.add("Felipe");
    lista_nomes.add("Antonio");
    lista_nomes.add("Esmeralda");
    lista_nomes.add("Frederico");
    lista_nomes.add("Matilde");

    cout << "LISTA CRIADA: " << endl;
    int i = 0;
    for (auto &s : lista_nomes) {
        cout << i++ << ": " << s << endl;
    }

    lista_nomes.remove(1);
    lista_nomes.remove(2);

    cout << endl << "LISTA POS-REMOCAO: " << endl;
    i = 0;
    for (auto &s : lista_nomes) {
        cout << i++ << ": " << s << endl;
    }

    // ----------------------
    /* Tabela de notas por aluno: nome -> nota */
    cout << endl << "*** Tabela de Notas *** " << endl;

    vector<pair<string, float>> dados_notas =  {{"Joao", 5},
                                                {"Pedro", 7},
                                                {"Larissa", 10},
                                                {"Tereza", 7.5},
                                                {"Victor", 6},
                                                {"Mario", 4}};

    vector<pair<string, float>> teste_notas = {{"Joao", 5},
                                               {"Carlos", -1},
                                               {"Pedro", 7},
                                               {"Maria", -1},
                                               {"Mario", 4}};

    if (!testar_hashtable<string, float>(dados_notas, teste_notas, -1.0f))
        return -1;

    // ----------------------
    /* Tabela de clientes: CPF -> Nome */
    cout << endl << "*** Tabela de Clientes *** " << endl;


    vector<pair<CPF, string>> dados_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"987.654.231-00", "Maria"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"555.666.777-88", "Pedro"},
                                                  {"123.321.123-32", "Everaldo"}};

    vector<pair<CPF, string>> teste_clientes =   {{"123.456.789-99", "Joao"},
                                                  {"999.999.999-99", "NOT_FOUND"},
                                                  {"111.222.333-44", "Tereza"},
                                                  {"111.111.111-11", "NOT_FOUND"},
                                                  {"123.321.123-32", "Everaldo"}};

    if (!testar_hashtable<CPF, string>(dados_clientes, teste_clientes, "NOT_FOUND"))
        return -1;

    cout << "HASHTABLE OK!" << endl;

    return 0;
}

