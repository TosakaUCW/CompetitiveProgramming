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
	std::string s; int len, cnt = 0;
	std::cin >> len >> s;
	for (auto x : s) if (x == '0') cnt++;
	puts(cnt & 1 and cnt > 1 ? "ALICE" : "BOB");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
