#ifndef PRATICA_06_LINKEDLIST_H
#define PRATICA_06_LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

/* Lista encadeada simples */
template<class T>
class linkedlist {
private:
    struct Node {
        T value;
        Node * next;
        Node(T value, Node * next) : value(value), next(next) { }
    };

    Node * head = nullptr;
    int _size = 0;

public:
    linkedlist() = default;

    ~linkedlist() {
	// Brinde: estude e entenda!
        while (head != nullptr) { //quando o inicio nao estiver vazio, ou seja, tiver um item
            Node * tmp = head; //cria um nó temporário que recebe o inicio
            head = head->next; // agora o inicio é o proximo
            delete tmp;
        }
    }

    // Adiciona no in�cio da lista
    void add(T value) {
        if (head == nullptr) {
            head = new Node(value, nullptr);
        } else {
            Node * newHead = new Node(value, head);
            head = newHead;
        }

        _size++;
    }

    // Remove um item identificado por value, retorna indice.
    // Se o elemento n�o existe, retorna -1;
    void remove(int idx) {
        if (idx < 0 || idx >= _size) throw runtime_error("Indice invalido.");
        Node* deleteNode = nullptr;

        if (idx == 0) {
            deleteNode = head;  // guarda o nó que será removido
            head = head->next;       // head é o próximo nó
        } else {
            Node* anterior = head;
            for (int i = 0; i < idx - 1; i++) {
                anterior = anterior->next;
            }
            deleteNode = anterior->next;
            anterior->next = deleteNode->next;
        }

        // delete deleteNode; // libera a memória
        _size--;
    }

    // Exibe os items na tela
    void show() {
        Node *node = head;
        while (node != nullptr) {
            cout << "(" << node->value << ") ";
            node = node->next;
        }
    }

    int size() {
        return _size;
    }

    // Para compatibilidade com for() de C++
    class iterator {
        Node* node;
    public:
        explicit iterator(Node* n) : node(n) {}
        T &operator*() const { return node->value; }
        iterator& operator++() { node = node->next; return *this; }
        bool operator==(iterator other) const { return node == other.node; }
        bool operator!=(iterator other) const { return !(*this == other); }
    };
    iterator begin() { return iterator(head); }
    iterator end()   { return iterator(nullptr); }
};

#endif //PRATICA_06_LINKEDLIST_H
