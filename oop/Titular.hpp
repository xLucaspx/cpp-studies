#pragma once

#include <string>
#include "Cpf.hpp"

class Titular
{
private:
	Cpf cpf;
	std::string nome;

public:
	Titular(std::string cpf, std::string nome);

	[[nodiscard]] std::string getCpf() const;

	[[nodiscard]] std::string getNome() const;


private:
	void validaNome();
};
