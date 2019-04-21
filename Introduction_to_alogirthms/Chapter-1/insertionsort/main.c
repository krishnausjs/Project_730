#include <stdio.h>
void printArray(int arr[], int n)
{
    int i;
    printf("Printing array to sort using insertion sort is \n");
    for(i = 0; i < n; i++)
        printf("%d\t",arr[i]);    
    printf("\n");
}

void insertionSort(int arr[], int n)
{
    int i = 0, j = 0;
    int key = 0;
    
    for(j = 1;  j < n;  j++)
    {
        key = arr[j];
        i = j - 1;
        printf("Outer Loop: Value of i is %d and j is  %d , arr[%d] is %d , key is %d\n",i,j,i,arr[i],key);
        while (( i >= 0) && (arr[i] > key))
        {
            arr[i+1] = arr[i];
            printArray(arr,n);
            i = i - 1 ;
            printf("Inner Loop: Value of i is %d and j is  %d , arr[%d] is %d , key is %d\n",i,j,i,arr[i],key);
        }
        arr[i+1] = key;
    }
    printArray(arr,n);
}

int main(int argc, char **argv)
{
    int arr[20] = {5, 9, 2, 7, 1 ,3};
    int n = 6;
    int i = 0, j = 0;
    insertionSort(arr,n);
	return 0;
}
