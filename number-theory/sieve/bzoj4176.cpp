#include <bits/stdc++.h>
using namespace std;

int sigma(int n) {
	int ans = 0;
	for(int i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			ans++;
			if(i * i != n) ans++;
		}
	}
	return ans;
}
int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}
int lcm(int a, int b) {
	return a / gcd(a,b) * b;
}

int main() {
	int n = 30, m = 30;
	for(int i = 2; i <= n; i++)
		for(int j = 2; j <= m; j++)
			printf("%d %d s(%d) = %d s(%d) = %d s(%d) = %d s(%d) = %d\n", 
					i, j, i * j, sigma(i*j), i/gcd(i,j), sigma(i/gcd(i,j)), j/gcd(i,j), sigma(j/gcd(i,j)), gcd(i,j), sigma(gcd(i,j))
					);
}

