#include <bits/stdc++.h>
using i64 = long long;
using i128  = __int128_t;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using namespace std;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }

const int MOD = 10007;

int pow10[11];

void solve() {
    int k;
    int c, d, e, f;
    cin >> k >> c >> d >> e >> f;

    int ans = 0;

    for (int b = 0; b < MOD; b++) {
        i128 bb = b;
        i128 y  = (i128) c * bb * bb * bb
                + (i128) d * bb * bb
                + (i128) e * bb
                + (i128) f;

        if (y <= 0) continue;

        int res[11];
        int len = 0;
        bool flag = 1;

        for (auto tmp = y; tmp; tmp /= 27) {
            if (len == k) { flag = 0; break; }

            int rem = tmp % 27;

            if (rem == 0) { flag = 0; break; }
            res[len++] = rem;
        }

        if (!flag) continue;

        int nb = 0;
        for (int i = 0; i < len; ++i) {
            nb = (nb + res[i] * pow10[i]) % MOD;
        }
        if (nb == b) ++ans;
    }

    cout << ans << '\n';
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    
    pow10[0] = 1;
    for (int i = 1; i <= 10; ++i) {
        pow10[i] = (pow10[i - 1] * 10) % MOD;
    }

    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}