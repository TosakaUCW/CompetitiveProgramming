#include <bits/stdc++.h>
using i64 = long long;
// #define int i64
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

vector<int> del(auto A, auto B) {
    vector<int> res(26);
    for (int i = 0; i < 26; i++) {
        res[i] = A[i] - B[i];
    }
    return res;
}
vector<int> add(auto A, auto B) {
    vector<int> res(26);
    for (int i = 0; i < 26; i++) {
        res[i] = A[i] + B[i];
    }
    return res;
}
bool check(auto A, auto B) {
    for (int c = 0; c < 26; c++) {
        if (A[c] < B[c]) return 0;
        if ((A[c] - B[c]) % 2 != 0) return 0;
    }
    return 1;
}

void solve() {
    string s;
    cin >> s;

    int n = s.size();
    int m = n / 2;

    bool f = 1;
    for (int i = 0; i < m; i++) {
        if (s[i] != s[n - 1 - i]) { f = 0; break; }
    }
    if (f) { puts("0"); return; }

    vector<vector<int>> P1(m + 1, vector<int>(26, 0));
    vector<vector<int>> Q1(m + 1, vector<int>(26, 0));
    vector<int> mm1(m, 0);
    vector<int> sum1(m + 1, 0);
    vector<vector<int>> P2(m + 1, vector<int>(26, 0));
    vector<vector<int>> Q2(m + 1, vector<int>(26, 0));
    vector<int> mm2(m, 0);
    vector<int> sum2(m + 1, 0);

    for (int i = 0; i < m; i++) {
        P1[i + 1] = P1[i];
        Q1[i + 1] = Q1[i];
        P1[i + 1][s[i] - 'a']++;
        Q1[i + 1][s[n - 1 - i] - 'a']++;
        sum1[i + 1] = sum1[i] + (s[i] != s[n - 1 - i]);

        P2[i + 1] = P2[i];
        Q2[i + 1] = Q2[i];
        P2[i + 1][s[m + i] - 'a']++;
        Q2[i + 1][s[m - 1 - i] - 'a']++;
        sum2[i + 1] = sum2[i] + (s[m + i] != s[m - 1 - i]);
    }

    auto valid1 = [&](int L, int R) -> bool {
        if ((L > 0 and sum1[L] != 0) or (R < m - 1 and sum1[m] - sum1[R + 1] != 0)) return 0;
        return check(del(P1[R + 1], P1[L]), del(Q1[R + 1], Q1[L]));
    };

    auto valid2 = [&](int L, int R) -> bool {
        int Lp = L - m, Rp = R - m;
        if ((Lp > 0 and sum2[Lp] != 0) or (Rp < m - 1 and sum2[m] - sum2[Rp + 1] != 0)) return 0;
        return check(del(P2[Rp + 1], P2[Lp]), del(Q2[Rp + 1], Q2[Lp]));
    };

    auto valid3 = [&](int L, int R) -> bool {
        int X = (n - 1) - R;
        int mini = min(L, X);
        if (mini > 0 and sum1[mini] != 0) return 0;
        vector<int> forced(26, 0);
        if (L <= X and X - L > 0)
            forced = del(Q1[X], Q1[L]);
        else if (L > X and L - X > 0)
            forced = del(P1[L], P1[X]);

        vector<int> totalBlock = add(del(P1[m], P1[L]), del(P2[R - m + 1], P2[0]));
        return check(totalBlock, forced);
    };


    int ans = n;
    auto judge = [&](int mid) -> bool {
        for (int i = 0; i + mid <= n; i++) {
            int j = i + mid - 1;
            if ((j < m and valid1(i, j)) or 
                (i >= m and valid2(i, j)) or 
                (i < m and j >= m and valid3(i, j))) {
                return 1;
            }
        }
        return 0;
    };
    for (int L = 1, R = n; L <= R; ) {
        int mid = L + R >> 1;
        if (judge(mid)) ans = mid, R = mid - 1;
        else L = mid + 1;
    }
    cout << ans << '\n';
}

// abcde
// edcba

signed main() {
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}
