#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n;
int a[N];
int b[N];

bool judge(int x)
{
    if (x == 1)
        return true;
    for (int i = 1; i < x; i++)
        b[i] = a[i];
    std::sort(b + 1, b + x);
    int y = n - x;
    for (int i = 1; i < x; i++, y++)
        if (b[i] > y)
            return false;
    return true;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    int L = 0, R = n, res;
    while (L <= R)
    {
        int mid = (L + R) / 2;
        if (judge(mid))
            res = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%d", n - res);
    return 0;
}