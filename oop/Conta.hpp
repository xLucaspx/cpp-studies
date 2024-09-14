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

	~Conta(); // método destrutor, chamado implicitamente quando um objeto sai do escopo (deixa de existir); não recebe parâmetros!

	void depositar(float valor);

	void sacar(float valor);

	void transferir(Conta &destino, float valor);

	// quando métodos não modificam a classe, os declaramos como const

	[[nodiscard]] std::string getNumero() const;

	[[nodiscard]] Titular getTitular() const;

	[[nodiscard]] float getSaldo() const;
};
