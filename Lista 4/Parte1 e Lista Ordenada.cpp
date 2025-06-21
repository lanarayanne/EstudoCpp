#include <iostream>

#include "lista.h"

using namespace std;

struct tarefa {
    string nome;
    bool feita = false;

    bool operator < (const tarefa &t) const {
        return this->nome < t.nome;
    }

    bool operator > (const tarefa &t) const {
        return this->nome > t.nome;
    }

    bool operator ==(const tarefa &t) const {
        return this->nome == t.nome;
    }
};

//Problema 2 (pt1)
struct compras {
    string nome;
    int quantidade;
    float preco;

    bool operator < (const compras &t) const {
        return this->nome < t.nome;
    }

    bool operator > (const compras &t) const {
        return this->nome > t.nome;
    }

    bool operator ==(const compras &t) const {
        return this->nome == t.nome;
    }
};


int main() {
    int valores[] = {11, 4, 7, 9, 10,15,21, 8}; //array

    cout << "Lista Simples: " << endl;

    Lista<int> lista(10); //declara lista

    for (auto &v : valores) {
        lista.adicionar(v);
    } //cada elemento da lista é um elemento do array

    cout << "Antes: ";
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pega(i) << "; ";
    } // imprime a lista
    cout << endl;

    //chamando as funcoes

    lista[5] = 55;
    lista.inserir(2, 22);
    lista.remover(3);
    lista.adicionar(77);
    lista.remover(4);

    cout << "Depois: ";
    for (int i = 1; i <= lista.tamanho(); i++) {
        cout << i << ": " << lista.pega(i) << "; ";
    }
    cout << endl;

    int b[] = {10, 22, 11, 5, 7};
    cout << "Buscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << lista.buscar(v) << endl;
    }

    cout << "Lista Ordenada: " << endl;

    ListaOrdenada<int> listaOrd(10);

    for (auto &v : valores) {
        listaOrd.adicionar(v);
    }

    for (int i = 1; i <= listaOrd.tamanho(); i++) {
        cout << i << ": " << listaOrd.pega(i) << "; ";
    }
    cout << endl;

    cout << "Buscas: " << endl;
    for (int v : b) {
        cout << "- Buscando " << v << ": " << listaOrd.buscar(v) << endl;
    }

    cout << endl << "Lista Ordenada de Tarefas: " << endl;

    // tarefa é o tipo do item; string é o tipo da chave usada para buscar o item
    ListaOrdenada<tarefa> todo(10);

    tarefa arr[] = { {"Feira", false},
                     {"Aluguel", false},
                     {"Lixo", false},
                     {"Estudar", false},
                     {"Cinema", false}};

    for (auto &v : arr) {
        todo.adicionar(v);
    }

    todo[1].feita = true;
    todo[3].feita = true;

    for (int i = 1; i <= todo.tamanho(); i++) {
        cout << i << ": " << todo[i].nome << " [" << (todo[i].feita?"feita":"nao feita") << "]" << endl;
    }

    string str[] = {"Feira", "Tarefa de casa", "Cinema", "Padaria"};
    for (string &s : str) {
        // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        cout << "- Buscando " << s << ": " << todo.buscar({s, false })+1 << endl;
    }

    //Parte 1 - Problema 2 (pt2)

    compras arr1[] = {  {"Arroz", 1, 7.00},
                        {"Feijao", 2, 6.40},
                        {"Batata", 5, 4.20},
                        {"Carne", 1, 7.45}};


    cout << "Lista nao ordenada de compras:" << endl;

    Lista<compras> listaCompras(10);

    for (compras v : arr1) {
        listaCompras.adicionar(v);
    }

    for (int i = 1; i <= listaCompras.tamanho(); i++) {
        cout << i << ": " << listaCompras[i].nome << " quantidade: " << listaCompras[i].quantidade << " valor: " << listaCompras[i].preco << endl;
    }

    listaCompras.adicionar({"Sabonete", 1, 2.50});
    listaCompras.adicionar({"Cafe", 15, 16.00});

    cout << "Depois" << endl;
    for (int i = 1; i <= listaCompras.tamanho(); i++) {
        cout << i << ": " << listaCompras[i].nome << " quantidade: " << listaCompras[i].quantidade << " valor: " << listaCompras[i].preco << endl;
    }

    string str1[] = {"Arroz", "Caixa", "Gato", "Banana", "Sabonete", "Cereja"};
    for (string &s : str1) {
        // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        compras listaTemp = {s , 0, 0};
        cout << "- Buscando " << s << ": " << listaCompras.buscar(listaTemp) << endl;
    }

    cout << "Lista ordenada de compras:" << endl;

    ListaOrdenada<compras> listaComprasOrd(10);

    for (compras v : arr1) {
        listaComprasOrd.adicionar(v);
    }

    for (int i = 1; i <= listaComprasOrd.tamanho(); i++) {
        cout << i << ": " << listaComprasOrd[i].nome << " quantidade: " << listaComprasOrd[i].quantidade << " valor: " << listaComprasOrd[i].preco << endl;
    }

    listaComprasOrd.adicionar({"Racao Gato", 1, 25.00});
    listaComprasOrd.adicionar({"Banana", 15, 15.00});

    cout << "Depois" << endl;
    for (int i = 1; i <= listaComprasOrd.tamanho(); i++) {
        cout << i << ": " << listaComprasOrd[i].nome << " quantidade: " << listaComprasOrd[i].quantidade << " valor: " << listaComprasOrd[i].preco << endl;
    }

    string str2[] = {"Arroz", "Caixa", "Gato", "Banana", "Sabonete", "Cereja"};
    for (string &s : str1) {
    // Sintaxe { s, false } cria uma tarefa temporária com nome s, que é usada na busca
        compras listaTemp = {s , 0, 0};
        cout << "- Buscando " << s << ": " << listaComprasOrd.buscar(listaTemp) << endl;
    }


    return 0;
}
