#include <stdio.h>
#include <algorithm>
#include <memory.h>
#include <iostream>
#include <string>

#define int long long

const int N = 2e5 + 5;

int f[N][2];

void solve()
{
	std::string s;
	std::cin >> s;
	int len  = s.length();
	if (s[0] == '?') f[0][0] = f[0][1] = 1;
	else f[0][s[0] - 48] = 1;
	for (int i = 1; i < len; i++)
		if (s[i] == '?')
			f[i][0] += f[i - 1][1] + 1,
			f[i][1] += f[i - 1][0] + 1;
		else
			f[i][s[i] - 48] += f[i - 1][(s[i] - 48) ^ 1] + 1;
	int ans = 0;
	for (int i = 0; i < len; i++) 
		ans += std::max(f[i][0], f[i][1]),
		f[i][0] = f[i][1] = 0;
	printf("%lld\n", ans);
}

signed main()
{
    int T;
	for (std::cin >> T; T--; solve());
	return 0;
}
