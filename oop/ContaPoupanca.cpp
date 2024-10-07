#include <utility>
#include "ContaPoupanca.hpp"

ContaPoupanca::ContaPoupanca(std::string numero, Titular titular)
	: Conta(std::move(numero), std::move(titular))
{
}

float ContaPoupanca::taxaDeSaque() const
{
	return 0.03;
}
