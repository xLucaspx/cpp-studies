#include <iostream>
#include <string>
#include "Conta.hpp"

int main()
{
	// em C++, não precisamos utilizar a palavra struct na declaração da variável
Conta c1{
			"12345",
			// em C++, é mais performático passar o objeto direto no construtor do que
			// guardá-lo em uma variável temporária, pois assim ocorrem menos cópias
			Titular("12345678909", "Fulano de Tal")
	};

	Conta c2("54321", Titular("01234567800", "Pafuncia da Silva"));

	c1.depositar(500);
	c2.depositar(200);

	c1.sacar(100);

	c1.transferir(c2, c1.getSaldo() - 100);

	printf("{ numero: %s, cpf: %s, nome: %s, saldo: R$ %.2f }\n",
				 c1.getNumero().c_str(),
				 c1.getTitular().getCpf().c_str(),
				 c1.getTitular().getNome().c_str(),
				 c1.getSaldo());

	printf("{ numero: %s, cpf: %s, nome: %s, saldo: R$ %.2f }\n",
				 c2.getNumero().c_str(),
				 c2.getTitular().getCpf().c_str(),
				 c2.getTitular().getNome().c_str(),
				 c2.getSaldo());

	std::cout << "Total de contas: " << Conta::getTotalContas() << std::endl;

	return 0;
}
