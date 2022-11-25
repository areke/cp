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

pair<int, int> solve(int x, vector<vector<int> > & e) {
	vector<pair<int, int> > v(e[x].size());
	int mini = x;
	int best = 1;
	int res = 0;
	int depth = 1;
	for (int i = 0; i < e[x].size(); i++) {
		v[i] = solve(e[x][i], e);
		res += v[i].first;
		depth = max(depth, 1 + v[i].second);
	}
	res = max(res, depth);
	return {res, depth};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> p(n);
	vector<vector<int> > e(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i];
		p[i]--;
		e[p[i]].push_back(i);
	}
	cout << solve(0, e).first << endl;
	return 0;
}
