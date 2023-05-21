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
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int cnt[2] = {0};
		sort(a.begin(), a.end());
		for (int i = 0; i < n; i++) {
			cnt[a[i] % 2]++;
		}
		if (cnt[0] == 0 || cnt[1] == 0) {
			cout << "YES" << endl;
			continue; 
		}
		if (a[0] % 2 == 0) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
