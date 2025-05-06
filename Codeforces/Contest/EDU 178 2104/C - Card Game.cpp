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
    string s;
    cin >> s;
    int x = s[0] == 'A';
    int y = s[n - 1] == 'A';
    if (x and y) {
        cout << "Alice\n";
    } else if (!x and !y) {
        cout << "Bob\n";
    } else {
        
        if (x) {
            // A 1 B n
            bool f = 0;
            for (int i = n - 2; i >= 1; i--) {
                if (s[i] == 'B') {
                    f = 1;
                    break;
                }
            }

            if (!f) {
                cout << "Alice\n";
            } else {
                cout << "Bob\n";
            } 
        }
        
        if (y) {
            // A n B 1
           if (s[n - 2] == 'A') {
                // A n B 1 A n - 1
                cout << "Alice\n";
            } else {
                // A n B 1 B n - 1
                cout << "Bob\n";
            } 
        }
        
    }
}

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}

