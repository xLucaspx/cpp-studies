#include "Conta.hpp"

unsigned int Conta::totalContas = 0;

// Conta::Conta(std::string numero, std::string cpfTitular, std::string nomeTitular) {
// 	// this é um ponteiro para a instância do objeto
// 	this->numero = std::move(numero);
// 	this->cpfTitular = std::move(cpfTitular);
// 	this->nomeTitular = std::move(nomeTitular);
// 	saldo = 0.0f; // devemos inicializar todos os atributos para evitar lixo da memória!
// }

// Initialization list: forma mais sucinta de inicializar atributos da classe no construtor;
// após os dois pontos, colocamos o atributo e entre parênteses o valor que queremos passar (argumento ou imediato).
// É uma boa prática inicializar na mesma ordem que os membros foram declarados na classe!

Conta::Conta(std::string numero, Titular titular)
		: numero(std::move(numero)),
			titular(std::move(titular)),
			saldo(0.0f)
{
	totalContas++;
}

unsigned int Conta::getTotalContas()
{
	return totalContas;
}

void Conta::depositar(float valor)
{
	if (valor <= 0) {
		return;
	}

	saldo += valor;
}


void Conta::sacar(float valor)
{
	if (valor <= 0 || valor > saldo) {
		return;
	}

	saldo -= valor;
}

void Conta::transferir(Conta &destino, float valor)
{
	if (valor <= 0 || valor > saldo) {
		return;
	}

	sacar(valor);
	destino.depositar(valor);
}

std::string Conta::getNumero() const
{
	return numero;
}

Titular Conta::getTitular() const
{
	return titular;
}

float Conta::getSaldo() const
{
	return saldo;
}

Conta::~Conta()
{
	// o destrutor serve para destruir o que o construtor criou, e.g. fechar um arquivo
	// que foi aberto, liberar (com delete) memória alocada (com new) etc. Serve para liberar recursos!
	totalContas--;
}
