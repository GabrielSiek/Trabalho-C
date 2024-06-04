#include <stdio.h>
#include <stdlib.h>
#include "hardware_library.h"

void alterarExibicao();
void alterarVelocidade();
void alterarCor();
void alterarTexto();
void atualizarLedBateria();

int main()
{
    int escolha;

    do
    {

        atualizarLedBateria();

        printf("\nDigite a opção desejada:\n");
        printf("1. Alterar o modo de exibição\n");
        printf("2. Alterar a velocidade\n");
        printf("3. Alterar a cor\n");
        printf("4. Alterar o texto\n");
        printf("0. Encerrar a aplicação\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            alterarExibicao();
            break;
        case 2:
            alterarVelocidade();
            break;
        case 3:
            alterarCor();
            break;
        case 4:
            alterarTexto();
            break;
        case 0:
            printf("Encerrando a aplicação...\n");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (escolha != 0);

    return 0;
}

void alterarExibicao()
{
    int escolha;

    do
    {
        printf("Digite a opção desejada\n");
        printf("1. Estático\n");
        printf("2. Deslizante\n");
        printf("3. Piscante\n");
        printf("4. Deslizante e piscante\n");
        printf("0. Voltar\n");

        scanf("%d", &escolha);

        switch (escolha)
        {
        case 1:
            W(0, 1, 0b00, 2);
            printf("Display alterado");
            break;
        case 2:
            W(0, 1, 0b01, 2);
            printf("Display alterado");
            break;
        case 3:
            W(0, 1, 0b10, 2);
            printf("Display alterado");
            break;
        case 4:
            W(0, 1, 0b11, 2);
            printf("Display alterado");
            break;
        case 0:
            printf("Voltando...");
            break;
        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
        }
    } while (escolha != 0);
}

void alterarVelocidade()
{
    int velocidade;

    do {
        printf("Digite a velocidade que deseja(de 0 a 127):\n");
        scanf("%d", &velocidade);

        if(velocidade > 127 || velocidade < 0)
            printf("Valor de velocidade inválido");
    } while (velocidade > 127 || velocidade < 0);
    
    W(0, 3, velocidade, 6);

    printf("Velocidade alterada");
}

void alterarCor()
{
    int red;
    int green;
    int blue;

    do
    {
        printf("Digite o valor do vermelho(de 0 a 255):");
        scanf("%d", &red);
        if(red > 255 || red < 0)
            printf("Valor do vermelho inválido");
    } while (red > 255 || red < 0);

    do
    {
        printf("Digite o valor do verde(de 0 a 255):");
        scanf("%d", &green);
        if(green > 255 || green < 0)
            printf("Valor do verde inválido");
    } while (green > 255 || green < 0);

    do
    {
        printf("Digite o valor do azul(de 0 a 255):");
        scanf("%d", &blue);
        if(blue > 255 || blue < 0)
            printf("Valor do azul inválido");
    } while (blue > 255 || blue < 0);

    W(1, 0, red, 8);
    W(1, 8, green, 8);
    W(2, 0, blue, 8);
}

void alterarTexto()
{
    char texto[24];
    
    printf("Digite o texto que deseja exibir(limite de 24 caracteres):\n");

    scanf("%s", texto);

    changeString(texto);
}

void atualizarLedBateria()
{
    int nivelBateria = R(3,0,2);

    switch (nivelBateria)
    {
    case 0b00: //vermelho
        W(0,10, 0b001, 3);
        break;
     case 0b01: //amarelo
        W(0,10, 0b011, 3);
        break;
     case 0b10: //verde
        W(0,10, 0b010, 3);
        break;
     case 0b11: //verde
        W(0,10, 0b010, 3);
        break;         
    default:
        printf("Erro na leitura do nível de bateria");
        break;
    }
}