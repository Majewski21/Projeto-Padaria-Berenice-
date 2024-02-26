#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Vari�veis Globais
int estoque[5]= {0};
float valores[] = {7.5,8.69,5,4.5,3.35};
int vendas[5] = {0};
int qnt_item[5] = {0};
int contador[] = {0};
float valor_total;
char nome_produto[5][20] = {"Pao de Forma","Pao de Centeio","Broa de Milho","Sonho","Tubaina"};

//Fun��es de cada parte
int nomecodigo(int nomecodigo);
void cadastroestoque (int cadastro);
void visualizarestoque (int visualizar);
void venda (int venda);
void pagamento(int pagamento);
void fcupomFiscal(int cupom);
void relatorio (int relatorio);


int main()
{
    int menu=0;
    int escolha,visualizar;

    while(menu == 0)     //While loop para ficar retornando ao menu
    {

        printf("\n________________________________________________");
        printf("\n|              PADARIA DA BERENICE             |");
        printf("\n|        1.     Cadastrar Estoque              |");
        printf("\n|        2.     Visualizar Estoque             |");
        printf("\n|        3.     Realizar Venda                 |");
        printf("\n|        4.          Sair                      |");
        printf("\n|______________________________________________|");

        printf("\n\n Digite a operacao que deseja realizar: ");
        scanf("%d", &escolha);
        if(escolha > 4 || escolha <= 0)  // Verifica��o
        {
            printf("Digite um numero Correspondente!");
            menu = 0;
        }
        else
        {
            menu = 2;
        }

        switch(escolha) //Menus de Cada Op��o
        {
        case 1:    // Cadastro de Estoque
            cadastroestoque(nomecodigo);
            menu = 0;
            break;
        case 2:    //Visualiza��o de Estoque
            visualizarestoque(visualizar);
            menu = 0;
            break;
        case 3:
            venda(venda);  // Venda
            break;
        case 4:
            relatorio(relatorio);
            return 0;
        }
    }
}

int nomecodigo(int nomecodigo)
{
    switch(nomecodigo)
    {
    case 1:
        printf("\nPao de Forma");
        break;
    case 2:
        printf("\nPao de Centeio");
        break;
    case 3:
        printf("\nBroa de Milho");
        break;
    case 4:
        printf("\nSonho");
        break;
    case 5:
        printf("\nTubaina");
        break;
    }
}

void cadastroestoque (int cadastro)
{
    int codigo = 0;
    int escolhaestoque, quantidade;
    while(codigo == 0)
    {
        printf("\n_______________________________________________________");
        printf("\n Codigo do Item |       Item        |   Quantidade   ");
        printf("\n-----------------------------------------------------");
        printf("\n       1        |   Pao de Forma    |       %d       ", estoque[0]);
        printf("\n       2        |   Pao de Centeio  |       %d       ", estoque[1]);
        printf("\n       3        |   Broa de Milho   |       %d       ", estoque[2]);
        printf("\n       4        |   Sonho           |       %d       ", estoque[3]);
        printf("\n       5        |   Tubaina         |       %d       ", estoque[4]);
        printf("\n_______________________________________________________");
        printf("\n\nDigite 0 para retornar ao menu.");
        printf("\n\nDigite o Codigo do Item que deseja alterar o estoque: ");
        scanf("%d", &escolhaestoque);
        getchar();
        if(escolhaestoque <= 5 && escolhaestoque >= 1)
        {

            printf("\n\nInsira a nova quantidade: ");
            scanf("%d", &quantidade);
            getchar();
            if(quantidade >= 0 )
            {
                estoque[escolhaestoque-1] = quantidade;
                printf("\n\nSeu novo estoque para este produto e: %d", quantidade);
                codigo = 0;
            }
            else
            {
                printf("\n\nQuantidade Invalida, a mesma deve ser maior ou igual a zero");
                codigo = 0;
            }
        }
        else if(escolhaestoque == 0)
        {
            printf("\n\nRetornando ao menu inicial.....");
            codigo = 1;
        }
        else
        {
            printf("\n\nCodigo Invalido!");
            codigo = 0;

        }
    }
}

