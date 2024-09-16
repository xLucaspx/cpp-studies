#include <iostream>
#include <utility>
#include "Cpf.hpp"

Cpf::Cpf(std::string cpf)
		: m_Cpf(std::move(cpf))
{
	validaCpf();
}

std::string Cpf::getCpf() const
{
	return m_Cpf;
}

void Cpf::validaCpf()
{
	// validação complexa de CPF aqui!!! (motivo pelo qual extraímos a classe)

	if (m_Cpf.length() != 11) {
		std::cerr << "CPF de tamanho inválido!" << std::endl;
		exit(1);
	}
}
