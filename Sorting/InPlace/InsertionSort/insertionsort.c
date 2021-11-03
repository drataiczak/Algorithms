#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 10
#define BS_RAND_MIN 0
#define BS_RAND_MAX 10

/* In place sorting using a pre-malloced array */
void sort(int *array, int arraySize) {
  int curr;
  int j;

  /* Start from the second element since we want to compare with the previous */
  for(int i = 1; i < arraySize; i++) {
    /* Get the current element and the index of the previous element */
    curr = array[i];
    j = i - 1;

    /* If we have a previous element and the current element is less than the previous element */
    while(j >= 0 && curr < array[j]) {
      /* Shift everything over if it is larger than the current element */
      array[j + 1] = array[j];
      j -= 1;
    }

    /* Set the next element to be the current element */
    array[j + 1] = curr;
  }
}

int main() {
  int *array = NULL;

  array = malloc(sizeof(int) * ARR_SIZE);
  srand(time(NULL));

  printf("The original array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    array[i] = rand() % (BS_RAND_MAX - BS_RAND_MIN + 1) + BS_RAND_MIN;  
    
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);
  }

  sort(array, ARR_SIZE);

  printf("The sorted array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);  
  }

  return 0;
}
