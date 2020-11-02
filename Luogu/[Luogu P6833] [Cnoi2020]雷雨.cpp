#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <queue>

typedef long long ll;

const ll N = 1e3 + 5;
const ll INF = 1LL << 60;
const ll dx[] = {-1, 1, 0, 0};
const ll dy[] = {0, 0, 1, -1};

ll n, m, a, b, c;
ll map[N][N];
long long ans = INF, dis[3][N][N];

struct data
{
    ll x, y, dis;
    bool friend operator<(data A, data B) { return A.dis > B.dis; };
};

std::priority_queue<data> Q;

ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while ('0' > ch or ch > '9')
        f = ch == '-' ? -1 : 1, ch = getchar();
    while ('0' <= ch and ch <= '9')
        x = x * 10 + ch - 48, ch = getchar();
    return x * f;
}

void dijkstra(const ll &sx, const ll &sy, const ll &opt)
{
    Q.push(data{sx, sy, map[sx][sy]});
    dis[opt][sx][sy] = map[sx][sy];
    while (!Q.empty())
    {
        ll x = Q.top().x, y = Q.top().y, tmp = Q.top().dis;
        Q.pop();
        if (tmp > dis[opt][x][y])
            continue;
        for (ll i = 0; i < 4; i++)
        {
            ll xx = x + dx[i], yy = y + dy[i];
            if (xx < 1 or xx > n or yy < 1 or yy > m)
                continue;
            if (dis[opt][x][y] + map[xx][yy] < dis[opt][xx][yy])
            {
                dis[opt][xx][yy] = dis[opt][x][y] + map[xx][yy];
                Q.push(data{xx, yy, dis[opt][xx][yy]});
            }
        }
    }
}

signed main()
{
    memset(dis, 0x3f, sizeof dis);
    n = read(), m = read(), a = read(), b = read(), c = read();
    for (ll i = n; i >= 1; i--)
        for (ll j = 1; j <= m; j++)
            map[i][j] = read();
    dijkstra(n, a, 0), dijkstra(1, b, 1), dijkstra(1, c, 2);
    for (ll i = n; i >= 1; i--)
        for (ll j = 1; j <= m; j++)
            ans = std::min(ans, dis[0][i][j] + dis[1][i][j] + dis[2][i][j] - 2 * map[i][j]);
    printf("%lld", ans);
    return 0;
}