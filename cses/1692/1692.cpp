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
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <list>
#include <assert.h>
#include <array>
#include <cstring>
using namespace std;
int mask;

void dfs(int x, vector<set<int> > & v, vector<int> & res) {
	while (v[x].size()) {
		auto it = v[x].begin();
		v[x].erase(it);
		dfs(*it, v, res);
	}
	res.push_back(x);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m;
	cin >> n;
	if (n == 1) {
		cout << "10" << endl;
		return 0;
	}
	vector<set<int> > v(1 << n);
	mask = (1 << (n - 1)) - 1;
	for (int i = 0; i < (1 << (n - 1)); i++) {
		v[i].insert((2 * i) & mask);
		v[i].insert((2 * i + 1) & mask);
	}
	vector<int> res;
	dfs(0, v, res);
	reverse(res.begin(), res.end());

	for (int i = n - 2; i >= 0; i--) {
		cout <<((1 << i) & res[0]);
	}
	for (int i = 1; i < res.size(); i++) {
		cout << (res[i] & 1);
	}
	cout << endl;
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
