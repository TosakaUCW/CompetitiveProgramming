#include <bits/stdc++.h>
#define int long long
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

const int N = 1e5 + 5;
const int M = 1e3 + 5;
const int P = 998244353;

int n, ans;
int s[M][M];
struct Node
{
    int x1, y1, x2, y2;
    void input() { x1 = read(), y1 = read(), x2 = read(), y2 = read(); }
} a[N];

#define calc(x) (x >= 3 ? x * (x - 1) * (x - 2) / 6 : 0)

int solve(int dx, int dy)
{
    int res = 0;
    memset(s, 0, sizeof s);
    for (int i = 1; i <= n; i++)
    {
        int x1 = a[i].x1, x2 = a[i].x2 + dx;
        int y1 = a[i].y1, y2 = a[i].y2 + dy;
        s[x1][y1]++, s[x2 + 1][y1]--, s[x1][y2 + 1]--, s[x2 + 1][y2 + 1]++;
    }
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
        {
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
            res += calc(s[i][j]);
        }
    return res;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i++)
        a[i].input();
    printf("%lld\n", solve(0, 0) - solve(0, -1) - solve(-1, 0) + solve(-1, -1));
}

signed main()
{
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}