/*
 * 51nod 1239
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
const int Mod = 1e9 + 7;
const int Inv2 = (Mod + 1) / 2;

int n;
long long sphi[N];
bool notprime[N];
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
	for(int i = 2; i <= n; i++)
		sphi[i] = (sphi[i] + sphi[i-1]) % Mod;

}
long long M(long long n) {
	if(n <= 1e7) return sphi[n];
	if(mp.count(n)) return mp[n];
	long long rt = ((1 + n) % Mod) * (n % Mod) % Mod * Inv2 % Mod;
	for(long long d = 2, dd; d <= n; d = dd + 1) {
		dd = n / (n /d);
		rt -= M(n / d) * ((dd - d + 1) % Mod) % Mod;
		if(rt < 0) rt += Mod;
	}
	return mp[n] = rt;
}
int main() {
	sieve(1e7);
	long long n;
	scanf("%lld", &n);
	printf("%lld\n", M(n));
}

