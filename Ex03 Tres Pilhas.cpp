#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int cont_glob = 0, limmax;

struct Pilha {
  int Number;
  struct Pilha *next;
} pilha;

struct Pilha2 {
  int Number2;
  struct Pilha2 *next;
} pilha2;

struct Pilha3 {
  int Number3;
  struct Pilha3 *next;
} pilha3;

struct Pilha4 {
  int Number4;
  struct Pilha4 *next;
} pilha4;

void push(struct Pilha *&topo, int dado) {
  struct Pilha *novo = (struct Pilha *)calloc(1, sizeof(struct Pilha));
  if (topo) {
    novo->Number = dado;
    novo->next = topo->next;
    topo->next = novo;
  }
}

void push2(struct Pilha2 *&topo2, int dado2) {
  struct Pilha2 *novo2 = (struct Pilha2 *)calloc(1, sizeof(struct Pilha2));
  if (topo2) {
    novo2->Number2 = dado2;
    novo2->next = topo2->next;
    topo2->next = novo2;
  }
}

void push3(struct Pilha3 *&topo3, int dado3) {
  struct Pilha3 *novo3 = (struct Pilha3 *)calloc(1, sizeof(struct Pilha3));
  if (topo3) {
    novo3->Number3 = dado3;
    novo3->next = topo3->next;
    topo3->next = novo3;
  }
}
void push4(struct Pilha4 *&topo4, int dado4) {
  struct Pilha4 *novo4 = (struct Pilha4 *)calloc(1, sizeof(struct Pilha4));
  if (topo4) {
    novo4->Number4 = dado4;
    novo4->next = topo4->next;
    topo4->next = novo4;
  }
}

int pop(struct Pilha *&topo) {
  if (topo) {
    Pilha *seguinte = topo->next;
    if (seguinte) {
      int val = seguinte->Number;
      topo->next = seguinte->next;
      free(seguinte);
      return val;
    }
  }
  return -1;
}

int pop2(struct Pilha2 *&topo2) {
  if (topo2) {
    Pilha2 *seguinte = topo2->next;
    if (seguinte) {
      int val = seguinte->Number2;
      topo2->next = seguinte->next;
      free(seguinte);
      return val;
    }
  }
  return -1;
}
int pop3(struct Pilha3 *&topo3) {
  if (topo3) {
    Pilha3 *seguinte = topo3->next;
    if (seguinte) {
      int val = seguinte->Number3;
      topo3->next = seguinte->next;
      free(seguinte);
      return val;
    }
  }
  return -1;
}
int pop4(struct Pilha4 *&topo4) {
  if (topo4) {
    Pilha4 *seguinte = topo4->next;
    if (seguinte) {
      int val = seguinte->Number4;
      topo4->next = seguinte->next;
      free(seguinte);
      return val;
    }
  }
  return -1;
}

void Exibir1(struct Pilha *&topo) {

  printf("\nExibir pilha 1:");
  struct Pilha *aux = topo->next;
  while (aux != NULL) {
    printf("\n%d", aux->Number);
    aux = aux->next;
  }
}

void Exibir2(struct Pilha2 *&topo2) {

  printf("\n\nExibir pilha 2:");
  struct Pilha2 *aux2 = topo2->next;
  while (aux2 != NULL) {
    printf("\n%d", aux2->Number2);
    aux2 = aux2->next;
  }
}

void Exibir3(struct Pilha3 *&topo3) {

  printf("\n\nExibir pilha 3:");
  struct Pilha3 *aux3 = topo3->next;
  while (aux3 != NULL) {
    printf("\n%d", aux3->Number3);
    aux3 = aux3->next;
  }
}
void Exibir4(struct Pilha4 *&topo4) {

  printf("\n\nExibir pilha 4:");
  struct Pilha4 *aux4 = topo4->next;
  while (aux4 != NULL) {
    printf("\n%d", aux4->Number4);
    aux4 = aux4->next;
  }
}

int main() {

  struct Pilha *topo = (struct Pilha *)calloc(1, sizeof(struct Pilha));
  struct Pilha2 *topo2 = (struct Pilha2 *)calloc(1, sizeof(struct Pilha2));

  push(topo, 100);
  push(topo, 80);
  push(topo, 60);
  push(topo, 40);
  push(topo, 20);

  push2(topo2, 90);
  push2(topo2, 70);
  push2(topo2, 50);
  push2(topo2, 30);
  push2(topo2, 10);

  Exibir1(topo);
  Exibir2(topo2);

  printf("\n\nCriando pilha 3...\n");

  struct Pilha3 *topo3 = (struct Pilha3 *)calloc(1, sizeof(struct Pilha3));
  struct Pilha4 *topo4 = (struct Pilha4 *)calloc(1, sizeof(struct Pilha4));
  struct Pilha *aux = topo->next;
  struct Pilha2 *aux2 = topo2->next;
  struct Pilha3 *aux3 = topo3->next;
  struct Pilha4 *aux4 = topo4->next;

  int x = 0, y = 0, z = 0;
  int dado1[x], dado2[y], dado3[z];

  while (aux != NULL && aux2 != NULL) {

    dado1[x] = aux->Number;
    printf("\n%d - dado1", dado1[x]);
    push3(topo3, dado1[y]);
    aux = aux->next;
    x++;

    dado2[y] = aux2->Number2;
    printf("\n%d - dado2", dado2[y]);
    push3(topo3, dado2[y]);
    aux2 = aux2->next;
    y++;
  }
Exibir4(topo4);
}