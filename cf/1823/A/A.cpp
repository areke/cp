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
	for (int test = 1; test <= tests; test++) {
		int n, k;
		cin >> n >> k;
		int num = -1;
		for (int i = 0; i <= n; i++) {
			int c = i * (i - 1) / 2;
			int d = (n - i) * (n - i - 1) / 2;
			if (c + d== k) {
				num = i;
				break;
			}
		}
		if (num == -1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
			for (int i = 0; i < num; i++) {
				cout << 1 << " ";
			}
			for (int i = 0; i < n - num; i++) {
				cout << - 1 << " ";
			}
			cout << endl;
		}
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
