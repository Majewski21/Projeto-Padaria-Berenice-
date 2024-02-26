#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_nome 26

typedef struct
{
    int codigo;
    char nome[MAX_nome];
    float preco;
    int quantidade;
    int vendidos;
    int vendidos_relatorio;
} produto;

produto *estoque;

int contador_items = 0;

///Cadastro:

void atualizar();
void cadastrar();
void excluir();
void exibir();
void salvar();
void submenu();
void ler();
int valida_cod(int codigo);

///Venda
void submenu_venda();
void pagamento(float valor_t);
void cupom(float valor_t);
void venda();
void relatorio();

int main()
{
    system("COLOR 0E");
    int escolha,verify = 0;
    do
    {
        printf("\n\n_________Mercadinho da Berenice________\n");
        printf("            1 - Produtos              \n");
        printf("            2 - Vendas                \n");
        printf("            3 - Sair                  \n");
        printf("______________________________________\n");
        printf("\n\n Escolha --> ");
        scanf("%d", &escolha);
        if(escolha < 1 || escolha > 3)
        {
            printf("\nDigite um numero valido");
            verify = 1;
        }
        switch(escolha)
        {
        case 1:
            verify = 0;
            submenu();
            break;
        case 2:
            verify = 0;
            submenu_venda();
            break;
        case 3:
            relatorio();
            printf("\n Finalizando Programa...\n");
            exit(0);
            break;
        }
    }
    while(verify == 1);
}


void submenu()
{
    int escolha;
    while (escolha != 7)
    {
        printf("\n\n________________Produtos________________\n");
        printf("        1 - Atualizar Produto         \n");
        printf("        2 - Cadastrar Produto         \n");
        printf("        3 -  Excluir Produto          \n");
        printf("        4 -   Exibir Estoque          \n");
        printf("        5 -    Salvar Dados           \n");
        printf("        6 -     Ler Dados             \n");
        printf("        7 -       Sair                \n");
        printf("______________________________________\n");
        printf("\n\n Escolha --> ");
        scanf("%d", &escolha);
        if(escolha <= 0 || escolha > 7)
        {
            printf("Opcao Invalida!");
        }
        else if (escolha == 7)
        {
            main();
        }

        switch(escolha)
        {
        case 1:
            atualizar();
            break;
        case 2:
            cadastrar();
            break;
        case 3:
            excluir();
            break;
        case 4:
            exibir();
            break;
        case 5:
            salvar();
            break;
        case 6:
            ler();
            break;
        }
    }
    main();
}

