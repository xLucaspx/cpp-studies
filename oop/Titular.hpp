#pragma once

#include <string>
#include "Autenticavel.hpp"
#include "Cpf.hpp"
#include "Pessoa.hpp"

// : -> sintaxe de "extends" em C++
// Repare no modificador de acesso: `public` significa que tudo o que é público em Pessoa
// continuará sendo público em Titular; se fosse `protected`, o que é público tornaria-se
// protegido e, caso fosse `private`, todos os membros públicos e protegidos de Pessoa se
// tornariam privados em Titular. Este último tipo de herança é muito raro pois é como se
// a herança privada não existisse para o mundo externo, i.e. códigos que utilizam o tipo
// não tem como saber que a herança existe. A mais comum é public (não modifica a super).

class Titular : public Pessoa<Cpf>, public Autenticavel // C++ permite herança múltipla
{
public:
	Titular(std::string cpf, std::string nome, std::string senha);
};
