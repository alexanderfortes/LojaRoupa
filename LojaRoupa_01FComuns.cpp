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
//* https://github.com/Alex-Fortes/LojaRoupa/tree/master
//*******************************************************
//* Criação de Bibliotecas
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
	#include <cstring>
	#include <ctime>
	#include <windows.h>
	// Biblioteca de C++
	#include <string>     
	#include <iostream>   
	#include <iomanip>   
using namespace std; 

//**********************************************
//*  Função "pausa()"
//*    Entradas: não tem.
//*    Saida(s): não tem.
//**********************************************
		void pausa()
		{
		cout<< "Prima qualquer tecla para continuar ... ";
		cin.get(); 
		} // Fim da função "pausa()".


//*************************************************
//*  Função "sairDoPrograma()"
//*   Entrada(s): queroSair (bool) 
//*   Saida(s): queroSair (bool)
//*************************************************
	bool sairDoPrograma(bool queroSair)
		{
		char resposta = '\0';
			fflush(stdin);
			cout<<"Tem a certeza (S/N)? ";
		    cin>>resposta; cin.ignore();	
				if (resposta == 'S'  ||  resposta == 's')
			   	queroSair = true;	
	return queroSair;	
} // Fim da função "sairDoPrograma()".


//**************************************************
//* Função "escolhaInvalida()"
//*  Entrada(s): não tem.
//*  Saida(s): não tem.
//**************************************************
//**************************************************
//* Função escolhaInvalida()
//***************************************************
	void escolhaInvalida(int numOp)
	{
		char ultimaOp = (char)(64 + numOp);  // 68 -> 'D'
		cout<<"Escolha inválida! Escolha deve ser de A a "<<ultimaOp;
		cout<<"."<<endl;
	pausa();	
} // Fim da função "escolhaInvalida()".

//**************************************************
//* Função "escolhaInvalida()"
//*  Entrada(s): não tem.
//*  Saida(s): não tem.
//**************************************************
	void escolhaInvalida()
		{
		  cout<<"Escolha inválida!\n"; system("pause");	
	} // Fim da função "escolhaInvalida()".

//***************************************************
//*  Função "despedida()"
//*   Entrada(s): não tem.
//*   Saida(s): não tem.
//***************************************************
	void despedida()
		{
		cout<<"Obrigado por ter utilizado o nosso \"software\"!\n";
		cout<< "Prima qualquer tecla para continuar ... ";
		cin.get(); 	
	} // Fim da função "despedida()".


	class DataEHoras {
		
		public:
			
		static const std::string currentDate() {
		    time_t     now = time(0);
		    struct tm  tstruct;
		    char       buf[80];
		    tstruct = *localtime(&now);
		    strftime(buf, sizeof(buf), "%Y-%m-%d", &tstruct);
		return buf;
}

	static const std::string currentTime() {
		    time_t     now = time(0);
		    struct tm  tstruct;
		    char       buf[80];
		    tstruct = *localtime(&now);
		    strftime(buf, sizeof(buf), "%H:%M:%S", &tstruct);
		return buf;
}

//***********************************************************
//* Obtenção dos elementos de uma data e hora - Versão C/C++
//**********************************************************
	static int obtemAno(string data)
	    {                                  // 01234567
	    string infoAno = data.substr(0,4); // YYYY-MM-DD
		int ano = atoi(infoAno.c_str());  	
    return ano;	
}  

	static int obtemMes(string data)
	    {                                  // 01234567
	    string infoMes = data.substr(5,2); // YYYY-MM-DD
		int mes = atoi(infoMes.c_str());  	
	    return mes;	
	}  

	static int obtemDia(string data)
	    {                                  // 012345678
	    string infoDia = data.substr(8,2); // YYYY-MM-DD
		int dia = atoi(infoDia.c_str());  	
    return dia;	
	}  

	static int obtemHoras(string tempo)
	    {
	    string infoHoras = tempo.substr(0,2);  // HH:MM:SS
	        // substr(posição inicial, num. carcateres)
			int numHoras = atoi(infoHoras.c_str()); 
			    // ascii to integer    	
				// "c_str()" - c_STRING() - 
				// transforma uma "string" num array
				// de caracteres.
    return numHoras;	
	}   

	static int obtemMinutos(string tempo)
	    {                                       // 01234567
	    string infoMinutos = tempo.substr(3,2); // HH:MM:SS
		int numMinutos = atoi(infoMinutos.c_str());  	
    return numMinutos;	
}  

//***********************************************************
//* Obtenção dos elementos de uma data e hora - Versão C++
//**********************************************************
	static int obtemAnoV2(string data)
	    {                                  // 01234567
	    string infoAno = data.substr(0,4); // YYYY-MM-DD
		int ano = stoi(infoAno,nullptr,10);  	
    return ano;	
	}  

	static int obtemMesV2(string data)
	    {                                  // 01234567
	    string infoMes = data.substr(5,2); // YYYY-MM-DD
		int mes = stoi(infoMes,nullptr,10);  	
    return mes;	
	}  

	static int obtemDiaV2(string data)
	    {                                  // 01234567
	    string infoDia = data.substr(8,2); // YYYY-MM-DD
		int dia = stoi(infoDia,nullptr,10);  	
    return dia;	
	}  
	
	static int obtemHorasV2(string tempo)
	    {                                   // 01234567
	    string infoHoras = tempo.substr(0,2); // HH:MM:SS
		int horas = stoi(infoHoras,nullptr,10);  	
    return horas;	
	}  	

	static int obtemMinutosV2(string tempo)
	    {                                     // 01234567
	    string infoMinutos = tempo.substr(0,2); // HH:MM:SS
		int minutos = stoi(infoMinutos,nullptr,10);  	
    return minutos;	
	} 	
};



	




	