void visualizarestoque(int visualizar)
{
    int confirma;
    int resultado;
    do
    {
        printf("\n________________________________________________________");
        printf("\n| Codigo |  Nome do Item   |    Preco      |   Estoque  ");
        printf("\n|________|_________________|_______________|____________");
        printf("\n|    1   |  Pao de Forma   |   R$ %.2f     |     %d      ",valores[0],estoque[0]);
        printf("\n|    2   |  Pao de Centeio |   R$ %.2f     |     %d      ",valores[1],estoque[1]);
        printf("\n|    3   |  Broa de Milho  |   R$ %.2f     |     %d      ",valores[2],estoque[2]);
        printf("\n|    4   |  Sonho          |   R$ %.2f     |     %d      ",valores[3],estoque[3]);
        printf("\n|    5   |  Tubaina        |   R$ %.2f     |     %d      ",valores[4],estoque[4]);
        printf("\n|________|_________________|_______________|____________");
        printf("\n\nEste eh o seu estoque no momento, deseja retornar ao menu:");
        printf("\n 1. Sim");
        printf("\n 2. Nao\n");
        scanf("%d",&confirma);
        getchar();
        if(confirma == 1)
        {
            resultado = 0;
        }
        else if(confirma == 2)
        {
            resultado = 2;
        }
    }
    while(resultado != 0);
}

void venda(int venda)
{
    int armazenar_item;
    int armazenar_quantidade;
    int pergunta;
    int confirma;
    float soma_valores[] = {};
    int comparacao = 1;
    float forma;
    int resto;
    float centeio;
    float broa;
    float sonho;
    float tubaina;
    int cod_item;
    int item;
    int visualizar;
    int opcao_pagamento;
    int parcelas = 0;
    float valor_recebido;
    float troco;
    float valor_parcela;

    while(item == 0)
    {

        printf("\n\n____________________________________________________________");
        printf("\n| Codigo  |  Nome do Item  | Valor por Unidade |  Estoque   ");
        printf("\n|-----------------------------------------------------------");
        printf("\n|    1    |  Pao de Forma  |       R$ %.2f     |     %d     ",valores[0],estoque[0]);
        printf("\n|    2    | Pao de Centeio |       R$ %.2f     |     %d     ",valores[1],estoque[1]);
        printf("\n|    3    | Broa de Milho  |       R$ %.2f     |     %d     ",valores[2],estoque[2]);
        printf("\n|    4    |     Sonho      |       R$ %.2f     |     %d     ",valores[3],estoque[3]);
        printf("\n|    5    |    Tubaina     |       R$ %.2f     |     %d     ",valores[4],estoque[4]);
        printf("\n|_________|________________|___________________|____________");
        printf("\n\n Digite o codigo do item que deseja comprar: ");
        scanf("%d", &cod_item);
        getchar();
        if(cod_item > 5 || cod_item < 0 )
        {
            printf("\n Selecione um item existente!");
            item = 0;

        }
        else if(estoque[cod_item-1] < comparacao)
        {
            printf("\n\n Item invalido (Item selecionado nao possui estoque)");
            item = 0;
        }
        else
        {
            nomecodigo(cod_item);
            item = 1;
            printf("\n\n Digite a quantidade que desejada comprar: ");
            scanf("%d",&qnt_item[cod_item-1]);
            getchar();
            if (qnt_item[cod_item-1] <= 0)
            {
                printf("\n Quantidade Invalida!");
                item = 0;
            }
            else if(qnt_item[cod_item-1] > estoque[cod_item-1])
            {
                printf("\n Quantidade invalida ou insuficiente");
                item = 0;
            }
            else
            {
                switch(cod_item)
                {
                case 1:
                    soma_valores[0] = qnt_item[0]*valores[0];
                    break;
                case 2:
                    soma_valores[1] = qnt_item[1]*valores[1];
                    break;
                case 3:
                    soma_valores[2] = qnt_item[2]*valores[2];
                    break;
                case 4:
                    soma_valores[3] = qnt_item[3]*valores[3];
                    break;
                case 5:
                    soma_valores[4] = qnt_item[4]*valores[4];
                    break;
                }
                for(int i=0; i<=5; i++)
                {
                    valor_total = valor_total + soma_valores[i];
                }
                // Contador n de itens:
                contador[cod_item-1]++;

                // Nome do produto:
                printf("\n\nItem registrado!, deseja continuar com a compra?");
                printf("\n1. Sim");
                printf("\n2. Nao\n");
                scanf("%d", &pergunta);
                getchar();
                //Calcula a subtra��o do estoque
                resto = estoque[cod_item-1] - qnt_item[cod_item-1];
                estoque[cod_item-1] = resto;
                //Salva
                vendas[cod_item-1] += qnt_item[cod_item-1];
                if(pergunta == 1)
                {
                    printf("\n\nRetornando ao menu...");
                    item = 0;
                }
                else
                {
                    fcupomFiscal(fcupomFiscal);
                    printf("\n O valor total eh: %.2f",valor_total);
                    printf("\n\n___________________");
                    printf("\n |Opcoes de Pagamento|");
                    printf("\n |___________________|");
                    printf("\n |     1.A vista     |");
                    printf("\n |     2.Parcelado   |");
                    printf("\n |___________________|");
                    printf("\n Selecione um opcao de pagamento:");
                    scanf("%d", &opcao_pagamento);
                    getchar();

                    if (opcao_pagamento <= 0 || opcao_pagamento >2)
                    {
                        printf("\n Opcao de pagamento invalida!");
                    }

                    // A VISTA

                    else if (opcao_pagamento == 1)
                    {
                        if (valor_total>= 1.00 && valor_total <= 50)
                        {
                            valor_total = valor_total - (valor_total * 5 / 100);
                        }
                        else if (valor_total >= 50 && valor_total <= 100)
                        {
                            valor_total = valor_total - (valor_total * 10 / 100);
                        }
                        else
                        {
                            valor_total = valor_total - (valor_total * 18 / 100);
                        }

                        getchar();
                        printf(" O Valor Total eh: R$%.2f \n", valor_total);
                        printf("\n Informe o valor recebido: ");
                        scanf("%f", &valor_recebido);
                        troco = valor_recebido - valor_total;
                        if (troco < 0)
                        {
                            printf("\n De mais dinheiro mao de vaca!!!!");
                        }
                        else
                        {
                            printf("\n O valor do troco eh: %.2f",troco);
                        }

                        // opcao 2 parcelado
                    }
                    else if (opcao_pagamento == 2)
                    {
                        printf("\n  Digite o numero de parcelas: ");
                        scanf("%d", &parcelas);
                        if (parcelas <= 0)
                        {
                            printf("\n Parcelamento invalido!");
                        }

                        else if (parcelas >= 1 && parcelas <= 3)
                        {
                            valor_total = valor_total + (valor_total * 5/100);
                        }
                        else
                        {
                            valor_total = valor_total + (valor_total * 8/100);
                        }
                        printf("\n O valor total da compra parcelada eh: %.2f", valor_total);
                        valor_parcela = valor_total / parcelas;
                        printf("\n Valor por parcela: %.2f ",valor_parcela);
                    }
                    else
                    {
                        printf("\n Forma de pagamento invalida!!");
                    }
                }
            }
        }
    }
}

