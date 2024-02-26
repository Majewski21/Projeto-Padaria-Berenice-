#include <stdio.h>
#include <stdlib.h>

// Variáveis Globais
int estoque[5] = {};
float valores[5] = {7.5,8.69,5,4.5,3.35};
int qnt_item[5];

// Funções
void cadastroestoque();
void visualizarestoque();
void venda();
void pagamento;


int main()
{
    int escolha,opcao = 1;
    do
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
        if(escolha > 4 || escolha < 1)
        {
            printf("Digite um numero correspondente!");
        }
        else
        {
            opcao = 0;
            switch(escolha)
            {
            case 1:
                cadastroestoque();
                opcao = 1;
                break;
            case 2:
                visualizarestoque();
                opcao = 1;
                break;
            case 3:
                venda();
                opcao = 1;
                break;
            case 4:
                opcao = 0;
                break;
            }
        }
    }
    while(opcao != 0);


}

void cadastroestoque ()
{
    int menu;
    int escolhaestoque, quantidade;
    do
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
                menu = 0;
            }
            else
            {
                printf("\n\nQuantidade Invalida, a mesma deve ser maior ou igual a zero");
                menu = 0;
            }
        }
        else if(escolhaestoque == 0)
        {
            printf("\n\nRetornando ao menu inicial.....");
            menu = 1;
        }
        else
        {
            printf("\n\nCodigo Invalido!");
            menu = 0;

        }
    }
    while(menu != 1);
}

void visualizarestoque()
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

void venda()
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

    do
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
        printf("Digite 0 para retornar ao menu.");
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
        else if(cod_item = 0)
        {
            item = 1;
        }
        else
        {
            nomecodigo(cod_item);
            printf("\n\n Digite a quantidade que desejada comprar: ");
            scanf("%d", &qnt_item[cod_item-1]);
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
                //Calcula a subtração do estoque
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
                    pagamento();
                }
            }
        }
    }while(item != 1);
    return 1;
}

    void pagamento()
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
