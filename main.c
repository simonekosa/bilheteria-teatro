#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Structs
typedef struct
{
	char* nome;
	int lugares[5][4];
	float valor;
	float valorVendido;
	int totalIngressos;
} espetaculo;

typedef struct
{
	float valorTotal;
} caixa;

// Informações estáticas
espetaculo espetaculo1;
espetaculo espetaculo2;
espetaculo espetaculo3;

caixa fluxoCaixa;

int main(int argc, char *argv[])
{
	espetaculo1.nome = "A Dama e o vagabundo (19:00)";
	espetaculo1.valor = 20;
	
	espetaculo2.nome = "Minha Mae e uma Peca (20:00)";
	espetaculo2.valor = 20;
	
	espetaculo3.nome = "O Fantasma da Opera  (21:00)";
	espetaculo3.valor = 20;
	
	fluxoCaixa.valorTotal = 0;

	limparLugares();
	
	mostraCabecalho();
	mostraMenu();
	
	system("pause");
	return 0;
}

int limparLugares() 
{
	int i, j;
	
	for (i = 0; i < 5; i++)
	  	for (j = 0; j < 4; j++)
	  	{
	    	espetaculo1.lugares[i][j] = 0;
	    	espetaculo2.lugares[i][j] = 0;
	    	espetaculo3.lugares[i][j] = 0;
	    }
}

float selecionaValorEspetaculo(int numeroEspetaculo) 
{
	if (numeroEspetaculo == 1) {
		return espetaculo1.valor;
	} else if (numeroEspetaculo == 2) {
		return espetaculo2.valor;
	} else if (numeroEspetaculo == 3) {
		return espetaculo3.valor;
	} else {
		return espetaculo1.valor;
	}
}

void editarEspetaculo(int numeroEspetaculo, float valor, float ingressos) {
	
	if (numeroEspetaculo == 1) {
		espetaculo1.valorVendido = espetaculo1.valorVendido + valor;
		espetaculo1.totalIngressos = espetaculo1.totalIngressos + ingressos;
	} else if (numeroEspetaculo == 2) {
		espetaculo2.valorVendido = espetaculo2.valorVendido + valor;
		espetaculo2.totalIngressos = espetaculo2.totalIngressos + ingressos;
	} else if (numeroEspetaculo == 3) {
		espetaculo3.valorVendido = espetaculo3.valorVendido + valor;
		espetaculo3.totalIngressos = espetaculo3.totalIngressos + ingressos;
	} else {
		espetaculo1.valorVendido = espetaculo1.valorVendido + valor;
		espetaculo1.totalIngressos = espetaculo1.totalIngressos + ingressos;
	}
	
}

// Mostra na tela do cabeçalho do sistema
int mostraCabecalho()
{
	printf("###############################");
	printf("\n");
	printf("     BILHETERIA DO TEATRO      ");
	printf("\n");
	printf("###############################");
	printf("\n");
	
	return 0;
}

// Mostra os espetáculos
int mostraEspetaculos()
{
	int numeroEspetaculo = 0;
	
	printf("---------------------------------------");
	printf("\n");
	printf(" 1 - A Dama e o vagabundo (19:00)");
	printf("\n");
	printf(" 2 - Minha Mae e uma Peca (20:00)");
	printf("\n");
	printf(" 3 - O Fantasma da Opera  (21:00)");
	printf("\n");
	printf("---------------------------------------");
	printf("\n");
	printf("Digite o numero do espetaculo desejado: ");
	printf("\n");
	
	scanf("%d", &numeroEspetaculo);
	
	return numeroEspetaculo;
}

float mostraFormulario(float valor)
{
	int idade;
	char professor[1000];
	char criancaCarente[1000];
	
	printf("---------------------------------------");
	printf("\n");
	
	printf("Digite sua idade: ");
	printf("\n");
	
	scanf("%d", &idade);
	
	printf("Professor da rede publica (sim/nao): ");
	printf("\n");
	
	scanf("%s", professor);
	
	printf("Crianca carente (sim/nao): ");
	printf("\n");
	
	scanf("%s", criancaCarente);
	
	printf("---------------------------------------");
	printf("\n");
	
	if ((idade >= 2 && idade <= 12) || idade >= 60)
	{
		// Pagar meia
		return valor / 2;
	}
	else if ((strcmp(professor, "sim") == 0) || (strcmp(professor, "s") == 0))
	{
		// Pagar meia
		return valor / 2;
	}
	else if ((strcmp(criancaCarente, "sim") == 0) || (strcmp(criancaCarente, "s") == 0))
	{
		//ponteiro para struct que armazena data e hora  
		struct tm *data_hora_atual;    
		
		//variável do tipo time_t para armazenar o tempo em segundos  
		time_t segundos;
		
		//obtendo o tempo em segundos  
		time(&segundos);  
		
		//para converter de segundos para o tempo local  
		//utilizamos a função localtime  
		data_hora_atual = localtime(&segundos);
		
		// A propriedade tm_wday retorna o dia da semana de 0 (domingo) até 6 (sábado) - Verifica se é terça-feira
		if (data_hora_atual->tm_wday == 2)
		{
			// Pagar meia
			return valor / 2;
		}
		else
		{
			// Pagar inteira
			return valor;
		}
	}
	else
	{
		// Pagar inteira
		return valor;
	}
}

