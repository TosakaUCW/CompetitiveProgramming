#include <bits/stdc++.h>
#define int long long
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
using std::string;
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

const int N = 1e6 + 5;
const int P = 998244353;

int n, a[N], f[N][25];

int query(int L, int R)
{
    int k = 0;
    while ((1 << k + 1) <= R - L + 1)
        k++;
    return std::__gcd(f[L][k], f[R - (1 << k) + 1][k]);
}

bool judge(int len)
{
    for (int i = 1; i + len - 1 <= n; i++)
        if (query(i, i + len - 1) != 1)
            return 1;
    return 0;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    if (n == 1)
        return puts("1"), void();
    n--;
    for (int i = 1; i <= n; i++)
        a[i] = abs(a[i] - a[i + 1]);
    for (int i = 1; i <= n; i++)
        f[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = std::__gcd(f[i][j - 1], f[i + (1 << j - 1)][j - 1]);
    int L = 1, R = n, ans = 0;
    while (L <= R)
    {
        int mid = L + R >> 1;
        if (judge(mid))
            ans = mid, L = mid + 1;
        else
            R = mid - 1;
    }
    printf("%lld\n", ans + 1);
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