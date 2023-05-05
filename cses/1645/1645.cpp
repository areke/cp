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
	int n;
	cin >> n;
	vector<long long> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	stack<int> s;
	vector<int> res(n, 0);
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && a[s.top()] > a[i]) {
			res[s.top()] = i + 1;
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		cout << res[i] << " \n"[i == n - 1];
	}
	// IF STUCK:
		// DIV CONQUER?
		// CONSIDER SMALL CASES
	return 0;
}
