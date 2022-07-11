#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct {
	int codigo;
	char nome[50];
	char cpf[30];
	char vacina[30];
	char data[30];
	char numeroLote[30];
}Vacinacao;

Vacinacao cadastrarVacinacao(int index) {
	printf("--- CADASTRO DE VACINAÇÕES --- \n");
	
	Vacinacao info;
	int i;

	printf("\n Qual o nome da pessoa %d: ", index + 1);
	gets(info.nome);
	fflush(stdin);
	
	printf("\n Qual o CPF da pessoa %d: ", index + 1);
	gets(info.cpf);
	fflush(stdin);
	
	printf("\n Qual o Nome da Vacina: ");
	gets(info.vacina);
	fflush(stdin);
	
	printf("\n Qual o Número de lote da Vacina: ");
	gets(info.numeroLote);
	fflush(stdin);
	
	printf("\n Qual a Data de Aplicação da Vacina: ");
	gets(info.data);
	fflush(stdin);
	
	system("cls");
	return info;
	
}

void listarVacinacoes(Vacinacao v) {
	printf("CÓDIGO: %d\n", v.codigo);
	printf("NOME: %s\n", v.nome);
	printf("CPF: %s\n", v.cpf);
	printf("VACINA: %s\n", v.vacina);
	printf("LOTE: %s\n", v.numeroLote);
	printf("DATA DE APLICAÇÃO: %s\n", v.data);
	printf("============================== \n\n");
}

void consultarPorCpf(Vacinacao v) {
	printf("CÓDIGO: %d\n", v.codigo);
	printf("NOME: %s\n", v.nome);
	printf("CPF: %s\n", v.cpf);
	printf("VACINA: %s\n", v.vacina);
	printf("LOTE: %s\n", v.numeroLote);
	printf("DATA DE APLICAÇÃO: %s\n", v.data);
	printf("============================== \n\n");
}

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");

	int qntd = 0;
	int i;	
	int igual;
	
	printf("Bem vindo ao Sistema de Cadastro de Aplicação de Vacinas! \n\n");
	system("pause");
	system("cls");
	
	Vacinacao infos[99];
	
	int option = 0;
	while(option != 4) {
		system("cls"); 
		printf("Controle de Vacinação: \n 1- Cadastrar Vacinas \n 2- Listar Aplicações \n 3- Consultar por CPF \n 4- Sair \n\n");
		scanf("%d", &option);
		fflush(stdin);
		system("cls");

		switch(option) {
			case 1: {
				printf("Quantas Pessoas Realizarão o Cadastro? \n");
				scanf("%d", &qntd);
				fflush(stdin);
				system("cls");
				
				
				for(i = 0; i < qntd; i++) {
					infos[i] = cadastrarVacinacao(i);
					infos[i].codigo = i + 1;
				}	
				
				printf("Cadastrado com sucesso! \n");		
				system("pause");
				break;
			}
			
			case 2: {
				system("cls");
				printf("--- LISTAGEM DE APLICAÇÕES --- \n");
				
				
				for(i = 0; i < qntd; i++) {
					listarVacinacoes(infos[i]);
				}
				
				system("pause");
				break;
			}
			
			case 3: {
				char cpf[14];
				
				printf("Digite o CPF: ");
				gets(cpf);
				fflush(stdin);
				
				for(i = 0; i < qntd; i++) {
					igual = strcmp(cpf, infos[i].cpf);
					
					if(igual == 0) {
						consultarPorCpf(infos[i]);
					} 
				}
				
				system("pause");
				break;
			}
			
			case 4: {
				printf("Saindo do Programa... \n");
				break;
			}
			
			default: {
				printf("Opção Inválida \n");
				break;
			}
		}

	}
	
	return 0;
}
