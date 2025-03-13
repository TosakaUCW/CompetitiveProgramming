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

void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<int> vis(n + 1);
    for (auto x : a) vis[x] = 1;

    int p = -1;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            p = i;
            break;
        }
    }
    int mn = -1, mx = -1;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) mn = i;
        if (a[i] == n) mx = i;
    }

    if (p != -1) {
        int q = p == 1 ? 2 : 1;
        cout << "? " << p << " " << q << endl;

        // int res = read();
        int res; cin >> res;
        if (res == 0) {
            cout << "! A" << endl;
        } else {
            cout << "! B" << endl;
        }
    } else {
        int res1, res2;
        cout << "? " << mn << " " << mx << endl;
        cin >> res1;
        cout << "? " << mx << " " << mn << endl;
        cin >> res2;

        if (res1 == res2 and res1 >= n - 1 and res2 >= n - 1) {
            cout << "! B" << endl;
        } else {
            cout << "! A" << endl;
        }
    }

}

signed main() {
    int T; cin >> T;
    for (; T--; solve());
    // solve();
    return 0;
}
