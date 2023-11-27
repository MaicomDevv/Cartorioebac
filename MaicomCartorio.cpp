#include <stdio.h> //biblioteca de comunicacao com o usuario 
#include <stdlib.h> //biblioteca de alocacao de espaco em memoria
#include <locale.h> //biblioteca de alocacoes de texto por regiao 
#include <string.h> // biblioteca responsavel por cuidar das string

int registrar() // funcao responsavel por cadastrar os usuarios no sistema 
{
	//inicio criacao de variaveis/string
	setlocale(LC_ALL, "portuguese");
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim criacao de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informacao do usuario 
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);	
	
    system("pause");
}

int consultar()
{
	setlocale (LC_ALL, "portuguese");
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("CPF invalido \n");
	}
	
	while(fgets (conteudo, 200, file) != NULL)
	{
		printf("\n resultado: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
	
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf ("%S", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("usuario nao se encontra no sistema. \n");
		system("pause");
	}
}
	
		
int main()
{
	int opcao=0; //Definindo variaveis 
 	int laco=1;
 	
 	for (laco=1;laco=1;)
 	{
 	
	 	system("cls");
	
 	
		setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
		printf("--- Cart�rio da EBAC ---\n\n");//inicio do menu
		printf("escolha a op��o no menu\n\n"); 
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Sair do sistema\n\n");
		printf("opc�o: "); // fim do menu
		
	
		scanf("%d", &opcao); //armazenanto a escolha do usuario  
	
		system("cls");//limpar a tela
		
		switch(opcao) //inicio da selecao
		{
			case 1:
			registrar(); //chamada de funcoes 
			break;
			
			case 2:
			consultar();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema\n ");
			return 0;
			break;
			
			default:
			printf("\nop��o indisponel\n\n");
			system("pause");
			break; // fim da selecao 
		} 
	}
}
