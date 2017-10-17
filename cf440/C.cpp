#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int Mod = 1e9 + 7;

int n;
int xx[N], yy[N];
int fa[N];
map<int,vector<int> > mpx, mpy;
vector<int> vcs[N];
vector<int> vcsx[N], vcsy[N];

int find(int a) {
	return a == fa[a] ? a : fa[a] = find(fa[a]);
}
void unon(int a, int b) {
	fa[find(a)] = find(b);
}
long long mpow(long long a, long long b) {
	long long rt;
	for(rt = 1; b; b>>=1,a=(a*a)%Mod)
		if(b&1) rt=rt*a%Mod;
	return rt;
}
void unique(vector<int> &vc) {
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(),vc.end()), vc.end());
}
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		fa[i] = i;
		scanf("%d%d", xx+i, yy+i);
		mpx[xx[i]].push_back(i);
		mpy[yy[i]].push_back(i);
	}
	for(auto &p : mpx) {
		vector<int> &vc = p.second;
		for(int t = 1; t < (int)vc.size(); t++)
			unon(vc[t-1], vc[t]);
	}
	for(auto &p : mpy) {
		vector<int> &vc = p.second;
		for(int t = 1; t < (int)vc.size(); t++)
			unon(vc[t-1], vc[t]);
	}
	for(int i = 1; i <= n; i++) {
		int r = find(i);
		vcs[r].push_back(i);
		vcsx[r].push_back(xx[i]);
		vcsy[r].push_back(yy[i]);
	}
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		if(find(i) != i) continue;
		unique(vcsx[i]);
		unique(vcsy[i]);
		int atot = (int)vcs[i].size(), etot = (int)vcsx[i].size() + (int)vcsy[i].size();
		if(atot == etot - 1)
			ans = ans * (mpow(2, etot) + Mod - 1) % Mod;
		else
			ans = ans * mpow(2, etot) % Mod;
	}
	printf("%d\n", (int)ans);
}

