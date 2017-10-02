#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int Mod = 1e9 + 7;
const int Inv2 = (Mod + 1) / 2;
const int Inv3 = (Mod + 1) / 3;
const int Inv6 = (long long)Inv2 * Inv3 % Mod;

long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a % b);
}
long long lcm(long long a, long long b) {
	return a / gcd(a,b) * b;
}

int notprime[N]; 
long long f[N];
vector<int> primes;
map<long long,long long> mp;

void sieve(int n) {
	f[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			f[i] = (long long)i * (1 - i) % Mod;
			if(f[i] < 0) f[i] += Mod;
		}
		for(int p : primes) {
			int j = i * p;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				f[j] = (long long)f[i] * p % Mod;
				break;
			} else {
				f[j] = (long long)f[i] * p % Mod * (1 - p) % Mod;
				if(f[j] < 0) f[j] += Mod;
			}
		}
	}
	for(int i = 1; i <= n; i++)
		f[i] = (f[i] + f[i - 1]) % Mod;
}
long long S(long long n) {
	n %= Mod;
	return n * (n + 1) % Mod * (n + n + 1) % Mod * Inv6 % Mod;
}
long long F(long long n) {
	if(n <= 1e7) return f[n];
	auto it = mp.find(n);
	if(it != mp.end()) return it->second;
	long long rt = ((1 + n) % Mod) * (n % Mod) % Mod * Inv2 % Mod;
	for(long long d = 2, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		rt -= F(n / d) * (S(dd) - S(d - 1)) % Mod;
		while(rt >= Mod) rt -= Mod;
		while(rt < 0) rt += Mod;
	}
	return mp[n] = rt;
}
long long solve(long long n) {
	long long rt = 0;
	for(long long d = 1, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		long long rg = n / d % Mod;
		rg = (rg * (1 + rg) / 2) % Mod;
		rg = (rg * rg) % Mod;
		rt = (rt + rg * (F(dd) - F(d - 1))) % Mod;
		if(rt < 0) rt += Mod;
	}
	return rt;
}
int main() {
	sieve(1e7);
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", solve(n));
}

