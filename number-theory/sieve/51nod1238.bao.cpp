#include <bits/stdc++.h>
using namespace std;

const int Mod = 1e9 + 7;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return a / gcd(a,b) * b;
}
int main() {
	long long n;
	scanf("%lld", &n);
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			ans += lcm(i,j);
			ans %= Mod;
		}
	printf("%lld\n", ans);
}

