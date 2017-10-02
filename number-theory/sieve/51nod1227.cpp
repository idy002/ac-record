#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int Mod = 1e9 + 7;
const int Inv2 = (Mod + 1) / 2;
const int Inv3 = (Mod + 1) / 3;
const int Inv6 = 1LL * Inv2 * Inv3 % Mod;

int notprime[N];
long long f[N];
map<long long,long long> mp;
vector<int> primes;

void sieve(int n) {
	f[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			f[i] = 1 - i;
		}
		for(int p : primes) {
			int j = i * p;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				f[j] = f[i];
				break;
			} else {
				f[j] = f[i] * (1 + Mod - p) % Mod;
			}
		}
	}
	for(int i = 2; i <= n; i++)
		f[i] = (f[i-1] + f[i]) % Mod;
}
long long S(long long a, long long b) {
	return (a + b) % Mod * ((b - a + 1) % Mod) % Mod * Inv2 % Mod;
}
long long F(long long n) {
	if(n <= 1e7) return f[n];
	if(mp.count(n)) return mp[n];
	long long & ans = mp[n];
	ans = n % Mod;
	for(long long d = 2, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		ans -= S(d,dd) * F(n / d) % Mod;
		if(ans < 0) ans += Mod;
	}
	return ans;
}
long long G(long long n) {
	n %= Mod;
	return n * (n + 1) % Mod * (n + 2) % Mod * Inv6 % Mod;
}
long long solve(long long n) {
	long long ans = 0;
	for(long long d = 1, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		ans += G(n / d) * (F(dd) - F(d-1)) % Mod;
		while(ans < 0) ans += Mod;
		while(ans >= Mod) ans -= Mod;
	}
	return ans;
}
int main() {
	sieve(1e7);
	long long a, b;
	scanf("%lld%lld", &a, &b);
	long long ans = (solve(b) - solve(a - 1) + Mod) % Mod;
	printf("%lld\n", ans);
}


