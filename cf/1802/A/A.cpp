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
		map<int, int> m;
		int x = 0;
		int y = 0;
		for (int i = 0; i < n; i++ ){
			cin >> a[i];
			m[abs(a[i])]++;
		}
		sort(a.begin(), a.end());
		for (auto it : m) {
			if (it.second >= 2) x++;
			else y++;
		}
		vector<int> mini(n);
		vector<int> maxi(n);
		for (int i = 0; i < x; i++) {
			mini[2 * i] = 1;
			mini[2 * i + 1] = 0;
		}
		for (int i = 2 * x; i < n; i++) {
			mini[i] = i - 2 * x + 1;
		}
		for (int i = 0; i < x + y; i++) {
			maxi[i] = i + 1;
		}
		int cur = x + y - 1;
		for (int i = x + y; i < n; i++) {
			maxi[i] = cur--;
		}
		for (int i = 0; i < n; i++) {
			cout << maxi[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
		for (int i = 0; i < n; i++) {
			cout << mini[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}

	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
