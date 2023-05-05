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

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update

using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	vector<vector<int> > v;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({a, 1, i});
		v.push_back({b + 1, -1, i});
	}
	sort(v.begin(), v.end());
	set<int> s;
	map<int, int> m;
	int cnt = 0;
	int maxi = 0;
	vector<int> res(n);
	for (int i = 0; i < v.size(); i++) {
		if (v[i][1] == -1) {
			s.insert(m[v[i][2]]);
			cnt--;
		} else {
			cnt++;
			maxi = max(cnt, maxi);
			if (s.empty()) {
				m[v[i][2]] = cnt;
			} else {
				m[v[i][2]] = (*s.begin());
				s.erase(s.begin());
			}
			res[v[i][2]] = m[v[i][2]];
		}
	}
	cout << maxi << endl;
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
