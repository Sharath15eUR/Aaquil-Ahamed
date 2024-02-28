#include <stdio.h>
#include <stdlib.h>

int main() 
{
  int n;

  scanf("%d", &n);


  int **a = (int **)malloc(n * sizeof(int *));
  int **b = (int **)malloc(n * sizeof(int *));
  int **c = (int **)malloc(n * sizeof(int *));
  
  if (a == NULL || b == NULL || c == NULL) {
    printf("Memory allocation failed.\n");
    return 1;
  }
  
  for (int i = 0; i < n; i++) {
    a[i] = (int *)malloc(n * sizeof(int));
    b[i] = (int *)malloc(n * sizeof(int));
    c[i] = (int *)malloc(n * sizeof(int));
    if (a[i] == NULL || b[i] == NULL || c[i] == NULL){
      printf("Memory allocation failed.\n");
      return 1;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &b[i][j]);
    }
  }
  
  printf("The array a is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", a[i][j]);
    }
    printf("\n");
  }
  
  printf("The array b is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", b[i][j]);
    }
    printf("\n");
  }
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c[i][j] = 0;
      for(int x =0 ; x<n; x++){
        c[i][j] += a[i][x]*b[x][j]; 
      }
    }
  }

  printf("\nThe Product Array is:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
  

  for (int i = 0; i < n; i++) {
      free(a[i]);
      free(b[i]);
      free(c[i]);
  }
  free(a);
  free(b);
  free(c);

  return 0;
}
