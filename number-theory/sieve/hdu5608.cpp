#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
const int Mod = 1e9 + 7;
const int Inv3 = (Mod + 1) / 3;

int ans[N];
map<int,int> mp;

void init(int n) {
	for(int i = 1; i <= n; i++)
		ans[i] = (long long)(i - 1) * (i - 2) % Mod;
	for(int i = 1; i <= n; i++) {
		for(int j = i + i; j <= n; j += i) {
			ans[j] -= ans[i];
			if(ans[j] < 0) ans[j] += Mod;
		}
	}
	for(int i = 2; i <= n; i++) {
		ans[i] += ans[i - 1];
		if(ans[i] >= Mod) ans[i] -= Mod;
	}
}
int S(int n) {
	return 1LL * n * (n - 1) % Mod * (n - 2) % Mod * Inv3 % Mod;
}
int F(int n) {
	if(n <= 1e6) return ans[n];
	if(mp.count(n)) return mp[n];
	int rt = S(n);
	for(int d = 2, dd; d <= n; d = dd + 1) {
		dd = n/(n/d);
		rt = rt - 1LL * F(n / d) * (dd - d + 1) % Mod;
		if(rt < 0) rt += Mod;
	}
	return mp[n] = rt;
}
int main() {
	int T;
	scanf("%d", &T);
	init(1e6);
	while(T--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", F(n));
	}
}

