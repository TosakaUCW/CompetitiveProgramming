#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

struct Frac {
    int num;
    int den;
};
bool operator<(const Frac &a, const Frac &b) {
    return a.num * b.den < b.num * a.den;
}
Frac &operator+=(Frac &a, const Frac &b) {
    a.num += b.num;
    a.den += b.den;
    return a;
}

void solve() {
    int n = read(), X = read();

    vector<vector<int>> g(n + 1);
    for (int i = 1; i < n; i++) {
        int u = read(), v = read();
        g[u].eb(v), g[v].eb(u);
    }

    int ans = 0;
    vector<int> v(n + 1);
    vector<multiset<Frac>> s(n + 1);

    int sum = 0;
    for (int i = 2; i <= n; i++) {
        int t = read();
        if (t == 1) {
            v[i] = -1;
        } else {
            int a = read(), d = read(), h = read();
            v[i] = (h - 1) / (X - d);
            ans -= v[i] * a;
        }
    }

    int tot = 0;

    auto dfs = [&](this auto&& dfs, int u, int fa) -> void {
        for (auto v : g[u]) {
            if (v == fa) continue;

            dfs(v, u);
            if (s[u].size() < s[v].size()) {
                swap(s[u], s[v]);
            }

            s[u].merge(s[v]);
            s[v].clear();
        }

        if (v[u] == -1) {
            s[u].ep(0, 1);
        } else if (s[u].empty()) {
            tot += v[u];
        } else {
            Frac f {v[u], 0};
            do {
                auto g = s[u].extract(s[u].begin()).value();

                ans += f.den * g.num;
                f += g;
            } while (!s[u].empty() and *s[u].begin() < f);
            s[u].ep(f);
        }
    };
    dfs(1, 0);

    int now = 0;
    for (auto [num, den] : s[1]) {
        ans += now * num;
        now += den;
    }
    ans += tot * now;

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}