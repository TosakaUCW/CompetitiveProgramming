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

const int N = 1e6 + 5;
const int M = 1e7;
const int P = 998244353;

int n;
int a[N], pre[N], nxt[N], f[N], las[2][M];
vector<int> b[N];

typedef long long ll;

int DST;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long quick_pow(long long x, long long p, long long mod)
{ //快速幂
    long long ans = 1;
    while (p)
    {
        if (p & 1)
            ans = ans * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return ans;
}

bool Miller_Rabin(long long p)
{ //判断素数
    if (p < 2)
        return 0;
    if (p == 2)
        return 1;
    if (p == 3)
        return 1;
    long long d = p - 1, r = 0;
    while (!(d & 1))
        ++r, d >>= 1; //将d处理为奇数
    for (long long k = 0; k < 10; ++k)
    {
        long long a = rand() % (p - 2) + 2;
        long long x = quick_pow(a, d, p);
        if (x == 1 || x == p - 1)
            continue;
        for (int i = 0; i < r - 1; ++i)
        {
            x = x * x % p;
            if (x == p - 1)
                break;
        }
        if (x != p - 1)
            return 0;
    }
    return 1;
}

long long Pollard_Rho(long long x)
{
    long long s = 0, t = 0;
    long long c = (long long)rand() % (x - 1) + 1;
    int step = 0, goal = 1;
    long long val = 1;
    for (goal = 1;; goal *= 2, s = t, val = 1)
    { //倍增优化
        for (step = 1; step <= goal; ++step)
        {
            t = (t * t + c) % x;
            val = val * abs(t - s) % x;
            if ((step % 127) == 0)
            {
                long long d = gcd(val, x);
                if (d > 1)
                    return d;
            }
        }
        long long d = gcd(val, x);
        if (d > 1)
            return d;
    }
}

void fac(long long x)
{
    if (x < 2)
        return;
    if (Miller_Rabin(x))
    { //如果x为质数
        b[DST].pb(x);
        return;
    }
    long long p = x;
    while (p >= x)
        p = Pollard_Rho(x); //使用该算法
    while ((x % p) == 0)
        x /= p;
    fac(x), fac(p); //继续向下分解x和p
}
void solve(int L, int R, int fa)
{
    if (L > R)
        return;
    if (L == R)
        return f[L] = fa, void();
    int i = L, j = R;
    while (i <= j)
    {
        if (pre[i] < L and R < nxt[i])
        {
            solve(L, i - 1, i), solve(i + 1, R, i);
            f[i] = fa;
            return;
        }
        if (pre[j] < L and R < nxt[j])
        {
            solve(L, j - 1, j), solve(j + 1, R, j);
            f[j] = fa;
            return;
        }
        i++, j--;
    }
    puts("impossible"), exit(0);
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read(),
        nxt[i] = n + 1;
    for (int i = 1; i <= n; i++)
        DST = i, fac(a[i]);
    for (int i = 1; i <= n; i++)
        for (auto x : b[i])
            pre[i] = std::max(pre[i], las[0][x]),
            las[0][x] = i;
    for (int i = n; i >= 1; i--)
        for (auto x : b[i])
            nxt[i] = std::min(nxt[i], las[1][x] ? las[1][x] : n + 1),
            las[1][x] = i;
    solve(1, n, 0);
    for (int i = 1; i <= n; i++)
        printf("%d ", f[i]);
    puts("");
}

signed main()
{
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}