#include <stdio.h>
#include <algorithm>
#include <vector>
#include <memory.h>

#define int long long

int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e5 + 5;
const int M = 511;

int n, a[N];
int f[N];
std::vector<int> ans;

void solve()
{
    n = read(), ans.clear(), memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++)
        a[i] = read();
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        f[a[i]] = f[a[i]] == -1 ? a[i] : std::min(f[a[i]], a[i]);
        for (int j = 0; j <= M; j++)
            if (f[j] < a[i] and f[j] != -1)
                f[a[i] ^ j] = f[a[i] ^ j] == -1 ? a[i] : std::min(f[a[i] ^ j], a[i]);
    }
    for (int i = 0; i <= M; i++)
        if (f[i] != -1)
            ans.emplace_back(i);
    printf("%lld\n", ans.size());
    for (int x : ans)
        printf("%lld ", x);
    puts("");
}

signed main()
{
    solve();
    return 0;
}
