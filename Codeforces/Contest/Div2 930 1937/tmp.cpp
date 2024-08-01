#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int INFF = 1e18;

int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        freopen("E.in", "r", stdin);
        int t;
        cin >> t;

        while (t --> 0) {
                int n, m;
                cin >> n >>  m;

                vector<int> c(n + 1);
                for (int i = 1; i <= n; i++) cin >> c[i];

                vector<vector<int>> a(n + 1, vector<int>(m + 1));
                vector<vector<pair<int, int>>> b(m + 1);
                for (int i = 1; i <= n; i++) {
                        for (int j = 1; j <= m; j++) {
                                cin >> a[i][j];

                                b[j].push_back({a[i][j], i});
                        }
                }

                vector<vector<int>> rank(n + 1, vector<int>(m + 1));
                vector<vector<int>> dec(n + 1, vector<int>(m + 1));
                for (int j = 1; j <= m; j++) {
                        sort(b[j].begin(), b[j].end());

                        for (int i = 0; i < n; i++) {
                                auto [x, id] = b[j][i];
                                rank[id][j] = i + 1;
                                dec[i + 1][j] = id;
                        }
                }

                int ans = INFF;
                vector<int> vis(n + 1, 0);
                vector<vector<int>> dist(n + 1, vector<int>(m + 1, INFF));
                priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
                vis[1] = 1;
                for (int j = 1; j <= m; j++) dist[1][j] = 0, pq.push({dist[1][j], 1, j});
                while (!pq.empty()) {
                        auto [w, x, t] = pq.top();
                        pq.pop();
cout << w << x << t << '\n';
                        if (dist[x][t] < w) continue;

                        if (x == n) ans = min(ans, w + c[n]);

                        if (rank[x][t] < n) {
                                int z = dec[rank[x][t] + 1][t];
                                if (w < dist[z][t]) {
                                        dist[z][t] = w;
                                        pq.push({dist[z][t], z, t});
                                }
                        }

                        if (rank[x][t] > 1) {
                                int z = dec[rank[x][t] - 1][t];
                                if (w + a[x][t] - a[z][t] < dist[z][t]) {
                                        dist[z][t] = w + a[x][t] - a[z][t];
                                        pq.push({dist[z][t], z, t});
                                }
                        }

                        if (!vis[x]) {
                                vis[x] = 1;
                                for (int j = 1; j <= m; j++) {
                                        if (w + c[x] < dist[x][j]) {
                                                dist[x][j] = w + c[x];
                                                pq.push({dist[x][j], x, j});
                                        }
                                }
                        }
                }

                cout << ans << '\n';
        }

        return 0;
}