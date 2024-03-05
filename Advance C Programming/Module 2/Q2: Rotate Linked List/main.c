#include <stdio.h>
#include<stdlib.h>
void create();
void display();
struct node* head = NULL;
struct node
{
  int data;
  struct node* next;
  struct node* prev;
};

struct node* Rotate(struct node* head) {
  int n;
  printf("Enter the number of nodes to be rotated: ");
  scanf("%d", &n);

  if (head == NULL || n == 0) {
    return head;
  }
  struct node* ptr = head;
  while (ptr->next != NULL) {
    ptr = ptr->next;
  }

  ptr->next = head;
  head->prev = ptr;

  if (n > 0) {
    while (n--) {
      head = head->next;
    }
  } else {
    n = -n;
    while (n--) {
      head = head->prev;
    }
}
  head->prev->next = NULL;
  head->prev = NULL;

  return head;
}

int main(){
  int choice;
  while(1)
  {
      printf("\n*****\n");
      printf("1. Create\n");
      printf("2. display\n");
      printf("3. Rotate Nodes\n");

    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: create();
          break;
      case 2: display();
          break;
      case 3: head = Rotate(head);
          break;
      default: printf("Invalid");
    }
  }
}
void create(){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  printf("Enter node data: ");
  scanf("%d",&temp->data); 
  temp->next = NULL;
  if(head==NULL)	{
    head = temp;
    head->prev = NULL;
  }
  else{
    struct node* ptr = head;
    while(ptr->next!=NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
  }
}

void display(){
  if(head==NULL)
  {
    printf("Linked List is Empty\n");
    return;
  }
  printf("LinkedList: \n");
  struct node* ptr = head;
  while(ptr!=NULL)
  {
    printf("%d->",ptr->data);
    ptr = ptr->next;
  }
  printf("NULL\n");
}
