#include <utility>
#include "Titular.hpp"

// precisamos definir o construtor, mesmo querendo apenas
// chamar o construtor da superclasse
Titular::Titular(std::string cpf, std::string nome, std::string senha)
	: Pessoa(Cpf(std::move(cpf)), std::move(nome)), Autenticavel(std::move(senha))
{
}
