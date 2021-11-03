#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ARR_SIZE 10
#define BS_RAND_MIN 0
#define BS_RAND_MAX 10

/* In place sorting using a pre-malloced array */
void sort(int *array, int arraySize) {
  for(int i = 0; i < arraySize; i++) {
    for(int j = i + 1; j < arraySize; j++) {
      if(array[i] > array[j]) {
        int temp = array[i];

        array[i] = array[j];
        array[j] = temp;
      }
    }
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

  sort(array, ARR_SIZE);

  printf("The sorted array is: [ ");
  for(int i = 0; i < ARR_SIZE; i++) {
    i == ARR_SIZE - 1 ? printf("%d ]\n", array[i]) : printf("%d, ", array[i]);  
  }

  free(array);

  return 0;
}
