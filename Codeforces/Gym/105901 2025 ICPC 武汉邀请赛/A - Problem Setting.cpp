#include <bits/stdc++.h>
using i64 = long long;
using ull = unsigned long long;
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

void solve() {
    int n = read();
    // int k = read();
    int q = read();


    vector<int> a(n);
    for (int &x : a) x = read();

    vector<array<int, 3>> b(q);
    int ans = 0;
    for (auto &[i, l, r] : b) {
        i = read() - 1;
        l = read(), r = read();

        if (a[i] < l) ans += l - a[i], a[i] = l;
        if (a[i] > r) ans += a[i] - r, a[i] = r;
    }

    for (auto &[i, l, r] : b) {
        if (a[i] < l or a[i] > r) {
            ans = -1;
        }
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}