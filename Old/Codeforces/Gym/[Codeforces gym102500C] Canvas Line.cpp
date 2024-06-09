#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::swap, std::vector, std::string, std::queue, std::cin, std::cout;
int read(int x = 0, bool f = 0, char ch = getchar())
{
    while (ch < 48 or ch > 57)
        f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57)
        x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
int pow(int x, int k, int P, int res = 1)
{
    for (; k; k >>= 1, x = x * x % P)
        if (k & 1)
            res = res * x % P;
    return res;
}

const int N = 1e6 + 5;
const int P = 998244353;

int n, m;
pii a[N];
int cnt[N];
vector<int> ans;

std::map<int, bool> map;

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].fi = read(), a[i].se = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int x = read();
        map[x] = 1;
        for (int i = 1; i <= n; i++)
            if (a[i].fi <= x and x <= a[i].se)
                cnt[i]++;
    }

    for (int i = 1; i <= n; i++)
        if (cnt[i] > 2)
            return puts("impossible"), void();

    for (int i = 2; i <= n; i++)
        if (a[i].fi == a[i - 1].se and cnt[i - 1] < 2 and cnt[i] < 2 and !map[a[i].fi])
            ans.pb(a[i].fi), cnt[i]++, cnt[i - 1]++, map[a[i].fi] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = a[i].fi + 1; j <= a[i].se - 1 and cnt[i] < 2; j++)
            if (!map[j])
                map[j] = 1, cnt[i]++, ans.pb(j);

    printf("%d\n", ans.size());
    for (int x : ans)
        printf("%d ", x);
}

signed main()
{
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}