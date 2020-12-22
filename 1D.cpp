#include <stdio.h>
#include <stdlib.h>

struct Node {
  int angka;
  Node *next;
} *head, *tail;

Node *createNode(int angka) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->angka = angka;
  newNode->next = NULL;
  return newNode;
}

void pushTail(int angka) {
  Node *temp = createNode(angka);

  if(!head) {
    head = tail = temp;
  } else {
    tail->next = temp;
    tail = temp;
  }
}

void deleteDuplicate(){
  Node *curr = head, *temp;

  if(curr == NULL){
    return;
  }

  while(curr->next != NULL) {
    if(curr->angka == curr->next->angka){
      temp = curr->next->next;
      free(curr->next);
      curr->next = temp;
    } else {
      curr = curr->next;
    }
  }
}

void printLinkedList(){
  Node *curr = head;

  while(curr) {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  pushTail(5);
  pushTail(5);
  pushTail(5);
  pushTail(13);
  pushTail(45);
  pushTail(46);

  printf("BEFORE:\n");
  printLinkedList();

  deleteDuplicate();

  printf("AFTER:\n");
  printLinkedList();

  return 0;
}