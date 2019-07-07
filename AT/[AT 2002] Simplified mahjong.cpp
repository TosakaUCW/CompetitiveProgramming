#include <stdio.h>

const int N = 1e5 + 5;

int n, a[N];
long long ans;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
    {
        ans += a[i] / 2, a[i] %= 2;
        if (i < n and a[i] and a[i + 1])
            ans++, a[i]--, a[i + 1]--;
    }
    printf("%lld\n", ans);
    return 0;
}