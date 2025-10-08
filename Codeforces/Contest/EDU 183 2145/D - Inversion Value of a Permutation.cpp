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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
using pii = pair<int, int>;
const int inf = 1e18;

int val(int x) { return x * (x - 1) / 2; }
const int N = 30 * 30;
int f[N], g[N];
void init() {
    for (int i = 1; i < N; i++) {
        f[i] = 1e9;
        for (int j = 2; val(j) <= i; j++) {
            if (f[i - val(j)] + j < f[i]) {
                f[i] = f[i - val(j)] + j;
                g[i] = j;
            }
        }
    }
}

void solve() {
    int n = read();
    int k = read();

    vector<int> a(n);
    ranges::iota(a, 0);
    ranges::reverse(a);

    k = val(n) - k;
    for (int i = 0; i < n and k; ) {
        int len = g[k];
        if (i + len > n) break;
        reverse(a.begin() + i, a.begin() + i + len);

        k -= val(len);
        i += len;
    }

    if (k) {
        cout << "0\n";
    } else {
        for (auto x : a) cout << x + 1 << " ";
        cout << '\n';
    }
}

signed main() {
    init();
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}