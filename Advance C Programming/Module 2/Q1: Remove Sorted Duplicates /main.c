#include <stdio.h>
#include<stdlib.h>
void create();
void display();
struct node* head = NULL;
struct node
{
  int data;
  struct node* next;
};

void removeduplicate(struct node* head){
  struct node* temp = head;
  while(temp->data != temp->next->data) temp = temp->next;
  struct node* duplicate = temp->next;
  temp->next = duplicate->next;
  free(duplicate);
}

int main()
{
  int choice;
  while(1)
  {
      printf("\n*****\n");
      printf("0. Create\n");
      printf("1. display\n");
      printf("2. remove duplicate\n");

    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 0: create();
          break;
      case 1: display();
          break;
      case 2: removeduplicate(head);
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
  }
  else{
    struct node* ptr = head;
    while(ptr->next!=NULL)
    {
      ptr = ptr->next;
    }
    ptr->next = temp;
  }
}


void display(){
  if(head==NULL)
  {
    printf("Linked List is Empty\n");
    return;
  }
        printf("LinkedList: ");
  struct node* ptr = head;
  while(ptr!=NULL)
  {
    printf("%d->",ptr->data);
    ptr = ptr->next;
  }
    printf("NULL\n");
}
