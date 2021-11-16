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

typedef unsigned long long ull;

const int N = 1e6 + 5;
const ull bas = 19260817;
const int P = 998244353;

int n;
ull pw[N], sum[N];
string s, ans;

ull hash(int L, int R) { return sum[R] - pw[R - L + 1] * sum[L - 1]; }

bool judge(int len)
{
    unordered_map<ull, int> buk;
    for (int i = 1, j = len; j <= n; i++, j++)
        buk[hash(i, j)]++;
    for (int i = 1, j = len; j <= n; i++, j++)
        if (buk[hash(i, j)] == 1)
            return ans = s.substr(i, len), 1;
    return 0;
}

void solve()
{
    std::cin >> s;
    n = s.size(), s = " " + s;
    pw[0] = 1;
    for (int i = 1; i <= n; i++)
        pw[i] = pw[i - 1] * bas,
        sum[i] = sum[i - 1] * bas + s[i];
    int L = 1, R = n;
    while (L <= R)
    {
        int mid = (L + R) >> 1;
        if (judge(mid))
            R = mid - 1;
        else
            L = mid + 1;
    }
    std::cout << ans;
}

signed main()
{
    solve();
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}