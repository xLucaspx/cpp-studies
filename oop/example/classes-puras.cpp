#include <iostream>

using namespace std;

struct A {
	virtual void metodo() = 0;
};

struct B {
	virtual void metodo() = 0;
};

struct C: A, B {
	void metodo() override {
		cout << "Implementacao do metodo em C" << endl;
	}
};

void chamaMetodoA(A& a) {
	cout << "Chamando metodo de uma referencia do tipo A:" <<endl;
	a.metodo();
}

void chamaMetodoB(B& b) {
	cout << "Chamando metodo de uma referencia do tipo B:" <<endl;
	b.metodo();
}

int main() {
	/**
	 * Quando temos classes só com métodos puramente virtuais, a herança
	 * múltipla não será um problema pois a classe derivada será obrigada
	 * a implementar os métodos, logo a implementação chamada sempre será
	 * a sua própria. Isso é muito útil, por exemplo, quando queremos fazer
	 * uso de polimorfismo!
	 *
	 * Classes que não possuem dados nem implementações são chamadas de classes
	 * puramente virtual (muito semelhante a interfaces)
	 */

	C var;

	var.metodo();

	chamaMetodoA(var);
	chamaMetodoB(var);

	return 0;
}
