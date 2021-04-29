#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

int main()
{
	int T;
	std::cin >> T;
	for (; T--; )
	{
		int n, k, f = 1;
		std::string s;
		std::cin >> n >> k >> s;
		s = ' ' + s;
		if (k * 2 >= n) { puts("NO"); continue; }
		for (int i = 1; i <= k; i++) if (s[i] != s[n - i + 1]) f = 0;
		puts(f ? "YES" : "NO");
	}
	return 0;
}
