# Q1: Write a C program to remove duplicate element from sorted Linked List. 


### Approch
> check current node and next node date 

### Solution
```C
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
```

### Compiler/Environment
Run it the online Compiler - [Remove_Sorted_Duplicates.C](https://replit.com/@AaquilAhamed/Module-2-Assignment#Q1:Remove%20Sorted%20Duplicates.c)
