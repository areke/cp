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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		long long n;
		cin >> n;
		
		vector<long long> o(n);
		set<long long> vis;
		for (int i = 0; i < n; i++) {
			cin >> o[i];
			vis.insert(o[i]);
		}
		vector<long long> v;
		for (auto i : vis) {
			v.push_back(i);
		}
		sort(v.begin(), v.end());
		sort(o.begin(), o.end());
		if (v.size() >= 3) {
			long long res = 0;
			res = max(abs(v[v.size() - 1] - v[0]) + abs(v[v.size() - 1] - v[v.size() - 2]), res);
			res = max(abs(v[v.size() - 1] - v[0]) + abs(v[1] - v[0]), res);
			cout << res << endl;
		} else if (v.size() == 2) {
			cout << 2 * abs(v[1] - v[0]);
		} else {
			cout << 0 << endl;
		}
	}
	return 0;
}
