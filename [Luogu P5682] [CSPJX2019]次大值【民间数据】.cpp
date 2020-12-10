#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + n);
    n = std::unique(a + 1, a + 1 + n) - a - 1;
    // printf("%d\n", n);
    a[0] = 0;
    printf("%d", n > 2 ? std::max(a[n - 2], a[n] % a[n - 1]) : -1);
    return 0;
}