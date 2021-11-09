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

const int N = 300 + 5;
const int P = 998244353;

int n, m, k, tot[N], cnt[N];
char ans[N][N];
vector<char> S;
string s[N];

void dfs(int x, int y, int dir, auto it)
{
    if (x == n)
        return;
    if (s[x][y] == 'R' and cnt[*it] == tot[*it])
        it++;
    ans[x][y] = *it, cnt[*it] += (s[x][y] == 'R');
    y += dir;
    if (y >= m)
        x++, y = m - 1, dir = -dir;
    if (y < 0)
        x++, y = 0, dir = -dir;
    dfs(x, y, dir, it);
}

void solve()
{
    n = read(), m = read(), k = read();
    int sum = 0;
    memset(cnt, 0, sizeof cnt);
    memset(tot, 0, sizeof tot);
    for (int i = 0; i < n; i++)
        std::cin >> s[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            sum += (s[i][j] == 'R');
    if (sum < k)
        for (int i = 0; i < n and sum < k; i++)
            for (int j = 0; j < m and sum < k; j++)
                if (s[i][j] == '.')
                    s[i][j] = 'R', sum++;
    for (int i = 0; i < k; i++)
        tot[S[i]] = sum / k;
    for (int i = 0; i < (sum % k); i++)
        tot[S[i]]++;
    dfs(0, 0, 1, S.begin());
    for (int i = 0; i < n; i++, puts(""))
        for (int j = 0; j < m; j++)
            std::cout << ans[i][j];
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("my_input.in", "r", stdin);
#endif
    for (int i = '0'; i <= '9'; i++)
        S.pb(i);
    for (int i = 'a'; i <= 'z'; i++)
        S.pb(i);
    for (int i = 'A'; i <= 'Z'; i++)
        S.pb(i);
    for (int T = read(); T--; solve())
        ;
#ifndef ONLINE_JUDGE
    std::cerr << (double)clock() / CLOCKS_PER_SEC << 's' << std::endl;
#endif
    return 0;
}