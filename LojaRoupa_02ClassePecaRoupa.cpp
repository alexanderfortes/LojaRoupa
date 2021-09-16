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
		#include <vector>
		using namespace std; 

	// DESLOCAMENTO ENCRIPTAÇÃO
	const int DESLOCAMENTO = 3;


	// Definição da classe
	class Vestuario
	{
	 private:   
		    // Dados devem ser privados	
		    //*   - código do vestuario -> posição no vetor
		    string categoria;
		    string tipo;
		    string cor;
		    string materiaPrima;
		    float preco;
		    string tamanho;
		    int numSecao;
		    char letraPrateleira;
		    int numUnidades;
		    int indiceQuebra;
    
  
//****************************************************
//* Função encripta()
//****************************************************
	string  encripta(string mensagemO, int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemO.c_str());
						 	
// for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] + desl;
		   	if ( ((valor) > 90 && isupper(mensagem[cLetra]))
			    || ((valor) > 122 && islower(mensagem[cLetra]))
			   )
			   valor = valor - 26;
				if (mensagem[cLetra]=='.')
				   mensagem[cLetra] ='.';
			else   
		   	   mensagem[cLetra] = valor; 
  		}
	//cout<<mensagem;	
	return mensagem;	
}

//****************************************************
//* Função desencripta()
//****************************************************
	string  desencripta(string mensagemE, int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE.c_str());
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< mensagemE.length(); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
			else   
		   	   mensagem[cLetra] = valor; 	
	   }
	//cout<<mensagem;	
	return mensagem;	
}

//****************************************************
//* Função desencripta()
//****************************************************
	char*  desencriptaII(char mensagemE[], int desl)
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
		else   
		   	mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
return mensagem;	
}    


