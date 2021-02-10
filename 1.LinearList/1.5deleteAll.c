#include "./head/LL.h"
LL *deleteAll(LL *L, int x)
{
    while (L && L->val == x)
    {
        LL *t = L;
        L = L->next;
        free(t);
    }
    LL *precursor = L;
    LL *head = L;
    while (L)
    {
        if (L->val == x)
        {
            precursor->next = L->next;
            LL *t = L;
            L = L->next;
            free(t);
        }
        else
        {
            precursor = L;
            L = L->next;
        }
    }
    return head;
}
int main()
{
    int list[] = {5, 5, 1, 2, 5, 5, 3, 6};
    LL *head = createLL(list, 8);
    head = deleteAll(head, 5);
    printLL(head);
    return 0;
}