void submenu_venda()
{
    int escolha,loop;
    while(loop != 1)
    {
        printf("\n\n ____Venda Berenice____\n");
        printf("        1 -    Realizar Venda              \n");
        printf("        2 -  Relatorio de Vendas           \n");
        printf("        3 -        Voltar                  \n");
        printf(" _____________\n");
        printf("\n\n --> ");
        scanf("%d", &escolha);
        if(escolha > 3 || escolha < 1)
        {
            printf("\n Digite um numero valido");
            loop = 3;
        }
        switch(escolha)
        {
        case 1:
            venda();
            break;
        case 2:
            relatorio();
            break;
        case 3:
            main();
            break;
        }
    }

}
///FALTA FAZER VERIFICAÇÃO DE NOME E SIMBOLO NO CODIGO;
void cadastrar()
{
    int validar_codigo, funcao_validar,loop, loop_2;
    int loop_preco = 2, loop_qtd = 2, loop_nome;
    //Da um check vendo se o codigo e maior que 0
    if(contador_items == 0)
    {
        estoque = (produto *)malloc(contador_items+1*sizeof(produto));
    }
    else
    {
        estoque = (produto *)realloc(estoque,((contador_items+1)*sizeof(produto)));
    }
    while(loop != 1)
    {
        printf("\n\n Digite o codigo do novo Produto: ");
        scanf("%d", &validar_codigo);
        getchar();
        if(validar_codigo < 0)
        {
            printf("\nCodigo Invalido!");
            loop = 2;
        }
        else
        {

            loop = 1;
        }
    }
    //Aloca espaço na memoria para o ponteiro(estoque):
    while(loop_2 != 1)
    {
        //Validação do código
        funcao_validar = valida_cod(validar_codigo);
        if(funcao_validar != -1)
        {
            printf("\n\nCodigo digitado ja existe!");
            printf("\n\n Digite o codigo do novo Produto: ");
            scanf("%d", &validar_codigo);
            getchar();
            loop_2 = 2;
        }
        else
        {
            loop_2 = 1;
        }
    }
    //Cadastro:
    estoque[contador_items].codigo = validar_codigo;
    printf("\nDigite o nome do Produto: ");
    gets(estoque[contador_items].nome);
    fflush(stdin);
    do
    {
        printf("\nDigite o Preco:  ");
        scanf("%f", &estoque[contador_items].preco);
        //Check Preço
        if(estoque[contador_items].preco < 0)
        {
        }
        else
        {
            loop_preco = 1;
        }
    }
    while(loop_preco != 1);
    do
    {
        printf("\nDigite Quantidade: ");
        scanf("%d", &estoque[contador_items].quantidade);
        //Check Quantidade
        if(estoque[contador_items].quantidade < 0)
        {

        }
        else
        {
            loop_qtd = 1;
        }
    }
    while(loop_qtd != 1);
    estoque[contador_items].vendidos = 0;
    estoque[contador_items].vendidos_relatorio = 0;
    contador_items++;
    return;
}

