#ifndef PRATICA_06_SIMPLE_HASHTABLE_H
#define PRATICA_06_SIMPLE_HASHTABLE_H

#include <list>
#include <vector>
#include "hashtable.h"


/* Tabela de Espalhamento simples com vector. */
template<class T_key, class T_value>
class simple_hashtable : public hashtable<T_key, T_value> {
private:
    std::vector<std::pair<T_key, T_value>> table;

    // Usados para representar posicoes vazias na tabela
    T_key no_key;
    T_value no_value;

public:
    explicit simple_hashtable(int cap, T_key no_key, T_value no_value)
    : hashtable<T_key, T_value>(cap), // construtor da superclasse
      no_key(no_key), no_value(no_value),
      table(cap, {no_key, no_value})  // iniciliza tabela com tamanho cap, e com valores {no_key, no_value}
    {

    }

    ~simple_hashtable() = default;

    void insert(T_key key, T_value value) override {
        int idx = this->get_idx(key);
        table[idx] = make_pair(key, value);
        cout << table[idx].first << " " << table[idx].second << endl;
        // Lembre que eh uma tabela de pares
        // Pares tem dois campos: first e second
    }

    void remove(T_key key) override {
        int idx = this->get_idx(key);
        table[idx].second = no_value;
        table[idx].first = no_key;
    }

    T_value search(T_key key) override {
        int idx = this->get_idx(key);
        if (table[idx].first == key) {
            return table[idx].second;
        } else {
            return no_value;
        }
    }

    void show() override {
        int i = 0;
        for (auto &[k, v]: table) {
            cout << i++ << ": (" << k << ": " << v << ") " << endl;
        }
    }

    T_value operator [] (const T_key &key) {
        return search(key);
    }

};

#endif
