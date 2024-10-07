#pragma once

#include <iostream>
#include <string>

// Quando criamos uma template class, todas as definições e implementações devem ficar apenas
// no arquivo de cabeçalho, pois o compilador que irá gerar o código e as implementações! Aqui,
// apenas para fins didáticos, vamos transformar o documento de pessoa em um template; na vida
// real, existem abordagens muito melhores para resolver a questão de pessoas com documentos
// diferentes (e.g. classe base Documento e filhas RG, CPF, CNPJ etc.).
// Lembrando que template faz parte da assinatura, quebramos a linha apenas por legibilidade!

template<typename Doc> // podemos substituir typename por class, porém o anterior é mais claro!
class Pessoa
{
private:
	std::string nome;

protected:
	Doc doc;

public:
	Pessoa(Doc documento, std::string nome)
		: doc(std::move(documento)), nome(std::move(nome))
	{
		validaNome();
	}

	[[nodiscard]] std::string getNome() const
	{
		return nome;
	}


	friend std::ostream &operator<<(std::ostream &out, const Pessoa &p);

	// friend function: declarada em outro lugar mas pode acessar a classe como se fosse membro!

private:
	void validaNome()
	{
		if (nome.length() <= 5) {
			std::cerr << "Nome muito curto!" << std::endl;
			exit(1);
		}
	}
};
