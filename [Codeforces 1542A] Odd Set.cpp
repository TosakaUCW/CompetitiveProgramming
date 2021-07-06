#include <stdio.h>
#include <algorithm>
#include <memory.h>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < 48 or ch > 57) f = ch == '-', ch = getchar();
	while (48 <= ch and ch <= 57) x = x * 10 + ch - 48, ch = getchar();
	return f ? -x : x;
}

const int N = 2e2 + 5;

int n, odd, even;

void solve()
{
	n = read() * 2, odd = even = 0;
	for (int i = 1; i <= n; i++) 
	{
		int x = read();
		if (x & 1) odd++;
		else even++;
	}
	puts(odd == even ? "Yes" : "No");
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}
