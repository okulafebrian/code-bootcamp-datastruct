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

void pushHead(int angka) {
  Node *temp = createNode(angka);

  if(!head){
    head = tail = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void printNth(int n){
  Node *target = head, *ref = head;

  int count = 0;
  if(head != NULL){
    while(count < n) {
      if(ref == NULL) {
        printf("WAIT\n");
        return;
      }
      ref = ref->next;
      count++;
    }

    if(ref == NULL) {
      head = head->next;
      if(head != NULL){
        printf("Target: %d\n", target->angka);
      }
    } else {
      while(ref != NULL){
        target = target->next;
        ref = ref->next;
      }
      printf("Target: %d\n", target->angka);
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

int main(){
  pushHead(29);
  pushHead(30);
  pushHead(22);
  pushHead(13);
  pushHead(9);

  printLinkedList();

  int n = 3;
  printNth(n);

  return 0;
}