#include <stdio.h>
#include <stdlib.h>

int Subset(int array1[], int m, int array2[], int n) {
  if (n > m) return 0;

  int i, j;
  for (i = 0; i < n; i++) {
    int flag = 0;
    for (j = 0; j < m; j++) {
      if (array2[i] == array1[j]) {
        flag = 1;
        break;
      }
    }
    if (!flag) {
      return 0;
    }
  }
  return 1;
}

int main() {
  int m, n;

  printf("\nEnter the size of the Array: ");
  scanf("%d", &m);

  int Arr[m];
  for (int i = 0; i < m; i++) {
    printf("\nEnter the element %d: ", i);
    scanf("%d", &Arr[i]);
  }

  printf("\nEnter the size of the subset array: ");
  scanf("%d", &n);

  int Sub[n];
  for (int i = 0; i < n; i++) {
    printf("\nEnter the element %d: ", i);
    scanf("%d", &Sub[i]);
  }

  if (Subset(Arr, m, Sub, n))
    printf("Sub[] is a subset of Arr[]\n");
  else
    printf("Sub[] is not a subset of Arr[].\n");
  return 0;
}
