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

#define ls (p << 1)
#define rs (p << 1 | 1)
#define mid (l + r >> 1)

void solve() {
    int n = read();

    vector g(n + 1, vector(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        for (int j = 0; j < n; j++) {
            g[i][j + 1] = s[j] - 48;
        }
    }

    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (g[i][j]) deg[i]++;
        }
    }

    int A = 1, B = -1, C = -1;
    for (int i = 2; i <= n; i++) {
        if (deg[i] > deg[A]) A = i;
    }

    if (deg[A] == n - 1) {
        cout << "NOT FOUND\n";
        return;
    }

    vector<int> s1(n + 1);
    for (int i = 1; i <= n; i++) {
        if (g[i][A]) s1[i] = 1, B = i;
    }
    if (B == -1) {
        cout << "NOT FOUND\n";
        return;
    }
    deg.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i] and s1[j] and g[i][j]) {
                deg[i]++;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (s1[i] and deg[i] > deg[B]) B = i;
    }

    vector<int> s2(n + 1);
    for (int i = 1; i <= n; i++) {
        if (g[i][B]) s2[i] = 1, C = i;
    }
    if (C == -1) {
        cout << "NOT FOUND\n";
        return;
    }
    deg.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (s2[i] and s2[j] and g[i][j]) {
                deg[i]++;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (s2[i] and deg[i] > deg[C]) C = i;
    }

    cout << A << ' ' << B << ' ' << C << '\n';
}

signed main() {
    solve();
    return 0;
}