#include <iostream> 
#include <vector> 
#include <cmath>
 
using namespace std; 
 
class fila_media { //classe chamada fila_media
private: 
    vector<int> itens; 
    int ini = 0,   // posicao do 1o elemento 
        tam = 0,   // tamanho (numero atual de elementos) 
        cap = 0;   // capacidade (numero max. de elementos)
    int sum = 0;
 
public: 
    // construtor receba capacidade; inicializa cap e o vector itens. 
    explicit fila_media(int cap) : cap(cap), itens(cap) {  } 
 
    bool cheia() const { 
        return (tam >= cap);
        
    } // fila esta cheia? 
 
    bool vazia() const { 
        return (tam == 0);
    
    } // fila esta vazia? 
 
    void desenfileira() { 
        if (vazia()){
            cout << "Fila Vazia" << endl;
            return;
        } 
        
        sum = sum - itens.at(ini);
        
        ini = (ini + 1) % cap;
        tam--;
    } // remove elemento na frente da fila 
 
    void enfileira(int i) {
        
        if (cheia()){
            cout << "Fila cheia" << endl;
        } 
        sum = sum+i;
        
        if(tam<cap){
            itens.at((ini+tam)%cap) = i;
            tam++;
        }
        
    } // adiciona i ao final da fila 
 
    int proximo() { 
        return itens.at(ini);
        
    } // retorna elemento na frente da fila 
 
    double media() const { 
        if (vazia()){
            cout << "Fila Vazia" << endl;
            return NULL;
        }
        return sum/tam;
        
    } // retorna atual media dos elementos 
    
    int tamanho() { 
        return tam;
        
    } // retorna tamanho atual da fila 
}; 
 
int main() { 
    int arr[] = {10, 2, 3, 5, 6, 10, 7, 9, 2, 6, 3, 13, 6}; 
 
    fila_media fila(4); 
 
    for (int i : arr) { 
        if (fila.cheia()) fila.desenfileira(); 
 
        fila.enfileira(i); 
 
        cout << fila.media() << endl; 
    } 
 
    // Saida: 10 6 5 5 4 6 7 8 7 6 5 6 7 
 
    return 0; 
} 
 