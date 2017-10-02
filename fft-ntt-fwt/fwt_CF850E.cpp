#include <bits/stdc++.h>
using namespace std;

const int N = 20;
const int Mod = 1e9 + 7;

int n, U;
long long a[1<<N], b[1<<N], c[1<<N];
char ss[(1<<N) + 10];

void trans( long long a[], int flag ) {
    for( int b=0; b<n; b++ ) {
        int u = U ^ (1<<b);
        for( int s=u,t=1<<(n-1); t; s=(s-1)&u,t-- ) {
            long long l=a[s], r=a[s|(1<<b)];
            if( flag==1 ) {
                a[s] = l+r;
                a[s|(1<<b)] = l-r;
            } else {
                a[s] = (l+r)/2;
                a[s|(1<<b)] = (l-r)/2;
            }
        }
    }
}


int bitscount(int a) {
	int rt = 0;
	while(a) {
		rt++;
		a -= a & -a;
	}
	return rt;
}
int main() {
    scanf( "%d", &n );
    U = (1<<n)-1;
	scanf("%s", ss);
	for(int i = 0; i <= U; i++)
		a[i] = ss[i] - '0';
	for(int i = 0; i <= U; i++)
		b[i] = 1 - (ss[i] - '0');
    trans(a,1);
    trans(b,1);
    for( int s=0; s<=U; s++ )
        c[s] = a[s]*b[s];
    trans(c,-1);
	long long ans = 0;
	for(int i = 0; i <= U; i++) {
		ans += 1LL * c[i] * (1LL<<bitscount(i));
	}
	printf("%d\n", (int)(ans * 3 % Mod));
}

