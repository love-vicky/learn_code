//二分查找重复项有序数组，返回指定值的下标区间

#include <stdio.h>

void binary_search(int *list, int len, int n, int *range)
{
    int left = 0;
    int right = len - 1;
    int mid = 0;
    int back = 0;
    int forword = 0;

    while (left <= right)
    {
        mid = (left + right) / 2;
        if (list[mid] > n)
        {
            right = mid - 1;
        }
        else if (list[mid] < n)
        {
            left = mid + 1;
        }
        else
        {
            back = mid;
            forword = mid;
            while (back >= 0)
            {
                if (list[back] != n)
                {
                    break;
                }
                back--;
            }

            range[0] = back + 1;

            while (forword <= len - 1)
            {
                if (list[forword] != n)
                {
                    break;
                }
                forword++;
            }
            range[1] = forword - 1;
            return;
        }
    }

}

int main()
{
    int i = 0;
    int a[10] = {23,44,44,44,55,65,65,65,76,81};
    int range[2] = {0};
    binary_search(a, 10, 65, range);
    printf("[");
    for (;i < 2;i++)
    {
        printf("%d", range[i]);
        if (i != 2 - 1)
        {
            printf(",");
        }
    }
    printf("]");

    return 0;
}