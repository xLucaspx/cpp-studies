#include <utility>
#include "ContaCorrente.hpp"

ContaCorrente::ContaCorrente(std::string numero, Titular titular)
		: Conta(std::move(numero), std::move(titular))
{}

float ContaCorrente::taxaDeSaque() const
{
	return 0.05;
}

void ContaCorrente::transferir(Conta &destino, float valor)
{
	if (valor <= 0 || valor > getSaldo()) {
		return;
	}

	sacar(valor);
	destino.depositar(valor);
}
