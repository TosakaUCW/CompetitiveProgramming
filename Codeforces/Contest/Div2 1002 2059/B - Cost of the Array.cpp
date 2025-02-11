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
    int k = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    if (n == k) {
        int ans = -1;
        for (int i = 2; i <= n; i += 2) {
            if (a[i] != i / 2) {
                ans = i / 2;
                break;
            }
        }
        if (ans == -1) {
            ans = n / 2 + 1;
        }
        cout << ans << '\n';
        return;
    }

    int pos = -1;
    for (int i = 2; i <= n - k + 2; i++) {
        if (a[i] != 1) {
            pos = i;
            break;
        }
    }
    if (pos != -1) {
        cout << "1\n";
        return;
    }
    
    int ans = 2;
    for (int i = n - k + 1; i <= n and a[i] == ans; i += 2) {
        ans++;
    }
    cout << ans << '\n';
    return;
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
