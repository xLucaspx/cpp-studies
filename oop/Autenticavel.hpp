#pragma once

#include <string>

class Autenticavel
{
private:
	std::string senha;

public:
	explicit Autenticavel(std::string senha);

	[[nodiscard]] bool autentica(const std::string &senha) const;
};

