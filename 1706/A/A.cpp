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
		int n, m;
		cin >> n >> m;
		string s(m, 'B');
		for (int i = 0; i < n; i++) {
			int x;
			cin >> x;
			x--;
			int mini = min(x, m - x - 1);
			int maxi = max(x, m - x - 1);
			if (s[mini] == 'A') {
				s[maxi] = 'A';
			} else {
				s[mini] = 'A';
			}
			
		}
		cout << s << endl;
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
