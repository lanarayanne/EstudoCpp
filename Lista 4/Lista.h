//
// Created by IFPE on 10/06/2025.
//

#ifndef FILAS_LISTA_H
#define FILAS_LISTA_H

#include <vector>

using namespace std;

template <class T>
class Lista {
protected:
    int capacidade;
    int num_itens = 0;
    vector<T> itens;

    T & pega_ref(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

public:
    explicit Lista(int capacidade)  : itens(capacidade), capacidade(capacidade), num_itens(0) {
        if (capacidade <= 0) throw runtime_error("Capacidade invalida");
    }

    virtual void adicionar(T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");

        itens[num_itens] = v;
        num_itens++;
    }

    virtual void inserir(int idx, T v) {
        if (num_itens >= capacidade) throw runtime_error("Fila cheia!");
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        for (int i = num_itens - 1; i >= idx - 1; i--) {
            itens[i + 1] = itens[i];
        }

        itens[idx - 1] = v;

        num_itens++;
    }

    //Parte 1 - Problema 1
    void remover(int idx) {
        if (num_itens < 0) throw runtime_error("Fila vazia!");
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        for (int i = idx; i < num_itens - 1; i++) {
            itens[i] = itens[i + 1];
        }
        num_itens--;
    }

    int tamanho() const {
        return num_itens;
    }

    T pega(int idx) {
        if (idx <= 0 || idx > tamanho()) throw runtime_error("Indice invalido");

        return itens[idx - 1];
    }

    T & operator [] (int idx) {
        return pega_ref(idx);
    }

    virtual int buscar(T valor) {
        for (int i = 0; i < num_itens; i++) {
            if (itens[i] == valor) {
                return i + 1;
            }
        }
        return -1;
    }
};

// T é o tipo do dado, ex., tarefa
template <class T>
class ListaOrdenada : public Lista<T> {

public:
    explicit ListaOrdenada(int cap) : Lista<T>(cap) {  }

    void inserir(int idx, T v) override {
        throw runtime_error("Operacao nao suportada!");
    }

    void adicionar(T v) override {
        if (this->num_itens >= this->capacidade) throw runtime_error("Fila cheia!");

        int i = 0;
        for (i = this->num_itens - 1; i >= 0 && this->itens[i] > v; i--) {
            this->itens[i + 1] = this->itens[i];
        }
        this->itens[i + 1] = v;
        this->num_itens++;
    }

    int buscar(T v, int inicio, int fim)  {
        //        int inicio = 0;
        //        int fim = this->tamanho()-1;
        int meio = (inicio + fim) / 2;

        if (inicio > fim) {
            return -1;
        }
        if (this->itens[meio]== v) {
            return meio+1;
        }
        if (this->itens[meio]> v) {
            return buscar(v, inicio, meio-1);
        } else {
            return buscar(v, meio+1 , fim);
        }

    }

    int buscar(T v) override {
        return buscar(v, 0, this->tamanho()-1);
    }


        //Abaixo reusando busca sequencial por enquanto; substituir por seu código
        //return Lista<T, K>::buscar(v);
};


#endif //FILAS_LISTA_H
