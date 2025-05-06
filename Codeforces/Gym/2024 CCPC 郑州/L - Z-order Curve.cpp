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
    int L = read(), R = read();

    if (L == 0 and R == 0) {
        cout << "0\n";
        return;
    }

    int x = 0, y = 4;
    while (y - 1 < R) {
        y = y * 4;
    }

    while (1) {
        int b = y / 4;

        if (y - b <= L) {
            // [y - b, y - 1]
            L -= (y - b);
            // R -= (y - 1);
            R -= (y - b);
        } else if (y - 2 * b <= L) {
            L -= (y - 2 * b);
            R -= (y - 2 * b);
        } else if (y - 3 * b <= L) {
            if (R <= y - 2 * b - 1) {
                L -= (y - 3 * b);
                R -= (y - 3 * b);
            } else {
                break;
            }
        } else {
            int r = y / 4;
            if (R < r) {
                y /= 4;
            } else {
                break;
            }
        }
    }

    cout << L << '\n';
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}