#include <bits/stdc++.h>
using i64 = long long;
#define int i64
#define pb push_back
#define ep emplace
#define eb emplace_back
using std::cerr;
using std::max, std::min, std::swap, std::array;
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar()) {
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
// using namespace std;
using std::ostream;
template <class T1, class T2> ostream &operator<<(ostream &os, const std::pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; ++i) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cerr << *i << " "; cerr << '\n'; }
using pii = std::pair<int, int>;
#define fi first
#define se second

const int inf = 1e18;

void solve() {
    int n = read();
    int k = read() - 1;

    if (n <= 60 and k >= (1LL << (n - 1))) {
        cout << "-1\n";
        return;
    }

    vector<int> p(n);
    int l = 0, r = n - 1;
    for (int i = 1; i < n; i++) {
        if (n - 1 - i > 60 or k < (1LL << (n - 1 - i))) {
            p[l++] = i;
        } else {
            p[r--] = i;
            k -= 1LL << (n - 1 - i);
        }
    }
    p[l] = n;
    // cout << p << '\n';
    for (int i = 0; i < n; i++) {
        cout << p[i] << " \n"[i == n - 1];
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}