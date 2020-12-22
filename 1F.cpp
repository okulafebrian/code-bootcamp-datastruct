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

void sortDescending(){
  Node *curr = head, *idx = curr->next, *temp;

  while(curr != NULL){
    if(curr->angka < idx->angka){
      temp->angka = curr->angka;
      curr->angka = idx->angka;
      idx->angka = temp->angka;
    }
    
    curr = curr->next;
    idx = idx->next;
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
  for(int i=1; i<=5; i++) {
    pushTail(i);
  }

  printLinkedList();
  sortDescending();
  printLinkedList();

  return 0;
}