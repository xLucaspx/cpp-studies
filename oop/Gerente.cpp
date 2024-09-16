#include <utility>
#include "Gerente.hpp"

Gerente::Gerente(std::string cpf, std::string nome, float salario, std::string senha)
		: Funcionario(std::move(cpf), std::move(nome), salario, std::move(senha))
{}

float Gerente::bonificacao() const
{
	return getSalario() * 0.05f;
}
