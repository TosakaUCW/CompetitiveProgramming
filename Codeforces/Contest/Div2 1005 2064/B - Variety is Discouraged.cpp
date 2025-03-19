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

    vector<int> a(n);
    for (auto &x : a) x = read();

    std::map<int, int> freq;
    for (auto x : a) freq[x]++;

    set<int> st;
    for (auto [x, y] : freq) {
        if (y == 1) {
            st.ep(x);
        }
    }

    int res = 0, L = -1, R = -1;
    for (int l = 0, r = 0; r < n; r++) {
        if (st.count(a[r]) == 0) {
            l = r + 1; 
        } else {
            int len = r - l + 1;
            if (len > res) {
                res = len;
                L = l;
                R = r;
            }
        }
    }
  
    if (res == 0) {
        cout << "0\n";
    } else {
        cout << L + 1 << " " << R + 1 << "\n";
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
