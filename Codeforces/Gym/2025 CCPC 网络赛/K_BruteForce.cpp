#include <bits/stdc++.h>

using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

void solve() {
    int n = read();
    
    vector<int> a(n);

    auto best_a = a;
    auto best_res = 0;
    

    for (int i = 0; i < n; i++) a[i] = i + 1;
    do {

        // for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1];
        auto calc = [&](vector<int> a) -> int {
            int ans = 0;
            for (int k = 0; k < n; k++) {
                vector<vector<int>> g(n + 1);
                for (int i = 0; i < n; i++) {
                    int u = a[i];
                    int v = (i + k) % n;
                    g[u].emplace_back(v);
                    g[v].emplace_back(u);
                }
                int res = 0;
                vector<int> vis(n + 1);
                auto dfs = [&](auto self, int u) -> void {
                    vis[u] = 1;
                    for (int v : g[u]) if (!vis[v]) self(self, v);
                };
                for (int i = 0; i < n; i++) {
                    if (!vis[i]) res++, dfs(dfs, i);
                }
                ans += res;
            }
            return ans;
        };

        int res = calc(a);
        // cout << res << '\n';

        if (best_res < res) {
            best_res = res;
            best_a = a;
        }
    } while (next_permutation(a.begin(), a.end()));

    cout << best_res << '\n';
    for (int i = 0; i < n; i++) cout << best_a[i] << " \n"[i == n - 1];
}

int main() {
    // freopen("K.in", "r", stdin);
    solve();
    return 0;
}