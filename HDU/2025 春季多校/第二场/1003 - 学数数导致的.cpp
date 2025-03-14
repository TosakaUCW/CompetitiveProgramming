#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n; cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<vector<int>> pos(1e6 + 1);
    for (int i = 0; i < n; i++) {
        pos[a[i]].eb(i);
    }
    vector<int> i3(1e6 + 1);
    for (int x = 1; x <= 1e6; x++) {
        int m = pos[0].size();
        int siz = pos[x].size();
        int z = 0;
        for (int i = 0; i + 1 < siz; i++) {
            while (z < m and pos[0][z] <= pos[x][i]) z++;
            if (z < m and pos[0][z] < pos[x][i + 1]) {
                i3[x] = pos[x][i + 1];
                break;
            }
        }
    }

    vector<int> cnt(n + 1);
    vector<int> used(1e6 + 1);
    for (int i = n - 1; i >= 0; i--) {
        cnt[i] = cnt[i + 1];
        if (!used[a[i]] and a[i] > 0) {
            used[a[i]] = 1;
            cnt[i]++;
        }
    }

    int ans = 0;
    for (int x = 1; x <= 1e6; x++) {
        if (i3[x] == 0) continue;
        ans += cnt[i3[x] + 1];
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
