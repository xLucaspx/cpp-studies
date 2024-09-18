#include <iostream>
#include <string>
#include <tuple>
#include <utility>

struct Person
{
	std::string name;
	int age;
};

void createPerson1(std::string *name, int *age)
{
	// utilizando ponteiros é, talvez, a forma mais performática; temos a vantagem
	// de poder ignorar algum dos valores, se for o caso
	// e.g. int age; createPerson1(nullptr, &age); // queremos apenas a idade
	if (name) {
		*name = "Fulano de Tal";
	}
	if (age) {
		*age = 42;
	}
}

Person createPerson2()
{
	// structs são uma ótima opção, são legíveis e nos dão bastante poder!
	return {"Fulano de Tal", 42};
}

std::tuple<std::string, int> createPerson3()
{
	// antes do C++17 teríamos que declarar:
	// return std::make_pair("Fulano de Tal", 42);

	// agora podemos usar a sintaxe:
	return {"Fulano de Tal", 42};

	// neste caso, como são dois valores, poderíamos retornar um `pair` apenas
	// alterando na assinatura da função; porém, tuplas nos permitem adicionar
	// novos valores facilmente e tem comportamento semelhante; o uso depende do contexto!
}

int main()
{
	std::string name1;
	int age1;
	// utilizando ponteiros, temos que passar o endereço de memória na chamada, o que
	// deixa ainda mais explicito que estes dados serão alterados
	createPerson1(&name1, &age1);

	// com structs tudo fica muito claro
	Person p1 = createPerson2();
	std::string name2 = p1.name;
	int age2 = p1.age;
	// sintaxe C++17:
	auto [name3, age3] = p1;

	// o pior de usar pair/tuple em C++ era a falta de clareza ao acessar valores;
	std::tuple<std::string, int> p2 = createPerson3();
	std::string name4 = std::get<0>(p2);
	int age4 = std::get<1>(p2); // com pair poderíamos fazer p2.first e p2.second, mas continua não claro

	// fica um pouquinho melhor com std::tie...
	std::string name5;
	int age5;
	std::tie(name5, age5) = createPerson3();

	// ... mas melhorou muito com a sintaxe de structured bindings do C++17:
	auto [name6, age6] = createPerson3();;

	std::cout << "1 -> nome: " << name1 << ", idade: " << age1 << " anos;" << std::endl;
	std::cout << "2 -> nome: " << name2 << ", idade: " << age2 << " anos;" << std::endl;
	std::cout << "3 -> nome: " << name3 << ", idade: " << age3 << " anos;" << std::endl;
	std::cout << "4 -> nome: " << name4 << ", idade: " << age4 << " anos;" << std::endl;
	std::cout << "5 -> nome: " << name5 << ", idade: " << age5 << " anos;" << std::endl;
	std::cout << "6 -> nome: " << name6 << ", idade: " << age6 << " anos;" << std::endl;

	return 0;
}
