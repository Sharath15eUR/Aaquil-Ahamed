#include <stdio.h>
#include<stdlib.h>
char pop();
void push(char);
struct node* top = NULL;
int size =0;
struct node {
  char data;
  struct node *next;
}; 
 
void reverseString(char* str){
  for(char* ptr = str; *ptr!='\0'; ptr++){
    push(*ptr);
  }
  for(char* ptr= str; top !=NULL; ptr++){
    *ptr = pop();
  }
}

int main(void) {
  char *string = (char *)malloc(100 * sizeof(char));
  if (string == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  printf("Enter a string: ");
  fgets(string, 100, stdin);

  int len = strlen(string);
  if (string[len - 1] == '\n') {
      string[len - 1] = '\0';
  }
  printf("\nBefore Reverse: %s\n", string);
  reverseString(string);
  printf("After Reverse : %s\n", string);
  return 0;
}

void push(char data) {
  struct node* temp = (struct node *)malloc(sizeof(struct node));
  if (temp == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }

  temp->data = data;
  temp->next = top;
  top = temp;
  size++;
}

char pop() {
  if (top == NULL) {
    printf("\nEMPTY STACK");
    exit(1);
  } 
  else {
    struct node *temp = top;
    char info = top->data;
    top = top->next; 
    free(temp);
    size--;
    return info;
  }
}
