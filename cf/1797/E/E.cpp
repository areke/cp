#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <limits>
#include <assert.h>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;

void dfs(int x, vector<map<long long, int> >)

long long MAXN = 5e6 + 10;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<long long> e(MAXN + 1, 0);
	e[1] = 1;
	for (int i = 2; i <= MAXN; i++) {
		if (e[i] != i) continue;
		e[i] = i - 1;
		for (int j = i; j <= MAXN; j+=i) {
			e[j] /= i;
			e[j] *= (i - 1);
		}
	}
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<map<long long, int> > v(n); 
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		while (a[i]) {
			v[i][a[i]] = cnt;
			a[i] = e[a[i]];
			if (a[i] == 1) break;
		}
	}
	map<pair<long long, int> > comp;
	for (int i = 0; i < n; i++) {
		dfs(i, v, comp);
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
