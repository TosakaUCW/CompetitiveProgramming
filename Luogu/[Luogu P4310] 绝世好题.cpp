#include <stdio.h>
#include <algorithm>
#include <memory.h>

const int N = 1e5 + 5;

int n;
int a[N];
int f[N], max;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]), f[i] = 1;
    for (int i = 1; i <= n; max = std::max(max, f[i++]))
        for (int j = i - 1; j; j--)
            if (f[i] > max)
                break;
            else if ((a[j] & a[i]) != 0)
                f[i] = std::max(f[i], f[j] + 1);
    printf("%d", max);
    return 0;
}