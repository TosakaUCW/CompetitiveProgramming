#include <stdio.h>
#include <algorithm>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

bool solve()
{
	int n = read();
	static char s[100000 + 5];
	scanf("%s", s);
	int x = 0, y = 0;
	for (int i = 0; i < n; i++)
	{
		s[i] == 'T' ? ++x : ++y;
		if (x < y) return false;
	}
	x = y = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		s[i] == 'T' ? ++x : ++y;
		if (x < y) return false;
	}
	return x == y * 2;
}

int main()
{
	for (int T = read(); T--; puts(solve() ? "YES" : "NO"));
	return 0;
}
