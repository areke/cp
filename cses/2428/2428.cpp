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
#include <unordered_map>
#include <unordered_set>
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
	int n, k;
	cin >> n >> k;
	vector<long long> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	map<int, int> m;
	long long res = 0;
	for (int l = 0, r = 0; r < n; r++) {
		m[v[r]]++;
		while (m.size() > k) {
			m[v[l]]--;
			if (m[v[l]] == 0) m.erase(v[l]);
			l++;
		}
		res += r - l + 1;
		
	}
	cout << res << endl;


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
