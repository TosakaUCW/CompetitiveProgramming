#include <stdio.h>
#include <algorithm>

const int N = 2e5 + 5;

int n, m, ans;
int f[N], g[N];
char s[N], t[N];

int main()
{
    scanf("%d%d%s%s", &n, &m, s, t);
    for (int i = 0, j = 0; i < n and j < m; i++)
        if (s[i] == t[j])
            f[j++] = i;
    for (int i = n - 1, j = m - 1; ~i and j; i--)
        if (s[i] == t[j])
            g[j--] = i;
    for (int i = 1; i <= m; i++)
        ans = std::max(ans, g[i] - f[i - 1]);
    return printf("%d", ans), 0;
}