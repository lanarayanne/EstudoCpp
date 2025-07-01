//
// Created by IFPE on 24/06/2025.
//

#ifndef PRATICA_06_HASHTABLE_H
#define PRATICA_06_HASHTABLE_H

#include <stdexcept>

/* Funcao de espalhamento abstrata
 * Deve sempre retornar valor positivo! */
template <class T>
long hash_function(T v);


/* Tabela de Espalhamento abstrata. */
template<class T_key, class T_value>
class hashtable {

protected:
    int capacity, size = 0;

    // Pega a chave e retorna o indice
    // Chama hash_function() e ajusta para o tamanho da tabela
    int get_idx(T_key key) {
        int hash = hash_function(key);
        if (hash < 0) throw std::runtime_error("Erro no calculo do hash! [Negativo]");
        return hash % capacity;
        // return hash;
    }

public:
    explicit hashtable(int cap) : capacity(cap) {
        // ^ table(cap) inicializa o vector com tamanho inicial = cap
        if (cap <= 0) // testando se capacidade eh valida
            throw std::runtime_error("Capacidade invalida");
    }

    ~hashtable() = default;

    virtual void insert(T_key key, T_value value) = 0;

    virtual void remove(T_key key) = 0;

    virtual T_value search(T_key key) = 0;

    virtual void show() = 0;

};

#endif //PRATICA_06_HASHTABLE_H
