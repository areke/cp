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
		vector<int> a(n);

		map<int, int> mini;
		map<int, vector<int> > v;
		set<int> s;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (!mini.count(a[i])) {
				mini[a[i]] = i;
			} else {
				mini[a[i]] = min(mini[a[i]], i);
			}
			v[a[i]].push_back(i);
			s.insert(i);
		}
		int cnt = 0;
		bool e = true;
		for (int i = n; i >= 1; i--) {
			if (e) {
				
			}
			e = true;
			int maxi = 0;
			for (int j : v[i]) {
				s.erase(s.find(j));
			}
			for (auto it = s.rbegin(); it != s.rend(); it++) {
				maxi = *it;
				break;
			}
			
			if (mini.count(i) && mini[i] < maxi) {
				cnt++;
				e = false;
			}
			if (!e) {
				for (int j : v[i]) {
					s.insert(j);
				}
			}
			//cout << i << " " << cnt << " " << mini.count(i) << " " << mini[i] << " " << maxi << " " << s.size() << endl;
		}
		cout <<cnt << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
