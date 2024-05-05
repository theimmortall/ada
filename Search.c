#include <stdio.h>

void linear_search(int arr[], int len, int element)
{
    int found = 0; // A flag to check if the element is found

    for (int i = 0; i < len; i++)
    {
        if (arr[i] == element)
        {
            printf("Element at index: %d", i);
            found = 1; // Set the flag to true
            break;
        }
    }

    if (!found)
    {
        printf("Element not present");
    }
}

void binary_search(int arr[], int n, int data)
{
    int s = 0;
    int e = n - 1;
    int m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (arr[m] == data)
        {
            printf("Element present at index %d", m); // Element found, return its index.
            return;
        }
        else if (data > arr[m])
        {
            s = m + 1;
        }
        else
        {
            e = m - 1;
        }
    }
    printf("\nElement not present"); // Element not found.
}

int main()
{
    int len, element;
    int arr[20];
    int ch;
    char cha;
    printf("\nNote:- For Binary Search enter sorted array\n");
    printf("Enter length of array:");
    scanf("%d", &len);
    printf("Enter the values in array:");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search:");
    scanf("%d", &element);
   do{
    printf("\nEnter your Choice:\n");
    printf("\n1.Linear Search");
    printf("\n2.Binary Search\n");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
    {
        linear_search(arr,len,element);
        break;
    }

    case 2:
    {
        binary_search(arr,len,element);
        break;
    }

    default:
    {
        printf("Wrong choice");
        break;
    }
    }
    fflush(stdin);
    printf("\nEnter Y or y if u want to continue.....\n");
    scanf("%c", &cha);

   }while(cha=='y'||ch=='Y');
    return 0;
}