int * selecionarLugar(int numeroEspetaculo)
{
	int i, j, valido;

	valido = 0;
	
	static int lugarSelecionado[2];	

	while (valido == 0)
	{

		printf("###############################");
		printf("\n");
		printf("LUGARES");
		printf("\n");
		printf("###############################");
		printf("\n");
	
		printf("      ");
		for (j = 0; j < 5; j++)
	    {
	    	printf(" ");
	    	printf("%d", j);
	    	printf("  ");
	    }	
	    printf("\n");
	    j = 0;
	
	  	for (i = 0; i < 5; i++) {
	  		printf(" ");
	  		printf("%d", i);
	  		printf(" ");
	  		printf(" | ");
		    for (j = 0; j < 4; j++)
		    {
		    	if (numeroEspetaculo == 1) 
				{
		    		printf("%d", espetaculo1.lugares[i][j]);	
				}
				
				if (numeroEspetaculo == 2) 
				{
		    		printf("%d", espetaculo2.lugares[i][j]);	
				}
				
				if (numeroEspetaculo == 3) 
				{
		    		printf("%d", espetaculo3.lugares[i][j]);	
				}
		    	
		    	printf(" | ");
		    }
		    printf("\n");
		}
		
		int fileira, coluna;
		
		printf("\n");
		printf("Legenda: 0 - Livre, 1 - Ocupado");
		printf("\n");
		printf("###############################");
		printf("\n");
		printf("Digite a fileira: ");
		printf("\n");
		scanf("%d", &fileira);
		printf("\n");
		printf("Digite a coluna: ");
		printf("\n");
		scanf("%d", &coluna);
		printf("\n");
		
		lugarSelecionado[0] = fileira;
		lugarSelecionado[1] = coluna;
		
		if (numeroEspetaculo == 1) 
		{
			if (espetaculo1.lugares[fileira][coluna] == 1) 
			{
				printf("Esse lugar esta ocupado, escolha um lugar livre!");
				printf("\n\n");
				
				valido = 0;
			}
			else
			{
				valido = 1;
			}	
		}
		
		if (numeroEspetaculo == 2) 
		{
    		if (espetaculo2.lugares[fileira][coluna] == 1) 
			{
				printf("Esse lugar esta ocupado, escolha um lugar livre!");
				printf("\n\n");
				
				valido = 0;
			}
			else
			{
				valido = 1;
			}		
		}
		
		if (numeroEspetaculo == 3) 
		{
    		if (espetaculo3.lugares[fileira][coluna] == 1) 
			{
				printf("Esse lugar esta ocupado, escolha um lugar livre!");
				printf("\n\n");
				
				valido = 0;
			}
			else
			{
				valido = 1;
			}		
		}
		
	}
	
	return lugarSelecionado;
}

int modificaLugar(int numeroEspetaculo, int fileira, int coluna) 
{
	if (numeroEspetaculo == 1) 
	{
		espetaculo1.lugares[fileira][coluna] = 1;	
	}
	
	if (numeroEspetaculo == 2) 
	{
		espetaculo2.lugares[fileira][coluna] = 1;	
	}
	
	if (numeroEspetaculo == 3) 
	{
		espetaculo3.lugares[fileira][coluna] = 1;	
	}
	
	return 0;
}

int removerLugaresSelecionados(int numeroEspetaculo, int quantidade, int lugaresSelecionados[1000][2]) 
{
	if (numeroEspetaculo == 1) 
	{
		int i = 0;
		for (i = 0; i < quantidade; i++)
		{
			int fileira = lugaresSelecionados[i][0];
			int coluna = lugaresSelecionados[i][1];
			espetaculo1.lugares[fileira][coluna] = 0;		
		}
	}
	
	if (numeroEspetaculo == 2) 
	{
		int i = 0;
		for (i = 0; i < quantidade; i++)
		{
			int fileira = lugaresSelecionados[i][0];
			int coluna = lugaresSelecionados[i][1];
			espetaculo2.lugares[fileira][coluna] = 0;		
		}	
	}
	
	if (numeroEspetaculo == 3) 
	{
		int i = 0;
		for (i = 0; i < quantidade; i++)
		{
			int fileira = lugaresSelecionados[i][0];
			int coluna = lugaresSelecionados[i][1];
			espetaculo3.lugares[fileira][coluna] = 0;	
		}	
	}
	
	return 0;
}

