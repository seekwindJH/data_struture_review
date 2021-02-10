#include <stdio.h>

int getMainElement(int *arr, int length)
{
    int n = 0;
    int candidate = arr[0];
    for (int i = 0; i < length; ++i)
    {
        if (candidate == arr[i])
            n++;
        else
        {
            if (n)
            {
                n--;
            }
            else
            {
                n = 1;
                candidate = arr[i];
            }
        }
    }
    n = 0;
    for (int i = 0; i < length; ++i)
    {
        if (candidate == arr[i])
            n++;
    }
    return n > length / 2 ? candidate : -1;
}
int main()
{
    int a[] = {1, 5, 0, 5, 5};
    int mainElem = getMainElement(a, 5);
    printf("Main Element is %d", mainElem);
    return 0;
}