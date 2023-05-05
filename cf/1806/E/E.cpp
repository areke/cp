#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
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
 
int n, q;
vector<long long> d(1e5, 0);
vector<int> dc(1e5 + 1, 0);
vector<int> l(1e5, 0);
vector<vector<int> > r(1e5);
vector<vector<long long> > m(1e5, vector<long long>(325, -1));
vector<long long> a(1e5);
vector<int> p(1e5);
void dfs(int x, int cur) {
	d[x] = cur;
	for (int e : r[x]) {
		dfs(e, cur + 1);
	}
}
 
long long solve(long long x, long long y) {
	if (y < x) swap(x, y);
	if (x == -1) return 0;
	
	if (dc[d[x]] < 325 && m[x][l[y]] >= 0) return m[x][l[y]];
	long long res = a[x] * a[y];
	res += solve(p[x], p[y]);
	if (dc[d[x]] >= 325) return res;
	return m[x][l[y]] = res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n >> q;
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	p[0] = -1;
	for (int i = 0; i < n - 1; i++) {
		int x;
		cin >> x;
		x--;
		p[i + 1] = x;
		r[x].push_back(i + 1);
	}
	dfs(0, 0);
	for (int i = 0; i < n; i++) {
		l[i] = dc[d[i]];
		dc[d[i]]++;
		
	}
	
	for (int i = 0; i < q; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		cout << solve(x, y) << endl;
	}
 
	
 
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}