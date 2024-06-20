#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 2e2 + 5;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, 1, -1};
// const int INF = 1e18;
int n, m;
int f[N][N], ene[N][N];
char map[N][N];
bool inq[N][N];
void solve()
{
    n = read(), m = read();
    std::queue<pii> Q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j], f[i][j] = ene[i][j] = -1;
    for (int q = read(); q--; )
    {
        int x = read(), y = read();
        ene[x][y] = read();
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'S')
                f[i][j] = ene[i][j], Q.push({i, j}), inq[i][j] = 1;

    while (!Q.empty())
    {
        auto [x, y] = Q.front(); Q.pop(); inq[x][y] = 0;
        // cout << x << y << '\n';
        if (f[x][y] <= 0) continue;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 1 or nx > n or ny < 1 or ny > m or map[nx][ny] == '#') continue;
            if (f[nx][ny] < f[x][y] - 1)
            {
                f[nx][ny] = std::max(f[x][y] - 1, ene[nx][ny]);
                if (map[nx][ny] == 'T') break;
                if (!inq[nx][ny]) Q.push({nx, ny}), inq[nx][ny] = 1;
            }
        }
    }

    bool flag = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (map[i][j] == 'T' and f[i][j] >= 0)
            {
                flag = 1;
                break;
            }
    puts(flag ? "Yes" : "No");
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("A.in", "r", stdin);
#endif
    for (int T = 1; T--; solve());
    return 0;
}