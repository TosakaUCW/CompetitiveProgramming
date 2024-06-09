#include <stdio.h>
#include <algorithm>

const int N = 1e5 + 5;

int n, a[N];

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    std::sort(a + 1, a + 1 + n);
    int time = 0, ans = 0;
    for (int i = 1; i <= n; i++)
        if (time <= a[i])
            ans++, time += a[i];
    printf("%d", ans);
    return 0;
}