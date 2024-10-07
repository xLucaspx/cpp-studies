#include <utility>
#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente(std::string numero, Titular titular)
	: Conta(std::move(numero), std::move(titular))
{
}

float ContaCorrente::taxaDeSaque() const
{
	return 0.05;
}

void ContaCorrente::transferir(Conta &destino, float valor)
{
	auto resultadoSaque = sacar(valor);

	// se o índice retornado na variant for o primeiro é porque ocorreu erro
	if (resultadoSaque.index() == 0) {
		return;
	}

	destino.depositar(valor);
}
