#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char nome[30];
    int forca;
    int velocidade;
    int inteligencia;
    int resistencia;
} Carta;

void imprimirCarta(Carta c) {
    printf("Animal: %s\n", c.nome);
    printf("Força: %d\n", c.forca);
    printf("Velocidade: %d\n", c.velocidade);
    printf("Inteligência: %d\n", c.inteligencia);
    printf("Resistência: %d\n", c.resistencia);
}

int main() {
    srand(time(NULL));

    Carta cartas[] = {
        {"Leão", 90, 80, 60, 85},
        {"Elefante", 95, 30, 70, 90},
        {"Guepardo", 60, 100, 50, 60},
        {"Corvo", 40, 75, 90, 50},
        {"Urso", 85, 60, 55, 95}
    };

    int totalCartas = sizeof(cartas) / sizeof(cartas[0]);
    int indiceJogador = rand() % totalCartas;
    int indicePC;
    do {
        indicePC = rand() % totalCartas;
    } while (indicePC == indiceJogador);

    Carta jogador = cartas[indiceJogador];
    Carta pc = cartas[indicePC];

    printf("Sua carta:\n");
    imprimirCarta(jogador);

    printf("\nEscolha o atributo para competir:\n");
    printf("1 - Força\n");
    printf("2 - Velocidade\n");
    printf("3 - Inteligência\n");
    printf("4 - Resistência\n");
    int escolha;
    scanf("%d", &escolha);

    printf("\nCarta do Computador:\n");
    imprimirCarta(pc);

    int valorJogador, valorPC;
    switch (escolha) {
        case 1:
            valorJogador = jogador.forca;
            valorPC = pc.forca;
            break;
        case 2:
            valorJogador = jogador.velocidade;
            valorPC = pc.velocidade;
            break;
        case 3:
            valorJogador = jogador.inteligencia;
            valorPC = pc.inteligencia;
            break;
        case 4:
            valorJogador = jogador.resistencia;
            valorPC = pc.resistencia;
            break;
        default:
            printf("Escolha inválida!\n");
            return 1;
    }

    printf("\nResultado:\n");
    if (valorJogador > valorPC)
        printf("Você venceu!\n");
    else if (valorJogador < valorPC)
        printf("Computador venceu!\n");
    else
        printf("Empate!\n");

    return 0;
}