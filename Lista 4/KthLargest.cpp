#include <iostream>
#include "lista.h"

using namespace std;

class KthLargest {
    int posicao;
    vector<int> v;
    int capacidade;
    //scores(10000)

public:
    KthLargest(int k, vector<int>& nums) : posicao(k) {
        this->capacidade = nums.size(); //4
        this->posicao = k; //3
        this->v=nums; //4 5 8 2
        //this->lista = createLista(v);
    }

    void setCapacidade(vector<int> &v) {
        this->capacidade = v.size();
    }

    ListaOrdenada<int> createLista () {
        ListaOrdenada<int> lista (capacidade+1);
        for (int v : v) {
            lista.adicionar(v);
        }
        setCapacidade(v);
        return lista;
    }

    int add(int val) {
        this->v.push_back(val);
        ListaOrdenada<int> lista = createLista();
        return lista[capacidade - posicao+1];
    }
};
int main() {
    vector<int> nums = {4, 5, 8, 2};
    vector<int> vals = {3, 5, 10, 9, 4};
    KthLargest kthLargest (3, nums); // cria um objto
    for (int v : vals) {
        cout << "Adicionando " << v << ", 3o maior eh " << kthLargest.add(v)
       << endl;
    }
}