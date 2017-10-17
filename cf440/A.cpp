#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	scanf("%d", &q);
	for(int i = 1; i <= q; i++) {
		int n;
		scanf("%d", &n);
		if(n <= 3) {
			printf("-1\n");
		} else {
			int a = n / 4;
			int b = n % 4;
			if(b == 0) {
				printf("%d\n", a);
			} else if(b == 1) {
				if(a == 1)
					printf("%d\n", -1);
				else
					printf("%d\n", a - 1);
			} else if(b == 2) {
				printf("%d\n", a);
			} else if(b == 3) {
				if(a <= 2)
					printf("%d\n", -1);
				else 
					printf("%d\n", a - 1);
			}
		}
	}
	
}

