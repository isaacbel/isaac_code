#include <stdio.h>
#include <stdlib.h>
int main(){

    int size = 5;
    // Allocate memory for 5 integers
    int *arr2 = (int*) malloc(size * sizeof(int));
    
    int *arr1 = (int *)calloc(size, sizeof(int));;

    if (arr1 == NULL || arr2 == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Print the allocated array
    printf("\nThe first array using calloc : \n");
    for (int i = 0; i < size; i++) {
        printf("Enter the element T[%d] = %d \n", i+1,arr1[i]);
    }
    printf("\nThe seconde array using malloc : \n");
    for(int i = 0; i < size; i++) {
        printf("Enter the element T[%d]  = %d \n", i + 1,arr2[i]); 
        
    }
    // Free the allocated memory
    free(arr1);
    free(arr2);

    return 0;   
}