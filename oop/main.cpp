#include <iostream>
#include <string>
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"
#include "Caixa.hpp"

void realizaSaque(Conta &conta, float valor)
{
	// Em C++, o método que será executado é definido em tempo de compilação. Se quisermos
	// que diferentes classes de um mesmo tipo tenham implementações diferentes, como é o
	// caso de `sacar()` em ContaCorrente e em ContaPoupanca, que possuem taxas diferentes,
	// precisamos utilizar métodos virtuais para dizer ao C++ para escolher a implementação
	// que será chamada em tempo de execução.
	conta.sacar(valor);
}

void printFuncionario(Funcionario &f)
{
	printf("funcionario: { nome: %s, cpf: %s, salario: R$ %.2f, bonus: R$ %.2f }\n",
				 f.getNome().c_str(), f.getCpf().c_str(), f.getSalario(), f.bonificacao());
}

void printConta(Conta &c)
{
	printf("conta: { numero: %s, nome: %s, saldo: R$ %.2f }\n",
				 c.getNumero().c_str(), c.getTitular().getNome().c_str(), c.getSaldo());
}

int main()
{
	// em C++, não precisamos utilizar a palavra struct na declaração da variável
	ContaCorrente c1{
			"12345",
			// em C++, é mais performático passar o objeto direto no construtor do que
			// guardá-lo em uma variável temporária, pois assim ocorrem menos cópias
			Titular("12345678909", "Fulano de Tal", "senha123")
	};

	ContaPoupanca c2("54321", Titular("01234567800", "Pafuncia da Silva", "senha456"));

	c1.depositar(1000);
	c2.depositar(1000);

	c1.transferir(c2, 100);

	realizaSaque(c1, 100);
	realizaSaque(c2, 100);

	printConta(c1);
	printConta(c2);

	std::cout << "Total de contas: " << Conta::getTotalContas() << std::endl;

	Gerente f1("88877162534", "Gerente da Silva", 10000, "senha-gerente");
	Caixa f2("00119273688", "Caixa Pereira", 5000, "senha-caixa");

	printFuncionario(f1);
	printFuncionario(f2);

	std::cout << c1.getTitular().autentica("senha123") << std::endl;
	std::cout << c2.getTitular().autentica("senha456") << std::endl;
	std::cout << f1.autentica("senha-gerente") << std::endl;
	std::cout << f2.autentica("senha-caixa") << std::endl;

	return 0;
}
