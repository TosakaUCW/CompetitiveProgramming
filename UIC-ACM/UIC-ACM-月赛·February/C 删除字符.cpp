#include <bits/stdc++.h>
#define int long long
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
int n, buk[27];
void solve()
{
    string s;
    cin >> n >> s;
    for (int i = 0; i < 26; i++) buk[i] = 0;
    int ans = 0, cnt = 0;
    for (auto ch : s)
    {
        if (!buk[ch - 'a']) cnt++;
        buk[ch - 'a']++;
        ans += cnt;
    }
    cout << ans << '\n';
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("C.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    return 0;
}