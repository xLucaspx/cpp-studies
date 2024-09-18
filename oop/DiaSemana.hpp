#pragma once

// podemos usar a sintaxe de herança para definir como o enum será armazenado;
// neste caso, utilizando o char, cada constante consome apenas 1 byte.

enum class DiaSemana : char
{
	// A resolução de nomes em enums não é obrigatória, embora seja possível. Para
	// criarmos as constantes apenas no escopo de DiaSemana e forçarmos a obrigação
	// da resolução de nomes, criamos uma `enum class`! Isso ajuda a resolver problemas
	// de duplicação de nomes etc. que podem  ocorrer no escopo geral.
	// enum class também garante mais segurança de tipos: podemos atribuir um enum a um
	// inteiro, por exemplo, mas com uma enum class isso daria erro de compilação e seria
	// necessário realizar o casting manualmente.

	DOMINGO, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO
	// m.q. DOMINGO = 0, SEGUNDA = 1, etc.

	// se quiséssemos começar do 1, por exemplo, bastaria definir o primeiro
	// valor como 1 e os próximos seriam incrementados; também é possível definir
	// os valores de todas as constantes, e.g. DOMINGO = 1, SEGUNDA = 2 etc.
};
