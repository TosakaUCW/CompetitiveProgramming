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

    std::map<int, int> f;
    
    for (int i = 0; i < n; i++) {
        array<int, 3> v;
        cin >> v[0] >> v[1] >> v[2];

        std::map<int, int> nf;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                for (int z = 0; z < 3; z++) {
                    if (x == y or y == z or x == z) continue;

                    int a = v[x];
                    int b = v[y];
                    int c = v[z];

                    if ((c - b) % a == 0) {
                        int x = (c - b) / a;
                        if (x >= 0) nf[x] = 1;
                    }
                }
            }
        }

        for (auto &[x, y] : nf) {
            f[x]++;
        }

    }

    for (auto [x, y] : f) {
        // cout << x << ' ' << y << '\n';
        if (y == n) {
            cout << x << '\n';
        }
    }
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
