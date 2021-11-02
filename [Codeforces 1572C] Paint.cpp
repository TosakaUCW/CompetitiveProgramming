#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::unordered_map;
using std::unordered_set;
using std::vector;
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

const int N = 3e3 + 5;
const int P = 998244353;
const int INF = 2147483647;

int n, b[N], ans;
int pre[N], las[N], f[N][N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        b[i] = read(), las[b[i]] = -1;
    vector<int> a;
    for (int i = 1; i <= n;)
    {
        int j = i;
        a.pb(b[i]);
        while (j <= n and b[j] == b[i])
            j++;
        i = j;
    }
    n = a.size();
    for (int i = 0; i < n; i++)
        pre[i] = las[a[i]], las[a[i]] = i, f[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int l = 0, r; (r = l + len - 1) < n; l++)
        {
            f[l][r] = std::min(f[l][r - 1], f[l + 1][r]) + 1;
            for (int p = pre[r]; p >= l; p = pre[p])
                f[l][r] = std::min(f[l][r], f[l][p] + f[p + 1][r]);
            // printf("[%d, %d] %d\n", l, r, f[l][r]);
        }
    printf("%d\n", f[0][n - 1]);
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int T = read(); T--; solve())
        ;
    return 0;
}