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
const int P = 998244353;

int n, k, m;
int a[N];
vector<int> b;
double f[20][N];

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i] = read();
    m = 1;
    while (m < n)
        m <<= 1, k++;
    std::sort(a + 2, a + 1 + n);
    b.pb(0);
    for (int i = 1; i <= n; i++)
    {
        b.pb(a[i]);
        if (i <= m - n)
            b.pb(a[i]);
    }

    for (int i = 1; i <= m; i++)
        f[0][i] = 1;
    for (int i = 1, len = 2; len <= m; i++, len <<= 1)
        for (int j = 1; j <= m; j++)
        {
            int st = std::max(j - (j % len == 0 ? len : j % len) + 1, 1);
            int ed = std::min(st + len - 1, m);
            int mid = (st + ed) / 2;
            if (j <= mid)
                st = mid + 1;
            else
                ed = mid;
            for (int k = st; k <= ed; k++)
                f[i][j] += f[i - 1][j] * f[i - 1][k] * b[j] / (b[j] + b[k]);
        }
    if (m != n)
        f[k][1] *= 2;
    printf("%.8f\n", f[k][1]);
}

signed main() { return solve(), 0; }