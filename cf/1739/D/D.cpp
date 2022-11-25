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
#include <queue>
#include <list>
#include <cstring>
using namespace std;


int dfs(int x, vector<int> & p, vector<vector<int> > & v, int d, int & cuts) {
	int depth = 1;
	for (int i = 0; i < v[x].size(); i++) {
		depth = max(depth, dfs(v[x][i], p, v, d, cuts) + 1);
	}
	if (depth >= d && p[x] != -1 && p[x] != 0) {	
		cuts += 1;
		return 0;
	}
	return depth;

}

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n, k;
		cin >> n >> k;
		vector<vector<int> > v(n);
		vector<int> p(n);
		p[0] = -1;
		for (int i = 1; i < n; i++) {
			int x;
			cin >> x;
			v[x - 1].push_back(i);
			p[i] = x - 1;
		}
		vector<int> c(n, 0);
		vector<int> d(n, 0);
		int low = 1;
		int high = n;
		int res = n;
		while (low <= high) {
			int mid = (low + high) / 2;
			int cuts = 0;
			dfs(0, p, v, mid, cuts);
			if (cuts <= k) {
				high = mid - 1;
				res = min(res, mid);
			} else {
				low = mid + 1;
			}
		}
		cout << res << endl;
	}
	return 0;
}
