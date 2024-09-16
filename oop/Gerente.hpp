#pragma once

#include <string>
#include "Funcionario.hpp"

class Gerente : public Funcionario
{
public:
	Gerente(std::string cpf, std::string nome, float salario, std::string senha);

	[[nodiscard]] float bonificacao() const override;
};
