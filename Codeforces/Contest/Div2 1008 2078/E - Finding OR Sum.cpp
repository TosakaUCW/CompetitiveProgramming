#include <bits/stdc++.h>
using i64 = long long;
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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    auto qry = [&](int x) {
        cout << x << endl;
        int res; cin >> res;
        return res;
    };

    int num[2] {};
    for (int i = 0; i < 30; i++) {
        num[i % 2] += 1 << i;
    }

    int res[2] {};
    res[0] = qry(num[0]) - (num[0] << 1);
    res[1] = qry(num[1]) - (num[1] << 1);
    swap(res[0], res[1]);

    cout << "!" << endl;
    int m; cin >> m;

    int ans = 0;
    for (int i = 0; i < 30; i++) {
        if (m >> i & 1) {
            ans += (1 << i) << 1;
        } else {
            if (res[i % 2] >> i & 1) {
                ans += 1 << i;
            } else if (res[i % 2] >> (i + 1) & 1) {
                ans += (1 << i) << 1;
            }
        }
    }

    cout << ans << endl;
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
