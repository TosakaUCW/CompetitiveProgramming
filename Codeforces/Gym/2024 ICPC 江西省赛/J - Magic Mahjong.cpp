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
    string s;
    cin >> s;

    int n = s.size();

    unordered_map<char, map<int, int>> mp;

    for (int i = 0; i < n; i += 2) {
        int x = s[i] - '0';
        int y = s[i + 1];

        mp[y][x]++;
    }

    int cnt = 0;

    bool to = 1;
    bool pi = 1;

    for (auto [_, buk] : mp) {
        // cout << _ << ":\n";

        if (_ != 'z' and (buk[1] == 0 or buk[9] == 0)) {
            to = 0;
        }

        for (auto [x, y] : buk) {
            if (_ == 'z') cnt++;
            // cout << x << ' ' << y << '\n';
            if (y != 2 and y != 0) {
                pi = 0;
            }
        }
    }

    if (cnt != 7) to = 0;
    // cout << cnt << '\n';

    if (to) {
        cout << "Thirteen Orphans\n";
    } else if (pi) {
        cout << "7 Pairs\n";
    } else {
        cout << "Otherwise\n";
    }



    // cout << "--------";
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}