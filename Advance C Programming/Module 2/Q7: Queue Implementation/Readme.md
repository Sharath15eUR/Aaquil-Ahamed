# Q7: Write a C program to insert/delete and count the number of elements in a queue. 

### Approch
> Used Switch Case to get Choice from User and used linked list to implement Queue 

### Solution
```C
struct Node {
  int data;
  struct Node* next;
};

struct Queue {
  struct Node *front, *rear;
};

int size=0;
struct Node* newNode(int data); 
struct Queue* createQueue();
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int data);
int dequeue(struct Queue* queue);
void displayQueue(struct Queue* queue);

int main(){
  int choice;
  struct Queue* queue = createQueue();
  printf("Initialized Queue!\n");
  while(1)
  {
      printf("\n*****\n");
      printf("1. Insert Element\n");
      printf("2. Delete Element\n");
      printf("3. Queue is empty or not?\n");
      printf("4. Number of elements in queue?\n");
      printf("5. Display Queue\n");

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
        dequeue(queue);
        break;
      case 3: {
        if(isEmpty(queue)) 
          printf("Queue is empty!\n");
        else
          printf("Queue is not empty!\n");
        break;
      }
      case 4:
        printf("Size of queue is %d\n",size);
        break;
      case 5:
        displayQueue(queue);
        break;
      default: printf("Invalid");
    }
  }
}
```

### Compiler/Environment
Run it the online Compiler - [Queue_Implementation.C](https://replit.com/@AaquilAhamed/Q7-Queue-Implementation#main.c)
