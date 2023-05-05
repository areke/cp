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
		vector<int> b(n - 1);
		for (int i = 0; i < n - 1; i++) {
			cin >> b[i];
		}
		vector<int> a(n);
		a[0] = 0;
		for (int i = 0; i < n - 1; i++) {
			a[i + 1] = b[i];
			if (a[i + 1] > a[i]) continue;
			if (a[i + 1] == a[i]) a[i + 1] = 0;
			else swap(a[i], a[i - 1]);
		}
		for (int i = 0; i < n; i++) {
			cout << a[i];
			if (i == n - 1) cout << endl;
			else cout << " ";
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
