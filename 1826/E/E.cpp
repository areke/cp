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
	int m, n;
	cin >> m >> n;
	vector<long long> p(n);
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	vector<vector<long long> > v(n, vector<long long>(m, 0));

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> v[j][i];
		}
	}
	vector<vector<bool> > can(n, vector<bool>(n, 0));


	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
