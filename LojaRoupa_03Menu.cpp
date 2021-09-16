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
	#include <ctime>
	#include <windows.h>
	// Biblioteca de C++
	#include <string>     
	#include <iostream>   
	#include <iomanip>    
	#include <vector>
	#include <fstream>
	using namespace std; 


	//*******************
// DEclaração de um vetor dinâmico
vector<Vestuario> vestuarios;

// Protótipos das funções
// Declaração das funções - Cabeçalhos das funções
		void mostraMenu();
		char obtemEscolha(char );
		bool processaEscolha(vector<Vestuario>*, char, bool,int );
		void despedida();
		
		void listarVestuarios(vector<Vestuario>);
		void inserirVestuario(vector<Vestuario>*);
		void apagarVestuario(vector<Vestuario>*);
		void pesquisarVestuario(vector<Vestuario>);
		void atualizarVestuario(vector<Vestuario>*);
		void venderVestuario(vector<Vestuario>*);
		void reporVestuario(vector<Vestuario>*);
		void guardaFicheiro(vector<Vestuario> vestuarios);
		void lerFicheiro(vector<Vestuario> *vestuarios);

//***********************************************
//* Função "inicializaLojaRoupa()"
//* Entrada(s):  vestuarios.
//* Saida(s): não tem.
//************************************************
	void inicializaLojaRoupa()
	{
	} // Fim da função "inicializaLojaRoupa()"

//*******************************************************
//* Função "mostraMenu()".
//* Entrada(s): não tem.
//* Saida(s): não tem.
//*******************************************************
		void mostraMenu()
		{
		system("cls");   
		system("color A");
		cout<<"************************************"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"*       Loja de Roupa Moda         *"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"*    A. Inserir vestuario.         *"<<endl;
		cout<<"*    B. Apagar vestuario.          *"<<endl;
		cout<<"*    C. Pesquisar vestuario.       *"<<endl;
		cout<<"*    D. Atualizar vestuario.       *"<<endl;
		cout<<"*    E. Listar vestuario.          *"<<endl;
		cout<<"*    F. Vender vestuario.          *"<<endl;
		cout<<"*    G. Repor vestuario.           *"<<endl;
		cout<<"*    H. Sair do programa.          *"<<endl;
		cout<<"*                                  *"<<endl;
		cout<<"************************************"<<endl;
		cout<<endl;	
		} // Fim da função "mostraMenu()".

//*********************************************
//* Função "obtemEscolha()"
//* Entrada(s): char escolha 
//* Saida(s): char
//*********************************************
	char obtemEscolha(char escolha, int numOp)
		{
		char ultimaOp = (char)(numOp+64); // "A" - ASCII 65	
		cout<<"Qual a sua escolha (A-"<<ultimaOp<<")? ";
		cin>>escolha; cin.ignore();	
		return escolha;	
	} // Fim do "obtemEscolha()".


//**********************************************
//*  Função processaEscolha()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios,
//*              char escolha, bool queroSair.
//*    Saida(s): bool queroSair.
//**********************************************
	bool processaEscolha(vector<Vestuario> *vestuarios,
                        char escolha, bool queroSair, int numOp)
	{    
	 switch(escolha)
		 {
		  case 'A': case 'a': inserirVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'B': case 'b': apagarVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'C': case 'c': pesquisarVestuario(*vestuarios); 
		                      break;
		  case 'D': case 'd': atualizarVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;
		  case 'E': case 'e': listarVestuarios(*vestuarios);
		                      break;
		  case 'F': case 'f': venderVestuario(vestuarios);  
		                      guardaFicheiro(*vestuarios);
		                      break;			
		  case 'G': case 'g': reporVestuario(vestuarios);
		                      guardaFicheiro(*vestuarios);
		                      break;			  	 
		  case 'H': case 'h': queroSair = sairDoPrograma(queroSair);
		                      break;
	  default:	 
		  escolhaInvalida(numOp);
 } // Fim do "switch"

return queroSair;	
} // Fim da Função "processaEscolha()".

