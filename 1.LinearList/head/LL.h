#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList
{
    int val;
    struct LinkedList *next;
} LL;
LL *createLL(int *list, int length)
{
    LL *head = (LL *)malloc(sizeof(LL));
    LL *cur = head;
    for (int i = 0; i < length; i++)
    {
        cur->val = list[i];
        if (i < length - 1)
        {
            cur->next = (LL *)malloc(sizeof(LL));
            cur = cur->next;
        }
        else
        {
            cur->next = NULL;
        }
    }
    return head;
}
void printLL(LL *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->val);
        head = head->next;
    }
    printf("NULL\n");
}