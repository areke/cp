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
		int n, k;
		cin >> n >> k;
		vector<int> a(n, 0);
		int cnt = 1;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			if (i % k == k - 1) {
				a[i] = cnt;
				cnt++;
			}
		}
		cnt = n;
		for (int i = 0; i < n; i++) {
			if (!a[i]) {
				a[i] = cnt;
				cnt--;
			}
		}
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}

	// IF STUCK:
		// CONSIDER SMALL CASES
	return 0;
}
