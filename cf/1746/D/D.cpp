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
 
pair<long long, long long> solve(int x, vector<vector<int > > & v, vector<long long> & c, long long k) {
	long long res = c[x] * k;
 
	if (v[x].size() == 0) {
		return make_pair(c[x], res);
	}
	vector<pair<long long, long long> > scores(v[x].size());
	for (int i = 0; i < v[x].size(); i++) {
		scores[i] = solve(v[x][i], v, c, k / v[x].size());
		res += scores[i].second;
	}
	sort(scores.begin(), scores.end());
	int left = k % scores.size();
	for (int i = 0; i < left; i++) {
		res += scores[scores.size() - i - 1].first;
	}
	return make_pair(scores[scores.size() - 1].first + c[x], res);
}
 
int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		long long k;
		cin >> k;
		vector<vector<int> > v(n);
		vector<long long> c(n);
		for (int i = 1; i < n; i++) {
			int p;
			cin >> p;
			v[p - 1].push_back(i);
		}
		for (int i = 0; i < n; i++) {
			cin >> c[i];
		}
		pair<long long, long long> res = solve(0, v, c, k);
		cout << res.second << endl;
	}
	return 0;
}