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

int checkLoop() {
  Node *slow = head, *fast = head;

  while(slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if(slow == fast) {
      return 1;
    }
  }
  
  return 0;
}

int main() {
  pushTail(5);
  pushTail(10);
  pushTail(21);
  pushTail(11);

  head->next->next->next->next = head;
  
  if(checkLoop()){
    printf("Cycle\n");
  } else {
    printf("No Cycle\n");
  }
 
  return 0;
}