//**********************************************
//*  Função inserirVestuario()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void inserirVestuario(vector<Vestuario> *vestuarios)
	{		 
		Vestuario* vestuario;
		vestuario = new Vestuario;
		vestuario->leTudoVestuario();
		
		int nVestuarios = vestuarios->size();
		cout<<"Número de vestuarios: "<<nVestuarios<<"."<<endl;
		
		vestuarios->push_back(*vestuario); 
		Vestuario::numVestuarios++;
		//vestuarios.insert(vestuarios.begin()+nVestuarios, vestuario);
		vestuarios->at(nVestuarios).mostraTudoVestuario();
		nVestuarios = vestuarios->size();
		cout<<"Número de vestuarios: "<<nVestuarios<<"."<<endl;
		cout<< "Vestuário inserido com sucesso!"<<endl;
	pausa();
} // Fim da função "Inserirvestuario()".

//**********************************************
//*  Função apagarVestuario()"
//*    Entradas: vector<Vestuario>& vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void apagarVestuario(vector<Vestuario> *vestuarios)
	{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		cout<<"Número de vestuarios: "<<nVestuarios<<"."<<endl;
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		  do {
		   cout<<"Qual o vestuario a apagar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
		      {
		      cout<<"Número de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
		      cout<< "Prima qualquer tecla para continuar ... ";
		      cin.get(); 		
			  }
		  } while (nVestuario < 1 || nVestuario > nVestuarios);
		
		  vestuarios->erase(vestuarios->begin()+(nVestuario-1)); 
		  Vestuario::numVestuarios--;
		  cout<<"Vestuario apagado com sucesso!"<<endl;
	  pausa();
	  }
} // Fim da função "apagarvestuario()".

//**********************************************
//*  Função pesquisarVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void pesquisarVestuario(vector<Vestuario> vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios.size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a pesquisar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
			   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"Número de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
				  }
			} while (nVestuario < 1 || nVestuario > nVestuarios);
		vestuarios[nVestuario-1].mostraTudoVestuario();  
	pausa();
	}
} // Fim da função "pesquisarvestuario()".

//**********************************************
//*  Função atualizarVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void atualizarVestuario(vector<Vestuario> *vestuarios)
	{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a atualizar (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
			   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"Número de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
		cout<<"Insira o novo preço: "<<endl;
		(*vestuarios)[nVestuario-1].lePreco();
		(*vestuarios)[nVestuario-1].mostraTudoVestuario();
		cout<< "Atualização efetuada com sucesso!"<<endl; 
	pausa();
	}
} // Fim da função "atualizarvestuario()".

//**************************************************
//* Função "listarVestuarios()"
//* Entrada(s): Vestuario vestuarios[], int numVestuarios
//* Saida(s): não tem.
//**************************************************
	void listarVestuarios(vector<Vestuario> vestuarios)
		{
		int nVestuarios = vestuarios.size();
		cout<<"Número de vestuarios: "<<nVestuarios<<"."<<endl;
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		cout<<"-> Listagem de vestuarios: \n";
			for(int cVestuario=0; cVestuario<nVestuarios; cVestuario++)
				{
				cout<<"Vestuario "<< cVestuario+1<<": "<<endl;	
			    cout<<" -> Tipo: "<<vestuarios[cVestuario].getTipo()<<endl;
			    cout<<" -> Categoria: "<<vestuarios[cVestuario].getCategoria()<<endl;
			//    cout<<" -> Matéria-prima: "<<vestuarios[cVestuario].getMateriaPrima()<<endl;
			    cout<<" -> Tamanho: "<<vestuarios[cVestuario].getTamanho()<<endl;
				cout<<" -> Preço: "<<vestuarios[cVestuario].getPreco()<<" euros"<<endl;
				cout<<" -> Unidades em stock: "<<vestuarios[cVestuario].getNumUnidades()<<endl;
			} 
	pausa();
	}
} // Fim da função "listarVestuarioes()".

//**********************************************
//*  Função venderVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void venderVestuario(vector<Vestuario> *vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a vender (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"Número de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<<"Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		
			(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
			int uVendidas = 0, nUnidades=0;
			nUnidades = (*vestuarios)[nVestuario-1].getNumUnidades(); 
			cout<<"Quantas unidades vendeu? ";
			cin >> uVendidas; cin.ignore();
			nUnidades -= uVendidas;
			(*vestuarios)[nVestuario-1].setNumUnidades(nUnidades); 
			(*vestuarios)[nVestuario-1].mostraTudoVestuario(); 
			cout<< "Venda efetuada com sucesso!"<<endl;
	pausa();
	}
} // Fim da função "vendervestuario()".

