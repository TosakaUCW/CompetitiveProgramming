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
using pii = std::pair<int, int>;
#define fi first
#define se second

void solve() {
    int n = read();
    int x = read();
    int k = read();
    string s;
    cin >> s;

    int now = x;
    int a = 0, b = 0;
    if (now != 0) {
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') now--;
            else now++;
            if (now == 0) { a = i + 1; break; }
        }    
    }
    
    now = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'L') now--;
        else now++;
        if (now == 0) { b = i + 1; break; }
    }
    
    int ans = 0;
    if (a != 0) {
        if (k >= a) k -= a, ans++;
        if (b != 0) ans += k / b;
    }

    cout << ans << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
