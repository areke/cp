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
#include <assert.h>
using namespace std;

void set_place(int ind, long long val, vector<vector<pair<int, long long> > > & e, vector<long long> & a, vector<long long> & mini) {
	if (a[ind] != -1) return;
	a[ind] = val;
	mini[ind] = val;
	for (int i = 0; i < e[ind].size(); i++) {
		mini[e[ind][i].first] |= (e[ind][i].second - val);
		assert(val <= e[ind][i].second);
		if (val == 0) {
			set_place(e[ind][i].first, e[ind][i].second, e, a, mini);
		}
		//set(e[ind][i].first, )
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<long long> a(n, -1);
	vector<long long> mini(n, 0);
	vector<vector<pair<int, long long> > > e(n);

	for (int qq = 0; qq < q; qq++) {
		long long i, j, x;
		cin >> i >> j >> x;
		i--;
		j--;
		e[i].push_back(make_pair(j, x));
		e[j].push_back(make_pair(i, x));
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			if (e[i][j].first == i) {
				set_place(i, e[i][j].second, e, a, mini);
			} else if (e[i][j].second == 0) {
				set_place(i, e[i][j].second, e, a, mini);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			set_place(i, mini[i], e, a, mini);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i == n - 1) cout << endl;
		else cout << " ";
	}
	return 0;
}
