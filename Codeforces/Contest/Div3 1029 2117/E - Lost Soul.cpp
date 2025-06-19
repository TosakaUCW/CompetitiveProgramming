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
	int n = read();

    vector<int> a(n), b(n);
    for (auto &x : a) x = read();
    for (auto &x : b) x = read();

    if (a[n - 1] == b[n - 1]) {
        cout << n << "\n";
        return;
    }

    vector<int> vis(n + 1);

    int ans = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] == b[i]
            or a[i] == a[i + 1] or b[i] == b[i + 1]
            or vis[a[i]] or vis[b[i]]) {
            ans = i;
            break;
        }

        vis[a[i + 1]] = vis[b[i + 1]] = 1;
    }

    cout << ans + 1 << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}