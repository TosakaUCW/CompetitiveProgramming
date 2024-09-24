#include <bits/stdc++.h>

#define int long long

using std::cin;
using std::cout;
using std::vector;
using std::string;

signed main() {
    int n, k;
    cin >> n >> k;
    
    using pii = std::pair<int, int>;
    
    int cnt = 0;
    vector<vector<pii>> a(n);
    vector<int> vis(n);

    vector<int> c(k), w(n);
    for (int i = 0; i < k; i++) cin >> c[i];
    std::sort(c.begin(), c.end());
    std::map<string, int> mp;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> w[i] >> s;

        if (!mp[s]) mp[s] = ++cnt;
        a[mp[s]].push_back({w[i], i});
    }

    vector<int> b;
    vector<int> ans(n);
    for (int i = 1; i <= cnt; i++) {
        std::sort(a[i].rbegin(), a[i].rend());
        for (int j = 0; j < c[0] and j < a[i].size(); j++) {
            b.push_back(a[i][j].first);
            vis[a[i][j].second] = 1;
        }
    }

    std::sort(b.rbegin(), b.rend());

    for (int i = 0; i < n; i++) {
        int res = b.size();
        for (int L = 0, R = b.size() - 1; L <= R; ) {
            int mid = (L + R) / 2;
            if (w[i] >= b[mid]) res = mid, R = mid - 1;
            else L = mid + 1;
        }
        ans[i] = res - (!vis[i]) + 1;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}