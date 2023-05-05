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
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (a[i] == 2) tot++;
		}
		int cur = 0;
		int ind = -1;
		for (int i = 0; i < n; i++) {
			if (a[i] == 2) {
				cur++;
			}
			if (cur * 2 == tot) {
				ind = i + 1;
				break;
			}
		}
		cout << ind << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
