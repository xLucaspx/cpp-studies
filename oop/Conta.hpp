#pragma once

#include <string>
#include "Titular.hpp"

class Conta
{
// Em C++, a diferença entre struct e class é que em uma struct, por
// padrão, tudo é public; em uma class, o padrão é ser private.

private:
	static unsigned int totalContas;

public:
	static unsigned int getTotalContas();

private: // definindo explicitamente para melhorar a legibilidade!
	std::string numero;
	Titular titular;
	float saldo;

public:
	Conta(std::string numero, Titular titular);

	virtual ~Conta(); // método destrutor, chamado implicitamente quando um objeto sai do escopo (deixa de existir); não recebe parâmetros!
	// sempre que uma classe pode ser estendida é uma boa prática marcar seu destrutor como virtual para evitar vazamentos de
	// memória, garantindo assim que o destrutor das classes filhas será chamado de acordo com a instancia do objeto criado.

	void depositar(float valor);

	void sacar(float valor);

	[[nodiscard]] virtual float taxaDeSaque() const = 0;
	// método virtual: a implementação que será chamada depende da instância do objeto que chamou (polimorfismo).
	// método puramente virtual (= 0): nesta classe, este método não tem implementação (logo, esta classe não está,
	// completa -- não é concreta -- e precisa ser estendida

	[[nodiscard]] std::string getNumero() const; // quando métodos não modificam a classe, os declaramos como const

	[[nodiscard]] Titular getTitular() const;

	[[nodiscard]] float getSaldo() const;
};
