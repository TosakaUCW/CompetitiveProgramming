#include <bits/stdc++.h>
using i64 = long long;
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
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int l = read(), r = read();
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<int> s(n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] ^ a[i];

    unordered_map<int, int> mp;
    auto go = [&](this auto&& self, int x) {
        if (x <= n) return s[(int)x];
        if (mp.count(x)) return mp[x];
        int res;
        if (n % 2 == 1) {
            if (x % 2 == 1) {
                res = s[n];
            } else {
                res = s[n] ^ self(x / 2);
            }
        } else {
            if (x % 2 == 1) {
                res = s[n] ^ s[n / 2];
            } else {
                res = s[n] ^ s[n / 2] ^ self(x / 2);
            }
        }
        mp[x] = res;
        return res;
    };

    int ans;
    if (l <= n) {
        ans = a[(int)l];
    } else {
        ans = go(l / 2);
    }
    cout << ans << "\n";

}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
