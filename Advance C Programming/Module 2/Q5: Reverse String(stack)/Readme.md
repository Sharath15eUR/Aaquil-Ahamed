# Q5: Reverse the given string using stack


### Approch
> Push Each charater into the stack then pop it while assign it the string

### Solution
```C
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
```

### Compiler/Environment
Run it the online Compiler - [Rotate_Linked_List.C](https://replit.com/@AaquilAhamed/Q5-String-ReverseStack#main.c)
