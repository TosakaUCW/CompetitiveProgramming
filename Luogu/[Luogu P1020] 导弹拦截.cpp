#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n;
int a[N], s1[N], len1, s2[N], len2;

int main()
{
    while (scanf("%d", &a[++n]) != EOF)
        ;
    n--;
    s1[1] = s2[1] = a[1], len1 = len2 = 1;
    for (int i = 2; i <= n; i++)
    {
        if (s1[len1] >= a[i])
            s1[++len1] = a[i];
        else
        {
            int L = 1, R = len1, res;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (s1[mid] < a[i])
                    res = mid, R = mid - 1;
                else
                    L = mid + 1;
            }
            s1[res] = a[i];
        }
        if (s2[len2] < a[i])
            s2[++len2] = a[i];
        else
        {
            int L = 1, R = len2, res;
            while (L <= R)
            {
                int mid = (L + R) / 2;
                if (s2[mid] >= a[i])
                    res = mid, R = mid - 1;
                else
                    L = mid + 1;
            }
            s2[res] = a[i];
        }
    }
    printf("%d\n%d", len1, len2);
    return 0;
}
/*
8
38 27 55 30 29 70 58 65
*/