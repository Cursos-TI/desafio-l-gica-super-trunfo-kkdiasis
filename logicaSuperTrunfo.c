#include <stdio.h>
#include <string.h> // para possibilitar retirar o \n incluido no final da string pelo fgets 



// Estrutura única para todas as cartas
struct Carta
{

  char estado, codigo[5], cidade[20];
  float area, pib, densidadePopulacional,
  pibPerCapta, superPoder;
  int pontos_turisticos; 
  unsigned long int populacao;

};


/*
  função para calcular densidade populacional:
  Recebe o float cx_populacao e float cx_area > calcula densidade (densidade = população / área ocupada km²)
  > Retorna var com o valor do cálculo da densidade populacional em hab/km²
*/ 
float densidadePopulacional(unsigned long int populacao, float area)
{

  float densidadePop = populacao / area;

  return densidadePop;
}

/*
  Função para calcular o PIB per capta:
  Recebe float cx_pib e int cx_populacao > calcula: Pib / População e armazena em uma var > Retorna var com cálculo para main.
*/
float pibPerCapta(float pib, unsigned long int populacao)
{
  float pibPerCapta = pib / populacao;

  return pibPerCapta;
}





/*
  Função para exibir as cartas cadastradas
  esta deve reber os valores char estado, codigo[5], cidade[20];
  float area, pib, densidadePopulacional, pibPerCapta;
  int pontosTuristicos;
  unsigned long int populacao. 
*/
void exibeCartas(
  int carta,
  char estado, char *codigo, char *cidade,
  float area, float pib, float densidadePopulacional, float pibPerCapta,
  int pontosTuristicos, unsigned long int populacao, float superPoder
)
{ 

  printf("\t= CARTA #%d =\n", carta);
  printf("\tEstado: %c\n", estado);
  printf("\tCodigo: %s\n", codigo);
  printf("\tCidade: %s\n", cidade);
  printf("\tPopulacao: %ld\n", populacao);
  printf("\tArea: %.2f Km^2\n", area);
  printf("\tPIB: %.2f\n", pib);
  printf("\tPontos Turisticos: %d\n", pontosTuristicos);
  printf("\tDensidade populacional: %.2f HAB/Km^2\n", densidadePopulacional);
  printf("\tPIB per capta: R$ %.2f\n", pibPerCapta);
  printf("\tSUPER PODER: %.2f bi\n\n", (superPoder / 1e9));



}

/*
  O SUPER PODER é calculado somando 
  população, área, PIB, número de pontos turísticos, PIB per capita e o inverso da densidade populacional 
*/
float superPoder(
  float area, float pib, float densidadePopulacional, float pibPerCapta,
  float pontosTuristicos, float populacao
)
{
  
  float super = (populacao + area + pib + pontosTuristicos + pibPerCapta) + (-densidadePopulacional);

  return super;

}



