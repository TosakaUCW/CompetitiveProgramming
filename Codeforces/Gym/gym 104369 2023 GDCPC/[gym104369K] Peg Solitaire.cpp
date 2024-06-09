#include <bits/stdc++.h>
using namespace std;
#define int long long
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define fi first
#define se second
#define pb push_back
using std::cin, std::cout, std::string, std::vector, std::swap;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 6 + 5;
int a[N][N], vis[N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m, k, ans;
vector<pii> b;
void dfs(int cnt)
{
    ans = std::min(ans, cnt);

    // for (int i = 1; i <= n; i++, puts(""))
    //     for (int j = 1; j <= m; j++)
    //         cout << a[i][j] << ' ';

    for (int i = 1; i <= k; i++)
    {
        int x = b[i].fi, y = b[i].se;
        if (x + y == 0) continue;
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if (nx < 1 or nx > n or ny < 1 or ny > m) continue;
            if (!a[nx][ny]) continue;
            // cout << nx << ny << '\n';
            int mx = x + 2 * dx[j];
            int my = y + 2 * dy[j];
            if (mx < 1 or mx > n or my < 1 or my > m) continue;
            if (a[mx][my]) continue;

            // cout << mx << my << '\n';

            int tmp = a[nx][ny];
            swap(a[x][y], a[mx][my]), a[nx][ny] = 0;
            b[i] = {mx, my}, b[tmp] = {0, 0};
            // cout << cnt - 1 << '\n';
            dfs(cnt - 1);

            swap(a[x][y], a[mx][my]), a[nx][ny] = tmp;
            b[i] = {x, y}, b[tmp] = {nx, ny};
        }
    }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--)
    {
        memset(a, 0, sizeof a);
        cin >> n >> m >> k;
        b.clear(), ans = 1 << 30;
        b.push_back({0, 0});
        for (int i = 1; i <= k; i++)
        {
            int x, y;
            cin >> x >> y;
            a[x][y] = i;
            b.push_back({x, y});
        }
        dfs(k);
        cout << ans << "\n";
    }
}