//****************************************************
//* Função desencripta()
//****************************************************
	void  desencriptaIII(char mensagemE[], int desl,char mensagemO[])
		{
		const int MaxChars = 100;	
		char mensagem[MaxChars];
		for(int cLetra=0; cLetra<MaxChars; cLetra++) 
		                         mensagem[cLetra]='\0';
		                         
		strcpy(mensagem,mensagemE);
						 	
//for(int cLetra=0; cLetra< mensagemO.length(); cLetra++)
//    mensagem[cLetra]=toupper(mensagem[cLetra]);

	for(int cLetra=0; cLetra< strlen(mensagemE); cLetra++)	
	   {
	   	int valor = (int)mensagem[cLetra] - desl;
	   	if ( ((valor) < 65 && isupper(mensagem[cLetra]))
		    || ((valor) < 97 && islower(mensagem[cLetra]))
		   )
		   
	   	   valor = valor + 26;
			if (mensagem[cLetra]=='.')
			   mensagem[cLetra] ='.';
		else   
	   	   mensagem[cLetra] = valor; 	
   }
//cout<<mensagem;	
strcpy(mensagemO,mensagem);	
}    

	public:    // Funções devem ser públicas 
    // Dados estáticos
    static int numVestuarios;
    
    // 2. Funções
    // 2.0 Funções de inicialização
    void inicializaVestuario()
	     {
	     categoria =""; tipo =""; cor =""; materiaPrima =""; preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0';numUnidades = 0;
		 indiceQuebra = 0;
	 }
    
    // 2.1  Funções construtoras
    //      Servem para inicializar os dados de cada objeto.
    // 2.1.1 Construtor sem argumentos
    Vestuario()
	     {
	     categoria =""; tipo=""; cor="";materiaPrima=""; preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0'; numUnidades = 0; 
		 indiceQuebra = 0;	
	 }
	 
	// 2.1.2 Construtor com argumentos
	Vestuario(string aut, string tit) 
		 {
	     categoria.assign(aut); tipo=tit; cor.assign(aut); materiaPrima.assign(aut); preco=0; tamanho="";
	     numSecao =0; letraPrateleira = '\0';
		 numUnidades = 0; indiceQuebra = 0; 	
	 }
  
    // 2.1.3 Construtor com argumentos II
	Vestuario(string aut, string tit, int numA, char letraP) 
		 {
	     categoria.assign(aut); tipo=tit; cor.assign(aut); materiaPrima.assign(aut); preco=0; tamanho="";
	     numSecao =numA; letraPrateleira = letraP;
		 numUnidades = 0; 	indiceQuebra = 0;
	 }    
	 
	// 2.2 Destrutor
	//     Código que é executado antes de um objeto
	//     sair de memória.
    ~Vestuario() {
	         }
	
	// 2.3 Setters
	//     Permitem a atribuição de valores a cada 
	//     dado de um objeto.
	void setCategoria  (string a)  { categoria = a;}
	void setTipo (string t)  { tipo = t;}
	void setCor(string a)  { cor = a;}
	void setMateriaPrima(string a)  { materiaPrima = a;}
	void setTamanho    (string a)     { tamanho = a;}
	void setPreco  (float p)   { preco = p;}
	void setNumSecao(int na) { numSecao = na;}
	void setLetraPrateleira  (char lp)   
	                           { letraPrateleira = lp;}
	void setNumUnidades(int nu)   
	                           { numUnidades = nu;}	
	void setIndiceQuebra(int iq)   
	                           { indiceQuebra = iq;}							   	
	         
	// 2.4 Getters
	//     Permitem a obtenção do valor de  cada 
	//     dado de um objeto.
	string getCategoria  ()       	{ return categoria;}
	string getTipo ()       		{ return tipo;}
	string getCor()       			{ return cor;}
	string getMateriaPrima()       	{ return materiaPrima;}
	string getTamanho    ()         { return tamanho;}
	float getPreco  ()        		{ return preco;}
	int getNumSecao()       		{ return numSecao;}
	char getLetraPrateleira() 		{ return letraPrateleira;}
	int getNumUnidades()      		{ return numUnidades;}
	int getIndiceQuebra()     		{ return indiceQuebra;}
	
	// 2.5 Funções de Leitura
	void leCategoria()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual o categoria do vestuário?(homem/mulher/criaça) ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCategoria(string(letras));
      }
	  	
	void leTipo()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual o tipo do vestuário? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setTipo(string(letras));
      }
	  	
	void leCor()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual a cor do vestuário? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCor(string(letras));
      }
    void leMateriaPrima()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';
						  	
	  cout<<"Qual foi a matéria-prima usada? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setCor(string(letras));
      }
	  	
	void leTamanho()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o tamanho do vestuário? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setTamanho(string(letras));  
	}
	  	
	void lePreco()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o preço do vestuário? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setPreco(atof(letras));
	      // atof() - ascii to float- converte 
	      //          array de chars para float
      }	  	  	  	
	  		  	
	void leNumSecao()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o número da seção onde o vestuário está? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumSecao(atoi(letras));
      }	  	
	  
	void leLetraPrateleira()
	  {
      char letra = '\0';	
	  cout<<"Qual a letra da estante? ";
	  cin>>letra; 	  
	  if (isalpha(letra)) letra=toupper(letra); 
	  cin.ignore();  // fflush(stdin);
	  setLetraPrateleira(letra);
      }			

	void leNumUnidades()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Quantas unidades existem deste vestuário? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setNumUnidades(atoi(letras));
      }	 
	  
	void leIndiceQuebra()
	  {
	  const int MaxChars = 40;	
	  char letras[MaxChars];
	  for (int cLetra=0; cLetra<MaxChars; cLetra++)
	                      letras[cLetra]='\0';				  	
	  cout<<"Qual o índice de quebra? ";
	  cin.getline(letras, sizeof(letras),'\n');
	  setIndiceQuebra(atoi(letras));
      }	 	  	
	
	void leTudoVestuario()
	  {
	  leCategoria(); leTipo(); leCor(); leMateriaPrima();
	  leTamanho(); lePreco(); leNumSecao();
	  leLetraPrateleira(); leNumUnidades();	
	  leIndiceQuebra();
	  }
	  
	// 2.6 Funções de Escrita
	void mostraCategoria()
	   { cout<< "Categoria: "<<getCategoria()<<"."<<endl; }  

	void mostraTipo()
	   { cout<< "Tipo: "<<getTipo()<<"."<<endl; } 
	   
	void mostraCor()
	   { cout<< "Cor: "<<getCor()<<"."<<endl; }  
	   
	void mostraMateriaPrima()
	   { cout<< "Matéria-Prima: "<<getMateriaPrima()<<"."<<endl; } 
	    
	void mostraTamanho()
	   { cout<< "Tamanho: "<<getTamanho()<<"."<<endl; } 

	void mostraPreco()
	   { 
	   cout<<fixed<<setprecision(2);
	   cout<< "Preço s/IVA: "<<getPreco()<<" euros."<<endl;
	   cout<< "Preço c/IVA: "<<obtemPrecoComIVA(getPreco());
	   cout<<" euros."<<endl;
	   } 

	void mostraNumSecao()
	{ cout<< "N.º Seção: "<<getNumSecao()<<"."<<endl; } 

	void mostraLetraPrateleira()
	{ cout<<"Estante: "<<getLetraPrateleira()<<"."<<endl;}

	void mostraNumUnidades()
	{ cout<<"N.º Unidades: "<<getNumUnidades()<<"."<<endl; } 

	void mostraIndiceQuebra()
	{ cout<<"Índice quebra: "<<getIndiceQuebra()<<"."<<endl;} 

    void mostraTudoVestuario()
       { mostraCategoria(); mostraTipo(); mostraCor();
         mostraTamanho(); mostraPreco(); mostraNumSecao();
         mostraLetraPrateleira(); mostraNumUnidades();
         mostraIndiceQuebra();
       }
       
    // Outras Funções
	static float obtemPrecoComIVA(float psi)
	  {
	  const float IvaVestuario = 0.23;
	  return (psi*(1+IvaVestuario));	
	  }
	   
	static float obtemPrecoSemIVA(float pci)
	  {
	  const float IvaVestuario = 0.23;
	  return (pci/(1+IvaVestuario));	
	  }  
	  
