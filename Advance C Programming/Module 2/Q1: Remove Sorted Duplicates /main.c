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
  struct node* current = head;

  while (current != NULL && current->next != NULL) {
    if (current->data == current->next->data) {
      struct node* duplicate = current->next;
      current->next = duplicate->next;
      free(duplicate);
    } else {
      current = current->next;
    }
  }
}

int main(){
  int choice;
  while(1)
  {
      printf("\n*****\n");
      printf("1. Create\n");
      printf("2. display\n");
      printf("3. remove duplicate\n");

    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: create();
          break;
      case 2: display();
          break;
      case 3: removeduplicate(head);
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
