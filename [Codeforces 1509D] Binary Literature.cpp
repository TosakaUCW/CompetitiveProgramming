#include <stdio.h>
#include <algorithm>
#include <vector>

int read(int x = 0, int f = 0, char ch = getchar())
{
	while (ch < '0' or ch > '9')
		f = ch == '-', ch = getchar();
	while ('0' <= ch and ch <= '9')
		x = x * 10 + (ch ^ 48), ch = getchar();
	return f ? -x : x;
}

const int N = 2e5 + 5;

int n;
char s[3][N];
std::vector<int> cnt[2];

void solve(int p, int q, char ch)
{
#define x (s[p][i])
#define y (s[q][j])
	int i = 0, j = 0;
	for (; i < 2 * n and j < 2 * n; i++, j++)
		if (x == y) putchar(x);
		else if (x == ch)
		{
			while (j < 2 * n and y != ch)
				putchar(y), j++;
			putchar(ch);
		}
		else
		{
			while (i < 2 * n and x != ch)
				putchar(x), i++;
			putchar(ch);
		}
	while (i < 2 * n) putchar(x), i++;
	while (j < 2 * n) putchar(y), j++;
}

int main()
{
	for (int T = read(); T--; puts(""))
	{
		n = read(), cnt[0].clear(), cnt[1].clear();
		for (int i = 0; i < 3; i++) scanf("%s", s[i]);
		for (int i = 0; i < 3; i++)
		{
			int sum = 0;
			for (int j = 0; j < 2 * n; j++) sum += s[i][j] - '0';
			cnt[sum >= n].push_back(i);
		}
		if (cnt[0].size() >= 2) solve(cnt[0][0], cnt[0][1], '0');
		else solve(cnt[1][0], cnt[1][1], '1');
	}
	return 0;
}
