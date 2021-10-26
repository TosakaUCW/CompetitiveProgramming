#include <stdio.h>
#include <algorithm>
#include <vector>
#include <mem.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e6 + 5;
const int INF = 0x7f7f7f7f;

int n;
int a[N], f[N];
std::vector<int> g[N], ans;

#define pb emplace_back

int main()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(), g[a[i]].pb(i);
    memset(f, 0x7f, sizeof f), f[0] = 0;
    for (int i = 1; i <= 5000; i++)
        for (int j = 0; j < (1 << 13); j++)
        {
            auto it = std::lower_bound(g[i].begin(), g[i].end(), f[j]);
            if (it != g[i].end())
                f[j ^ i] = std::min(f[j ^ i], *it);
        }
    for (int i = 0; i < (1 << 13); i++)
        if (f[i] != INF)
            ans.pb(i);
    printf("%d\n", ans.size());
    for (auto x : ans)
        printf("%d ", x);
    return 0;
}