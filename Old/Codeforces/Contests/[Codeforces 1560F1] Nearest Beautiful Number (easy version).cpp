#include <stdio.h>
#include <algorithm>
#include <set>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

int n, k;
std::string s;

int calc(std::string str)
{
    std::set<char> s;
    for (char ch : str) s.insert(ch);
    return s.size();
}

int conv(std::string str)
{
	int res = 0;
	for (auto ch : str) res = res * 10 + ch - 48;
	return res;
}

std::string solve()
{
	std::cin >> s >> k;
	n = s.size();
    if (calc(s) <= k) return s;
    for (int i = n - 1; i >= 0; i--)
    {
        std::string t = s;
        for (char j = s[i] + 1; j <= '9'; j++)
        {
            std::set<char> S;
            for (int l = 0; l < i; l++) S.insert(s[l]);
            t[i] = j, S.insert(j);
            if (calc(t.substr(0, i + 1)) > k) continue;
            char p = calc(t.substr(0, i + 1)) < k ? '0' : *S.begin();
            for (int l = i + 1; l < n; l++) t[l] = p;
            if (conv(t) >= conv(s)) return t;
        }
    }
}

int main()
{
	for (int T = read(); T--; std::cout << solve() << '\n');
	return 0;
}

