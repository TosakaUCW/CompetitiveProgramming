#include <stdio.h>
#include <algorithm>
#include <memory.h>
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
	int n = read();
	std::string s;
	std::cin >> s;
	int cnt = 0, flag = 0;
	for (int i = 0; i < n; i++)
	{
		if (s[i] == '0') cnt++;
		if (s[i] != s[n - i - 1]) flag = 1;
	}
	if (!flag) puts(cnt == 1 or cnt % 2 == 0 ? "BOB" : "ALICE");
	else puts(cnt == 2 and n & 1 and s[n / 2] == '0' ? "DRAW" : "ALICE");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
