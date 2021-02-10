#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50

// 长度动态的顺序表
typedef struct
{
    int *data;
    int length;
} SeqList;

// 初始化动态顺序表函数
void initDynamicSeqList(SeqList *list, int initSize)
{
    // 顺序表长度赋值
    list->length = initSize;
    // 顺序表数组初始化
    list->data = (int *)malloc(sizeof(int) * initSize);
}

// 翻转数组
void reverse(SeqList *list, int start, int end)
{
    for (int i = 0; i < (end - start + 1) / 2; i++)
    {
        int t = list->data[start + i];
        list->data[start + i] = list->data[end - i];
        list->data[end - i] = t;
    }
}

/*
    Function: rotate
    Description: 数组元素向左循环挪动p位。
    Complex: T(n) = O(2n) = O(n)
             S(n) = O(1)
 
*/
void rotateArr(SeqList *list, int p)
{
    // 翻转整个数组
    reverse(list, 0, list->length - 1);
    // 翻转前半部分
    reverse(list, 0, p - 1);
    // 翻转后半部分
    reverse(list, p, list->length - 1);
}

int main()
{
    // 初始化
    SeqList *list = (SeqList *)malloc(sizeof(SeqList));
    initDynamicSeqList(list, 5);

    // 数组赋值
    for (int i = 0; i < list->length; i++)
    {
        list->data[i] = i + 1;
    }

    // 旋转数组
    rotateArr(list, 3);

    // 输出数组
    for (int i = 0; i < list->length; i++)
    {
        printf("%d,  ", list->data[i]);
    }
    printf("\n");
    return 0;
}