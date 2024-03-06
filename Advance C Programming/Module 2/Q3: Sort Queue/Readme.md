# Q3: Write a C program to sort the elements of a queue in ascending order


### Approch
> Variation of Bubble sort 

### Solution
```C
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
```

### Compiler/Environment
Run it the online Compiler - [Sort_Queue.C](https://replit.com/@AaquilAhamed/Q3-Sort-Queue#main.c)
