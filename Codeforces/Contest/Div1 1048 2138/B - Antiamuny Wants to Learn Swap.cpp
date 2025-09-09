#include <bits/stdc++.h>
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
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
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

void solve() {
    int n = read();
    int q = read();

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) a[i] = read();

    vector<int> l(n + 1, 0);
    {
        vector<int> st;
        st.reserve(n);
        for (int i = 1; i <= n; i++) {
            while (!st.empty() and a[st.back()] <= a[i]) st.pop_back();
            l[i] = st.empty() ? 0 : st.back();
            st.eb(i);
        }
    }
    vector<int> r(n + 1, n + 1);
    {
        vector<int> st;
        st.reserve(n);
        for (int i = n; i >= 1; --i) {
            while (!st.empty() and a[st.back()] >= a[i]) st.pop_back();
            r[i] = st.empty() ? n + 1 : st.back();
            st.eb(i);
        }
    }

    vector<int> f(n + 1, n);
    for (int i = 1; i <= n; i++) {
        if (l[i] != 0 && r[i] != n + 1) {
            f[l[i]] = min(f[l[i]], r[i] - 1);
        }
    }
    for (int i = n - 1; i >= 1; i--) {
        f[i] = min(f[i], f[i + 1]);
    }

    while (q--) {
        int l = read(), r = read();
        if (r <= f[l]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}