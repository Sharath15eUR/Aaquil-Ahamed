#include <stdio.h>
#include <stdlib.h>

struct Node {
  char data;
  struct Node* next;
};

struct Stack {
  struct Node* top;
};

struct Node* newNode(char data);
struct Stack* createStack();
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char data);
char pop(struct Stack* stack);
char peek(struct Stack* stack);


void reverseString(char* str) {
  struct Stack* stack = createStack();
  for (char* ptr = str; *ptr != '\0'; ptr++) {
      push(stack, *ptr);
  }
  for (char* ptr = str; !isEmpty(stack); ptr++) {
      *ptr = pop(stack);
  }
  free(stack);
}

int main(void) {
    char* string = (char*)malloc(100 * sizeof(char));
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

    free(string); // Free dynamically allocated memory
    return 0;
}

struct Node* newNode(char data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  if (temp == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  temp->data = data;
  temp->next = NULL;
  return temp;
}

struct Stack* createStack() {
  struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
  if (stack == NULL) {
    printf("Memory allocation failed.\n");
    exit(1);
  }
  stack->top = NULL;
  return stack;
}

int isEmpty(struct Stack* stack) {
  return stack->top == NULL;
}

void push(struct Stack* stack, char data) {
  struct Node* temp = newNode(data);
  temp->next = stack->top;
  stack->top = temp;
}

char pop(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack underflow\n");
    exit(1);
  }
  struct Node* temp = stack->top;
  char data = temp->data;
  stack->top = temp->next;
  free(temp);
  return data;
}

char peek(struct Stack* stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    exit(1);
  }
  return stack->top->data;
}
