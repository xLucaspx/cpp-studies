#pragma once

#include <string>
#include "Autenticavel.hpp"
#include "Cpf.hpp"
#include "DiaSemana.hpp"
#include "Pessoa.hpp"

class Funcionario : public Pessoa<Cpf>, public Autenticavel
{
private:
	float salario;
	DiaSemana diaPagamento;

public:
	Funcionario(std::string cpf, std::string nome, float salario, DiaSemana diaPagamento, std::string senha);

	[[nodiscard]] std::string getCpf() const;

	[[nodiscard]] float getSalario() const;

	[[nodiscard]] virtual float bonificacao() const = 0;
};
