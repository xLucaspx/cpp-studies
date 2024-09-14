#include <iostream>
#include <utility>
#include "Titular.hpp"

Titular::Titular(std::string cpf, std::string nome)
		: cpf(std::move(cpf)), nome(std::move(nome))
{
	validaNome();
}

std::string Titular::getCpf() const
{
	return cpf.getCpf();
}

std::string Titular::getNome() const
{
	return nome;
}

void Titular::validaNome()
{
	if (nome.length() <= 5) {
		std::cerr << "Nome muito curto!" << std::endl;
		exit(1);
	}
}
