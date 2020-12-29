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

void printMiddle() {
  Node *slow  = head, *fast = head;

  if(head != NULL) {
    while(fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
      slow = slow->next;
    }
    printf("Middle: %d\n", slow->angka);
  }
}

void printLinkedList(){
  Node *curr = head;

  while(curr){
    printf("%d ", curr->angka);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  for(int i=4; i>=1; i--){
    pushHead(i);
  }

  printLinkedList();
  printMiddle();

  return 0;
}