void cupom_fiscal(int cupom)
{
    printf("\n\n____________________RECIBO DA COMPRA______________________");
    printf("\n|   Item  |  Nome do Item  | Valor por Unidade |  Estoque   ");
    printf("\n|-----------------------------------------------------------");
    printf("\n|    1    |  Pao de Forma  |       R$ %.2f     |     %d     ",valores[0],estoque[0]);
    printf("\n|    2    | Pao de Centeio |       R$ %.2f     |     %d     ",valores[1],estoque[1]);
    printf("\n|    3    | Broa de Milho  |       R$ %.2f     |     %d     ",valores[2],estoque[2]);
    printf("\n|    4    |     Sonho      |       R$ %.2f     |     %d     ",valores[3],estoque[3]);
    printf("\n|    5    |    Tubaina     |       R$ %.2f     |     %d     ",valores[4],estoque[4]);
    printf("\n|_________|________________|___________________|____________");
}

void relatorio(int relatorio)
{

    printf("\n\n____________________RELATORIO DA BERENICE_______________");
    printf("\n|   Item  |  Nome do Item  |      Vendas    |  Estoque   ");
    printf("\n|---------------------------------------------------------");
    printf("\n|    1    |  Pao de Forma  |        %d       |     %d     ",vendas[0],estoque[0]);
    printf("\n|    2    | Pao de Centeio |        %d       |     %d     ",vendas[1],estoque[1]);
    printf("\n|    3    | Broa de Milho  |        %d       |     %d     ",vendas[2],estoque[2]);
    printf("\n|    4    |     Sonho      |        %d       |     %d     ",vendas[3],estoque[3]);
    printf("\n|    5    |    Tubaina     |        %d       |     %d     ",vendas[4],estoque[4]);
    printf("\n|_________|________________|________________|____________");
}

void fcupomFiscal(int cupom)
{
    int soma_itens;
    float soma_valores[5] = {0};
    // Corresponde a posi��o dos itens
    for(int i=0;i<=5;i++)
    {
        soma_itens = soma_itens + contador[i];
    }
    for(int i = 1;i<soma_itens ;i++){
    printf("\n_____________________________________________________________");
    printf("\n|  Item  | Nome do Item | Valor Unit.  |   Quant. | Sub-Total |");
    printf("\n|   %i   |       %s       |    %d         |          | (R$)      |",i,nome_produto[i]);
    printf("\n|-------------------------------------------------------------|");
}
}
