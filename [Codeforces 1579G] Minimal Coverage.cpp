#include <bits/stdc++.h>
// #define int long long
#define fi first
#define se second
#define ins insert
#define pb push_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
using std::map;
using std::priority_queue;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
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

const int N = 1e4 + 5;
const int L = 1e3;
const int P = 998244353;

int n, a[N], ans, f[N][L * 2 + 5];

void clear(int i)
{
    for (int j = 0; j < L * 2 + 5; j++)
        f[i][j] = INT_MAX / 10;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    clear(1), clear(2), f[1][a[1]] = a[1];
    for (int i = 2; i <= n; clear(++i))
        for (int j = 0, k; j <= L * 2; j++)
        {
            k = j + a[i];
            f[i][k] = std::min(f[i][k], std::max(f[i - 1][j], k));
            k = std::max(j - a[i], 0);
            f[i][k] = std::min(f[i][k], f[i - 1][j] + std::max(0, a[i] - j));
        }
    int ans = INT_MAX;
    for (int j = 0; j <= L * 2; j++)
        ans = std::min(ans, f[n][j]);
    printf("%d\n", ans);
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