// Mostra na tela o menu do sistema
int mostraMenu()
{
	int opcao = 1;

	while (opcao != 3)
	{
		printf("\n");
		printf("\n");
		printf("####### MENU #######");
		printf("\n");
		printf("1 - Espetaculos");
		printf("\n");
		printf("2 - Caixa");
		printf("\n");
		printf("3 - Sair");
		printf("\n");
		printf("####################");
		printf("\n");
		printf("Digite uma opcao: ");
		printf("\n");
		
		scanf("%d", &opcao);

		if (opcao == 1) 
		{
			int quantidadeDeIngressos;
			float valorTotalDosIngressos = 0;
			
			printf("Digite a quantidade de ingressos: ");
			printf("\n");

			scanf("%d", &quantidadeDeIngressos);
 
  			int numeroEspetaculo = mostraEspetaculos();
       
			int lugaresSelecionados[1000][2];
			memset(lugaresSelecionados, 0, sizeof(lugaresSelecionados));
			int i = 0;
		    for (i = 0; i < quantidadeDeIngressos; i++)
			{
			   	int* lugarSelecionado = selecionarLugar(numeroEspetaculo);
			   
			   	lugaresSelecionados[i][0] = lugarSelecionado[0];
			   	lugaresSelecionados[i][1] = lugarSelecionado[1];
			   
			   	modificaLugar(numeroEspetaculo, lugarSelecionado[0], lugarSelecionado[1]);
			   
			    valorTotalDosIngressos = valorTotalDosIngressos + mostraFormulario(selecionaValorEspetaculo(numeroEspetaculo));
			}

			//Imprimir ticket de compra
			printf("############# TICKET #################");
			printf("\n");
			printf("Total Ingressos: %d", quantidadeDeIngressos);
			printf("\n");
			printf("Valor total: %f", valorTotalDosIngressos);
			printf("\n\n");
			
			//Finalizar compra
			char comprarIngressos[1000];
			
			printf("Comprar ingressos (sim/nao): ");
			printf("\n");
			
			scanf("%s", comprarIngressos);

			if ((strcmp(comprarIngressos, "sim") == 0) || (strcmp(comprarIngressos, "s") == 0))
			{
				fluxoCaixa.valorTotal = fluxoCaixa.valorTotal + valorTotalDosIngressos;
				editarEspetaculo(numeroEspetaculo, valorTotalDosIngressos, quantidadeDeIngressos);
			}
			else
			{
				removerLugaresSelecionados(numeroEspetaculo, quantidadeDeIngressos, lugaresSelecionados);
			}
		}
		
		if (opcao == 2) 
		{
			mostraFluxoCaixa();
		}
	}
	
	return 0;
}

int mostraFluxoCaixa()
{
	//ponteiro para struct que armazena data e hora  
	struct tm *data_hora_atual2;    
	
	//variável do tipo time_t para armazenar o tempo em segundos  
	time_t segundos2;
	
	//obtendo o tempo em segundos  
	time(&segundos2);  
	
	//para converter de segundos para o tempo local  
	//utilizamos a função localtime  
	data_hora_atual2 = localtime(&segundos2);
	
	printf("----------------------------------------------------------------------");
	printf("\n");
	printf(" FLUXO DE CAIXA");
	printf("\n");
	printf("----------------------------------------------------------------------");
	printf("\n");
	printf(espetaculo1.nome);
	printf(" venderam ");
	printf("%d", espetaculo1.totalIngressos);
	printf(" ingressos - Total: R$ ");
	printf("%.2f", espetaculo1.valorVendido);
	printf("\n");
	printf(espetaculo2.nome);
	printf(" venderam ");
	printf("%d", espetaculo2.totalIngressos);
	printf(" ingressos - Total: R$ ");
	printf("%.2f", espetaculo2.valorVendido);
	printf("\n");
	printf(espetaculo3.nome);
	printf(" venderam ");
	printf("%d", espetaculo3.totalIngressos);
	printf(" ingressos - Total: R$ ");
	printf("%.2f", espetaculo3.valorVendido);
	printf("\n");
	printf("\n");
	printf("Total vendido no dia ");
	
	// Dia
	printf("%d", data_hora_atual2->tm_mday);  
	// Mês
	printf("/%d", data_hora_atual2->tm_mon+1);
	// Ano
	printf("/%d", data_hora_atual2->tm_year+1900);
	 
	printf(": R$ ");
	printf("%.2f", fluxoCaixa.valorTotal);
	printf("\n");
	printf("----------------------------------------------------------------------");
	
	return 0;
}
