#include <stdio.h>  //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de aLocação de espaço de memória
#include <locale.h> //biblioteca de aLocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registro() // Função responsável por registrar os usuários no sistema
{
	// Início de criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final de criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s", cpf); // Scaniando a string CPF
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // Cria o arquivo
	file = fopen(arquivo, "w"); // Cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // Salva o valor da variável
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o CPF e o nome cadastrado
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s",nome); // Scaniando a string nome
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,nome); // Salva o valor da variável nome
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o nome e o sobrenome do usuário
	fclose(file); // Fecha o arquivo
		
	printf("Digite o sobrenome a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s",sobrenome); // Scaniando a string sobrenome
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,sobrenome); // Salva o valor da variável sobrenome
	fclose(file); // Fecha o arquivo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,","); // Insere uma "," entre o sobrenome e o cargo
	fclose(file); // Fecha o arquivo
		
	printf("Digite o cargo a ser cadastrado: "); // Coletando informação do usuário
	scanf("%s",cargo); // Scaniando a string cargo
	
	file = fopen(arquivo, "a"); // "a" atualiza o arquivo
	fprintf(file,cargo); // Salva o valor da variável cargo
	fclose(file); // Fecha o arquivo
	
	system("pause"); // Pausa o sistema
	
}

int consulta() // Função responsável por consultar os usuários cadastrados no sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	// Início da criação das variáves
	char cpf[40];
	char conteudo[200];
	// Fim da criação de variáveis
	
	printf("Digite o CPF a ser consultado: "); // Coletando informação do usuário
	scanf("%s", cpf); // scaniando a string CPF
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" lendo o arquivo
	
	if(file == NULL) // Análise de usuário inexistente 
	{
		printf("Arquivo não existente ou não localizado!\n\n");
	}
		
	while(fgets(conteudo, 100, file) !=NULL) // Busca o conteúdo do arquivo
	{
		printf("Essas são as informações deste usuário: ");
		printf("%s", conteudo); // Escreve o conteúdo do arquivo
		printf("\n\n");
	}
	
	system("pause"); // Pausa o sistema
}
	
int deletar() // Função responsável por deletar usuários
{
	//Início da criação de variáveis
	char cpf[40];
	//Fim da criação de variáveis
	printf("Digite o CPF do usuário a ser DELETADO: "); // Coletando informação do usuário
	scanf("%s", cpf); // Scaneando a string CPF
	
	remove(cpf); // Remove o arquivo
	
	FILE *file;
	file = fopen(cpf,"r"); // "r" lendo o arquivo
	
	if(file == NULL) // Análise de usuário inexistente 
	{
		printf("O usuário não se encontra no sistema!.\n");
	}
	
	system("pause"); // Pausa o sistema
}
	
	
	
int main() // Menu principal 
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls"); // responsável por limpar a tela

		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("###  Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha a opção desejado do menu: \n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); //Fim do menu
	
		scanf("%d", &opcao); //armazenando a escolha do usuário
	
		system("cls");
	
		switch(opcao) //Início da seleção do menu
		{
			case 1:
			registro(); // chamada da função registro
			break;
			
			case 2:
			consulta(); // chamada de função consulta
			break;
			
			case 3:
			deletar();  // chamada de função deletar
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível\n");
			system("pause");
			break;				
		} //Fim da seleção
			
	}
}
