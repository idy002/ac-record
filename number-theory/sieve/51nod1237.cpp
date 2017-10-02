#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int Mod = 1e9 + 7;
const int Inv2 = (Mod + 1) / 2;

int notprime[N]; 
int sphi[N];
vector<int> primes;
map<long long,long long> mp;

void sieve(int n) {
	sphi[1] = 1;
	for(int i = 2; i <= n; i++) {
		if(!notprime[i]) {
			primes.push_back(i);
			sphi[i] = i - 1;
		}
		for(int p : primes) {
			int j = i * p;
			if(j > n) break;
			notprime[j] = true;
			if(i % p == 0) {
				sphi[j] = sphi[i] * p;
				break;
			} else {
				sphi[j] = sphi[i] * (p - 1);
			}
		}
	}
	for(int i = 1; i <= n; i++)
		sphi[i] = (sphi[i - 1] + sphi[i]) % Mod;
}
long long Sphi(long long n) {
	if(n <= 1e7) return sphi[n];
	if(mp.count(n)) return mp[n];
	long long & ans = mp[n];
	ans = (1 + n) % Mod * (n % Mod) % Mod * Inv2 % Mod;
	for(long long d = 2, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		ans -= Sphi(n / d) * ((dd - d + 1) % Mod) % Mod;
		while(ans < 0) ans += Mod;
	}
	return ans;
}

long long solve(long long n) {
	long long ans = 0;
	for(long long d = 1, dd; d <= n; d = dd + 1) {
		dd = n / (n / d);
		long long sub1 = ((n / d) % Mod) * ((n / d) % Mod) % Mod;
		long long sub2 = (Sphi(dd) - Sphi(d - 1) + Mod) % Mod;
		ans = (ans + sub1 * sub2) % Mod;
	}
	return ans;
}
long long gcd(long long a, long long b) {
	return b == 0 ? a : gcd(b, a%b);
}
long long solve2(long long n) {
	long long ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			ans = (ans + gcd(i,j))  % Mod;
	return ans;
}
int main() {
	sieve(1e7);
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", solve(n));
}

