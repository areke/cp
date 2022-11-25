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

int main() {
	int tests;
	cin >> tests;
	while (tests--) {
		int n, m;
		cin >> n >> m;
		vector<pair<int, int> > v;
		for (int i = 0; i < m; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		bool res = false;
		for (int i = 0; i <= m; i++) {
			bool b = true;
			map<int, int> mx;
			map<int, int> my;
			for (int j = 0; j < m; j++) {
				if (i == j) continue;
				mx[v[j].first]++;
				my[v[j].second]++;
				if (mx[v[j].first] > 1) b = false;
				if (mx[v[j].second] > 1) b = false;
			}
			if (b) res = true;
			if (i == n && b) res = false;
			//cout << i << " " << b << endl;
		}
		if (res) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
