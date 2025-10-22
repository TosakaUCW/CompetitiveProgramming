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

void solve() {
    int n = read();
    int k = read();

    vector<int> a(n), t(n);
    for (auto &x : a) x = read();

    auto judge = [&](double lim) -> int {
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            t[i] = max(0LL, (int)floor(lim - 100.0 / a[i]));
            cnt += t[i];
        }
        return cnt;
    };

    double res = 0;
    for (double L = 0, R = 1e6; R - L >= 1e-7; ) {
        double mid = (L + R) / 2;
        if (judge(mid) <= k) {
            res = mid, L = mid + 1;  
        } else { 
            R = mid - 1; 
        }
    }

    for (int x = judge(res); x < k; x++) {
        auto calc = [&](int i) -> double {
            return (100.0 + a[i] * (t[i] + 1)) / (100.0 + a[i] * t[i]);
        };
        int id = 0;
        for (int i = 1; i < n; i++) {
            if (calc(i) > calc(id)) id = i;
        }
        t[id]++;
    }

    double ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= (1.0 + 1.0 * (a[i] * t[i]) / 100.0);
    }

    cout << fixed << setprecision(8);
    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}