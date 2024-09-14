#pragma once

#include <string>

class Cpf
{
private:
	std::string m_Cpf;

public:
	explicit Cpf(std::string cpf);

	[[nodiscard]] std::string getCpf() const;

private:
	void validaCpf();
};
