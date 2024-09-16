#include <iostream>
#include <utility>
#include "Pessoa.hpp"

Pessoa::Pessoa(std::string cpf, std::string nome)
		: cpf(std::move(cpf)), nome(std::move(nome))
{
	validaNome();
}

void Pessoa::validaNome()
{
	if (nome.length() <= 5) {
		std::cerr << "Nome muito curto!" << std::endl;
		exit(1);
	}
}

std::string Pessoa::getNome() const
{
	return nome;
}
