#include <iostream>

using namespace std;

struct A
{
	A()
	{ cout << "Construtor de A" << endl; }

	void umMetodo()
	{ cout << "umMetodo de A" << endl; }
};

struct B : virtual A // usamos herança virtual para verificar se a classe já foi herdada na hierarquia de classes
{
	B()
	{ cout << "Construtor de B" << endl; }

	void algumMetodo()
	{ cout << "algumMetodo de B" << endl; }
};

struct C : virtual A
{
	C()
	{ cout << "Construtor de C" << endl; }

	void outroMetodo()
	{ cout << "outroMetodo de C" << endl; }
};

struct D : B, C
{
	D()
	{ cout << "Construtor de D" << endl; }
};

int main()
{
	/**
	 * Sem herança virtual há esperdício de recursos, pois o
	 * construtor de A é chamado duas vezes:
	 * - Construtor de A
	 * - Construtor de B
	 * - Construtor de A
	 * - Construtor de C
	 * - Construtor de D
	 *
	 * A   A
	 * |   |
	 * B   C
	 * \   /
	 *   D
	 *
	 * Com herança virtual esse problema é contornado:
	 *
	 * - Construtor de A
	 * - Construtor de B
	 * - Construtor de C
	 * - Construtor de D
	 *
	 *    A
	 *  /   \
	 * B     C
	 *  \   /
	 *    D
	 */

	D var;

	var.algumMetodo();
	var.outroMetodo();

	/**
	 * Problema diamante, não compila:
	 *
	 * Non-static member 'umMetodo' found in multiple base-class subjects of type 'A':
	 * - struct D -> B -> A
	 * - struct D -> C ->
	 *
	 * A member found by ambiguous name lookup
	 */
	// var.umMetodo();
	// var.A::umMetodo(); // D não herda diretamente de A

	// compila:
	var.B::umMetodo();
	var.C::umMetodo();

	return 0;
}
