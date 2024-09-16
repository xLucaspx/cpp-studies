#pragma once

#include <string>
#include "Conta.hpp"

class ContaPoupanca final : public Conta
{

public:
	ContaPoupanca(std::string numero, Titular titular);

private:
	[[nodiscard]] float taxaDeSaque() const override;
};
