#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValid(const string &s) {
		stack <char> pilha;
		int tam = s.length();

		for (int i=0; i<tam ; i++) {
			if(s[i] == '(' || s[i] == '[' || s[i] == '{' ) {
				pilha.push(s[i]);
			}

			if(pilha.top() == '(' && s[i] == ')' || pilha.top() == '[' && s[i] == ']' || pilha.top() == '{' && s[i] == '}' ) {
				pilha.pop();
			}

		}
		
		if (pilha.empty()) {
				return true;
			} else {
				return false;
			}
	}
	};

	int main() {
		string testes[] = { "[{()}]", "()[]{}", "{[(}])", "(][){}", "}{)(][" };
		for (auto &s : testes) {
			cout << s << ": "<< (Solution().isValid(s)?"Valida":"Invalida")<<endl;

		}
		return 0;
	}