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
const int inf = 1e9;

void solve() {
    int n = read();
    int k = read();

    if (k < n) { puts("No"); return; }

    vector a(n + 1, vector(n + 1, 0ll));

    auto check = [&]() -> int {
        int res = inf;
        int t;

        for (int i = 1; i <= n; i++) {
            t = 0;
            for (int j = 1; j <= n; j++) t = max(t, a[i][j]);
            res = min(res, t);
        }
        for (int i = 1; i <= n; i++) {
            t = 0;
            for (int j = 1; j <= n; j++) t = max(t, a[j][i]);
            res = min(res, t);
        }
        return res;
    };

    for (int i = 1; i < n; i++) {
        a[1][i] = i;
    }
    a[1][n] = k;

    priority_queue<int> q;
    for (int i = 1; i <= n * n; i++) {
        if (1 <= i and i < n) continue;
        if (i == k) continue;
        q.ep(i);
    }

    for (int i = 2, j = 1; i <= n; i++, j++) {
        a[i][j] = q.top();
        q.pop();
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) continue;
            a[i][j] = q.top();
            q.pop();
        }
    }


    // assert(check() == k);

    if (check() != k) { puts("No"); return; }

    // cout << check() << '\n';

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << " \n"[j == n];
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}