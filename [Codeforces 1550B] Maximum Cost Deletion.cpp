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

int cnt[2], tot[2];

void solve()
{
	int n = read(), a = read(), b = read();
	int ans = a * n;
	std::string s;
	std::cin >> s;
	cnt[0] = cnt[1] = tot[0] = tot[1] = 0;
	for (int i = 0; i < n; i++) tot[s[i] - 48]++;
	for (int i = 0; i < n; i++)
	{
		int st = i, ed = i;
		for (; ed + 1 < n and s[ed + 1] == s[st]; ed++);
		i = ed, cnt[s[st] - 48]++;
	}
	ans += std::max(std::min(cnt[0], cnt[1]) * b + b, b * n);
	printf("%d\n", ans);
}

int main()
{
	for (int T = read(); T--; solve());
	return 0;
}

