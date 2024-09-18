#include "Caixa.hpp"

Caixa::Caixa(std::string cpf, std::string nome, float salario, DiaSemana diaPagamento, std::string senha)
		: Funcionario(std::move(cpf), std::move(nome), salario, diaPagamento, std::move(senha))
{}

float Caixa::bonificacao() const
{
	return getSalario() * 0.03f;
}
