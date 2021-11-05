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

int n, a[N];

struct Trie
{
    int cnt, ch[N * 30][2];
    void clear()
    {
        for (int i = 0; i <= cnt; i++)
            ch[i][0] = ch[i][1] = 0;
        cnt = 1;
    }
    void ins(int x)
    {
        int now = 1;
        for (int i = 30; i >= 0; i--)
        {
            int p = (x >> i) & 1;
            if (!ch[now][p])
                ch[now][p] = ++cnt;
            now = ch[now][p];
        }
    }
    int query(int x)
    {
        int now = 1, res = 0;
        for (int i = 30; i >= 0; i--)
        {
            int p = (x >> i) & 1;
            if (ch[now][p])
                now = ch[now][p];
            else
                res += (1 << i), now = ch[now][p ^ 1];
        }
        return res;
    }
} trie;

int solve(int L, int R, int k)
{
    if (k < 0 or L > R)
        return 0;
    int p = L - 1;
    while (p < R and !(a[p + 1] & (1 << k)))
        p++;
    if ((p - L) & 1)
        return std::max(solve(L, p, k - 1), solve(p + 1, R, k - 1));
    trie.clear();
    int ans = INT_MAX;
    for (int i = L; i <= p; i++)
        trie.ins(a[i]);
    for (int i = p + 1; i <= R; i++)
        ans = std::min(ans, trie.query(a[i]));
    return ans;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    n = read() * 2;
    for (int i = 1; i <= n; i++)
        a[i] = read();
    std::sort(a + 1, a + 1 + n);
    printf("%d\n", solve(1, n, 30));
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << std::endl;
#endif
    return 0;
}