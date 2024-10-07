#include <utility>
#include "Funcionario.hpp"

Funcionario::Funcionario(std::string cpf, std::string nome, float salario, DiaSemana diaPagamento, std::string senha)
	: Pessoa(Cpf(std::move(cpf)), std::move(nome)),
	  salario(salario),
	  diaPagamento(diaPagamento),
	  Autenticavel(std::move(senha))
{
}

std::string Funcionario::getCpf() const
{
	return doc.getCpf();
}

float Funcionario::getSalario() const
{
	return salario;
}
