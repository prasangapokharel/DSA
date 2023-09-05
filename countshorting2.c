#include <stdio.h>
#include <conio.h>

#define MAX 20

int getDigitCount(int n)
{
    int count = 0;
    while (n > 0)
    {
        n = n / 10;
        count++;
    }
    return count;
}

int getMaxDigitCount(int arr[], int n)
{
    int max = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return getDigitCount(max);
}

void countsort(int arr[], int n, int pos)
{
    int temp[MAX];
    int count[10] = {0};
    int i;
    
    for (i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }
    
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }
    
    for (i = n - 1; i >= 0; i--)
    {
        temp[--count[(arr[i] / pos) % 10]] = arr[i];
    }
    
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void radixSort(int arr[], int n)
{
    int maxDigits = getMaxDigitCount(arr, n);
    for (int pos = 1; maxDigits / pos > 0; pos *= 10)
    {
        countsort(arr, n, pos);
    }
}

int main()
{
    int arr[MAX], n, i;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    radixSort(arr, n);
    
    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
