/*
 * ac
 */
#include <bits/stdc++.h>
using namespace std;

const int N = 210;
const int L = 11;
const int M = (1<<(L+1)) + 20;

int n, m;
bool dp[N][M];
int son[N][2], idc;
string str[N];
string stat[M];

void init() {
	for(int l = 1; l <= L; l++) {
		for(int i = 0; i < (1<<l); i++) {
			++idc;
			string &s = stat[idc];
			s.resize(l);
			for(int j = 0; j < l; j++)
				s[j] = (char)('0' + ((i>>j) & 1));
		}
	}
}
string merge(string a, string b) {
	string c;
	for(int i = 0; i < a.size(); i++)
		c.push_back(a[i]);
	for(int i = 0; i < b.size(); i++)
		c.push_back(b[i]);
	if(c.size() > 2 * L) {
		string cc;
		for(int i = 0; i < L; i++)
			cc.push_back(c[i]);
		for(int i = 0; i < L; i++)
			cc.push_back(c[c.size() - L + i]);
		return cc;
	} else {
		return c;
	}
}
int main() {
	init();
	cin >> n;
	for(int i = 1; i <= n; i++) 
		cin >> str[i];
	cin >> m;
	for(int i = 1; i <= m; i++) {
		int a, b;
		cin >> a >> b;
		str[i + n] = merge(str[a], str[b]);
		son[i + n][0] = a;
		son[i + n][1] = b;
	}
	for(int i = 1; i <= n + m; i++) {
		if(i <= n) {
			for(int j = 1; j <= idc; j++) {
				for(int k = 0; k + stat[j].size() <= str[i].size(); k++)
					if(str[i].substr(k,stat[j].size()) == stat[j]) {
						dp[i][j] = true;
						break;
					}
			}
		} else {
			int a, b;
			a = son[i][0];
			b = son[i][1];
			for(int j = 1; j <= idc; j++) {
				dp[i][j] = (dp[a][j] || dp[b][j]);

				if(dp[i][j]) {
//						printf("dp[%s][%s] = true\n", str[i].c_str(), stat[j].c_str());
					continue;
				}
				/*
				if(i == 4 && stat[j] == "111") {
					printf("h\n");
					printf("stat[j].size() = %u\n", stat[j].size());
					printf("str[a].size() = %u\n", str[a].size());
					printf("str[b].size() = %u\n", str[b].size());
				}
				*/
				for(int l = 1; l < stat[j].size(); l++) {
					if(!(l <= str[a].size() && (int)stat[j].size() - l <= (int)str[b].size())) continue;
//					if(i == 4 && stat[j] == "111") {
//						string ca = str[a].substr((int)str[a].size() - l, l);
//						string cb = str[b].substr(0, (int)stat[j].size() - l);
//						string cc = stat[j];
//						printf("test %s+%s = %s\n", ca.c_str(), cb.c_str(), cc.c_str());
//					}
					if(str[a].substr((int)str[a].size() - l, l) + str[b].substr(0, (int)stat[j].size() - l) == stat[j]) {
						dp[i][j] = true;
//						printf("dp[%s][%s] = true\n", str[i].c_str(), stat[j].c_str());
						break;
					}
				}
			}
		}
	}
	for(int i = n + 1; i <= n + m; i++) {
		bool ok[L + 1];
		memset(ok, true, sizeof(ok));
		for(int j = 1; j <= idc; j++) {
			if(dp[i][j] == false) {
				ok[stat[j].size()] = false;
			}
		}
		for(int k = L; k >= 0; k--)
			if(ok[k]) {
				printf("%d\n", k);
				break;
			}
	}
}

