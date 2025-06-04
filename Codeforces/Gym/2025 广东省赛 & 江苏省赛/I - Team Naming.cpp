#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
using i128 = __int128;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    const int S = 1 << 3;
    using sname = array<int, 3>; 

    int n = read();

    vector<sname> a(n);
    vector<map<ull, int>> buk(S);

    for (auto &arr : a) {
        for (auto &x : arr) {
            x = read();
        }
    }

    ull bas = 19260817;
    auto gethash = [&](auto s) -> ull {
        ull res = 0;
        for (auto x : s) res = res * bas + x;
        return res;
    };

    for (auto &arr : a) {
        for (int s = 0; s < S; s++) {
            vector<int> t;
            for (int i = 0; i < 3; i++) {
                if (s >> i & 1) {
                    t.eb(arr[i]);
                }
            }
            buk[s][gethash(t)]++;
        }
    }

    vector g(n, vector(S, 0));
    for (int i = 0; i < n; i++) {
        auto arr = a[i];
        for (int s = 0; s < S; s++) {
            vector<int> t;
            for (int i = 0; i < 3; i++) {
                if (s >> i & 1) {
                    t.eb(arr[i]);
                }
            }
            g[i][s] = buk[s][gethash(t)] - 1;
        }
    }

    // for (int i = 0; i < n; i++) {
    //     auto arr = a[i];
    //     for (int s = 0; s < S; s++) {
    //         cerr << "g[i][s]: " << i << " " << s << " " << g[i][s] << '\n';
    //     }
    // }

    auto f = g;
    for (auto &f : f) {
        for (int i = 0; i < 3; i++) {
            for (int s = 0; s < S; s++) {
                if (s >> i & 1) {
                    f[s ^ (1 << i)] -= f[s];
                }
            }
        }
    }
    

    // for (int i = 0; i < n; i++) {
    //     auto arr = a[i];
    //     for (int s = 0; s < S; s++) {
    //         cerr << "f[i][s]: " << i << " " << s << " " << f[i][s] << '\n';
    //     }
    // }

    int ans = 0;
    for (auto &f : f) {
        int res = 0;
        for (int s1 = 1; s1 < S; s1++) {
            for (int s2 = s1; s2 < S; s2++) {
                if (s1 != s2) {
                    res += f[s1] * f[s2];
                } else {
                    if (__builtin_popcountll(s1) < 2) continue;
                    int x = f[s1];
                    res += x * (x - 1) / 2;
                }
            }
        }

        ans += res;
    }

    cout << ans << '\n';
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}