//COMPARADOR DE CARTAS, DETERMINA O VENCEDOR.
void batalha(struct Carta *c1, struct Carta *c2)
{
    int opt1;
    int opt2;
    char atributo[50];
    char atributo2[50];

    printf("\n\t\t==== SUPER TRUNFO - BATALHA DE CARTAS ====\n\n");
    printf("\tEscolha DUAS OPCOES de atributo que sera usado para essa jogada:\n");
    printf("\t1 - Populacao\n");
    printf("\t2 - Area\n");
    printf("\t3 - PIB\n");
    printf("\t4 - Pontos Turisticos\n");
    printf("\t5 - Densidade populacional\n");
    printf("\t6 - PIB per Capta\n");
    printf("\t7 - Super Poder\n");
    
    printf("\t-> Digite o numero da PRIMEIRA opcao desejada: ");
    scanf("%d", &opt1);
    printf("\t-> Digite o numero da SEGUNDA opcao desejada (diferente do primeiro): ");
    scanf("%d", &opt2);

    //validado a opção, se o valores escolhidos nao forem iguais, maior que zero e menor que 7 = valido.
    // ((opt1 > 0 && opt2 > 0) && (opt1 < 8 && opt2 < 8) && (opt1 != opt2)) ? (validacao = 1): (validacao = 0);
    
    
    float carta1 = 0;
    float carta1_2 = 0;
    float carta2 = 0;
    float carta2_2 = 0;
    
    switch(opt1)
    {
        case 1:
            strcpy(atributo, "Populacao");
            carta1 = c1->populacao;
            carta2 = c2->populacao;
            break;

        case 2:
            strcpy(atributo, "Area");
            carta1 = c1->area;
            carta2 = c2->area;
            break;

        case 3:
            strcpy(atributo, "PIB");
            carta1 = c1->pib;
            carta2 = c2->pib;
            break;

        case 4:
            strcpy(atributo, "Pontos Turisticos");
            carta1 = c1->pontos_turisticos;
            carta2 = c2->pontos_turisticos;
            break;

        case 5:
            strcpy(atributo, "Densidade Populacional");
            carta1 = c1->densidadePopulacional;
            carta2 = c2->densidadePopulacional;
            break;

        case 6:
            strcpy(atributo, "PIB per Capta");
            carta1 = c1->pibPerCapta;
            carta2 = c2->pibPerCapta;
            break;

        case 7:
            strcpy(atributo, "Super Poder");
            carta1 = c1->superPoder;
            carta2 = c2->superPoder;
            break;
        default:
            printf("\t\t xxx Opcao Invalida xxx\n");
            break;
    }

    switch(opt2)
    {
        case 1:
            strcpy(atributo2, "Populacao");
            carta1_2 = c1->populacao;
            carta2_2 = c2->populacao;
            break;

        case 2:
            strcpy(atributo2, "Area");
            carta1_2 = c1->area;
            carta2_2 = c2->area;
            break;

        case 3:
            strcpy(atributo2, "PIB");
            carta1_2 = c1->pib;
            carta2_2 = c2->pib;
            break;

        case 4:
            strcpy(atributo2, "Pontos Turisticos");
            carta1_2 = c1->pontos_turisticos;
            carta2_2 = c2->pontos_turisticos;
            break;

        case 5:
            strcpy(atributo2, "Densidade Populacional");
            carta1_2 = c1->densidadePopulacional;
            carta2_2 = c2->densidadePopulacional;
            break;

        case 6:
            strcpy(atributo2, "PIB per Capta");
            carta1_2 = c1->pibPerCapta;
            carta2_2 = c2->pibPerCapta;
            break;

        case 7:
            strcpy(atributo2, "Super Poder");
            carta1_2 = c1->superPoder;
            carta2_2 = c2->superPoder;
            break;
        default:
            printf("\t\t xxx Opcao Invalida xxx\n");
            break;
    }

    printf("\n\tCARTA #1 - %s - %s e %s: %.2f\n",c1->cidade, atributo, atributo2, carta1);
    printf("\tCARTA #1 - %s - TOTAL: %.2f\n",c1->cidade, (carta1 + carta1_2));
    printf("\tCARTA #2 - %s - %s e %s: %.2f\n", c2->cidade, atributo, atributo2, carta2);
    printf("\tCARTA #2 - %s - TOTAL: %.2f\n\n",c2->cidade, (carta2 + carta2_2));

    ((carta1 + carta1_2) > (carta2 + carta2_2))?
        printf("\t^^^^ !! VITORIA DA CARTA #1 !! ^^^^\n"):
        printf("\t^^^^ !! VITORIA DA CARTA #2 !! ^^^^\n");

    if (carta1 == carta2){

        printf("\t^^^^ !! EMPATOU !! ^^^^\n");
    }

        
    

}  



/*
  Função para cadastramento das cartas
*/
void cadastraCartas(struct Carta *c)
{
  printf("\n\t\t==== CADASTRANDO CARTAS ====\n"); 
  
  printf("Por favor, digite uma letra para o estado de A a H (ex: A): ");
  scanf("%c", &c->estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta no formato LETRA DO ESTADO + numeral(ex: %c01, %c02): ", c->estado, c->estado);
  fgets(c->codigo, 5, stdin);
  c->codigo[strcspn(c->codigo, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite nome da cidade, sem acentuacao (ex: Sao Roque): ");
  fgets(c->cidade, 20, stdin);
  c->cidade[strcspn(c->cidade, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite a populacao da cidade (ex: 92060): ");
  scanf("%ld", &c->populacao);

  printf("Digite a area da cidade em Km^2 (ex: 307.553): ");
  scanf("%e", &c->area);

  printf("Digite o PIB da cidade (ex: 3108224143.00): ");
  scanf("%e", &c->pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c->pontos_turisticos);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER
  
}

int main() {
  
  struct Carta c1;//carta1
  struct Carta c2; //carta2
  
  // INICIANDO CADASTRO DE CARTAS
  cadastraCartas(&c1);
  cadastraCartas(&c2);
  
/*
  Enviando dados coletados para funções de cálculo de densidade populacional e pib per capta
*/

  c1.densidadePopulacional = densidadePopulacional(c1.populacao, c1.area);
  c1.pibPerCapta = pibPerCapta(c1.pib, c1.populacao); 
  c1.superPoder = superPoder(c1.area, c1.pib, c1.densidadePopulacional,
                             c1.pibPerCapta, c1.pontos_turisticos, 
                             c1.populacao
                            );
  
  c2.densidadePopulacional = densidadePopulacional(c2.populacao, c2.area);
  c2.pibPerCapta = pibPerCapta(c2.pib, c2.populacao); 
  c2.superPoder = superPoder(c2.area, c2.pib, c2.densidadePopulacional,
                             c2.pibPerCapta, c2.pontos_turisticos, 
                             c2.populacao
                            ); 


  // Área para exibição dos dados da cidade
  //Passando as variáveis para a função para exibição das cartas
  
  exibeCartas(
    1,
    c1.estado, c1.codigo, c1.cidade, c1.area, c1.pib,
    c1.densidadePopulacional, c1.pibPerCapta,
    c1.pontos_turisticos, c1.populacao,
    c1.superPoder
  );

  exibeCartas(
    2,
    c2.estado, c2.codigo, c2.cidade, c2.area, c2.pib,
    c2.densidadePopulacional, c2.pibPerCapta,
    c2.pontos_turisticos, c2.populacao,
    c2.superPoder
  );

  batalha(&c1, &c2);
  
return 0;
} 
