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
#define fi first
#define se second
#define debug(x) cout << #x << " = " << x << "\n";
#define vdebug(a) cout << #a << " = "; for (auto x : a) cout << x << " "; cout << "\n";
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << "(" << a.first << ", " << a.second << ")"; };
template <class T> ostream &operator<<(ostream &os, const vector<T> &as) { const int sz = as.size(); os << "["; for (int i = 0; i < sz; i++) { if (i >= 256) { os << ", ..."; break; } if (i > 0) { os << ", "; } os << as[i]; } return os << "]"; }
template <class T> void pv(T a, T b) { for (T i = a; i != b; i++) cerr << *i << " "; cerr << '\n'; }
template <class T> bool cmin(T &a, T b) { return (b < a) ? (a = b, true) : false; }
template <class T> bool cmax(T &a, T b) { return (a < b) ? (a = b, true) : false; }
using pii = pair<int, int>;
using tup = tuple<int, int, int>;
const int inf = 1e18;
const double eps = 1e-9;

vector<int> dp(26);
void prepare() {
    dp[0] = 1;
    for (int n = 1; n <= 25; n++) {
        for (int u = 0; u <= n - 1; u++) {
            for (int v = 0; v <= n - 1 - u; v++) {
                int w = n - 1 - u - v;
                dp[n] += dp[u] * dp[v] * dp[w];
            }
        }
    }
}

string decode(int n, int x) {
    if (n == 0) return "";
    for (int u = 0; u <= n - 1; u++) {
        for (int v = 0; v <= n - 1 - u; v++) {
            int w = n - 1 - u - v;
            int cur = dp[u] * dp[v] * dp[w];
            if (x >= cur) {
                x -= cur;
            } else {
                int z = x % dp[w];
                x /= dp[w];
                int y = x % dp[v];
                x /= dp[v];

                string A = decode(u, x);
                string B = decode(v, y);
                string C = decode(w, z);
                return "(" + A + "|" + B + ")" + C;
            }
        }
    }    
}

int encode(int n, string s) {
    if (n == 0) return 0;

    int L = 3 * n;

    int p = 0;
    int q = -1;
    int r = -1;

    int dep = 0;
    for (int i = 0; i < 3 * n; i++) {
        if (s[i] == '(') {
            dep++;
        } else if (s[i] == ')') {
            dep--;
            if (dep == 0) {
                r = i;
                break;
            }
        } else if (s[i] == '|' and dep == 1) {
            q = i;
        }
    }


    int lenA = (q - 1) - (1) + 1;
    int lenB = (r - 1) - (q + 1) + 1;
    int lenC = (3 * n - 1) - (r + 1) + 1;

    int u0 = lenA / 3;
    int v0 = lenB / 3;
    int w0 = lenC / 3;

    string A = s.substr(1, lenA);
    string B = s.substr(q + 1, lenB);
    string C = s.substr(r + 1, lenC);

    int x = 0;

    for (int u = 0; u <= n - 1; u++) {
        for (int v = 0; v <= n - 1 - u; v++) {
            int w = n - 1 - u - v;
            if (u == u0 and v == v0) {
                int cur = encode(u, A);
                cur *= dp[v];
                cur += encode(v, B);
                cur *= dp[w];
                cur += encode(w, C);
                return x + cur;
            } else {
                x += dp[u] * dp[v] * dp[w];
            }
        }
    }
}

signed main() {
    prepare();
    string s; cin >> s;
    if (s == "encode") {
        for (int T = read(); T--; ) {
            int n; string s;
            cin >> n >> s;
            cout << encode(n, s) << '\n';
        }
    } else {
        for (int T = read(); T--; ) {
            int n, x;
            cin >> n >> x;
            cout << decode(n, x) << '\n';
        }
    }
    return 0;
}