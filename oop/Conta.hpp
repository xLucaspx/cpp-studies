#pragma once

#include <string>
#include <variant>
#include "Titular.hpp"

class Conta
{
	// Em C++, a diferença entre struct e class é que em uma struct, por
	// padrão, tudo é public; em uma class, o padrão é ser private.

private:
	static unsigned int totalContas;

public:
	static unsigned int getTotalContas();

	enum ErroSaque
	{
		SALDO_INSUFICIENTE, VALOR_INVALIDO
	};

private: // definindo explicitamente para melhorar a legibilidade!
	std::string numero;
	Titular titular;
	float saldo;

public:
	Conta(std::string numero, Titular titular);

	virtual ~Conta();

	// método destrutor, chamado implicitamente quando um objeto sai do escopo (deixa de existir); não recebe parâmetros!
	// sempre que uma classe pode ser estendida é uma boa prática marcar seu destrutor como virtual para evitar vazamentos de
	// memória, garantindo assim que o destrutor das classes filhas será chamado de acordo com a instancia do objeto criado.

	void depositar(float valor);

	void operator+=(float valor); // operator overload
	// Em C++ não há resolução de overload entre classes base e derivadas. E.g.: se, em ContaCorrente tivermos outra
	// função `operator+=` o compilador sempre buscará a implementação da função no escopo da instância que foi chamada,
	// i.e. se chamarmos de Conta será a de Conta e se chamarmos de ContaCorrente será a de conta corrente, mesmo que os
	// parâmetros sejam diferentes. Isso é Name Hiding, não Overloading!

	bool operator<(const Conta &outra) const;

	std::variant<Conta::ErroSaque, float> sacar(float valor);

	// Em C++, a partir da versão 17, quando queremos retornar um tipo OU outro, podemos usar variant; nesse caso, se
	// ocorrer um erro vamos informar com o enum ErroSaque e, em caso de sucesso, vamos retornar o novo saldo.

	[[nodiscard]] virtual float taxaDeSaque() const = 0;

	// método virtual: a implementação que será chamada depende da instância do objeto que chamou (polimorfismo).
	// método puramente virtual (= 0): nesta classe, este método não tem implementação (logo, esta classe não está,
	// completa -- não é concreta -- e precisa ser estendida

	[[nodiscard]] std::string getNumero() const; // quando métodos não modificam a classe, os declaramos como const

	[[nodiscard]] Titular getTitular() const;

	[[nodiscard]] float getSaldo() const;
};
