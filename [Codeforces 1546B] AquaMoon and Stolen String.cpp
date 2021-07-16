#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <string>
#include <iostream>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == 45, ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 5e5 + 5;

int n, m;
int a[N];
std::string s;

void solve()
{
	n = read(), m = read();
	memset(a, 0, sizeof a);
	for (int i = 1; i <= n; i++)
	{
		std::cin >> s;
		for (int j = 0; j < m; j++)
			a[j] += s[j] - 48;
	}
	for (int i = 1; i < n; i++)
	{
		std::cin >> s;
		for (int j = 0; j < m; j++)
			a[j] -= s[j] - 48;
	}
	for (int i = 0; i < m; i++) putchar(a[i] + 48);
	puts("");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
