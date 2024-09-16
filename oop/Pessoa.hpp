#pragma once

#include <string>
#include "Cpf.hpp"

class Pessoa
{
private:
	std::string nome;

protected:
	Cpf cpf;

public:
	Pessoa(std::string cpf, std::string nome);

	[[nodiscard]] std::string getNome() const;

private:
	void validaNome();
};
