#include <stdio.h>

double findMedianSortedArrays(int *nums1, int *nums2, int length)
{
    int left1 = 0, left2 = 0;
    int right1 = length - 1, right2 = length - 1;
    int median1 = nums1[(left1 + right1) / 2];
    int median2 = nums2[(left2 + right2) / 2];
    while (left1 < right1 || left2 < right2)
    {
        int median1 = nums1[(left1 + right1) / 2];
        int median2 = nums2[(left2 + right2) / 2];
        if (median1 < median2)
        {
            // 舍弃nums1的左半部分(不包括中间元素)，舍弃nums2的右半部分(不包括中间元素)
            left1 = (left1 + right1 + 1) / 2;
            right2 = (left1 + right1) / 2;
        }
        else if (median1 > median2)
        {
            // 舍弃nums1的右半部分(不包括中间元素)，舍弃nums2的左半部分(不包括中间元素)
            left2 = (left2 + right2 + 1) / 2;
            right1 = (left1 + right1) / 2;
        }
        else
        {
            return median1;
        }
        median1 = nums1[(left1 + right1) / 2];
        median2 = nums2[(left2 + right2) / 2];
    }
    return median1 < median2 ? median1 : median2;
}