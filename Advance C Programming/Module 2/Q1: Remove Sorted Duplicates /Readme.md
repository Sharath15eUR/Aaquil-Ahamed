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
  struct node* temp = head;
  while(temp->data != temp->next->data) temp = temp->next;
  struct node* duplicate = temp->next;
  temp->next = duplicate->next;
  free(duplicate);
}
```

### Compiler/Environment
Run it the online Compiler - [Remove_Sorted_Duplicates.C](https://replit.com/@AaquilAhamed/Remove-Duplicate-Linked-List#main.c)
