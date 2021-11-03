#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 10
#define BS_RAND_MIN 0
#define BS_RAND_MAX 10

void merge(int *array, int leftBound, int mid, int rightBound) {
  int leftSize = mid - leftBound + 1;
  int rightSize = rightBound - mid;
  int L[leftSize];
  int R[rightSize];
  int i = 0, j = 0, k = 0;

  for(i = 0; i < leftSize; i++) {
    L[i] = array[leftBound + i];
  }

  for(j = 0; j < rightSize; j++) {
    R[j] = array[mid + 1 + j];
  }

  i = 0;
  j = 0;
  k = leftBound;

  while(i < leftSize && j < rightSize) {
    if(L[i] <= R[j]) {
      array[k] = L[i];
      i++;
    }
    else {
      array[k] = R[j];
      j++;
    }

    k++;
  }

  while(i < leftSize) {
    array[k] = L[i];
    i++;
    k++;
  }

  while(j < rightSize) {
    array[k] = R[j];
    j++;
    k++;
  }
}

void partition(int *array, int leftBound, int rightBound) {
  if(leftBound < rightBound) {

    int mid = leftBound + (rightBound - leftBound) / 2;

    partition(array, leftBound, mid);
    partition(array, mid + 1, rightBound);

    merge(array, leftBound, mid, rightBound);
  }
}

int main() {
  int *array = NULL;

  array = malloc(sizeof(int) * ARR_SIZE);
  if(NULL == array) {
    return -1;
  }

  srand(time(NULL));

  printf("The original array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    array[i] = rand() % (BS_RAND_MAX - BS_RAND_MIN + 1) + BS_RAND_MIN;  
    
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);
  }

  partition(array, 0, ARR_SIZE - 1);

  printf("The sorted array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);  
  }

  free(array);

  return 0;
}
