#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int cont_glob = 0, limmax;

struct Noh {
  int dado;
  Noh *proximo;
} node;

struct NohT {
  int dado;
  NohT *proximo;
} nodeT;

void enfileirar(struct Noh *&inicio, struct Noh *&fim, int dado) {

  Noh *novo = (Noh *)calloc(1, sizeof(Noh));

  novo->dado = dado;

  novo->proximo = NULL;
  if (inicio == NULL) {
    inicio = novo;
    fim = novo;
  } else {
    fim->proximo = novo;
    fim = novo;
  }
}
void enfileirar_Temp(struct NohT *&inicio, struct NohT *&fim, int dado) {

  NohT *novo = (NohT *)calloc(1, sizeof(NohT));

  novo->dado = dado;

  novo->proximo = NULL;
  if (inicio == NULL) {
    inicio = novo;
    fim = novo;
  } else {
    fim->proximo = novo;
    fim = novo;
  }
}

int desenfileirar(struct Noh *&inicio, struct Noh *&fim) {
  int dado = 0;
  if (inicio == NULL) {
    printf("\nFila vazia!");
  } else {
    Noh *aux = inicio;
    dado = inicio->dado;
    inicio = inicio->proximo;
    free(aux);
  }
  return dado;
}

void mostrarFila(struct Noh *&inicio, struct Noh *&fim) {

  Noh *aux = inicio;

  if (inicio == NULL) {
    printf("\nFila vazia!");
  } else {
    aux = inicio;
    while (aux != NULL) {
      printf(" %d", aux->dado);
      aux = aux->proximo;
    }
  }
}

void consulta(struct Noh *&inicio, struct Noh *&fim, struct NohT *&inicioT,
              struct NohT *&fimT, int val) {
  int dado = 0, sw = 0, x;

  int i = 0, j;
  int temp[i];

  while (inicio != NULL) {
    Noh *aux = inicio;
    dado = inicio->dado;

    if (dado == val) {
      sw = 1;
    }
    inicio = inicio->proximo;
    free(aux);
    temp[i] = dado;
    enfileirar_Temp(inicioT, fimT, temp[i]);
    i++;
  }

  if (sw == 0) {
    printf("\nValor não encontrado\n");
  } else if (sw == 1) {
    printf("\nValor encontrado.\n");
  }

  dado = 0, i = 0;

  while (inicioT != NULL) {
    NohT *auxT = inicioT;
    dado = inicioT->dado;

    inicioT = inicioT->proximo;
    free(auxT);
    temp[i] = dado;
    enfileirar(inicio, fim, temp[i]);
    i++;
  }
}

void LimMax() {

  printf("\nDigite o comprimento da fila: ");
  scanf("%d", &limmax);
  printf("\nDefinido!\n");
}

void StatusFila() {

  printf("\nStatus da fila:\n");

  if (cont_glob == 0) {

    printf("A fila está vazia.\n");

  } else

    printf("A fila não está vazia.\n");
  printf("Há %d elementos na fila.\n", cont_glob);
}

void Menu() {

  Noh *inicio = NULL;
  Noh *fim = NULL;
  Noh *aux;
  Noh *node;

  NohT *inicioT = NULL;
  NohT *fimT = NULL;
  NohT *auxT;
  NohT *nodeT;

  int selec, sw = 1, val;

  printf("Exercício 02 - Projeto Final, Igor e Lucas\n");
  printf("1- Definir limite da Fila\n");
  printf("2- Enfileirar\n");
  printf("3- Desenfileirar\n");
  printf("4- Status da Fila (isfull) \n");
  printf("5- Exibir elementos\n");
  printf("6- Consultar existencia de elemento\n");

  while (sw == 1) {

    printf("\nOpção: ");
    scanf("%d", &selec);

    switch (selec) {

    case 1:

      LimMax();
      break;

    case 2:

      if (cont_glob < limmax) {

        printf("\nInserção de valor na fila:");
        printf("\nDigite um valor a ser inserido: ");
        scanf("%d", &val);
        enfileirar(inicio, fim, val);

        cont_glob++;

        printf("\nValor inserido na fila");

      } else if (cont_glob >= limmax) {

        printf("\nNão é possível inserir valores, fila cheia.\n");
      }

      break;

    case 3:

      desenfileirar(inicio, fim);
      printf("\nValor removido da fila com sucesso.\n");

      cont_glob--;

      break;

    case 4:

      StatusFila();

      break;

    case 5:

      mostrarFila(inicio, fim);

      break;

    case 6:

      printf("Digite um valor para procurar:");
      scanf("%d", &val);
      consulta(inicio, fim, inicioT, fimT, val);

      break;
    }
  }
}

int main() { Menu(); }