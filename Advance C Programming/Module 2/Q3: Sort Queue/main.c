#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node *front, *rear;
};

struct Node* newNode(int data); 
struct Queue* createQueue();
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int data);
int dequeue(struct Queue* queue);
void displayQueue(struct Queue* queue);

void sort_queue(struct Queue* queue) {
  struct Node *i, *j;
  int temp;

  if (queue->front == NULL)
    return;

  for (i = queue->front; i->next != NULL; i = i->next) {
    for (j = i->next; j != NULL; j = j->next) {
      if (i->data > j->data) {
        temp = i->data;
        i->data = j->data;
        j->data = temp;
      }
    }
  }
}

int main(){
  int choice;
  struct Queue* queue = createQueue();
  while(1)
  {
      printf("\n*****\n");
      printf("1. Enqueue\n");
      printf("2. display Queue\n");
      printf("3. Sort Queue\n");

    printf("\n Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:{
        int temp;
        printf("Enter the element to be enqueued: ");
        scanf( "%d", &temp);
        enqueue(queue, temp);
        break;
      }
      case 2: 
        displayQueue(queue);
        break;
      case 3: 
        sort_queue(queue);
        break;
      default: printf("Invalid");
    }
  }
}
struct Node* newNode(int data) {
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  if(temp == NULL){
    printf("Error: Memory allocation failed\n");
    exit(1);
  }
  temp->data = data;
  temp->next = NULL;
  return temp;
}

struct Queue* createQueue() {
  struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
  if(queue == NULL){
    printf("Error: Memory allocation failed\n");
    exit(1);
  }
  queue->front = queue->rear = NULL;
  return queue;
}

int isEmpty(struct Queue* queue) {
  return queue->front == NULL;
}

void enqueue(struct Queue* queue, int data) {
  struct Node* temp = newNode(data);
  if (queue->rear == NULL) {
    queue->front = queue->rear = temp;
    return;
  }
  queue->rear->next = temp;
  queue->rear = temp;
}

int dequeue(struct Queue* queue) {
  if (queue->front == NULL) {
    printf("Queue is empty\n");
    return -1;
  }
  struct Node* temp = queue->front;
  int data = temp->data;
  queue->front = queue->front->next;
  if (queue->front == NULL) {
    queue->rear = NULL;
  }
  free(temp);
  return data;
}

void displayQueue(struct Queue* queue) {
    struct Node* temp = queue->front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
