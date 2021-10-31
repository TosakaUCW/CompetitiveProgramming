#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define ins insert
#define pb emplace_back
#define flu fflush(stdout)
#define pii std::pair<int, int>
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
const int INF = 2147483647;

int n, a[N], ans;

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    for (int i = 1; i <= n; i++)
    {
        bool f = 0;
        for (int j = 2; j <= std::min(i + 1, 100LL); j++)
            if (a[i] % j)
            {
                f = 1;
                break;
            }
        if (!f)
            return puts("NO"), void();
    }
    puts("YES");
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
    return 0;
}