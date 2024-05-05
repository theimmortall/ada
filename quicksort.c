#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int lb, int ub)
{

    int pivot = arr[lb];
    int s = lb;
    int e = ub;

    while (s < e)
    {

        while (arr[s] <= pivot)
        {
            s++;
        }

        while (arr[e] > pivot)
        {
            e--;
        }
        if (s < e)
        {
            swap(&arr[s],&arr[e]);
        }
        
    }
    swap(&arr[lb],&arr[e]);
    return e;
}

void quicksort(int arr[], int lb, int ub)
{
    if (lb < ub)
    {
        int val;
        val = partition(arr, lb, ub);
        quicksort(arr, lb, val - 1);
        quicksort(arr, val + 1, ub);
    }
}

int main()
{
    int num, i, j;
    int arr[20];
    printf("Enter the number of element in array: ");
    scanf("%d", &num);
    printf("Enter the elements of array:");
    for (i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, num - 1);

    printf("Array after sorting\n");
    for (j = 0; j < num; j++)
    {
        printf("%d ", arr[j]);
    }

    return 0;
}