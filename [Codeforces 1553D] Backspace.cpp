#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>

std::string s, t;

bool solve()
{
	std::cin >> s >> t;
	int n = s.size(), m = t.size();
	if (n < m) return false;
	int p = (n - m) & 1, q = 0, k = 0;
	for (int i = p; i < n; i++)
	{
		if (k == 1) { k = 0; continue; }
		if (q < m and s[i] == t[q]) q++;
		else k++;
	}
	return q == m;
}

int main()
{
	int T;
	for (scanf("%d", &T); T--; puts(solve() ? "YES" : "NO"));
	return 0;
}