void excluir()
{
    int escolha, validar_codigo,cod,loop_cod,escolha_2;
    printf("\n___Estoque da Berenice___");
    printf("\n|Codigo|Nome do Item|Valor|Estoque|\n");
    for(int i = 0; i<contador_items; i++)
    {
        printf("|%6d|%10s|%4.2f|%6d|\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco,estoque[i].quantidade);
    }
    printf("\n Pressione 0 para voltar");
    printf("\n Pressione 1 para Excluir produto");
    printf("\n--> ");
    scanf("%d", &escolha);
    if(escolha == 1)
    {
        while(loop_cod != 1)
        {
            printf("\nDigite o codigo do produto que deseja excluir: ");
            scanf("%d", &cod);
            if(cod <= 0)
            {
                printf("\nValor incorreto digitado");
                loop_cod = 2;
            }
            else
                validar_codigo = valida_cod(cod);
            if(validar_codigo < 0)
            {
                printf("\nProduto nao encontrado");
                submenu();
            }
            else
                printf("\n\n Confirma excluir o item [%s] da lista de itens?", estoque[validar_codigo].nome);
            printf("\n1 - Sim");
            printf("\n2 - Nao");
            printf("\n--> ");
            scanf("%d", &escolha_2);
            if(escolha_2 == 1)
            {
                for (int i = validar_codigo; i < contador_items - 1; i++)
                {
                    estoque[i] = estoque[i + 1];
                }
                contador_items--; // Atualiza o contador de itens
                // Realoca a memória para o novo tamanho
                estoque = realloc(estoque, contador_items * sizeof(produto));
                printf("\n Produto excluido com sucesso!\n");
                submenu();
            }
            else
                submenu();
        }
    }
    else
    {
        submenu();
    }
}
void exibir()
{
    int sair, loop = 1;
    while(loop == 1)
    {
        printf("\n___Estoque da Berenice___");
        printf("\n|Codigo|Nome do Item|Valor|Estoque|\n");
        for(int i = 0; i<contador_items; i++)
        {
            printf("|%6d|%10s|%4.2f|%6d|\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco,estoque[i].quantidade);
        }
        printf("\n Digite 0 para sair: ");
        scanf("%d", &sair);
        if(sair == 0)
        {
            loop = 0;
        }
        else
        {
        }
    }
    submenu();
}

void salvar()
{
    int escolha;
    char c = '\n';
    printf("%d", contador_items);
    printf("\n Pressione 0 para voltar");
    printf("\n Pressione 1 para salvar o estoque");
    printf("\n--> ");
    scanf("%d", &escolha);
    if(escolha == 1)
    {
        FILE *agenda = fopen("agenda.txt", "w");
        if(agenda == NULL)
        {
            printf("\nArquivo vazio");
            return;
        }
        else
        {
            printf("\nAbrindo o arquivo...");
        }
        fprintf(agenda, "%d\n", contador_items);
        for(int i = 0; i<contador_items; i++)
        {
            fprintf(agenda,"%d\n", estoque[i].codigo);
            fprintf(agenda,"%s\n", estoque[i].nome);
            fprintf(agenda,"%f\n", estoque[i].preco);
            fprintf(agenda,"%d\n", estoque[i].quantidade);
            fprintf(agenda,"%d\n",estoque[i].vendidos);
        }
        printf("\n\nItems Arquivados com sucesso!");
        fclose(agenda);
        submenu();
    }
    else
    {
        submenu();
    }

}

void ler()
{
    FILE *agenda = fopen("agenda.txt", "r");
    if(agenda == NULL)
    {
        printf("\n Arquivo nao encontrado");
        submenu();
    }
    else
    {
        printf("\nArquivo encontrado");
    }
    fscanf (agenda,"%d\n",&contador_items);
    estoque = (produto *) realloc(estoque,contador_items*sizeof(produto));
    for(int i = 0; i<contador_items; i++)
    {
        fscanf(agenda,"%d\n", &estoque[i].codigo);
        fscanf(agenda,"%29[^\n]", &estoque[i].nome);
        fscanf(agenda,"%f\n", &estoque[i].preco);
        fscanf(agenda,"%d\n", &estoque[i].quantidade);
        fscanf(agenda, "%d\n", &estoque[i].vendidos);
    }
    printf("\nInformacoes obtidas com sucesso");
    fclose(agenda);
    submenu();
}

void atualizar()
{
    int verifica_codigo, funcao_validar, loop_verificar,opcao,loop_menu,loop_qtd;
    int quantidade;
    float preco;
    while(loop_verificar != 1)
    {
        printf("\n\n___Items Berenice__");
        printf("\n|Codigo|Nome do Item|Valor|Estoque|\n");
        for(int i = 0; i<contador_items; i++)
        {
            printf("|%6d|%10s|%4.2f|%6d|\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco,estoque[i].quantidade);
        }
        printf("\n Digite 0 para retornar ao menu");
        printf("\n\nDigite o Codigo do produto: ");
        scanf("%d", &verifica_codigo);
        funcao_validar = valida_cod(verifica_codigo);
        if(verifica_codigo == 0)
        {
            submenu();
        }
        else if(funcao_validar != -1)
        {
            printf("\nCodigo Encontrado!");
            printf("\n\n___Items Berenice__");
            printf("\n|Codigo|Nome do Item|Valor|Estoque|\n");
            for(int i = 0; i<contador_items; i++)
            {
                printf("|%6d|%10s|%4.2f|%6d|\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco,estoque[i].quantidade);
            }
            do
            {
                printf("\n\nDeseja atualizar: ");
                printf("\n    1. Quantidade");
                printf("\n          2. Preco");
                printf("\n             3. Voltar");
                printf("\nOpcao: ");
                scanf("%d", &opcao);
                if(opcao > 3 || opcao <= 0)
                {
                    printf("\n\n Digite um numero valido.");
                    loop_menu = 3;
                }
                else
                {
                    switch(opcao)
                    {
                    case 1:
                        while(loop_qtd != 1)
                        {
                            printf("\nDigite a nova quantidade: ");
                            scanf("%d", &quantidade);
                            if(quantidade < 0)
                            {
                                printf("\n\nDigite uma quantidade valida!");
                                loop_qtd = 5;
                            }
                            else
                            {
                                estoque[funcao_validar].quantidade = quantidade;
                                loop_qtd = 1;
                                printf("\n\n Estoque Alterado");
                            }
                        }
                        break;
                    case 2:
                        loop_qtd = 2;
                        while(loop_qtd != 1)
                        {
                            printf("\nDigite o novo preco: ");
                            scanf("%f", &preco);
                            if(preco < 0)
                            {
                                printf("\n\nDigite um preco valido!");
                                loop_qtd = 5;
                            }
                            else
                            {
                                estoque[funcao_validar].preco = preco;
                                loop_qtd = 1;
                                printf("\n\n Preco Alterado");
                            }
                        }
                        break;
                    case 3:
                        loop_menu = 1;
                        loop_verificar = 10;
                        break;
                    }
                }
            }
            while(loop_menu != 1);
        }
        else
        {
            printf("\nProduto nao encontrado no sistema");
            printf("\nDigite novamente!\n");
        }
    }
}

void venda()
{
    int cod = 0, validar = 0,qnt_venda;
    int controle1 = 3, verifica;
    int loop1 = 2, loop_maior;
    int escolha, escolha_2;
    float sub_total, valor_total = 0;

    do{
            if(sub_total > 0 ){
                loop1 = 2;
                controle1 = 3;
            }
        printf("\n\n___MERCADO DA BERE___");
        printf("\n|Codigo|Nome do Item|Valor|Estoque|\n");
        for(int i = 0; i<contador_items; i++)
        {
            printf("|%6d|%10s|%4.2f|%6d|\n", estoque[i].codigo, estoque[i].nome, estoque[i].preco,estoque[i].quantidade);
        }
        while(loop1 != 0)
        {
            if(valor_total > 0)
            {
                cupom(valor_total);
            }
            printf("\nDigite 0 para retornar ao menu");
            printf("\nDigite -1 para finalizar a compra");
            printf("\n Codigo do produto: ");
            scanf("%i",&cod);
            getchar();
            if(cod == 0)
            {
                submenu_venda();
            }
            else if(cod == -1)
            {
                pagamento(valor_total);
            }
            validar = valida_cod(cod);
            if (validar != -1)
            {
                printf("\n Produto [%s] selecionado\n", estoque[validar].nome);
                loop1 = 0;
            }
            else
            {
                printf("\n Produto nao encontrado");
            }
        }
        while (controle1!=1)
        {
            printf("\n Selecione a quantidade: ");
            scanf("%d", &qnt_venda);
            getchar();
            if (qnt_venda > estoque[validar].quantidade || qnt_venda <= 0)
            {
                printf("\n\nQuantidade selecionada invalida ou maior que a disponivel!");
            }
            else
            {
                printf("\n\nQuantidade [%d] selecionada", qnt_venda);
                controle1 = 1;
            }
        }
        estoque[validar].quantidade = estoque[validar].quantidade - qnt_venda;
        sub_total = estoque[validar].preco * qnt_venda;
        valor_total = valor_total + sub_total;
        estoque[validar].vendidos = qnt_venda;
        estoque[validar].vendidos_relatorio = estoque[validar].vendidos;
        printf("\n%f", valor_total);
        loop_maior = 3;
    }while(loop_maior == 3);

}

void pagamento(float valor_t)
{
    int parcelas;
    int continuar;
    int checar_avista = 0;
    int opcao_pagamento;
    int checar_parcelas = 0;
    float troco;
    float valor_recebido;
    float valor_parcela;

    printf("\n O valor total eh: %.2f",valor_t);

    printf("\n\n______________________");
    printf("\n | Opcoes de Pagamento |");
    printf("\n |_____________________|");
    printf("\n |     1.A vista       |");
    printf("\n |     2.Parcelado     |");
    printf("\n |_____________________|");
    printf("\n Selecione um opcao de pagamento:");
    scanf("%d", &opcao_pagamento);
    getchar();
    if (opcao_pagamento < 1 || opcao_pagamento > 2)
    {
        printf("\nOpcao de pagamento invalida!");
    }
    else if (opcao_pagamento == 1)
    {
        if (valor_t>= 1 && valor_t <= 50)
        {
            printf("\nDesconto de 5 Por Cento aplicado!");
            valor_t = valor_t - (valor_t * 5 / 100);
        }
        else if (valor_t >= 50 && valor_t <= 100)
        {
            printf("\nDesconto de 10 Por Cento aplicado!");
            valor_t = valor_t - (valor_t * 10 / 100);
        }
        else
        {
            printf("\nDesconto de 18 Por Cento aplicado!");
            valor_t = valor_t - (valor_t * 18 / 100);
        }
        printf("\nValor Total: R$%.2f \n", valor_t);
        do
        {
            printf("\n Informe o valor recebido: ");
            scanf("%f", &valor_recebido);
            troco = valor_recebido - valor_t;
            if (troco < 0)
            {
                printf("\n\nDinheiro recebido insuficiente!");
                printf("\n\nInforme o valor recebido novamente:");
                checar_avista = 2;

            }
            else
            {
                printf("\nValor do troco: %.2f",troco);
                checar_avista = 0;
            }
        }
        while(checar_avista != 0);
    }
    ///OPCAO A PRAZO
    else if (opcao_pagamento == 2)
    {
        do
        {
            printf("\nDigite o numero de parcelas: ");
            scanf("%d", &parcelas);
            if (parcelas <= 1)
            {
                printf("\nParcelamento invalido!");
                checar_parcelas = 2;
            }
            else
            {
                if (parcelas >= 1 && parcelas <= 3)
                {
                    printf("\nJuros de 5 Por Cento aplicado!");
                    valor_t = valor_t + (valor_t * 5/100);
                    checar_parcelas = 0;
                }
                else
                {
                    printf("\nJuros de 8 Por Cento aplicado!");
                    valor_t = valor_t + (valor_t * 8/100);
                    checar_parcelas = 0;
                }
                valor_parcela = valor_t / parcelas;
                printf("\nValor por parcela: %.2f ",valor_parcela);
                printf("\nO valor total da compra parcelada eh: %.2f", valor_t);
            }
        }while(checar_parcelas != 0);
    }
    else
    {
        printf("\nForma de pagamento invalida!!");

    }
    printf("\nDigite 1 para continuar -->");
    scanf("%d", &continuar);

    cupom(valor_t);
    printf("\n________________________Trocol: %.2f|\n", troco);
    for(int i = 0;i<contador_items;i++)
            {
                estoque[i].vendidos = 0;
            }
        submenu();
}

void relatorio()
{
    printf("\n\n_________Relatorio de Vendas_________");
    printf("\n|Pos|Nome do Item|Estoque|Vendidos|\n");
        for(int i = 0;i<contador_items;i++)
    {
        if(estoque[i].vendidos_relatorio > 1000){
        estoque[i].vendidos_relatorio = 0;
        }
    }
        for(int i = 0; i<contador_items; i++)
        {

            if(estoque[i].vendidos_relatorio > 0){
            printf("|%6d|%10s|%4d|%4d|\n",i+1, estoque[i].nome,estoque[i].quantidade,estoque[i].vendidos_relatorio);
            }
        }
        printf("_________________________________\n");
}

void cupom(float valor_t)
{
     printf("\n\n_________CUPOM FISCAL_________");
    printf("\n|Pos|Nome do Item|Vendidos|\n");
        for(int i = 0; i<contador_items; i++)
        {
            if(estoque[i].vendidos > 0){
            printf("|%6d|%10s|%4d|\n",i+1, estoque[i].nome, estoque[i].vendidos);
            }
        }
        printf("________________________Subtotal: %.2f|\n", valor_t);
}

int valida_cod(int codigo)
{
    for(int i = 0; i<contador_items; i++)
    {
        if(codigo == estoque[i].codigo)
        {
            return i;
        }
    }
    return -1;
}
