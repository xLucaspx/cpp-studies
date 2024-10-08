#pragma once

#include <string>
#include "Funcionario.hpp"

class Caixa : public Funcionario
{
public:
	Caixa(std::string cpf, std::string nome, float salario, DiaSemana diaPagamento, std::string senha);

	[[nodiscard]] float bonificacao() const override;
};
