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

struct node* insert(struct node* Headnode){
  struct node* temp;
  temp = (struct node*)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  printf("Enter node data: ");
  scanf("%d",&temp->data); 
  temp->next = NULL;
  temp->prev = NULL;
  if(Headnode==NULL)	{
    Headnode = temp;
    Headnode->prev = NULL;
    Headnode->next = NULL;
  }
  else{
    struct node* ptr = Headnode;
    while (ptr->next != NULL && temp->data > ptr->data) {
      ptr = ptr->next;
    }

    if(ptr == Headnode){
      temp->next = ptr;
      ptr->prev = temp;
      Headnode = temp;
    }
    else if(ptr->next ==  NULL && temp->data >= ptr->data){
      ptr->next = temp;
      temp->prev = ptr;
    }
    else{
    ptr->prev->next =temp;
    temp->prev = ptr->prev;
    ptr->prev = temp;
    temp-> next = ptr;
    }
  }
  return Headnode;
}

int main(){
  int choice;
  while(1)
  {
      printf("\n*****\n");
      printf("1. Insert\n");
      printf("2. Display\n");

    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: head = insert(head);
          break;
      case 2: display();
          break;
      default: printf("Invalid");
    }
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
