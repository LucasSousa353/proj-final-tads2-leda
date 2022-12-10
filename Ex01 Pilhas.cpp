#include <iostream>
#include <stdio.h>
#include <stdlib.h>

int cont_glob = 0, limmax;

struct Node {
  int Number;
  struct Node *next;
};
struct Node2 {
  int Number;
  struct Node *next;
};

void LimMax() {
  printf("\nDigite a altura máxima da pilha: ");
  scanf("%d", &limmax);
  printf("\nDefinido!\n");
}

void push(struct Node *&topo, int dado) {
struct Node *novo = (struct Node *)calloc(1, sizeof(struct Node));
  if (topo) {
    novo->Number = dado;
    novo->next = topo->next;
    topo->next = novo;
  }
}

int pop(struct Node *&topo) {
  if (topo) {
    Node *seguinte = topo->next;

    if (seguinte) {
      int val = seguinte->Number;
      topo->next = seguinte->next;
      free(seguinte);
      return val;
    }
  }
  return -1;
}

void Stack(struct Node *&topo) {
  if (cont_glob == 0) {
    printf("\nPilha vazia.\n");
  } else {
    printf("\nExibir pilha:\n");
    struct Node *aux = topo->next;
    while (aux != NULL) {
      printf("\n%d", aux->Number);
      aux = aux->next;
    }
  }
}

void StatusPilha() {
  printf("\nStatus da pilha:\n");
  if (cont_glob == 0) {
    printf("A pilha está vazia.\n");
  } else
    printf("A pilha não está vazia.\n");

  printf("Há %d elementos na pilha.\n", cont_glob);
}

void Consulta(struct Node *&topo, int dado){
  int sw = 0, x;
  struct Node *aux = topo;
  struct Node *temp = (struct Node *)calloc(1, sizeof(struct Node));
  temp->next = NULL;

  while (topo->next != NULL) {
    int t = pop(topo);
    if (dado != t) {
      push(temp, t);
    } else {
      sw=1;
      push(temp, t);
      break;
    }
    aux = aux->next;
  }
  
  aux = temp;
  while (temp->next != NULL) {
    x = pop(temp);
    if( x != -1) push(topo, x);
    aux = aux->next;
  }

  if (sw == 0) {
    printf("\nValor não encontrado\n");
  } else {
    printf("\nValor encontrado.\n");
  }
}

void Menu() {
  struct Node *topo = (struct Node *)calloc(1, sizeof(struct Node));
  topo->next = NULL;
  int selec, sw = 1, val;

  printf("Exercício 01 - Projeto Final, Igor e Lucas\n");
  printf("1- Definir limite da pilha\n");
  printf("2- Push\n");
  printf("3- Pop\n");
  printf("4- Status da pilha\n");
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
        printf("\nInserção de valor na pilha:");
        printf("\nDigite um valor a ser inserido: ");
        scanf("%d", &val);
        push(topo, val);
        cont_glob++;
        printf("\nValor inserido na pilha");
      } else if (cont_glob >= limmax) {
        printf("\nNão é possível inserir valores, pilha cheia.\n");
      }
      break;

    case 3:
      pop(topo);
      printf("\nValor removido do topo com sucesso.\n");
      cont_glob--;
      break;

    case 4:
      StatusPilha();
      break;

    case 5:
      Stack(topo);
      break;

    case 6:
      printf("Digite um valor para procurar:");
      scanf("%d", &val);
      Consulta(topo, val);
      break;
    }
  }
}

int main() {
  
  struct Node *topo = (struct Node *)calloc(1, sizeof(struct Node));
  topo->next = NULL;

  Menu();

}