//**********************************************
//*  Função reporVestuario()"
//*    Entradas: vector<Vestuario> *vestuarios, int numVestuarios.
//*    Saida(s): não tem.
//**********************************************
	void reporVestuario(vector<Vestuario> *vestuarios)
		{ 
		int nVestuario = 0;
		int nVestuarios = vestuarios->size();
		if (nVestuarios <= 0) 
		  {
		  cout<<"Não existem vestuarios!"<<endl;
		  pausa();	
		  } 
		else
		  {
		do {
		   cout<<"Qual o vestuario a repor (1-"<<nVestuarios<<")? ";
		   cin>> nVestuario; cin.ignore();
		   if (nVestuario < 1 || nVestuario > nVestuarios)
			      {
			      cout<<"Número de vestuarios entre 1 e "<<nVestuarios<<"."<<endl;
			      cout<< "Prima qualquer tecla para continuar ... ";
			      cin.get(); 		
			  }
		} while (nVestuario < 1 || nVestuario > nVestuarios);
		
			(*vestuarios)[nVestuario-1].mostraTudoVestuario();  
			int uRepostas = 0, nUnidades=0;
			nUnidades = (*vestuarios)[nVestuario-1].getNumUnidades(); 
			cout<<"Quantas unidades vai repor? ";
			cin >> uRepostas; cin.ignore();
			nUnidades += uRepostas;
			(*vestuarios)[nVestuario-1].setNumUnidades(nUnidades); 
			(*vestuarios)[nVestuario-1].mostraTudoVestuario(); 
			cout<< "Reposição efetuada com sucesso!"<<endl;
	pausa();
	}
} // Fim da função "vendervestuario()".



//****************************************************************
//* GravarFicheiro
//****************************************************************
	void guardaFicheiro(vector<Vestuario> vestuarios)
		{
		 string caminho="", nomeFicheiro="LojaRoupa.txt";
		 string nomeCompleto = caminho + nomeFicheiro;
		 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;
		
		   // 4. Criar o objeto e abrir o ficheiro
		   //ofstream ficheiro4(nomeCompleto.c_str());
		   ofstream ficheiro;
		   ficheiro.open(nomeCompleto, ios::out); // | ios_base::binary
		    // Modos de abertura: "ios::out" -> escrita
		
		 if(!ficheiro)  {
		 	cout<<"Ficheiro não foi aberto!"<<endl; 
		 	pausa();
		 }
		 else {  
		   // 4. Escrever mensagem
		   int nVestuarios = vestuarios.size(); 
		   cout<<"Número de vestuarios: "<<nVestuarios<<"."<<endl;
			   if (nVestuarios <= 0) 
			      {
			      cout<<"Não existem vestuarios!"<<endl;
			      pausa();	
			      } 
			   else
			      {
			      cout<<"-> Gravação dos vestuarios: \n";
				      for(int cVestuario=0; cVestuario<nVestuarios; cVestuario++)
					     ficheiro<<vestuarios[cVestuario];
				   // 5. Fechar o ficheiro
				   ficheiro.close();
				   cout<<"Dados gravados com sucesso!"<<endl;  
		   pausa();
		  }
	}

} // Fim da função "guardaFicheiro()".

//****************************************************************
//* LerFicheiro
//****************************************************************
	void lerFicheiro(vector<Vestuario> *vestuarios)
	{
	 string caminho="", nomeFicheiro="LojaRoupa.txt";
	 string nomeCompleto = caminho + nomeFicheiro;
	 cout<<"Nome do ficheiro: "<<nomeCompleto.c_str()<<"."<<endl;   
	
	 vestuarios->erase(vestuarios->begin(),vestuarios->end());
	
	 cout<<"-> Leitura dos vestuarios: \n";
	    // 3. Criar o objeto e abrir o ficheiro
	   //ofstream ficheiro4(nomeCompleto.c_str());
	   ifstream ficheiroL;
	   ficheiroL.open(nomeCompleto, ios::in); // | ios_base::binary
	
		 if (ficheiroL.is_open ()) {  
		
		   Vestuario vestuario;
		    // 4. Leitura dos objetos
		   int contaVestuarios = 0;
		   while(ficheiroL>>vestuario && !ficheiroL.eof() )
		    {
		   	vestuarios->push_back(vestuario);
		    contaVestuarios++;
		    cout<<"Vestuario "<<contaVestuarios<<": "<<endl;
		    }
		   // 5. Fechar o ficheiro
		   ficheiroL.close();
		   cout<<endl;
	    }
}
