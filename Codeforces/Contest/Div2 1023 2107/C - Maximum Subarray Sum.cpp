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
const int inf = 1e13;

void solve() {
    int n = read();
    int k = read();

    string s; cin >> s;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    int pos = -1;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') {
            pos = i;
            a[i] = -inf;
        }
    }

    int mx = 0, cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = max(cur + a[i], a[i]);
        mx = max(mx, cur);
    }
    if (mx > k or (mx != k and pos == -1)) {
        cout << "No\n";
        return;
    }

    if (pos != -1) {
        int mx = 0, cur = 0;
        for (int i = pos + 1; i <= n; i++) {
            cur += a[i];
            mx = max(mx, cur);
        }
        int L = mx;

        mx = 0, cur = 0;
        for (int i = pos - 1; i >= 1; i--) {
            cur += a[i];
            mx = max(mx, cur);
        }
        int R = mx;

        a[pos] = k - L - R;
    }

    cout << "Yes\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    return 0;
}