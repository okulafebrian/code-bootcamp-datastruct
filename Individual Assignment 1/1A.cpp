#include <stdio.h>
#include <stdlib.h>

struct Node {
  int angka;
  Node *next;
} *headA, *headB, *tailA, *tailB;

Node *createNode(int angka) {
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->angka = angka;
  newNode->next = NULL;
  return newNode;
}

void pushTailA(int angka) {
  Node *temp = createNode(angka);

  if(!headA) {
    headA = tailA = temp;
  } else {
    tailA->next = temp;
    tailA = temp;
  }
}

void pushTailB(int angka) {
  Node *temp = createNode(angka);

  if(!headB) {
    headB = tailB = temp;
  } else {
    tailB->next = temp;
    tailB = temp;
  }
}

void printLinkedListA(){
  Node *curr = headA;

  while(curr) {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
}

void printLinkedListB(){
  Node *curr = headB;

  while(curr) {
    printf("%d ", curr->angka);
    curr = curr->next;
  }
}

int main() {
  pushTailA(1);
  pushTailA(3);
  pushTailA(5);

  pushTailB(10);
  pushTailB(13);
  pushTailB(19);

  printLinkedListA();
  printLinkedListB();
  printf("\n");

  return 0;
}