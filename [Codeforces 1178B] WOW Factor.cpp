#include <stdio.h>
#include <string.h>
#include <algorithm>

const int N = 1e6 + 5;

int n, cnt;
long long ans;
int l[N], r[N];
char str[N];

int main()
{
    scanf("%s", str + 1);
    n = strlen(str + 1);
    for (int i = 1, last = 1; i <= n; i++)
        if (str[i] == 'o')
            l[i] = l[last] + std::max(cnt - 1, 0), last = i, cnt = 0;
        else
            cnt++;
    cnt = 0;
    for (int i = n, last = n; i >= 1; i--)
        if (str[i] == 'o')
            r[i] = r[last] + std::max(cnt - 1, 0), last = i, cnt = 0;
        else
            cnt++;
    for (int i = 1; i <= n; i++)
        if (str[i] == 'o')
            ans += 1LL * l[i] * r[i];
    printf("%lld", ans);
    return 0;
}