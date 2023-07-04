#include <stdio.h>  //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aLoca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aLoca��o de texto por regi�o
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() // Fun��o respons�vel por registrar os usu�rios no sistema
{
	// In�cio de cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final de cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // Scaniando a string CPF
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da vari�vel
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o CPF e o nome cadastrado
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s",nome); // Scaniando a string nome
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,nome); // Salva o valor da vari�vel nome
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o nome e o sobrenome do usu�rio
	fclose(file); // Fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s",sobrenome); // Scaniando a string sobrenome
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,sobrenome); // Salva o valor da vari�vel sobrenome
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o sobrenome e o cargo
	fclose(file); // Fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: "); // Coletando informa��o do usu�rio
	scanf("%s",cargo); // Scaniando a string cargo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,cargo); // Salva o valor da vari�vel cargo
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema
	
}

int consulta() // Fun��o respons�vel por consultar os usu�rios cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	// In�cio da cria��o das vari�ves
	char cpf[40];
	char conteudo[200];
	// Fim da cria��o de vari�veis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // scaniando a string CPF
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" lendo o arquivo
	
	if(file == NULL) // An�lise de usu�rio inexistente 
	{
		printf("Arquivo n�o existente ou n�o localizado!\n\n");
	}
		
	while(fgets(conteudo, 100, file) !=NULL) // Busca o conte�do do arquivo
	{
		printf("Essas s�o as informa��es deste usu�rio: ");
		printf("%s", conteudo); // Escreve o conte�do do arquivo
		printf("\n\n");
	}
	
	system("pause"); // Pausa o sistema
}
	
int deletar() // Fun��o respons�vel por deletar usu�rios
{
	//In�cio da cria��o de vari�veis
	char cpf[40];
	//Fim da cria��o de vari�veis
	printf("Digite o CPF do usu�rio a ser DELETADO: "); // Coletando informa��o do usu�rio
	scanf("%s", cpf); // Scaneando a string CPF
	
	remove(cpf); // Remove o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" lendo o arquivo
	
	if(file == NULL) // An�lise de usu�rio inexistente 
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
	}
	
	system("pause"); // Pausa o sistema
}
	
	
	
int main() // Menu principal 
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // respons�vel por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("###  Cart�rio da EBAC ###\n\n"); //In�cio do menu
		printf("Escolha a op��o desejado do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Op��o: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
		system("cls");
	
		switch(opcao) //In�cio da sele��o do menu
		{
			case 1:
			registro(); // chamada da fun��o registro
			break;
			
			case 2:
			consulta(); // chamada de fun��o consulta
			break;
			
			case 3:
			deletar();  // chamada de fun��o deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel\n");
			system("pause");
			break;				
		} //Fim da sele��o
			
	}
}
