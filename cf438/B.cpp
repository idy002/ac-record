/*
 * ac
 */
#include <bits/stdc++.h>
using namespace std;

bool in(int a, int b, int x) {
	if(a <= b) {
		return a <= x && x <= b;
	} else {
		return in(a,12 * 3600,x) || in(0,b,x);
	}
}
void yes() {
	printf("YES\n");
	exit(0);
}
void no() {
	printf("NO\n");
	exit(0);
}
int main() {
	int h, m, s, t1, t2;
	int dh, dm, ds, dt1, dt2;
	scanf("%d%d%d%d%d", &h, &m, &s, &t1, &t2);
	ds = s * 60 * 12;
	dm = (m * 60+ s) * 12;
	dh = (h % 12) * 3600 + m * 60 + s;
	dt1 = (t1 % 12) * 3600;
	dt2 = (t2 % 12) * 3600;
	vector<int> vc;
	vc.push_back(ds);
	vc.push_back(dm);
	vc.push_back(dh);
	sort(vc.begin(), vc.end());
	for(int i = 0; i < (int)vc.size(); i++) {
		int cur = vc[i];
		int nxt = vc[(i + 1) % vc.size()];
		if(in(cur,nxt,dt1) && in(cur,nxt,dt2))
			yes();
		if(i == 2 && cur == nxt) {
			yes();
		}
	}
	no();
}

