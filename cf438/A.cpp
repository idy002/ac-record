/*
 * ac
 */
#include <bits/stdc++.h>
using namespace std;

int n;
char ss[111][22], tt[22];

void yes() {
	printf("YES\n");
	exit(0);
}
void no() {
	printf("NO\n");
	exit(0);
}
int main() {
	scanf("%s", tt);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%s", ss[i]);
	for(int i = 1; i <= n; i++) {
		if(ss[i][0] == tt[0] && ss[i][1] == tt[1])
			yes();
		for(int j = 1; j <= n; j++) {
			if(ss[i][1] == tt[0] && ss[j][0] == tt[1])
				yes();
		}
	}
	no();
}

