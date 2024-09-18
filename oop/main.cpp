#include <iostream>
#include <string>
#include "Caixa.hpp"
#include "Conta.hpp"
#include "ContaCorrente.hpp"
#include "ContaPoupanca.hpp"
#include "DiaSemana.hpp"
#include "Funcionario.hpp"
#include "Gerente.hpp"

void realizaSaque(Conta &conta, float valor)
{
	// Em C++, o método que será executado é definido em tempo de compilação. Se quisermos
	// que diferentes classes de um mesmo tipo tenham implementações diferentes, como é o
	// caso de `sacar()` em ContaCorrente e em ContaPoupanca, que possuem taxas diferentes,
	// precisamos utilizar métodos virtuais para dizer ao C++ para escolher a implementação
	// que será chamada em tempo de execução.
	auto resultado = conta.sacar(valor);

	if (auto saldo = std::get_if<float>(&resultado)) {
		std::cout << "Saque realizado; novo saldo: R$ " << *saldo << std::endl;
		return;
	}

	std::cout << "Erro ao sacar: ";
	Conta::ErroSaque erro = std::get<Conta::ErroSaque>(resultado);

	switch (erro) {
		case Conta::ErroSaque::SALDO_INSUFICIENTE:
			std::cout << "Saldo insuficiente!" << std::endl;
			break;
		case Conta::ErroSaque::VALOR_INVALIDO:
			std::cout << "Valor invalido!" << std::endl;
			break;
		default:
			std::cout << "Erro inesperado!";
	}
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

// operator overload para printar DiaSemana
// `cout` nada mais é do que uma classe que representa um fluxo de saída de dados (ostream).
std::ostream &operator<<(std::ostream &cout, const DiaSemana d)
{
	std::string dia;

	switch (d) {
		case DiaSemana::DOMINGO:
			dia = "Domingo";
			break;
		case DiaSemana::SEGUNDA:
			dia = "Segunda-feira";
			break;
		case DiaSemana::TERCA:
			dia = "Terça-feira";
			break;
		case DiaSemana::QUARTA:
			dia = "Quarta-feira";
			break;
		case DiaSemana::QUINTA:
			dia = "Quinta-feira";
			break;
		case DiaSemana::SEXTA:
			dia = "Sexta-feira";
			break;
		case DiaSemana::SABADO:
			dia = "Sábado";
			break;
	}

	cout << dia;
	return cout;
}

// operator overload declarado como friend function em Pessoa, ou seja, pode acessar tudo
// como se fosse membro da classe
std::ostream &operator<<(std::ostream &out, const Pessoa<Cpf> &p)
{
	out << "pessoa: { nome: " + p.getNome() + ", cpf: " + p.doc.getCpf() + " }";
	return out;
}

// utilizando template function para que o compilador gere o código necessário
// para cada chamada da função com tipos diferentes; para cada chamada com tipos
// diferentes, uma nova função será criada; se nenhuma chamada à função for realizada
// ela não existirá no código compilado.
// o template faz parte da assinatura do método; costumamos quebrar a linha por legibilidade
// template<typename T> T menor(T a, T b) { ... }
template<typename T>
T menor(T a, T b)
{
	// Um detalhe importante é que o tipo esperado pelo template não precisa ser usado (somente)
	// nos parâmetros; ele também pode ser usado no corpo da função ou no retorno dela também.
	return a < b ? a : b;
}
// Também podemos informar valores para templates; isso é útil quando, embora seja um parâmetro,
// o valor precisar estar no código em tempo de compilação. E.g.: Para criar um array na stack
// precisamos saber seu tamanho em tempo de compilação. Basta trocar `typename` pelo tipo em questão
// * nem todos os tipos são válidos!

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
	c2 += 1000; // operator overload que chama o método depositar

	c1.transferir(c2, 100);

	realizaSaque(c1, 1000000);
	realizaSaque(c2, -100);

	printConta(c1);
	printConta(c2);

	std::cout << "Total de contas: " << Conta::getTotalContas() << std::endl;

	Gerente f1("88877162534", "Gerente da Silva", 10000, DiaSemana::TERCA, "senha-gerente");
	Caixa f2("00119273688", "Caixa Pereira", 5000, DiaSemana::SEXTA, "senha-caixa");

	printFuncionario(f1);
	printFuncionario(f2);

	std::cout << c1.getTitular().autentica("senha123") << std::endl;
	std::cout << c2.getTitular().autentica("senha456") << std::endl;
	std::cout << f1.autentica("senha-gerente") << std::endl;
	std::cout << f2.autentica("senha-caixa") << std::endl;

	// operator overload em funcionamento:
	char seg = (char) DiaSemana::SEGUNDA;
	DiaSemana dom = DiaSemana::DOMINGO;

	std::cout << "Domingo: " << dom << ", Segunda: " << seg << std::endl; // `dom` funciona devido ao operator overload

	std::cout << c1.getTitular() << std::endl;
	std::cout << c2.getTitular() << std::endl;
	std::cout << f1 << std::endl;
	std::cout << f2 << std::endl;

	// template functions:
	// no primeiro caso o tipo é necessário entre <> pois estamos convertendo as duas referências
	// para o mesmo tipo (no caso ContaCorrente e ContaPoupanca para Conta)
	printConta(menor<Conta &>(c1, c2));
	std::cout << menor(42, 105) << std::endl; // tipo pode ser omitido dos <>
	std::cout << menor<float>(7.5, 29.7) << std::endl;

	return 0;
}
