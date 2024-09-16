#include "Caixa.hpp"

Caixa::Caixa(std::string cpf, std::string nome, float salario, std::string senha)
		: Funcionario(std::move(cpf), std::move(nome), salario, std::move(senha))
{}

float Caixa::bonificacao() const
{
	return getSalario() * 0.03f;
}
