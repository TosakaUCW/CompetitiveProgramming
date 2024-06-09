#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 47, ch = getchar();
	return f ? -x : x;
}

const int N = 2e2 + 5;

int last[N];
bool vis[N];

void solve()
{
	std::string s, t;
	std::cin >> s;
	memset(vis, 0, sizeof vis),
	memset(last, 0, sizeof last);
	int len = s.size();
	for (int i = 0; i < len; i++) last[s[i]] = i;
	for (int i = 0; i < len; i++)
		if (!vis[s[i]])
		{
			while (t.size() and t.back() < s[i] and last[t.back()] > i)
				t.pop_back();
			t += s[i];
			vis[s[i]] = true;
		}
	std::cout << t << '\n';
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
