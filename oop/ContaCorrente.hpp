#pragma once

#include <string>
#include "Conta.hpp"

class ContaCorrente final : public Conta // se ninguém pode extender a classe, a marcamos como final
{
public:
	ContaCorrente(std::string numero, Titular titular);

	void transferir(Conta &destino, float valor);

private:
	[[nodiscard]] float taxaDeSaque() const override; // override serve para garantir que estamos sobrescrevendo um método
};
