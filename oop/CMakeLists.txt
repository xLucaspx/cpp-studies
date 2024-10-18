cmake_minimum_required(VERSION 3.28)
project(oop)

set(CMAKE_CXX_STANDARD 23)

add_executable(oop main.cpp
		Conta.cpp
		Titular.cpp
		Cpf.cpp
		Funcionario.cpp
		ContaPoupanca.cpp
		ContaCorrente.cpp
		Gerente.cpp
		Caixa.cpp
		Autenticavel.cpp
		DiaSemana.hpp
)
