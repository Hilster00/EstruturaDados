#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//estrutura de dados 
typedef struct dados{
	int dados,id;
}Dados;

//estrutura de isercao de dados em um no
void inserirDados(Dados* vetor[500],int valor,int casa){
    vetor[casa]->dados=valor;
    vetor[casa]->id=casa;
}

//inserir dados no vetor 
void inserir(Dados* vetor[500],int valor,int casa){
    
    //verifica se e a primeira casa do vetor
    if(casa>0){
        //verifica se o valor é menor que o da casa anterior
        if(vetor[casa-1]->dados <= valor){
            inserirDados(vetor,valor,casa);
        }else{
            //passa o valor da casa anterior para a seguinte
            inserirDados(vetor,vetor[casa-1]->dados,casa);
            //chama a propria funcao para tentar inserir o valor na casa anterior
            inserir(vetor,valor,(casa-1));
        }
    }else{
        //insere o valor no nó da primeira casa
        inserirDados(vetor,valor,casa);
    }
}


//printa os dados de um no
void printar(Dados* vetor[500],int casa){
    printf("\nDados: %i",vetor[casa]->dados);
    printf("\nID: %i",vetor[casa]->id);
}

//busacar valor
void buscar(Dados* vetor[500]){
    int valor,validacao=0;
    printf("\nDigite o valor de busca:");scanf("%i",&valor);
    int i;
    for(i=0;i<500;i++){
        if(valor==vetor[i]->dados){
            validacao=1;
            printar(vetor,i);
        }
    }
    if(validacao==0){
        printf("\nO valor nao foi encontrado");
    }
}
//funcao principal
void main()
{
    //criacao de vetor e ponteiro de uma estrutura
    Dados vetor[500],*ponteiro[500];
    int i;
    
    //atribuir a cada item do ponteiro um item do vetor
    for(i=0;i<500;i++){
    	ponteiro[i]=&vetor[i];
	}
	
	//preencimento do vetor de forma randomica
	for(i=0;i<500;i++){
	    inserir(ponteiro,(rand() %500),i);
	}
	
	//programa principal
	int opcao=0,inicio,fim;
	while(opcao!=4){
	    
	    //menu interativo
	    printf("\n(1)Buscar no");
	    printf("\n(2)Buscar valor");
	    printf("\n(3)Printar intervalo");
	    printf("\n(4)Sair");
	    printf("\nDigite a opcao desejada:");scanf("%i",&opcao);
	    
	    //mensagem para quando usuario escolhe uma opcao nao cadastrada
	    if(opcao<1 || opcao >4){
	        printf("\nOpcao %i nao esta cadastrada",opcao);
	    }
	    //escolha de caso das opcoes
	    switch(opcao){
	        
	        //buscar no pelo ID
	        case 1:
	             //receber o parametro de busca
	             printf("\nDigite o ID do no:");scanf("%i",&opcao);
	             //verifica se o valor e valido
	             if(opcao<0 || opcao >499){
	                 printf("\nOpcao invalida");
	             }else{
	                 //printa o no pelo parametro indicado
	                 printar(ponteiro,opcao);
	             }
	             
	             //zera a variavel opcao para nao sair do programa caso digite 4
	             opcao=0;
	             break;
	             
	       //busca de ponteiro
	       case 2:
	            //chama funcao de buscar ponteiro
	            buscar(ponteiro);
	            break;
	       
	       //printar intervalo
	       case 3:
	       
	            //recebe o inicio do intervalo de busca
	            printf("\nDigite o comeco do intervalo:");scanf("%i",&inicio);
	            //verifica se e um valor valido
	            if(inicio<0 || inicio >499){
	                printf("\nValor invalido");
	                break;
	            }
	            
	            //recebe o fim do intervalo de busca
	            printf("\nDigite o fim do intervalo:");scanf("%i",&fim);
	            //verifica se e um valor valido
	            if(fim<0 || fim >499){
	                printf("\nValor invalido");
	                break;
	            }
	            
	            //printa o intervalo
	            if(inicio<=fim){
	                //em ordem se o inicio for menor que o fim
	                for(i=inicio;i<=fim;i++){
	                    printar(ponteiro,i);
	                }
	            }else{
	                //em ordem regressiva se o fim for menor que o inicio
	                for(i=inicio;i>=fim;i--){
	                    printar(ponteiro,i);
	                }
	            }
	            
	            break;
	    }
	}
    
    
}
