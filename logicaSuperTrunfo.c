#include <stdio.h>

typedef struct
{
    char id_card;          // Identificador do card (primeira letra do estado)
    char state[50];        // Nome do estado
    char nome_cidade[50];  // Nome da cidade
    int population;        // População da cidade
    long int pib;          // PIB da cidade
    int area;              // Área da cidade (em km²)
    int spot_tourist;      // Quantidade de pontos turísticos
    double pib_per_capita; // PIB per capita da cidade
    double densidade;      // Densidade populacional da cidade
} card;


//Funçao para imprimir os dados de um card.
void imprimir_card(card c)
{
    c.pib_per_capita = (double)c.pib / c.population;
    c.densidade = (double)c.population / c.area;

    printf(
        "CARD: %c\n"
        "ESTADO: %s\n"
        "NOME DA CIDADE: %s\n"
        "POPULAÇAO: %d\n"
        "PIB: %ld\n"
        "AREA: %d\n"
        "PONTOS TURISTICOS: %d\n"
        "DENSIDADE: %.2f\n"
        "PIB PER CAPITA: %.2f\n",
        c.id_card, c.state, c.nome_cidade, c.population, c.pib, c.area, c.spot_tourist, c.densidade, c.pib_per_capita);
};

//Funçao para cadastrar um novo card.
void newCard(card *cards, int *last_position)
{
    card c;
    printf("Digite o Estado: \n");
    scanf("%s", c.state);
    printf("Digite o Nome da cidade: \n");
    scanf("%s", c.nome_cidade);
    printf("Digite a populaçao: \n");
    scanf("%d", &c.population);
    printf("Digite o pib: \n");
    scanf("%ld", &c.pib);
    printf("Digite o area: \n");
    scanf("%d", &c.area);
    printf("Digite a quantidade de pontos turisticos: \n");
    scanf("%d", &c.spot_tourist);
    c.id_card = c.state[0];

    cards[*last_position] = c; // Armazenando o card no vetor.
    (*last_position)++;        // Atualiza a posiçao para o proximo card.
};

void listarCards(card *cards, int last_position)
{
    for (int i = 0; i < last_position; i++)
    {
        imprimir_card(cards[i]);
    }
};

int main()
{
    card cards[50];
    int last_position = 0;
    int opcao = 0;

    while (opcao != 3)
    {
        printf(
            "1-Cadastrar Card. \n"
            "2-Listar Cards. \n"
            "3-Sair do programa. \n"
            "4-Jogar. \n"
            "Escolha uma opcao: \n");
        scanf("%d", &opcao);

        switch (opcao)
        {

        case 1:
            newCard(cards, &last_position); // Cadastrar um novo card.
            break;
        case 2:
            listarCards(cards, last_position); // Listar todos os cards.
            break;
        case 3:
            printf("Saindo do Programa... \n");
            break;
        case 4:
            card maior;
            while(opcao != 7)
            {
                printf(
                    "Escolha qual status deseja comparar!\n"
                    "1-Populaçao\n"
                    "2-PIB\n"
                    "3-Area\n"
                    "4-Quantidade de pontos turísticos\n"
                    "5-PIB per capita\n"
                    "6-Densidade\n"
                    "7-Voltar\n");
                scanf("%d", &opcao);


            switch (opcao)
            {
                case  1:
                    maior = cards[0];
                    for(int count = 1; count <= last_position; count++)
                    {
                        if(cards[count].population > maior.population)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Maior População: %s: %d\n", maior.nome_cidade ,maior.population);
                    break;
                case 2:
                    maior = cards[0];
                    for(int count = 0; count <= last_position - 1; count++)
                    {
                        if(cards[count].pib > maior.pib)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Maior PIB: %s: %ld\n", maior.nome_cidade, maior.pib);
                    break;
                case 3:
                    maior = cards[0];
                    for(int count = 0; count <= last_position - 1; count++)
                    {
                        if(cards[count].area > maior.area)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Maior Area: %s: %d\n", maior.nome_cidade, maior.area);
                    break;
                case 4:
                    maior = cards[0];
                    for(int count = 0; count <= last_position - 1; count++)
                    {
                        if(cards[count].spot_tourist > maior.spot_tourist)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Mais pontos turisticos: %s: %d\n", maior.nome_cidade, maior.spot_tourist);
                    break;
                case 5:
                    maior = cards[0];
                    for(int count = 0; count <= last_position - 1; count++)
                    {
                        if(cards[count].pib_per_capita > maior.pib_per_capita)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Maior PIB Per Capita: %s: %.2f\n", maior.nome_cidade, maior.pib_per_capita);
                    break;
                case 6:
                    maior = cards[0];
                    for(int count = 0; count <= last_position - 1; count++)
                    {
                        if(cards[count].densidade > maior.densidade)
                        {
                            maior = cards[count];
                        }
                    }
                    printf("Maior Densidade: %s: %.2f\n", maior.nome_cidade, maior.densidade);
                    break;
                case 7:
                    main();
                default:
                    printf("Opcao Invalida! \n");
                    break;
            };
    };
        default:
            printf("Opcao Invalida! \n");
            break;
        };
    };

    return 0;
};