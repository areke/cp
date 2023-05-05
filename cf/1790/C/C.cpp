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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tests;
	cin >> tests;
	while (tests--) {
		int n;
		cin >> n;
		map<int, vector<int> > m;
		map<int, int> l;
		for (int i = 0; i < n; i++) {
			set<int> s;
			for (int j =1; j <= n; j++) {
				s.insert(j);
			}
			vector<int> v(n - 1);
			for (int j = 0; j < n - 1; j++) {
				cin >> v[j];
				s.erase(s.find(v[j]));
			}
			m[*s.begin()] = v;
			l[v.back()]++;
		}
		int best = -1;
		for (auto it : l) {
			if (it.second > l[best]) best = it.first;
		}
		for (int i = 0; i < m[best].size(); i++) {
			cout << m[best][i] << " ";
		}
		cout << best << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
