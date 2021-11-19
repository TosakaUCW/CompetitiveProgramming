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

int n;
int a[N], b[N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = b[i] = read();
    std::sort(b + 1, b + 1 + n);
    int l = 1, r = 1;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
        {
            l = i;
            break;
        }
    for (int i = n; i >= 1; i--)
        if (a[i] != b[i])
        {
            r = i;
            break;
        }
    std::reverse(a + l, a + 1 + r);
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
            return puts("impossible"), void();
    printf("%d %d\n", l, r);
}

signed main()
{
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}