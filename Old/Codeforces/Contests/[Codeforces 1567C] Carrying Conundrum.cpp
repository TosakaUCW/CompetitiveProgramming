#include <stdio.h>
#include <iostream>
#include <string>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

void solve()
{
	std::string str, s[2];
	std::cin >> str;
	int n = str.size();
	for (int i = 0; i < n; i++) s[i & 1] += str[i];
	printf("%d\n", s[1].empty() ? stoi(s[0]) - 1 : (stoi(s[0]) + 1) * (stoi(s[1]) + 1) - 2);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("x.in", "r", stdin);
#endif
	for (int T = read(); T--; solve());
	return 0;
}

