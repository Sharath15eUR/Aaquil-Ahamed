# Q2: Write a C program to rotate a doubly linked list by N nodes


### Approch
> Make the list circular then break the list after moving n nodes

### Solution
```C
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
```

### Compiler/Environment
Run it the online Compiler - [Rotate_Linked_List.C](https://replit.com/@AaquilAhamed/Q2Rotate-Linked-List#main.c)
