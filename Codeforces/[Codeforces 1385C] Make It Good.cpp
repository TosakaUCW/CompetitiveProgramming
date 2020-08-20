#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 2e5 + 5;

int n;
int a[N];

bool judge(int x)
{
    int p = x + 1, q = n;
    int now = 0;
    while (p <= q)
    {
        if (a[p] < a[q] and now <= a[p])
            now = a[p], p++;
        else if (a[p] < a[q] and now > a[p])
            return false;
        else if (a[p] > a[q] and now <= a[q])
            now = a[q], q--;
        else if (a[p] > a[q] and now > a[q])
            return false;
        else if (a[p] == a[q] and now <= a[q])
            now = a[q], q--, p++;
        else if (a[p] == a[q] and now > a[q])
            return false;
        // printf("x:%d  now:%d \n", now, x);
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int L = 0, R = n, res = 0;
        while (L <= R)
        {
            int mid = (L + R) / 2;
            if (judge(mid))
                res = mid, R = mid - 1;
            else
                L = mid + 1;
        }
        printf("%d\n", res);
    }
    return 0;
}