#include <bits/stdc++.h>
using namespace std;

const int N = 5000 + 10;

int n;
int sab[N], tab[N];
int xpn[N], xbn[N], xp[N], xb[N];
int pp[N], bb[N];
int ansp[N], ansb[N], tot;
int vis[N], vclock;

int query(int i, int j) {
	/*
	int p[] = { 0, 1, 2, 0 };
	int b[] = { 0, 1, 2, 0 };
	return p[i] ^ b[j];
	*/
	printf("? %d %d\n", i, j);
	fflush(stdout);
	int res;
	scanf("%d", &res);
	return res;
}
bool check() {
	vclock++;
	for(int i = 0; i < n; i++) {
		if(0 <= pp[i] && pp[i] < n && vis[pp[i]] != vclock) {
			vis[pp[i]] = vclock;
		} else {
			return false;
		}
	}
	for(int i = 0; i < n; i++) 
		if((bb[i] ^ bb[0]) != xb[i]) return false;
	for(int i = 0; i < n; i++) {
		if((pp[i] ^ bb[i]) != sab[i]) return false;
		if((pp[i] ^ bb[(i+1)%n]) != tab[i]) return false;
	}
	return true;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		sab[i] = query(i, i);
		tab[i] = query(i, (i + 1) % n);
	}
	for(int i = 0; i < n; i++) {
		xpn[i] = sab[(i+1) % n] ^ tab[i];
		xbn[i] = sab[i] ^ tab[i];
	}
	xp[0] = xb[0] = 0;
	for(int i = 1; i < n; i++) {
		xp[i] = xpn[i - 1] ^ xp[i - 1];
		xb[i] = xbn[i - 1] ^ xb[i - 1];
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			pp[j] = i ^ xp[j];
			bb[pp[j]] = j;
		}
		if(check()) {
			if(tot == 0) {
				memcpy(ansp, pp, sizeof(ansp));
				memcpy(ansb, bb, sizeof(ansb));
			}
			/*
			for(int i = 0; i < n; i++) 
				printf("%d ", pp[i]);
			printf("\n");
			for(int i = 0; i < n; i++) 
				printf("%d ", bb[i]);
			printf("\n");
			*/
			tot++;
		}
	}
	printf("!\n");
	printf("%d\n", tot);
	for(int i = 0; i < n; i++) 
		printf("%d ", ansp[i]);
	printf("\n");
	fflush(stdout);
	/*
	for(int i = 0; i < n; i++) 
		printf("%d ", ansb[i]);
	printf("\n");
	*/
	
}

