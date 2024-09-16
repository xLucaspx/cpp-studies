#include <utility>
#include "Funcionario.hpp"

Funcionario::Funcionario(std::string cpf, std::string nome, float salario, std::string senha)
		: Pessoa(std::move(cpf), std::move(nome)), salario(salario), Autenticavel(std::move(senha))
{}

std::string Funcionario::getCpf() const
{
	return cpf.getCpf();
}

float Funcionario::getSalario() const
{
	return salario;
}
