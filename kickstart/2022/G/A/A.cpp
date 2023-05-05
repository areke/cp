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
		int n, m, p;
		cin >> m >> n >> p;
		vector<vector<long long> > v(m, vector<long long>(n, 0));
		vector<long long> maxi(n, 0);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> v[i][j];
				maxi[j] = max(v[i][j], maxi[j]);
			}
		}
		p--;
		long long res = 0;
		for (int i = 0; i < n; i++) {
			res += maxi[i] - v[p][i];
		}
		cout << "Case #" << test << ": " << res << endl;
		
	}

	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
