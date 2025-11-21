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
  Função para exibir as cartas cadastradas
  esta deve reber os valores char estado, codigo[5], cidade[20];
  float area, pib, densidadePopulacional, pibPerCapta;
  int pontosTuristicos;
  unsigned long int populacao. 
*/
void exibeCartas(int carta, struct Carta *c)
{ 

  printf("\t= CARTA #%d =\n", carta);
  printf("\tEstado: %c\n", c->estado);
  printf("\tCodigo: %s\n", c->codigo);
  printf("\tCidade: %s\n", c->cidade);
  printf("\tPopulacao: %ld\n", c->populacao);
  printf("\tArea: %.2f Km^2\n", c->area);
  printf("\tPIB: %.2f\n", c->pib);
  printf("\tPontos Turisticos: %d\n", c->pontos_turisticos);
  printf("\tDensidade populacional: %.2f HAB/Km^2\n", c->densidadePopulacional);
  printf("\tPIB per capta: R$ %.2f\n", c->pibPerCapta);
  printf("\tSUPER PODER: %.2f bi\n\n", (c->superPoder / 1e9));



}

/*
  funcao realiza calculos Densidade Populacional
  PIB per capta e Super poder
*/
void calculos(struct Carta *c)
{
  
    c->superPoder = (c->populacao + c->area + c->pib + c->pontos_turisticos + c->pibPerCapta) + (-c->densidadePopulacional);
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapta = c->pib / c->populacao;

    printf("%f", c->superPoder);

}




//COMPARADOR DE CARTAS, DETERMINA O VENCEDOR.
void menuBatalha(struct Carta *c1, struct Carta *c2)
{
        
    char atributo[50];
    char atributo2[50];
    
    int opt1, opt2;
    
    float carta1 = 0;
    float carta1_2 = 0;
    float carta2 = 0;
    float carta2_2 = 0;
    
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
    printf("\t-> Digite o numero da SEGUNDA opcao desejada: ");
    scanf("%d", &opt2);
    
    
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
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->populacao = c2->populacao);
            break;
    
        case 2:
            strcpy(atributo2, "Area");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->area = c2->area);
            // carta1 = c1->area;
            // carta2 = c2->area;
            break;
    
        case 3:
            strcpy(atributo2, "PIB");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->pib = c2->pib);
            // carta1 = c1->pib;
            // carta2 = c2->pib;
            break;
    
        case 4:
            strcpy(atributo2, "Pontos Turisticos");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->pontos_turisticos = c2->pontos_turisticos);
            // carta1 = c1->pontos_turisticos;
            // carta2 = c2->pontos_turisticos;
            break;
    
        case 5:
            strcpy(atributo2, "Densidade Populacional");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->densidadePopulacional = c2->densidadePopulacional);
            // carta1 = c1->densidadePopulacional;
            // carta2 = c2->densidadePopulacional;
            break;
    
        case 6:
            strcpy(atributo2, "PIB per Capta");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->pibPerCapta = c2->pibPerCapta);
            // carta1 = c1->pibPerCapta;
            // carta2 = c2->pibPerCapta;
            break;
    
        case 7:
            strcpy(atributo2, "Super Poder");
            (opt1 == opt2)? (printf("As opcoes precisam ser diferentes.")): 
                            (carta1_2 = carta2_2 = c1->superPoder = c2->superPoder);
            // carta1 = c1->superPoder;
            // carta2 = c2->superPoder;
            break;
        default:
            printf("\t\t xxx Opcao Invalida xxx\n");
            
            break;
    }
   

    printf("\n\n\tCARTA #1 - %s - %s: %.2f\n",c1->cidade, atributo, carta1);
    printf("\tCARTA #1 - %s - %s: %.2f\n",c1->cidade, atributo2, carta1);
    printf("\tCARTA #1 - %s - TOTAL: %.2f\n\n",c1->cidade, (carta1 + carta1_2));
    
    printf("\tCARTA #2 - %s - %s: %.2f\n",c2->cidade, atributo, carta2);
    printf("\tCARTA #2 - %s - %s: %.2f\n",c2->cidade, atributo2, carta2);
    printf("\tCARTA #2 - %s - TOTAL: %.2f\n\n",c2->cidade, (carta2 + carta2_2));

    
    if((carta1 + carta1_2) > (carta2 + carta2_2)){
        
       printf("\t^^^^ !! VITORIA DA CARTA #1 !! ^^^^\n");
    }else if((carta1 + carta1_2) == (carta2 + carta2_2)){
        printf("\t^^^^ !! EMPATOU !! ^^^^\n");
        
    }else if(carta1){

    }else{
        printf("\t^^^^ !! VITORIA DA CARTA #2 !! ^^^^\n");

    }

        
    

}  



/*
  Função para cadastramento das cartas
*/
void cadastraCartas(struct Carta *c)
{
  printf("\n\t\t==== CADASTRANDO NOVA CARTA ====\n"); 
  
  printf("Por favor, digite uma letra para o estado de A a H: ");
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

  printf("Digite a area da cidade em Km^2 (ex: 307.55): ");
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
    // cadastraCartas(&c2);
    
    calculos(&c1);
    printf("\ndentro da main %f\n", c1.superPoder);
    // calculos(&c2);
 
    exibeCartas(1, &c1);
    // exibeCartas(2, &c2 );

    // menuBatalha(&c1, &c2);

  
return 0;
} 
