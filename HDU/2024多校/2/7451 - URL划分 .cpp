#include <bits/stdc++.h>
using i64 = long long;
using pii = std::pair<int, int>;
using tuu = std::tuple<int, int, int>;
#define pb push_back
using std::cin, std::cout, std::string, std::vector;
int read(int x = 0, int f = 0, char ch = getchar())
{
    while (ch < 48 or 57 < ch) f = ch == 45, ch = getchar();
    while(48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
    return f ? -x : x;
}

const int N = 2e5 + 5;

void solve()
{
    string s;
    getline(cin, s);
    int n = s.size();
    
    int x = 0;
    
    for (int i = 2; i < n; i++)
        if (s[i] == '/' and s[i - 1] == '/' and s[i - 2] == ':')
            {
                cout << s.substr(0, i - 2) << '\n', x = i + 1;
                break;
            }
            
    bool f = 1;
    for (int i = x; i < n; i++)
        if (s[i] == '/')
        {
            if (f or s.substr(x, i - x).find('=') != string::npos)
                cout << s.substr(x, i - x) << '\n', f = 0;
            x = i + 1;
        }
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("x.in", "r", stdin);
#endif
    for (int T = read(); T--; solve());
    // solve();
    return 0;
}