//*************************************************************************************
//* Redefinição do operador ">>"
//**************************************************************************************
	friend istream& operator>> (istream& is, Vestuario& liv)
	    {
	  	char letra='\0';
			
	    { 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra < MaxNome; cLetra++) 
		                            texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setTipo(liv.desencripta(string(texto),DESLOCAMENTO)); 
	    }
		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setCategoria(liv.desencripta(string(texto),DESLOCAMENTO));
		}
	
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setCor(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setMateriaPrima(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
	    
	    { 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		liv.setTamanho(liv.desencripta(string(texto),DESLOCAMENTO));
	    }
	   
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++) texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setPreco(atof(texto));
		}                   
		 
						
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setNumUnidades(atoi(texto));
		}										 	
	     
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setIndiceQuebra(atoi(texto));
		}	                 
						  
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setNumSecao(atoi(texto));
		}					  
						  		
		{ 
		const int MaxNome = 40; char texto[MaxNome];
		for(int cLetra= 0; cLetra<MaxNome;cLetra++)
		                                     texto[cLetra]= '\0';
		is.getline(texto, MaxNome, '\n');
		strcpy(texto,liv.desencriptaII(texto,DESLOCAMENTO) );
	    liv.setLetraPrateleira(atoi(texto));
		}	  
		
	    is.ignore(); 	
	    return is;
}


//*************************************************************************************
//* Redefinição do operador "<<"
//**************************************************************************************
	friend ostream& operator<< (ostream& os, Vestuario& liv)
		{
		
			os << liv.encripta(liv.getTipo(),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(liv.getCategoria(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getCor(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getMateriaPrima(),DESLOCAMENTO)<<endl;
			os << liv.encripta(liv.getTamanho(),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(to_string(liv.getPreco()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getNumUnidades()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getIndiceQuebra()),DESLOCAMENTO)<<endl;
			os << liv.encripta(to_string(liv.getNumSecao()),DESLOCAMENTO)<<endl;  	
			os << liv.encripta(to_string(liv.getLetraPrateleira()),DESLOCAMENTO)<<endl;
			os << endl;	  	
    return os;
	}     
}; // Fim da classe
