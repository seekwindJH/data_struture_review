#include "./head/LL.h"
/*
    @Description: Print the Element in Linked List in reverse.
*/
void reverseOutput(LL *L)
{
    if (L->next)
    {
        reverseOutput(L->next);
    }
    printf("%d ->", L->val);
}
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    LL *L = createLL(a, 7);
    printLL(L);
    reverseOutput(L);
    puts(" NULL");
}