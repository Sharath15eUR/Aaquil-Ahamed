# Q4: Write an equivalent pointer expression for fetching the value of array element a[i][j][k][2]

### Solution
```C
*(*(*(*(a + i) + j) + k) + 2)
```

### Explaination
a is 4D array so, 
Add i to a to get the ith 3D array, 
Add j to that will get the jth 2D array within the ith 3D array, 
Add k to that will  get the kth 1D array within the jth 2D array and 
Adding 2 will access the value at index 2 within the kth 1D array.
