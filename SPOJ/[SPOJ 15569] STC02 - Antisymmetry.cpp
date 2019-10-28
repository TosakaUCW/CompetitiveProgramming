#include <stdio.h>
#include <algorithm>

const int N = 5e5 + 5;

int n, r[N + 5];
long long ans;
char s[N + 5];

void Manacher()
{
    int mid = 0;
    for (int i = 1; i < n; i++)
    {
        if (i <= mid + r[mid])
            r[i] = std::min(r[mid * 2 - i], mid + r[mid] - i);
        else
            r[i] = 0;
        int L = i - r[i], R = i + r[i] + 1;
        while (L >= 1 and R <= n and s[L] != s[R])
            L--, R++;
        L++, R--;
        r[i] = (R - L + 1) / 2;
        if (R > mid + r[mid])
            mid = i;
        ans += r[i];
    }
}

int main()
{
    scanf("%d\n%s", &n, s + 1);
    Manacher();
    printf("%lld", ans);
    return 0;
}