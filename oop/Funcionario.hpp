#pragma once

#include <string>
#include "Pessoa.hpp"
#include "Autenticavel.hpp"

class Funcionario : public Pessoa, public Autenticavel
{
private:
	float salario;

public:
	Funcionario(std::string cpf, std::string nome, float salario, std::string senha);

	[[nodiscard]] std::string getCpf() const;

	[[nodiscard]] float getSalario() const;

	[[nodiscard]] virtual float bonificacao() const = 0;
};
