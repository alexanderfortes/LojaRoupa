//* 0784 Projeto Final - Alexander Fortes
//
//* Programa que gere uma loja de roupa.
//*    Especificações:
//*     Opções do menu:   
//*       -> 
//*        - Inserir produto      - Apagar produto
//*        - Pesquisar produto    - Listar produto
//*        - Repor produto        - Vender produto
//*        - Sair do programa.
//*
		//*  Dados dos vestuários:		
		//*   - código do vestuário
		//*   - categoria (homem, mulher, criança)
		//*   - tipo de roupa (vestido, calças, t-shirts...)
		//*   - cor do vestuário
		//*   - matéria-prima do vestuário
		//*   - preço do vestuário
		//*   - tamanho do vestuário
		//*   - número do armário onde está guardado;
		//*   - letra da prateleira.
//*
//**********************************************************
//*   - Vetores dinâmicos; classes derivadas; ficheiros
//*   - Operadores; Linguagem orientada a objetos - conceitos 
//*   - Bibliotecas. Base de Dados. 
//************************************************************
//* Versão 01 
//*   - Vetores estáticos - locais
//* Versão 02 
//*   - Vetores dinâmicos - globais
//* Versão 03 
//*   - Vetores dinâmicos - globais
//* Versão 04 
//*   - Vetores dinâmicos - locais
//* Versão 05 
//*   - Vetores dinâmicos - locais
//* Versão 06 
//*   - Vetores dinâmicos - locais
//* Versão 07 
//*   - Vetores dinâmicos - Ficheiros
//* Versão 08 
//*   - Vetores dinâmicos - Ficheiros - Libraries
//* Versão 09 
//*   - Vetores dinâmicos - Ficheiros - Libraries - Encriptação
//************************************************************
//*  Ordem de trabalhos:
//*   - Classe: dados, construtores, setters, getters, 
//*             leitura e escrita. 
//*   - Menu: opções do menu.
//*
//************************************************************
//* Todos os ficheiros do programa e as suas versões podem 
//* 	ser encontrados no meu repositório no github 
//* https://github.com/Alex-Fortes/LojaRoupa/tree/master
//*******************************************************
//* 	Criação de Bibliotecas
//*******************************************************
//* Se der o erro do "nullptr"
//* acrescentar em 
//* Menu Tools -> Compiler Options -> Separador Programs
//*  inserir:
//* gcc.exe -std=c++0x
//* g++.exe -std=c++11
//*******************************************************
//********************************************************
//* Este ficheiro contém todas as funções que 
//* implementam as opções do menu.
//********************************************************
// Bibliotecas de C
#include <cstdio>
#include <cstdlib>
#include <clocale>
// Biblioteca de C++
#include <string>     
#include <iostream>   
#include <iomanip>    
#include <vector>
#include "LojaRoupa_01FComuns.cpp" 
              // Inclusão das funções comuns
#include "LojaRoupa_02ClassePecaRoupa.cpp"
              // Inclusão do ficheiro de classe
#include "LojaRoupa_03Menu.cpp"
              // Inclusão das funções da Loja de roupa
using namespace std; 

	// Declaração e inicialização dos dados estaticos
		int Vestuario::numVestuarios = 0;

	// Dados globais
	const int MAXOPCOES = 8;
	extern vector<Vestuario> vestuarios;

    // Vetor de "Vestuario", ou seja composto por 
	//  objetos da classe Vestuario.
	// Nome do vetor: vestuarios.

//****************************************************
//* Função principal
//****************************************************
int main() 
	{
	setlocale(LC_ALL, "Portuguese");
	
	// 1. Dados
	vector<Vestuario> vestuarios;
	
	char escolha = '\0';
	bool queroSair = false;
	const int NUMOPCOES = 8;
	// 2. Programa principal
	lerFicheiro(&vestuarios);
	do 
		{
		mostraMenu();
		escolha = obtemEscolha(escolha, NUMOPCOES);
		queroSair = processaEscolha(&vestuarios, escolha, queroSair, NUMOPCOES);							
		} while(!queroSair);
	despedida();
return 0;
} // Fim da função "main()"
