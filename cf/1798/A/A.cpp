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
		vector<int> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}
		bool res = true;
		for (int i = n - 2; i >= 0; i--) {
			if (a[i] > a[n - 1] || b[i] > b[n - 1]) {
				
				swap(a[i], b[i]);
				//cout << i << " !" << a[i] << " " << b[i] << " " << a[i + 1] << " " << b[i + 1] << endl;
			}
			if (a[i] > a[n - 1] || b[i] > b[n - 1]) {
				//cout << i << " /" << a[i] << " " << b[i] << " " << a[i + 1] << " " << b[i + 1] << endl;
				res = false;
				break;
			}
		}
		if (res) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
