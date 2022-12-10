#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIM_ADEGA 100
#define tamstd 30

int qtdvinhos = -1, qtdvinhomem = 1, totvin = 0, contrem = 0;

struct Vinho {
  int ano_safra, id;
  char pais[tamstd], nome[tamstd], tipouva[tamstd];
} * Vinho;

void Limpa_Buffer() {
  int clean;
  while ((clean = fgetc(stdin)) != '\n') {
  }
}

void incVinho() {
  int tam;

  Vinho = (struct Vinho *)realloc(Vinho, qtdvinhomem * sizeof(struct Vinho));

  qtdvinhos++;
  qtdvinhomem++;
  totvin++;

  Limpa_Buffer();
  printf("\nDigite o nome do vinho: ");
  fgets(Vinho[qtdvinhos].nome, tamstd, stdin);
  tam = (int)strlen(Vinho[qtdvinhos].nome);
  Vinho[qtdvinhos].nome[tam - 1] = '\0';

  printf("Digite o País de Origem: ");
  fgets(Vinho[qtdvinhos].pais, tamstd, stdin);
  tam = (int)strlen(Vinho[qtdvinhos].pais);
  Vinho[qtdvinhos].pais[tam - 1] = '\0';

  printf("Tipo da Uva: ");
  fgets(Vinho[qtdvinhos].tipouva, tamstd, stdin);
  tam = (int)strlen(Vinho[qtdvinhos].tipouva);
  Vinho[qtdvinhos].tipouva[tam - 1] = '\0';

  printf("Insira o ano da Safra AAAA: ");
  scanf("%d", &Vinho[qtdvinhos].ano_safra);

  Vinho[qtdvinhos].id = (totvin + contrem);

  Vinho = (struct Vinho *)realloc(Vinho, qtdvinhomem * sizeof(struct Vinho));
}

void relGeral() {

  int i = 0;

  printf("\n\n-- Relatório geral de Vinhos Cadastrados --\n");

  if (totvin > 0) {

    printf("Há %d Vinhos cadastrados.\n\n", totvin);
    for (i = contrem; i <= qtdvinhos; i++) {
      printf("ID Vinho: %d\n", Vinho[i].id);
      printf("Nome: %s\n", Vinho[i].nome);
      printf("Ano Safra: %d\n", Vinho[i].ano_safra);
      printf("País Origem: %s\n", Vinho[i].pais);
      printf("Tipo da Uva: %s\n\n", Vinho[i].tipouva);
    }
  } else
    printf("\nNão há Vinhos cadastrados.\n");
};

void remMaisAntigo() {

  if (totvin > 0) {
    printf(
        "\nO vinho abaixo é o mais antigo no estoque e será removido...\n\n");
    for (int i = contrem; i < contrem + 1; i++) {
      printf("ID Vinho: %d\n", Vinho[i].id);
      printf("Nome: %s\n", Vinho[i].nome);
      printf("Ano Safra: %d\n", Vinho[i].ano_safra);
      printf("País Origem: %s\n", Vinho[i].pais);
      printf("Tipo da Uva: %s\n\n", Vinho[i].tipouva);
    }
    contrem++;
    totvin--;
    printf("Vinho removido.\n");
  } else {
    printf("\nNão há vinhos para serem removidos.\n");
  }
}

void infMaisNovo() {

  if (totvin > 0) {
    printf("\nO último vinho que foi inserido na adega é:\n");
    printf("\nID Vinho: %d\n", Vinho[qtdvinhos].id);
    printf("Nome: %s\n", Vinho[qtdvinhos].nome);
    printf("Ano Safra: %d\n", Vinho[qtdvinhos].ano_safra);
    printf("País Origem: %s\n", Vinho[qtdvinhos].pais);
    printf("Tipo da Uva: %s\n", Vinho[qtdvinhos].tipouva);
  } else
    printf("\nNão há Vinhos cadastrados.\n");
}

void cincoNovos() {

  if (totvin > 0) {
    printf("\nAbaixo os 5 vinhos adquiridos recentemente:\n\n");

    for (int j = qtdvinhos; j > qtdvinhos - 5; j--) {
      printf("ID Vinho: %d\n", Vinho[j].id);
      printf("Nome: %s\n", Vinho[j].nome);
      printf("Ano Safra: %d\n", Vinho[j].ano_safra);
      printf("País Origem: %s\n", Vinho[j].pais);
      printf("Tipo da Uva: %s\n\n", Vinho[j].tipouva);
    }
  } else
    printf("\nNão há Vinhos cadastrados.\n");
}

void cincoAntigos() {

  if (totvin > 0) {
    printf("\nAbaixo os 5 vinhos adquiridos há mais tempo:\n\n");

    for (int j = contrem; j < contrem + 5 && j <= qtdvinhos; j++) {
      printf("ID Vinho: %d\n", Vinho[j].id);
      printf("Nome: %s\n", Vinho[j].nome);
      printf("Ano Safra: %d\n", Vinho[j].ano_safra);
      printf("País Origem: %s\n", Vinho[j].pais);
      printf("Tipo da Uva: %s\n\n", Vinho[j].tipouva);
    }

  } else
    printf("\nNão há Vinhos cadastrados.\n");
}

void Menu() {
  int selec, sw = 1, val;

  printf("Exercício 06 - Adega Ramos & Sousa\n");
  printf("1- Incluir vinho\n");
  printf("2- Exibir vinhos cadastrados\n");
  printf("3- Remover vinho mais antigo independente da safra\n");
  printf("4- Informar último vinho inserido na adega\n");
  printf("5- Cinco aquisições mais antigas\n");
  printf("6- Cinco aquisições mais novas\n");
  printf("7- Sair\n");

  while (sw == 1) {
    printf("\nOpção: ");
    scanf("%d", &selec);

    switch (selec) {
    case 1:
      incVinho();
      break;
    case 2:
      relGeral();
      break;
    case 3:
      remMaisAntigo();
      break;
    case 4:
      infMaisNovo();
      break;

    case 5:
      cincoAntigos();
      break;

    case 6:
      cincoNovos();
      break;

    case 7:
      printf("\nSaindo...\n");
      sw = 0;
      break;
    }
  }
}

int main() { Menu(); }
