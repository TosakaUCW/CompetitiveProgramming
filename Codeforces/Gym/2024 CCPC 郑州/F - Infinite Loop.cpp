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
// const int inf = 1e18;

void solve() {
    int n = read();
    int k = read();
    int q = read();

    vector<pii> a(n);
    int sum = 0;
    for (auto &[x, y] : a) {
        x = read(), y = read();
        sum += y;
    }

    vector ans(3, vector(n, pii{}));
    int dd = 1, hh = 0;
    for (int day = 1; day <= 2; day++) {
        if (dd < day) dd = day, hh = 0;
        for (int i = 0; i < n; i++) {
            auto [x, y] = a[i];
            if (dd == day and hh < x) {
                hh = x + y - 1;
            } else {
                hh += y;
            }
            if (hh > k) hh -= k, dd++;
            ans[day][i] = {dd, hh};
        }
    }

    while (q--) {
        int x = read(), y = read() - 1;

        if (x <= 2) {
            auto [dd, hh] = ans[x][y];
            cout << dd << ' ' << hh << '\n';
            continue;
        }

        if (sum <= k) {
            auto [dd, hh] = ans[2][y];
            dd += x - 2;
            cout << dd << ' ' << hh << '\n';
        } else {
            auto [dd, hh] = ans[2][y];
            hh += sum * (x - 2);
            dd += (hh - 1) / k;
            hh = (hh - 1) % k + 1;
            cout << dd << ' ' << hh << '\n';
        }

    }
}

signed main() {
    // for (int T = read(); T--; solve());
    solve();
    return 0;
}