#include <stdio.h>
#include <stdlib.h>

int findNum(int *arr, int length)
{
    int *mark;
    mark = (int *)malloc(sizeof(int) * length);
    for (int i = 0; i < length; i++)
        mark[i] = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > 0 && arr[i] <= length)
        {
            mark[arr[i] - 1] = 1;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (!mark[i])
            return i + 1;
    }
    return length + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int minNum = findNum(arr, 4);
    printf("min num is %d", minNum);
}