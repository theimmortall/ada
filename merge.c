#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


void merge(int arr[], int lb, int mid, int ub) {
    int i = lb;
    int j = mid + 1;
    int k = lb;
    int b[ub + 1];

    while (i <= mid && j <= ub) {
        if (arr[i] <= arr[j]) {
            b[k] = arr[i];
            i++;
        } else {
            b[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        b[k] = arr[i];
        i++;
        k++;
    }

    while (j <= ub) {
        b[k] = arr[j];
        j++;
        k++;
    }

    // Copy the merged elements back to the original array
    for (i = lb; i <= ub; i++) {
        arr[i] = b[i];
    }
}

void merge_sort(int arr[], int lb, int ub){
    if(lb<ub){
        int mid = (lb+ub)/2;
        merge_sort(arr,lb,mid);
        merge_sort(arr, mid+1, ub);
        merge(arr,lb,mid,ub);
    }
}

void printarray(int arr[], int num)
{
    int i;
    for (i = 0; i < num; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int num;
    printf("Enter the total number of element:");
    scanf("%d", &num);
    int arr[num];
    printf("Enter the elements:");
    for (int j = 0; j < num; j++)
    {
        scanf("%d", &arr[j]);
    }
    merge_sort(arr,0,num-1);
    printarray(arr,num);

    return 0;
}