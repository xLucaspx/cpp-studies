#include <utility>
#include "Autenticavel.hpp"

Autenticavel::Autenticavel(std::string senha)
		: senha(std::move(senha))
{}

bool Autenticavel::autentica(const std::string &senha) const
{
	return this->senha == senha;
}
