#include <bits/stdc++.h>
// #define int long long
using pii = std::pair<int, int>;
#define pb push_back
using std::cin, std::cout, std::string;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}
const int N = 1e6 + 5;
const int INF = 1 << 30;
// const long long INF = 1LL << 60;
int n;
void solve()
{
    string s1, s2;
    cin >> n >> s1 >> s2;
    string res = s1[0] + s2;
    int ans = 0;
    for (int i = 1; i < n; i++)
        if (res[i] > s1[i])
            res[i] = s1[i], ans = 0;
        else if (res[i] == s1[i])
            ans++;
        else if (res[i] < s1[i])
            break;
    cout << res << '\n' << ans + 1 << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("B.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}