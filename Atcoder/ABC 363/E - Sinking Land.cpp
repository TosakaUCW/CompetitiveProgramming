#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 1e3 + 5;

int n, m, Y;
int a[N][N];
bool vis[N][N];

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

struct Node
{
    int x, y;
    bool friend operator < (Node a, Node b) { return ::a[a.x][a.y] > ::a[b.x][b.y]; }
};
std::priority_queue<Node> S;

void put(int x, int y)
{
    if (x < 1 or x > n or y < 1 or y > m) return;
    if (vis[x][y]) return;
    S.push({x, y}), vis[x][y] = 1;
}

void solve()
{
    n = read(), m = read(), Y = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] = read();
    
    for (int i = 1; i <= n; i++) put(i, 1), put(i, m);
    for (int j = 1; j <= m; j++) put(1, j), put(n, j);

    int ans = n * m;
    for (int i = 1; i <= Y; i++)
    {
        while (!S.empty() and a[S.top().x][S.top().y] <= i)
        {
            auto [x, y] = S.top(); S.pop();
            ans--;
            for (int j = 0; j < 4; j++) put(x + dx[j], y + dy[j]);
        }
        printf("%d\n", ans);
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}