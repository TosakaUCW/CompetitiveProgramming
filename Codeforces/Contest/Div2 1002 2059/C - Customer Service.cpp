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
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();

    vector a(n, vector(n, 0));
    for (auto &x : a) {
        for (auto &y : x) {
            y = read();
        }
    }

    vector<int> buk;
    for (auto x : a) {
        int cnt = 0;
        for (int j = n - 1; j >= 0; j--) {
            if (x[j] == 1) {
                cnt++;
            } else {
                break;
            }
        }
        buk.eb(cnt);
    }

    ranges::sort(buk);
    int mex = 0;
    for (int cnt : buk) {
        if (cnt >= mex) {
            mex++;
        }
    }
    cout << mex << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
